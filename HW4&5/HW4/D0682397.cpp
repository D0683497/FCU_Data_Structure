#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

typedef struct Order
{
	int preCount;
	Data pre[MAX_SIZE]; // 前序
	void Set(char* string);
	void ShowPreResule();
} Order;

void Order::Set(char* string)
{
	char s;
	preCount = 0;

	while(!(string[preCount] == '\0'))
	{
		s = string[preCount];
		if(s >= '0' && s <= '9')
		{
			pre[preCount].type = val;
			pre[preCount].value = int(s) - '0';
		}
		else
		{
			pre[preCount].type = oper;
			pre[preCount].oper = s;
			switch (s)
			{
				case '+':
					pre[preCount].pre = add;
					break;
				case '-':
					pre[preCount].pre = sub;
					break;
				case '*':
					pre[preCount].pre = mult;
					break;
				case '/':
					pre[preCount].pre = division;
					break;
				case '%':
					pre[preCount].pre = mod;
					break;
				case ')':
					pre[preCount].pre = right;
					break;
				case '(':
					pre[preCount].pre = left;
					break;
				default:
					break;
			}
		}
		preCount++;		
	}
	
	return;
}

void Order::ShowPreResule()
{
	int i;
	int value1, value2;
	Data result;
	Stack stack;
	printf("Result : ");
	for (i = preCount-1; i >= 0; i--)
	{
		if (pre[i].type == val)
		{
			stack.Push(pre[i]);
		}
		else
		{
			value1 = stack.Pop().value;
			value2 = stack.Pop().value;
			switch (pre[i].oper)
			{
				case '+':
					result.type = val;
					result.value = value1 + value2;
					break;
				case '-':
					result.type = val;
					result.value = value1 - value2;
					break;
				case '*':
					result.type = val;
					result.value = value1 * value2;
					break;
				case '/':
					result.type = val;
					result.value = value1 / value2;
					break;
				case '%':
					result.type = val;
					result.value = value1 % value2;
					break;
				default:
					break;
			}
			stack.Push(result);	
		}
	}

	printf("%d\n", stack.data[stack.top].value);

	printf("\n");
}

int main()
{
	char tmp[MAX_SIZE];
	Order Order;

	printf("請輸入: ");
	scanf("%s", tmp);

	Order.Set(tmp);
	Order.ShowPreResule();
	
	return 0;
} 
