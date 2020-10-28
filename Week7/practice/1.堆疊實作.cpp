#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

struct Stack
{
	Node* head;
	Node* tail;
	
	Stack() 
	{
		head=tail=NULL;
	}
	
	// void create();
	int isFull();
	int isEmpty();
    void push();
    void pop();
    void show();
};

// void Stack::create() { }

int Stack::isFull()
{
    return 0; // false
}

int Stack::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return 1; // true
    }

    return 0; // false
}

void Stack::push()
{
    int num;
    printf("輸入值: ");
    scanf("%d", &num);

    Node *add = (Node*)malloc(sizeof(Node));
    add->num = num;
    add->next = NULL;

    if (tail == NULL) // 1. head 跟 tail 為空，直接把 head 跟 tail 換成目前輸入的
	{		
		head = add;
		tail = add;
	}
	else // 2. head 跟 tail 不為空，插在最前面
	{
        add->next = head;
        head = add;
	}
}

void Stack::pop()
{
    Node* curr = head; // 目前的頭

    if (curr == tail) // 目前刪的是最後一個
    {
        head = NULL;
        tail = NULL;
        free(curr);
        return;
    }

    head = head->next; // 把頭往下指
    free(curr);
}

void Stack::show()
{
    Node *curr;
	curr = head;

    printf("堆疊內容: ");

    if (curr == NULL)
    {
        printf("NULL");
    }
	
	while(curr != NULL)
	{
		printf("%d ", curr->num);	
		curr = curr->next;
	}

    printf("\n");
}

int main()
{
    int op;
    Stack stack;

    while (1)
	{
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 : ");
		scanf("%d",&op);
		switch (op)
		{
			case 1: // 新增
                if (stack.isFull())
                {
                    printf("滿了\n");
                }
                else
                {
                    stack.push();
                }
				break;
			case 2: // 刪除
                if (stack.isEmpty())
                {
                    printf("空了\n");
                }
                else
                {
                    stack.pop();
                }
				break;
			case 3: // 顯示
				stack.show();
				break;
			case 0: // 結束
				return 0;
			default:
				printf("ERROR!!!!\n");
				return 0;	
		}
	}

    return 0;
}
