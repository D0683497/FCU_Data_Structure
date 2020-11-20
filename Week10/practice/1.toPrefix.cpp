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
	mod = 2,
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
	
	Stack()
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

typedef struct InOrder
{
	int inCount;
	Data in[MAX_SIZE]; // 原資料
	int preCount;
	Data pre[MAX_SIZE]; // 前序
	void Set(char* string);
	void Reset();
	void ShowIn();
	void InToPre();
	void ShowPre();
	void ShowResule();
} InOrder;

void InOrder::Set(char* string)
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

void InOrder::Reset()
{
	inCount = 0;
	memset(in, 0, sizeof(struct Data)*MAX_SIZE);
	preCount = 0;
	memset(pre, 0, sizeof(struct Data)*MAX_SIZE);
}

void InOrder::ShowIn()
{
	int i;
	printf("Infix :");
	for(i = 0; i < inCount; i++)
	{
		if(in[i].type == val)
		{
			printf("%d", in[i].value);
		}
		else
		{
			printf("%c", in[i].oper);
		}	
	}
	printf("\n");
}

void InOrder::InToPre()
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

void InOrder::ShowResule()
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
	InOrder inOrder;
	
	FILE *fptr = fopen(FILE_NAME, "r");
	while(fscanf(fptr, "%s", tmp) != EOF)
	{
		inOrder.Set(tmp);
		inOrder.ShowIn();
		inOrder.InToPre();
		inOrder.ShowPre();
		inOrder.ShowResule();
		
		/* 重設所有變數 */
		memset(tmp, 0, sizeof tmp);
		inOrder.Reset();
	}
	fclose(fptr);
	
	return 0;
} 
