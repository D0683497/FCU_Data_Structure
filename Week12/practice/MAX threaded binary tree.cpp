#include<stdio.h> 
#include<stdlib.h>

struct Thtree {
    int data;     
    bool thLeft;//0表示左分支為正常Link，反之為引線
    struct Thtree *Left;
    bool thRight;//0表示右分支為正常Link，反之為引線
    struct Thtree *Right; 
};

struct List
{
	Thtree* root;
	
	List() 
	{
		root=NULL;
	}
	
	void Insert(int input);
	void Delete(int input);
	void Print();
    void PrintThreaded();
};

void List::Insert(int input)
{
    Thtree *ptr = root;
    Thtree *par = NULL;

    // 找重複
    while (ptr != NULL)
    {
        if (input == (ptr->data)) 
        { 
            printf("already exit.\n"); 
            return; 
        }

        par = ptr;

        if (input < ptr->data) // Moving on left subtree. 
        { 
            if (ptr->thLeft == false)
            {
                ptr = ptr->Left;
            } 
            else
            {
                break;
            }
        }
        else // Moving on right subtree. 
        { 
            if (ptr->thRight == false)
            {
                ptr = ptr->Right;
            }
            else
            {
                break;
            }
        }
    }

    // 新增
    Thtree *tmp = (Thtree*)malloc(sizeof(Thtree));;
    tmp->data = input; 
    tmp->thLeft = true; 
    tmp->thRight = true;

    if (par == NULL) 
    { 
        root = tmp;
        tmp->Left = NULL; 
        tmp->Right = NULL; 
    }
    else if (input < (par->data)) 
    { 
        tmp->Left = par->Left; 
        tmp->Right = par; 
        par->thLeft = false; 
        par->Left = tmp; 
    }
    else
    { 
        tmp->Left = par; 
        tmp->Right = par->Right; 
        par->thRight = false; 
        par->Right = tmp; 
    }

    return;
}

// https://www.geeksforgeeks.org/threaded-binary-search-tree-deletion/?ref=lbp
void List::Delete(int input)
{
    // Case A: Leaf Node need to be deleted 
    // Case B: Node to be deleted has only one child
    // Case C: Node to be deleted has two children 

    Thtree *par = NULL;
    Thtree *ptr = root;
    bool found = false;

    // 搜尋
    while (ptr != NULL)
    {
        if (input == ptr->data)
        {
            found = true;
            break;
        }

        par = ptr;
        
        if (input < ptr->data)
        {
            if (ptr->thLeft == false)
            {
                ptr = ptr->Left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->thRight == false)
            {
                ptr = ptr->Right;
            }
            else
            {
                break;
            }
        }
    }

    if (found == false)
    {
        printf("Not Found.\n");
        return;
    }
    else if (ptr->thLeft == false && ptr->thRight == false) // Two Children
    {
        // root = caseC(root, par, ptr);
    }
    else if (ptr->thLeft == false) // Only Left Child
    {
        // root = caseB(root, par, ptr);
    }
    else if (ptr->thRight == false) // Only Right Child
    {
        // root = caseB(root, par, ptr);
    }
    else // No child
    {
        // root = caseA(root, par, ptr);
        if (par == NULL)
        {
            root = NULL;
        }
        else if (ptr == par->Left)
        {
            par->thLeft = true;
            par->Left = ptr->Left;
        }
        else
        {
            par->thRight = true;
            par->Right = ptr->Right;
        }
    
        free(ptr);
    }
    
    return;
}

int main()
{
    int op;
    int input;
    List list;
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
                        list.Insert(input);
                    }
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }

    return 0;
}
