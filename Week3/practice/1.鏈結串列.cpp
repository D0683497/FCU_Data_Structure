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

//���J���ݡA�|���Ƨ�
void List::Insert()
{
    int num;
    printf("Insert a number:");
    scanf("%d", &num);
    
    Node *add=(Node*)malloc(sizeof(Node));
    add->num = num;
    add->next = NULL;
    
    if(tail==NULL) // head �� tail ���šA������ head �� tail �����ثe��J��
	{		
		head = add;
		tail = add;
	}
	else // tail �����ŮɡAptr�����(���b����)
	{
		tail->next = add;
		tail = add;
	}
}

// ���
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

// �R��
void List::Delete()
{
    int num;
    printf("Delete a number: ");
    scanf("%d",&num);
    
    Node* pre = NULL; // �e�@�Ӹ`�I 
	Node* curr = NULL; // �ثe�`�I 
    pre = curr = head;
    
    while(curr != NULL)
	{
		if(curr->num == num)
		{
			if(head == curr) // �p�G�n�R���O head 
			{
				head = head->next; // head ���U��
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
				pre->next = curr->next; // �ڪ��e�@�ӫ���ڪ��U�@�� 
				free(curr); // �R���� 
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
		printf("  �ާ@�ﶵ��\n==============\n[1]�[�J���\n[2]�R�����\n[3]�C�L\n[4]����\n");
		printf("��J�ﶵ:");
		scanf("%d",&op);
		switch(op){
			case 1:
				// �[�J���
				list.Insert();
				break;
			case 2:
				// �R�����
				list.Delete();
				break;
			case 3:
				// �C�L
				list.Show();
				break;
			case 4:
				// ����
				return 0;
			default:
				printf("ERROR!!!!\n");
				return 0;	
		}
	}
}

