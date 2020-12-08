#include<stdio.h> 
#include<stdlib.h>
#define MAX 80

struct Thtree {
    int data;     
    bool thLeft;//0表示左分支為正常Link，反之為引線
    Thtree *Left;
    bool thRight;//0表示右分支為正常Link，反之為引線
    Thtree *Right; 
};

Thtree* Insert(Thtree* root, int input)
{
    printf("Insert %d\n", input);
    Thtree* ptr = root;
    // Thtree* par = NULL; // 要插的前一個

    // 建立要插入節點
    Thtree *tmp = (Thtree*)malloc(sizeof(Thtree));
    tmp->data = input;
    tmp->thLeft = true;
    tmp->thRight = true;

    if (ptr == NULL) // 如果 root 為空
    {
        root = tmp;
        tmp->Left = NULL;
        tmp->Right = NULL;
    }
    else
    {
        while(1)
        {
            if (ptr->thLeft == true) // 插左邊
            {
                tmp->Left = ptr->Left;
                tmp->Right = ptr;
                ptr->thLeft = false;
                ptr->Left = tmp;
                break;
            }
            else if (ptr->thRight == true) // 插右邊
            {
                tmp->Left = ptr;
                tmp->Right = ptr->Right;
                ptr->thRight = false;
                ptr->Right = tmp;
                break;
            }
            else if (ptr->Left->thLeft == true || ptr->Left->thRight == true) // 左移
            {
                ptr = ptr->Left;
            }
            else // 右移
            {
                ptr = ptr->Right;
            }
        }
    }
 
    return root;
}

Thtree* InorderSuccessor(Thtree* ptr)
{
    if (ptr->thRight == true)
    {
        return ptr->Right;
    }
 
    ptr = ptr->Right;
    while (ptr->thLeft == false)
    {
        ptr = ptr->Left;
    }
        
    return ptr;
}

void Inorder(Thtree* root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
    }
        
    Thtree* ptr = root;
    while (ptr->thLeft == false)
    {
        ptr = ptr->Left;
    }
 
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = InorderSuccessor(ptr);
    }

    printf("\n");
}

int main()
{
    int i;
    int length = 0;
    int inputArray[MAX] = {};
    bool flag = false;
    Thtree *root = NULL;
    int op;
    int input;

    while(1)
    {
        printf("MAX threaded binary tree\n");
        printf("--------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Print threaded\n");
        printf("--------\n");
        printf("choose your operation:");
        
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                while (1)
                {
                    scanf("%d", &input);
                    if (input == 0)
                    {
                        printf("End Insert\n");
                        break;
                    }
                    else
                    {
                        // 判斷重複
                        if (length == 0)
                        {
                            inputArray[length] = input;
                            length++;
                            root = Insert(root, input);
                        }
                        else
                        {
                            for (i = 0; i < length; i++)
                            {
                                if (inputArray[i] == input)
                                {
                                    flag = true;
                                }
                            }
                            if (flag == true)
                            {
                                flag = false;
                                printf("already exit.\n");
                            }
                            else
                            {
                                inputArray[length] = input;
                                length++;
                                root = Insert(root, input);
                            }
                        }
                        
                    }
                }
                break;
            case 2:
                printf("加分題\n");
                break;
            case 3:
                Inorder(root);
                break;
            case 4:
                break;
            default:
                break;
        }
    }

    return 0;
}
