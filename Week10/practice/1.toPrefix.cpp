#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "mid_109_input_2D.txt"
#define MAX_SIZE 80

enum Type
{
	val,
	oper
};

enum Precedence
{
	add = 1,
	sub = 1,
	mult = 2,
	division = 2,
	left = 0,
	right = 0
};

typedef struct Data
{
	Type type;
	int value;
	char oper;
	Precedence pre;
} Data;

typedef struct Stack
{
	int top;
	Data data[MAX_SIZE]; 
	bool IsEmpty();
	bool IsFull();
	void Push(Data d);
	Data Pop();
	Data Top();
	
	MyStack()
	{
		top=-1;
	}
} Stack;

bool Stack::IsEmpty()
{	
	if(top == -1)
		return true;
	else
		return false;	
}

bool Stack::IsFull()
{
	if(top == MAX_SIZE-1)
		return true;
	else
		return false;
}

void Stack::Push(Data d)
{
	if(IsFull() == true)
		printf("Stack is full. Cannot Push any element.\n");
	else
	{
		top++;
		data[top]= d;
	}	
}

Data Stack::Pop()
{
	if(IsEmpty() == true)
	{
		printf("Stack is Empty. Cannot pop any element.\n");
	}
	else
	{
		return data[top--];
	}
}

Data Stack::Top() 
{
	if (IsEmpty() == true)
		printf("The STACK is empty") ; 
	else
		return data[top];
}

typedef struct InOrder
{
	int itemcount;
	Data item[MAX_SIZE]; // 原資料 
	int preCount;
	Data pre[MAX_SIZE]; // 前序
	void Set(char* string);
	void Reset();
	void ShowIn();
	void InToPre();
	void ShowPre();
} InOrder;

void InOrder::Set(char* string)
{
	char s;
	itemcount = 0;

	while(!(string[itemcount] == '\0'))
	{
		s = string[itemcount];
		if(s >= '0' && s <= '9')
		{
			item[itemcount].type = val;
			item[itemcount].value = int(s) - '0';
		}
		else
		{
			item[itemcount].type = oper;
			item[itemcount].oper = s;
			switch (s)
			{
				case '+':
					item[itemcount].pre = add;
					break;
				case '-':
					item[itemcount].pre = sub;
					break;
				case '*':
					item[itemcount].pre = mult;
					break;
				case '/':
					item[itemcount].pre = division;
					break;
				case ')':
					item[itemcount].pre = right;
					break;
				case '(':
					item[itemcount].pre = left;
					break;
				default:
					break;
			}
		}
		itemcount++;		
	}
	
	return;
}

void InOrder::Reset()
{
	itemcount = 0;
	memset(item, 0, sizeof(struct Data)*MAX_SIZE);
	memset(pre, 0, sizeof(struct Data)*MAX_SIZE);
}

void InOrder::ShowIn()
{
	int i;
	printf("Infix :");
	for(i = 0; i < itemcount; i++)
	{
		if(item[i].type == val)
		{
			printf("%d", item[i].value);
		}
		else
		{
			printf("%c", item[i].oper);
		}	
	}
	printf("\n");
}

void InOrder::InToPre()
{
	int i, j, preCount;
	Data reverse[MAX_SIZE];
	Stack stack;
	
	/* 反轉，並將括號互換 */
	j = itemcount - 1;
	for (i = 0; i < itemcount; i++)
	{
		if (item[i].type == oper)
		{
			switch (item[i].oper)
			{
				case ')':
					reverse[j] = item[i];
					reverse[j].oper = '(';
					j--;
					break;
				case '(':
					reverse[j] = item[i];
					reverse[j].oper = ')';
					j--;
					break;
				default:
					reverse[j] = item[i];
					j--;
					break;
			}
		}
		else
		{
			reverse[j] = item[i];
			j--;
		}
	}
	
	/*  */
	for (i = 0; i < itemcount; i++)
	{
		if (reverse[i].type == val)
		{
			pre[preCount] = reverse[i];
			preCount++;
		}
		else
		{
			switch (reverse[i].oper)
			{
				case ')':
					stack.Push(reverse[i]);
					break;
				case '(':
					while (1)
					{
						if (stack.IsEmpty() == true)
						{
							break;
						}
						
						if (stack.Top().oper != ')')
						{
							pre[preCount] = stack.Pop();
							preCount++;
						}
						else
						{
							stack.Pop();
							break;
						}
					}
					break;
				default:
					if (stack.IsEmpty() == true)
					{
						stack.Push(reverse[i]);
					}
					else if (stack.Top().pre <= reverse[i].pre)
					{
						stack.Push(reverse[i]);
					}
					else
					{
						while(1)
						{
							if (stack.IsEmpty() == true)
							{
								break;
							}
							else if (stack.Top().pre >= reverse[i].pre)
							{
								pre[preCount] = stack.Pop();
								preCount++;
							}
						}
						stack.Push(reverse[i]);
					}
					break;
			}
		}
	}
	
//	while(stack.IsEmpty() != true)
//	{
//		pre[preCount] = stack.Pop();
//		preCount++;
//	}
}

void InOrder::ShowPre()
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
	InOrder inOrder;
	
	FILE *fptr = fopen(FILE_NAME, "r");
	while(fscanf(fptr, "%s", tmp) != EOF)
	{
		inOrder.Set(tmp);
		inOrder.ShowIn();
		inOrder.InToPre();
		inOrder.ShowPre();
		
		/* 重設所有變數 */
		memset(tmp, 0, sizeof tmp);
		inOrder.Reset();
	}
	fclose(fptr);
	
	return 0;
} 
