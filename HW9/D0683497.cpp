#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    Tree *left;  
    Tree *right; 
} Tree;

// 新增節點
Tree* NewNode(int input)
{
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->data = input;
    temp->left = temp->right = NULL;
    return temp;
}

// 插入
Tree* Insert(Tree* tree, int input)
{
    if (tree == NULL)
    {
        return NewNode(input);
    }
 
    if (input == tree->data)
    {
        printf("%d already exist.\n", input);
    }
    else if (input < tree->data)
    {
        tree->left = Insert(tree->left, input);
    }  
    else
    {
        tree->right = Insert(tree->right, input);
    }

    return tree;
}

// 輸出
void Preorder(Tree* root)
{
    if (root != NULL)
    {
        printf("%d  ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

Tree* MinValueNode(Tree* node)
{
    Tree* current = node;
 
    while (current && current->left != NULL)
    {
        current = current->left;
    }  
 
    return current;
}

// 刪除
Tree* Delete(Tree* root, int input)
{
    if (root == NULL)
    {
        printf("%d does not exist in the tree.\n", input);
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
    else if (root->data == input)
    {
        if (root->left == NULL)
        {
            Tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree* temp = root->left;
            free(root);
            return temp;
        }

        Tree* temp = MinValueNode(root->left);
        root->data = temp->data;
        root->left = Delete(root->left, temp->data);
    }

    return root;
}

int main()
{
    Tree* root = NULL;
    int option, input;

    while(1)
    {
        printf("[1]Insert [2]Delete [3]Print [0]Exit: ");
        scanf("%d", &option);

        if (option == 0)
        {
            break;
        }
        else
        {
            switch (option)
            {
                case 1: // 插入
                    printf("Insert a number: ");
                    scanf("%d", &input);
                    root = Insert(root, input);
                    break;
                case 2: // 刪除
                    if (root == NULL)
                    {
                        printf("Tree is Empty.\n");
                    }
                    else
                    {
                        printf("Delete a number: ");
                        scanf("%d", &input);
                        root = Delete(root, input);
                    }
                    break;
                case 3: // 輸出
                    printf("Preorder:");
                    Preorder(root);
                    printf("\n");
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
