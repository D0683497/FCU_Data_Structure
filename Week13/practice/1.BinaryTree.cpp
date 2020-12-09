#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} Node;
 
Node* NewNode(int input)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = input;
    temp->left = temp->right = NULL;
    return temp;
}

void Preorder(Node* root)
{
    if (root != NULL)
    {
        printf("%d  ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

Node* Insert(Node* node, int input)
{
    if (node == NULL)
    {
        return NewNode(input);
    }
 
    if (input == node->data)
    {
        printf("%d already exist.\n", input);
    }
    else if (input < node->data)
    {
        node->left = Insert(node->left, input);
    }  
    else
    {
        node->right = Insert(node->right, input);
    }

    return node;
}

Node* MinValueNode(Node* node)
{
    Node* current = node;
 
    while (current && current->left != NULL)
    {
        current = current->left;
    }  
 
    return current;
}

Node* Delete(Node* root, int input)
{
    if (root == NULL)
    {
        return root;
    }
    
    if (input < root->data)
    {
        root->left = Delete(root->left, input);
    }
    else if (input > root->data)
    {
        root->right = Delete(root->right, input);
    }
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        Node* temp = MinValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }

    return root;
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
                printf("Insert a number:");
                scanf("%d", &input);
                root = Insert(root, input);
                printf("Preorder:");
                Preorder(root);
                printf("\n----------------------\n\n");
                break;
            case 2:
                if (root != NULL)
                {
                    printf("Delete a number:");
                    scanf("%d", &input);
                    root = Delete(root, input);
                }
                printf("Preorder:");
                Preorder(root);
                printf("\n----------------------\n\n");
                break;
            default:
                break;
        }
    }
 
    return 0;
}