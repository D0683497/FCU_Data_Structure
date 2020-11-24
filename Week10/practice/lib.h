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