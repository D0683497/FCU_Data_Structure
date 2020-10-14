#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int row;  //行
    int col;  //列 
    int value;   
} term;

int main()
{
	int arrayA[MAX_SIZE][MAX_SIZE];
	int arrayB[MAX_SIZE][MAX_SIZE];
	int newArray[MAX_SIZE][MAX_SIZE];
	term termArray[MAX_SIZE*MAX_SIZE];
	
	int arrayARow, arrayACol, arrayBRow, arrayBCol;
	int i, j, k, itemCount;
	
	while(1)
	{
		printf("請輸入矩陣A(m*n)的大小: ");
		scanf("%d %d", &arrayARow, &arrayACol);
		printf("請依序輸入二維陣列A(%d*%d)的元素內容:\n", arrayARow, arrayACol);
		for (i = 0; i < arrayARow; i++)
		{
			for (j = 0; j < arrayACol; j++)
			{
				scanf("%d", &arrayA[i][j]);
			}
		}
		
		printf("請輸入矩陣B(m*n)的大小: ");
		scanf("%d %d", &arrayBRow, &arrayBCol);
		printf("請依序輸入二維陣列B(%d*%d)的元素內容: \n", arrayBRow, arrayBCol);
		for (i = 0; i < arrayBRow; i++)
		{
			for (j = 0; j < arrayBCol; j++)
			{
				scanf("%d", &arrayB[i][j]);
			}
		}
		
		if (arrayARow > MAX_SIZE || arrayACol > MAX_SIZE || arrayBRow > MAX_SIZE || arrayBCol > MAX_SIZE)
		{
			printf("請重新輸入!!!!\n");
		}
		else if (arrayARow != arrayBCol && arrayACol != arrayBRow)
		{
			printf("請重新輸入!!!!\n");
		}
		else
		{
			break;	
		}
	}
	
	/* 初始化 */
	for (i = 0; i < arrayARow; i++)
	{
		for (j = 0; j < arrayBCol; j++)
		{
			newArray[i][j] = 0;
		}
	}
	
	/* 相乘 */
	for (i = 0; i < arrayARow; i++)
	{
		for (j = 0; j < arrayBCol; j++)
		{
			for (k = 0; k < arrayACol; k++)
			{
				newArray[i][j] += ((arrayA[i][k]) * (arrayB[k][j]));
			}
		}
	}
	
	/* 稀疏矩陣 */
	itemCount = 0;
	for (i = 0; i < arrayARow; i++)
	{
		for (j = 0; j < arrayBCol; j++)
		{
			if (newArray[i][j] != 0)
			{
				termArray[itemCount].row = i;
				termArray[itemCount].col = j;
				termArray[itemCount].value = newArray[i][j];
				itemCount++;
			}
		}
	}
	
	/* 輸出 */
	printf("稀疏矩陣:\n");
	printf("尺寸: %d*%d 項目數: %d\n", arrayARow, arrayBCol, itemCount);
	printf("index   row     col     value\n");
	for (i = 0; i < itemCount; i++)
	{
		j = i+1;
		printf("%d        %d        %d        %d\n", j, termArray[i].row, termArray[i].col, termArray[i].value);
	}
	
	
	return 0;
}

