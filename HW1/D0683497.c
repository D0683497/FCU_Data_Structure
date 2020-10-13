#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 9 /* 最大方陣大小 */

int square[MAX_SIZE][MAX_SIZE];

void recursive(int i, int j, int count, int size)
{
    if (count > size*size)
    {
        return;
    }

    if (count == 1)
    {
        square[i][j] = count;
    }
    else
    {
        int row = (i-1<0) ? (size-1) : (i-1); /* 上面 */
        int column = (j-1<0) ? (size-1) : (j-1); /* 左邊 */
        
        if (square[row][column]) /* 下面 */
        {
            i = (++i) % size;
        }
        else
        {
            i = row;
            j = (j-1<0) ? (size-1) : --j;
        }

        square[i][j] = count;
    }
   
    recursive(i, j, count+1, size);
}

void main(void)
{
    /* 反覆地產生一個大小為 n 的魔術方陣 */
    int i, j;
    int size;

    printf("Enter the size of the square:");
    scanf("%d", &size);

    /* 檢查錯誤的輸入 */
    if (size < 4 || size > MAX_SIZE+1)
    {
        fprintf(stderr, "Error! Size is out od range\n");
        exit(EXIT_FAILURE);
    }
    if (!(size % 2))
    {
        fprintf(stderr, "Error! Size is even\n");
        exit(EXIT_FAILURE);
    }

    /* 初始化陣列 */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            square[i][j] = 0;
        }
    }

    recursive(0 ,((size-1)/2), 1, size);

    /* 輸出魔術方陣 */
    printf("Magic Square of size %d : \n\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%5d", square[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
