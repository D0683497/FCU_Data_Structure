#include<stdio.h>
#include<stdlib.h>

struct Node {
    int num1;
    int num2;
    struct Node* next;
};

struct List {
    Node* head;
    Node* tail;

    List()
    {
        head = tail = NULL;
    }

    void Insert(int, int);
    void Show();
};

// 逼(Ωよ) 
void List::Insert(int num1, int num2)
{
    Node* add = (Node*)malloc(sizeof(Node));
    
    add->num1 = num1;
    add->num2 = num2;
    add->next = NULL;

    if (tail == NULL)
    {
        tail = add;
        head = add;
    }
    else
    {
        Node* curr;
        Node* pre;
        curr = pre = head;
        
        while (curr != NULL)
        {
        	if (curr->num2 == num2) // 穝糤计竒﹃
        	{
        		printf("%d竒﹃い\n", num2);
        		return;
			}
			else if (curr->num2 < add->num2) // 础 
			{
				if (curr == head) // 础计琌程(程玡)
				{
					add->next = head;
					head = add;
					return;
				}
				else // 础い丁 
				{
					pre->next = add;
					add->next = curr;
					return;
				} 
			}
			else //  
			{
				pre = curr;
				curr = curr->next;
			}
        }
        
        // 础计琌程(程)
		tail->next = add;
		tail = add;
		return; 
    }

    return;
}

void List::Show()
{
    Node* curr;

    curr = head;

    while (curr != NULL)
    {
		if (curr->next != NULL && curr->next->num1 > 0)
		{
			if (curr->num1 == 0)
			{
				if (curr->num2 == 0)
				{
					printf("x+");
				}
				else
				{
					printf("x^%d+", curr->num2);
				}
			}
			else
			{
				printf("%dx^%d+", curr->num1, curr->num2);
			} 
		}
		else
    	{
    		if (curr->num1 == 0)
			{
				if (curr->num2 == 0)
				{
					printf("x");
				}
				else
				{
					printf("x^%d", curr->num2);
				}
			}
			else
			{
				if (curr->num2 == 0)
				{
					printf("%dx", curr->num1);
				}
				else
				{
					printf("%dx^%d", curr->num1, curr->num2);
				}
			} 
		}
    	
        curr = curr->next;
    }

    return;
}

int main()
{
    int num1, num2;
    List list1;
    List list2;

    while (1)
	{
        printf("块兜Α1(玒计 Ωよ): ");
        scanf("%d %d", &num1, &num2);
        
        if (num1 == 0 && num2 == 0)
		{
			break;
		}
		else
		{
			list1.Insert(num1, num2);
		}
    }
    
    list1.Show();
    printf("\n");
    
    while (1)
	{
        printf("块兜Α2(玒计 Ωよ): ");
        scanf("%d %d", &num1, &num2);
        
        if (num1 == 0 && num2 == 0)
		{
			break;
		}
		else
		{
			list2.Insert(num1, num2);
		}
    }
    
    list2.Show();
    printf("\n");

    return 0;
}
