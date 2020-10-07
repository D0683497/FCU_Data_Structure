#include<stdio.h>
#include<stdlib.h>

struct Node {
    int num;
    struct Node* next;
};

struct List {
    Node* head;
    Node* tail;

    List()
    {
        head = tail = NULL;
    }

    void Insert();
    void Delete();
    void Show();
};

// 小至大排序
// 若欲新增的數已經存在於串列中，請重新輸入
void List::Insert()
{
	int num;
    Node* add = (Node*)malloc(sizeof(Node));

    printf("Insert a number: ");
    scanf("%d", &num);
    
    add->num = num;
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
        	if (curr->num == num) // 新增的數已經存在於串列
        	{
        		printf("%d已經存在串列中\n", num);
        		return;
			}
			else if (curr->num > add->num) // 可以插入 
			{
				if (curr == head) // 插入的數是最小的(最前面)
				{
					add->next = head;
					head = add;
					return;
				}
				else // 插在中間 
				{
					pre->next = add;
					add->next = curr;
					return;
				} 
			}
			else // 下一個 
			{
				pre = curr;
				curr = curr->next;
			}
        }
        
        // 插入的數是最大的(最後面)
		tail->next = add;
		tail = add;
		return; 
    }

    return;
}

void List::Delete()
{
	int num;
	Node* curr;
	Node* pre;
	
	curr = pre = head;
	
	printf("Delete a number: ");
    scanf("%d", &num);
    
    while (curr != NULL)
	{
		if (curr->num == num)
		{
			if (curr == head) // 1. delete head
			{
				head = head->next;
				free(curr);
				return;
			}
			else if (curr == tail) // 2. delete tail
			{
				tail = pre;
				tail->next = NULL;
				free(curr);
				return;	
			} 
			else // 3. other
			{
				pre->next = curr->next;
				free(curr);
				return;	
			}
		}
		else
		{
			pre = curr;
			curr = curr->next;
		}
	}
	
	printf("Not Found!!!\n");
	
    return;
}

void List::Show()
{
    Node* curr;

    curr = head;

    while (curr != NULL)
    {
        printf("%d->", curr->num);
        curr = curr->next;
    }

    printf("\b \b\b \b\n");

    return;
}

int main()
{
    int op;
    List list;

    while (1)
    {
        printf("操作選項表\n==============\n[1]加入資料\n[2]刪除資料\n[3]列印\n[4]結束\n");
        printf("輸入選項: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                list.Insert();
                break;
            case 2:
                list.Delete();
                break;
            case 3:
                list.Show();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Error!!!\n");
        }
    }

    return 0;
}
