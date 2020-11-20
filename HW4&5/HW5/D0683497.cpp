#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

typedef struct Order
{
	int inCount;
	Data in[MAX_SIZE]; // 原資料
	int preCount;
	Data pre[MAX_SIZE]; // 前序
	void Set(char* string);
	void InToPre();
	void ShowPre();
} Order;

void Order::Set(char* string)
{
	char s;
	inCount = 0;

	while(!(string[inCount] == '\0'))
	{
		s = string[inCount];
		if(s >= '0' && s <= '9')
		{
			in[inCount].type = val;
			in[inCount].value = int(s) - '0';
		}
		else
		{
			in[inCount].type = oper;
			in[inCount].oper = s;
			switch (s)
			{
				case '+':
					in[inCount].pre = add;
					break;
				case '-':
					in[inCount].pre = sub;
					break;
				case '*':
					in[inCount].pre = mult;
					break;
				case '/':
					in[inCount].pre = division;
					break;
				case '%':
					in[inCount].pre = mod;
					break;
				case ')':
					in[inCount].pre = right;
					break;
				case '(':
					in[inCount].pre = left;
					break;
				default:
					break;
			}
		}
		inCount++;		
	}
	
	return;
}

void Order::InToPre()
{
	int i, j;
	Stack operStack;
	Stack valStack;

	/* 從後面讀 */
	for (i = inCount-1; i >=0; i--)
	{
		if (in[i].type == val)
		{
			valStack.Push(in[i]);
		}
		else
		{
			switch (in[i].oper)
			{
				case ')':
					operStack.Push(in[i]);
					break;
				case '(':
					/* operStack pop 到 valStack 直到遇到 ) */
					while (1)
					{
						if (operStack.data[operStack.top].oper == ')')
						{
							operStack.Pop();
							break;
						}
						else
						{
							valStack.Push(operStack.Pop());
						}
					}
					break;
				default:
					if (operStack.IsEmpty() == true)
					{
						operStack.Push(in[i]);
					}
					else
					{
						/* 堆疊裡的優先權小於或等於要放進去的 */
						if (operStack.data[operStack.top].pre <= in[i].pre)
						{
							operStack.Push(in[i]);
						}
						else
						{
							/* 將 operStack pop 至 valStack，直到 operStack 裡的優先權小於或等於要放進去的 */
							do {
								valStack.Push(operStack.Pop());
							} while(operStack.data[operStack.top].pre > in[i].pre && operStack.IsEmpty() != true);
							operStack.Push(in[i]);
						}
					}
					break;
			}
		}
	}
	
	/* 將 operStack 裡的資料全丟到 valStack */
	while (operStack.top != -1)
	{
		valStack.Push(operStack.Pop());
	}
	
	/* 將 valStack 的資料存到 pre */
	preCount = 0;
	while (valStack.top != -1)
	{
		pre[preCount] = valStack.Pop();
		preCount++;
	}
	
	return;
}

void Order::ShowPre()
{
	int i;
	printf("Prefix :");
	for(i = 0; i < preCount; i++)
	{
		if(pre[i].type == val)
		{
			printf("%d", pre[i].value);
		}
		else
		{
			printf("%c", pre[i].oper);
		}	
	}
	printf("\n");
}

int main()
{
	char tmp[MAX_SIZE];
	Order Order;

	printf("請輸入: ");
	scanf("%s", tmp);

	Order.Set(tmp);
	Order.InToPre();
	Order.ShowPre();
	
	return 0;
} 