#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10000

struct Node {
    int coef; // 係數
    int exp; // 次方
};

struct Poly
{
	// 開始位置、結束位置、下次要放的位置
    int list_1_start, list_1_end, list_1_next;
    int list_2_start, list_2_end, list_2_next;
	int list_3_start, list_3_end, list_3_next; // 放相乘結果

    Node list[MAX_SIZE];

    Poly()
    {
        list_1_start = list_1_end = list_1_next = 0;
        list_2_start = list_2_end = list_2_next = 0;
		list_3_start = list_3_end = list_3_next = 0;
    }

    void add_list_1(int, int);
    void add_list_2(int, int);
	void add_list_3(int, int);
	void print_list_1();
	void print_list_2();
	void print_list_3();
	void mul_list_1_2_to_3();
	void bubble_sort_list_3();
};

void Poly::add_list_1(int coef, int exp)
{
	if (coef == 0) // 係數為零次項
	{
		return;
	}

	list[list_1_next].coef = coef;
	list[list_1_next].exp = exp;
	list_1_end = list_1_next;
	list_1_next++;
	return;
}

void Poly::add_list_2(int coef, int exp)
{
	if (coef == 0) // 係數為零次項
	{
		return;
	}

	if (list_2_next == 0) // 第一次放
	{
		list_2_start = list_1_next; 
		list_2_next = list_1_next;
	}

	list[list_2_next].coef = coef;
	list[list_2_next].exp = exp;
	list_2_end = list_2_next;
	list_2_next++;
	return;
}

void Poly::add_list_3(int coef, int exp)
{
	int i;

	if (coef == 0) // 係數為零次項
	{
		return;
	}

	if (list_3_next == 0) // 第一次放
	{
		list_3_start = list_2_next;
		list_3_next = list_2_next;
	}

	for (i = list_3_start; i <= list_3_end; i++)
	{
		if (list[i].exp == exp)
		{
			list[i].coef = list[i].coef + coef;
			return;
		}
	}

	list[list_3_next].coef = coef;
	list[list_3_next].exp = exp;
	list_3_end = list_3_next;
	list_3_next++;
	return;
}

/* 輸出多項式1 */
void Poly::print_list_1()
{
	int i;

	printf("--多項式1為: ");
	for (i = 0; i <= list_1_end; i++)
	{
		if (list[i].coef == 1)
		{
			if (list[i].exp == 0)
			{
				printf("1+");
			}
			else if (list[i].exp == 1)
			{
				printf("x+");
			}
			else
			{
				printf("x^%d+", list[i].exp);
			}
		}
		else if (list[i].exp == 0)
		{
			printf("%d+", list[i].coef);
		}
		else
		{
			printf("%dx^%d+", list[i].coef, list[i].exp);
		}
	}

	printf("\b \b"); // 刪除最後一個符號
	printf("\n\n");
	
	return;
}

/* 輸出多項式2 */
void Poly::print_list_2()
{
	int i;

	printf("--多項式2為: ");
	for (i = list_2_start; i <= list_2_end; i++)
	{
		if (list[i].coef == 1)
		{
			if (list[i].exp == 0)
			{
				printf("1+");
			}
			else if (list[i].exp == 1)
			{
				printf("x+");
			}
			else
			{
				printf("x^%d+", list[i].exp);
			}
		}
		else if (list[i].exp == 0)
		{
			printf("%d+", list[i].coef);
		}
		else
		{
			printf("%dx^%d+", list[i].coef, list[i].exp);
		}
	}

	printf("\b \b"); // 刪除最後一個符號
    printf("\n\n");
	
	return;
}

/* 輸出結果 */
void Poly::print_list_3()
{
	int i;

	for (i = list_3_start; i <= list_3_end; i++)
	{
		if (list[i].coef == 1)
		{
			if (list[i].exp == 0)
			{
				printf("1+");
			}
			else if (list[i].exp == 1)
			{
				printf("x+");
			}
			else
			{
				printf("x^%d+", list[i].exp);
			}
		}
		else if (list[i].exp == 0)
		{
			printf("%d+", list[i].coef);
		}
		else
		{
			printf("%dx^%d+", list[i].coef, list[i].exp);
		}
	}

	printf("\b \b"); // 刪除最後一個符號
	printf("\n\n");
	
	return;
}

void Poly::mul_list_1_2_to_3()
{
	int i, j;

	for (i = list_1_start; i <= list_1_end; i++)
	{
		for (j = list_2_start; j <= list_2_end; j++)
		{
			add_list_3(list[i].coef * list[j].coef, list[i].exp + list[j].exp);
		}
	}
	
	return;
}

void Poly::bubble_sort_list_3()
{
	int length = list_3_end - list_3_start + 1;
	int i;
	Node temp;

	while (length > 1)
	{
		length--;
		for (i = list_3_start; i < length+list_3_start; i++) //每次循環要比較的次數
		{
			if (list[i].exp > list[i+1].exp) // 比大小後交換
			{
				temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
			}
		}
	}

	return;
}

int main()
{
	Poly poly;
    int num1, num2;

	/* 輸入多項式1 */
    while (1)
	{
        printf("輸入多項式1(係數 次方): ");
        scanf("%d %d", &num1, &num2);
        
		if (num1 == 0 && num2 == 0)
		{
			break;
		}

		poly.add_list_1(num1, num2);
    }
    
    /* 輸出多項式1 */
    poly.print_list_1();
    
    /* 輸入多項式2 */
	while (1)
	{
        printf("輸入多項式2(係數 次方): ");
        scanf("%d %d", &num1, &num2);
        
        if (num1 == 0 && num2 == 0)
		{
			break;
		}
		
		poly.add_list_2(num1, num2);
    }
    
    /* 輸出多項式2 */
    poly.print_list_2();

	/* 相乘 */
	poly.mul_list_1_2_to_3();

	/* 排序 */
	poly.bubble_sort_list_3();

	/* 輸出結果 */
	poly.print_list_3();

    return 0;
}
