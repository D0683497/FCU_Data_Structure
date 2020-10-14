#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int row;  //��
    int col;  //�C 
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
	bool flag;
	
	while(1)
	{
		printf("�п�J�x�}A(m*n)���j�p: ");
		scanf("%d %d", &arrayARow, &arrayACol);
		printf("�Ш̧ǿ�J�G���}�CA(%d*%d)���������e:\n", arrayARow, arrayACol);
		for (i = 0; i < arrayARow; i++)
		{
			for (j = 0; j < arrayACol; j++)
			{
				scanf("%d", &arrayA[i][j]);
			}
		}
		
		printf("�п�J�x�}B(m*n)���j�p: ");
		scanf("%d %d", &arrayBRow, &arrayBCol);
		printf("�Ш̧ǿ�J�G���}�CB(%d*%d)���������e: \n", arrayBRow, arrayBCol);
		for (i = 0; i < arrayBRow; i++)
		{
			for (j = 0; j < arrayBCol; j++)
			{
				scanf("%d", &arrayB[i][j]);
			}
		}
		
		if (arrayARow > MAX_SIZE || arrayACol > MAX_SIZE || arrayBRow > MAX_SIZE || arrayBCol > MAX_SIZE)
		{
			printf("�Э��s��J!!!!\n");
		}
		else if (arrayARow != arrayBCol && arrayACol != arrayBRow)
		{
			printf("�Э��s��J!!!!\n");
		}
		else
		{
			break;	
		}
	}
	
	/* ��l�� */
	for (i = 0; i < arrayARow; i++)
	{
		for (j = 0; j < arrayBCol; j++)
		{
			newArray[i][j] = 0;
		}
	}
	
	/* �ۭ� */
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
	
	/* �}���x�} */
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
	
	/* ��m */
	for (i = 0; i < itemCount; i++)
	{
		j = termArray[i].row;
		termArray[i].row = termArray[i].col;
		termArray[i].col = j;
	}
	
	/* ��X��m�x�} */
	printf("��m�x�}:\n");
	printf("�ؤo: %d*%d\n", arrayBCol, arrayARow);
	flag = false;
	for (i = 0; i < arrayBCol; i++)
	{
		for (j = 0; j < arrayARow; j++)
		{
			for (k = 0; k < itemCount; k++)
			{
				if (termArray[k].row == i && termArray[k].col == j)
				{
					flag = true;
					printf("%d ", termArray[k].value);
				}
			}
			if (flag)
			{
				flag = false;
			}
			else
			{
				printf("%d ", 0);
			}
			
		}
		printf("\n");
	}
	
	
	return 0;
}

