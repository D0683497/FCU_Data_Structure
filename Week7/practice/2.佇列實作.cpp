#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

struct Queue
{
	Node* head;
	Node* tail;
	
	Queue() 
	{
		head=tail=NULL;
	}
	
	// void create();
	int isFull();
	int isEmpty();
    void add();
    void del();
    void show();
};

// void Queue::create() { }

int Queue::isFull()
{
    return 0; // false
}

int Queue::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return 1; // true
    }

    return 0; // false
}

void Queue::add()
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
	else // 2. head 跟 tail 不為空，插在最後面
	{
        tail->next = add;
		tail = add;
	}
}

void Queue::del()
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

void Queue::show()
{
    Node *curr;
	curr = head;

    printf("佇列內容: ");

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
    Queue queue;

    while (1)
	{
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 : ");
		scanf("%d",&op);
		switch (op)
		{
			case 1: // 新增
                if (queue.isFull())
                {
                    printf("滿了\n");
                }
                else
                {
                    queue.add();
                }
				break;
			case 2: // 刪除
                if (queue.isEmpty())
                {
                    printf("空了\n");
                }
                else
                {
                    queue.del();
                }
				break;
			case 3: // 顯示
				queue.show();
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
