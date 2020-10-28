#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#define MAX 100

struct Node
{
    char in;
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
	
	int isEmpty();
    void push(char);
    char pop();
};

int Stack::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return 1; // true
    }

    return 0; // false
}

void Stack::push(char in)
{
    Node *add = (Node*)malloc(sizeof(Node));
    add->in = in;
    add->next = NULL;

    if (tail == NULL) // 1. head 跟 tail 為空，直接把 head 跟 tail 換成目前輸入的
	{		
		head = add;
		tail = add;
	}
	else // 2. head 跟 tail 不為空，插在最前面
	{
        // 比較優先權

        add->next = head;
        head = add;
	}
}

char Stack::pop()
{
    char out;
    Node* curr = head; // 目前的頭
    out = curr->in;

    if (curr == tail) // 目前刪的是最後一個
    {
        head = NULL;
        tail = NULL;
        free(curr);
        return out;
    }

    head = head->next; // 把頭往下指
    free(curr);
    return out;
}

int main()
{
    char s[MAX];
    scanf("%s", s);
    Stack stack;
    int i;
    char out;

    for (i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
            case '(':
                stack.push('(');
                break;
            case ')':
                while (!stack.isEmpty())
                {
                    out = stack.pop();
                    if (out != ')' && out != '(')
                    {
                        printf("%c", out);
                    }
                }
                break;
            case '+':
                stack.push('+');
                break;
            case '-':
                stack.push('-');
                break;
            case '*':
                stack.push('*');
                break;
            case '/':
                stack.push('/');
                break;
            case '%':
                stack.push('%');
                break;
            default:
                if (int(s[i]) > 57 || int(s[i]) < 48)
                {
                    printf("\nERROR!!!!\n");
                }
                printf("%c", s[i]);
        }
    }

    return 0;
}

// 運算子：
// ( 17
// ) 17
// + 12
// - 12
// * 13
// / 13
// % 13
