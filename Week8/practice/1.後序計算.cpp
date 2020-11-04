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
	
    void push(char);
    char pop();
};

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
    char string[MAX];
    int i;
    Stack stack;
    int value1, value2, result;

    while (1)
    {
        scanf("%s", string);

        if (strcmp(string, "0") == 0)
        {
            break;
        }

        for (i = 0; i < strlen(string); i++)
        {
            // char - '0' => int
            // int + '0' => char
            switch (string[i])
            {
                case '+':
                    value1 = stack.pop() - '0';
                    value2 = stack.pop() - '0';
                    result = value2 + value1;
                    stack.push(result + '0');
                    break;
                case '-':
                    value1 = stack.pop() - '0';
                    value2 = stack.pop() - '0';
                    result = value2 - value1;
                    stack.push(result + '0');
                    break;
                case '*':
                    value1 = stack.pop() - '0';
                    value2 = stack.pop() - '0';
                    result = value2 * value1;
                    stack.push(result + '0');
                    break;
                case '/':
                    value1 = stack.pop() - '0';
                    value2 = stack.pop() - '0';
                    result = value2 / value1;
                    stack.push(result + '0');
                    break;
                default:
                    stack.push(string[i]);
            }
        }

        result =  stack.pop() - '0';
        printf("%d\n", result);

        memset(string, 0, sizeof(string));
    }

    return 0;
}
