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

// �p�ܤj�Ƨ�
// �Y���s�W���Ƥw�g�s�b���C���A�Э��s��J
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
        	if (curr->num == num) // �s�W���Ƥw�g�s�b���C
        	{
        		printf("%d�w�g�s�b��C��\n", num);
        		return;
			}
			else if (curr->num > add->num) // �i�H���J 
			{
				if (curr == head) // ���J���ƬO�̤p��(�̫e��)
				{
					add->next = head;
					head = add;
					return;
				}
				else // ���b���� 
				{
					pre->next = add;
					add->next = curr;
					return;
				} 
			}
			else // �U�@�� 
			{
				pre = curr;
				curr = curr->next;
			}
        }
        
        // ���J���ƬO�̤j��(�̫᭱)
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
        printf("�ާ@�ﶵ��\n==============\n[1]�[�J���\n[2]�R�����\n[3]�C�L\n[4]����\n");
        printf("��J�ﶵ: ");
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
