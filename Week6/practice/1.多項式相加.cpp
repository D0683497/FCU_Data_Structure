#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Node {
    int coef; // 係數 
    int exp; // 次方 
};

int index1 = 0;
int index2 = 0;
Node list[MAX_SIZE];

void bubble_sort_1()
{
	int len = index1;
	int i, j;
	Node temp;
	
	for (i = 0; i < len-1; ++i) //循環N-1次
	{
		for (j = 0; j < len-1-i; ++j) //每次循環要比較的次數
		{
			if (list[j].exp < list[j+1].exp) // 比大小後交換
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	
	return;
}

void bubble_sort_2()
{
	int len = index2-index1;
	int i, j;
	Node temp;

	for (i = 0; i < len-1; ++i) //循環N-1次
	{
		for (j = index1+1; j < len-1-i+index1+1; ++j) //每次循環要比較的次數
		{
			if (list[j].exp < list[j+1].exp) // 比大小後交換
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	
	return;
}

void bubble_sort_all()
{
	int len = index2+1;
	int i, j;
	Node temp;
	
	for (i = 0; i < len-1; ++i) //循環N-1次
	{
		for (j = 0; j < len-1-i; ++j) //每次循環要比較的次數
		{
			if (list[j].exp < list[j+1].exp) // 比大小後交換
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	
	return;
}

void add_all()
{
	int len = index2+1;
	int i, j;
	Node temp;
	
	for (i = 0; i < len-1; ++i) //循環N-1次
	{
		for (j = 0; j < len-1-i; ++j) //每次循環要比較的次數
		{
			if (list[j].exp == list[j+1].exp) // 比大小後交換
			{
				temp.coef = list[j].coef + list[j+1].coef;
				temp.exp =  list[j].exp;
				
				list[j] = temp;
				list[j+1].coef = 0;
				list[j+1].exp = 0;
			}
		}
	}
	
	return;
}

int main()
{
    int num1, num2;
    int i, j;
    bool flag = false;

	/* 輸入多項式1 */
    while (1)
	{
		flag = false;
        printf("輸入多項式1(係數 次方): ");
        scanf("%d %d", &num1, &num2);
        
        if (num1 == 0 && num2 == 0)
		{
			index1--;
			break;
		}
		else
		{
			for (i = 0; i < index1; i++)
			{
				if (list[i].exp == num2) // 輸入已經有的次方
				{
					list[i].coef += num1;
					flag = true;
				}
			}
			
			if (!flag) // 輸入新的次方
			{
				list[index1].coef = num1;
				list[index1].exp = num2;
				index1++;
			}
		}
    }
    
    /* 排序多項式1 */
    bubble_sort_1();
    
    /* 輸出多項式1 */
    printf("--多項式1為: ");
    for (i = 0; i <= index1; i++)
    {
    	if (list[i].coef == 0) // 係數為 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // 次方為 0 (最後一個)
		{
			printf("%d", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // 係數為 1
			{
				printf("x^%d+", list[i].exp);
			}
			else
			{
				printf("%dx^%d+", list[i].coef, list[i].exp);
			}
		}
	}
    printf("\n\n");
    
    /* 輸入多項式2 */
    index2 = index1 + 1;
	while (1)
	{
		flag = false;
        printf("輸入多項式2(係數 次方): ");
        scanf("%d %d", &num1, &num2);
        
        if (num1 == 0 && num2 == 0)
		{
			index2--;
			break;
		}
		else
		{
			for (i = index1+1; i < index2; i++)
			{
				if (list[i].exp == num2) // 輸入已經有的次方
				{
					list[i].coef += num1;
					flag = true;
				}
			}
			
			if (!flag) // 輸入新的次方
			{
				list[index2].coef = num1;
				list[index2].exp = num2;
				index2++;
			}
		}
    }
    
    /* 排序多項式2 */
    bubble_sort_2();
    
    /* 輸出多項式2 */
    printf("--多項式2為: ");
    for (i = index1+1; i <= index2; i++)
    {
    	if (list[i].coef == 0) // 係數為 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // 次方為 0 (最後一個)
		{
			printf("%d", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // 係數為 1
			{
				printf("x^%d+", list[i].exp);
			}
			else
			{
				printf("%dx^%d+", list[i].coef, list[i].exp);
			}
		}
	}
    printf("\n\n");
    
//  printf("index1: %d\n", index1);
//	printf("index2: %d\n", index2);
//	for (i = 0; i<= index2; i++)
//	{
//		printf("%dx^%d + ", list[i].coef, list[i].exp);
//	}

	
	bubble_sort_all();
	
	add_all();
	printf("相加結果為: ");
	for (i = 0; i <= index2; i++)
	{
		if (list[i].coef == 0) // 係數為 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // 次方為 0
		{
			printf("%d+", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // 係數為 1
			{
				printf("x^%d+", list[i].exp);
			}
			else
			{
				printf("%dx^%d+", list[i].coef, list[i].exp);
			}
		}
	}
	printf("\b \b");
	printf("\n\n");

	
    return 0;
}
