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

void Inorder(Node* tree)
{
    if (tree)
    {
        Inorder(tree->llink);
        printf("%d  ",tree->data);
        Inorder(tree->rlink);
    }
}

void Postorder(Node* tree)
{
    if (tree)
    {
        Postorder(tree->llink);
        Postorder(tree->rlink);
        printf("%d  ",tree->data);
    }
}

void MAX(Node* tree)
{
    if (tree->rlink)
    {
        MAX(tree->rlink);
    }
    else
    {
        printf("%d",tree->data);
    }
}

void MIN(Node* tree)
{
    if (tree->llink)
    {
        MIN(tree->llink);
    }
    else
    {
        printf("%d",tree->data);
    }
}

void LeafNodes(Node* tree)
{
    if (tree)
    {
        LeafNodes(tree->llink);
        LeafNodes(tree->rlink);
        if (tree->llink == NULL && tree->rlink == NULL)
        {
            printf("%d  ",tree->data);
        }
    }
}

int main()
{
    Node* root = NULL;
    int tmp;

    while(1)
    {
        printf("Insert a number : ");
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            break;
        }
        else
        {
            Insert(&root, tmp);
        }
    }

    printf("Preorder  : ");
    Preorder(root);
    printf("\n");

    printf("Inorder   : ");
    Inorder(root);
    printf("\n");

    printf("Postorder : ");
    Postorder(root);
    printf("\n");

    printf("MAX : ");
    MAX(root);
    printf("\n");
    printf("MIN : ");
    MIN(root);
    printf("\n");
    
    printf("LeafNodes : ");
    LeafNodes(root);
    printf("\n");

    return 0;
}
