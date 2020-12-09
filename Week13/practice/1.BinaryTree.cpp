#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node* llink;
    Node* rlink;
} Node;

void Insert(Node** tree, int val)
{
    Node *temp = NULL;

    if(!(*tree)) // 樹是空的
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->llink = temp->rlink = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if (val == (*tree)->data)
    {
        printf("%d already exit.\n", val);
    }
    else if(val < (*tree)->data)
    {
        Insert(&(*tree)->llink, val);
    }
    else if(val > (*tree)->data)
    {
        Insert(&(*tree)->rlink, val);
    }
}

void Preorder(Node* tree)
{
    if (tree)
    {
        printf("%d  ",tree->data);
        Preorder(tree->llink);
        Preorder(tree->rlink);
    }
}

int main()
{
    Node* root = NULL;
    int input;
    bool end = false;

    while(!end)
    {
        printf("[1] Add [2] Delete [0] Exit:");
        scanf("%d", &input);
        switch(input)
        {
            case 0:
                end = true;
                break;
            case 1:
                printf("Insert a number : ");
                scanf("%d", &input);
                Insert(&root, input);
                printf("Preorder  : ");
                Preorder(root);
                printf("\n----------------------\n\n");
                break;
            case 2:
                break;
            default:
                break;
        }
    }

    return 0;
}
