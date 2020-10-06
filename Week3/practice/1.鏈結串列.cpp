#include<stdio.h> 
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

struct List
{
	Node* head;
	Node* tail;
	
	List() 
	{
		head=tail=NULL;
	}
	
	void Show();
	void Insert();
	void Delete();
};

//插入尾端，尚未排序
void List::Insert()
{
    int num;
    printf("Insert a number:");
    scanf("%d", &num);
    
    Node *add=(Node*)malloc(sizeof(Node));
    add->num = num;
    add->next = NULL;
    
    if(tail==NULL) // head 跟 tail 為空，直接把 head 跟 tail 換成目前輸入的
	{		
		head = add;
		tail = add;
	}
	else // tail 不為空時，ptr往後找(插在尾巴)
	{
		tail->next = add;
		tail = add;
	}
}

// 顯示
void List::Show()
{
	Node *tmp;
	tmp = head;
	
	while(tmp != NULL)
	{
		printf("%d->", tmp->num);	
		tmp = tmp -> next;
	}
	printf("\b \b\b \b");
	printf("\n");
}

// 刪除
void List::Delete()
{
    int num;
    printf("Delete a number: ");
    scanf("%d",&num);
    
    Node* pre = NULL; // 前一個節點 
	Node* curr = NULL; // 目前節點 
    pre = curr = head;
    
    while(curr != NULL)
	{
		if(curr->num == num)
		{
			if(head == curr) // 如果要刪的是 head 
			{
				head = head->next; // head 往下指
				free(curr);
				return;
			}
			else if(tail == curr)
			{
				tail = pre;
				pre->next = NULL;
				free(curr);
				return;
			}
			else
			{
				pre->next = curr->next; // 我的前一個指到我的下一個 
				free(curr); // 刪掉我 
				return;
			}
		}
		else{
			pre = curr;
			curr = curr->next;
		}
	}
} 

int main() {
	int op;
	List list;
	while(1){
		printf("  操作選項表\n==============\n[1]加入資料\n[2]刪除資料\n[3]列印\n[4]結束\n");
		printf("輸入選項:");
		scanf("%d",&op);
		switch(op){
			case 1:
				// 加入資料
				list.Insert();
				break;
			case 2:
				// 刪除資料
				list.Delete();
				break;
			case 3:
				// 列印
				list.Show();
				break;
			case 4:
				// 結束
				return 0;
			default:
				printf("ERROR!!!!\n");
				return 0;	
		}
	}
}

