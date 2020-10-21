#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Node {
    int coef; // �Y�� 
    int exp; // ���� 
};

int index1 = 0;
int index2 = 0;
Node list[MAX_SIZE];

void bubble_sort_1()
{
	int len = index1;
	int i, j;
	Node temp;
	
	for (i = 0; i < len-1; ++i) //�`��N-1��
	{
		for (j = 0; j < len-1-i; ++j) //�C���`���n���������
		{
			if (list[j].exp < list[j+1].exp) // ��j�p��洫
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

	for (i = 0; i < len-1; ++i) //�`��N-1��
	{
		for (j = index1+1; j < len-1-i+index1+1; ++j) //�C���`���n���������
		{
			if (list[j].exp < list[j+1].exp) // ��j�p��洫
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
	
	for (i = 0; i < len-1; ++i) //�`��N-1��
	{
		for (j = 0; j < len-1-i; ++j) //�C���`���n���������
		{
			if (list[j].exp < list[j+1].exp) // ��j�p��洫
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
	
	for (i = 0; i < len-1; ++i) //�`��N-1��
	{
		for (j = 0; j < len-1-i; ++j) //�C���`���n���������
		{
			if (list[j].exp == list[j+1].exp) // ��j�p��洫
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

	/* ��J�h����1 */
    while (1)
	{
		flag = false;
        printf("��J�h����1(�Y�� ����): ");
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
				if (list[i].exp == num2) // ��J�w�g��������
				{
					list[i].coef += num1;
					flag = true;
				}
			}
			
			if (!flag) // ��J�s������
			{
				list[index1].coef = num1;
				list[index1].exp = num2;
				index1++;
			}
		}
    }
    
    /* �ƧǦh����1 */
    bubble_sort_1();
    
    /* ��X�h����1 */
    printf("--�h����1��: ");
    for (i = 0; i <= index1; i++)
    {
    	if (list[i].coef == 0) // �Y�Ƭ� 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // ���謰 0 (�̫�@��)
		{
			printf("%d", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // �Y�Ƭ� 1
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
    
    /* ��J�h����2 */
    index2 = index1 + 1;
	while (1)
	{
		flag = false;
        printf("��J�h����2(�Y�� ����): ");
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
				if (list[i].exp == num2) // ��J�w�g��������
				{
					list[i].coef += num1;
					flag = true;
				}
			}
			
			if (!flag) // ��J�s������
			{
				list[index2].coef = num1;
				list[index2].exp = num2;
				index2++;
			}
		}
    }
    
    /* �ƧǦh����2 */
    bubble_sort_2();
    
    /* ��X�h����2 */
    printf("--�h����2��: ");
    for (i = index1+1; i <= index2; i++)
    {
    	if (list[i].coef == 0) // �Y�Ƭ� 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // ���謰 0 (�̫�@��)
		{
			printf("%d", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // �Y�Ƭ� 1
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
	printf("�ۥ[���G��: ");
	for (i = 0; i <= index2; i++)
	{
		if (list[i].coef == 0) // �Y�Ƭ� 0 
    	{
    		continue;
		}
		else if (list[i].exp == 0) // ���謰 0
		{
			printf("%d+", list[i].coef);
		}
		else
		{
			if (list[i].coef == 1) // �Y�Ƭ� 1
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
