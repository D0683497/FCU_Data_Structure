#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 40
#define MAX_COL 20

int array[MAX_ROW][MAX_COL] = { 0 };
int imove[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int jmove[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int all_count = 0; // 總步數
int check_number; // 判斷是不是都走過

/* 移動 */
int move(int inext, int jnext, int n, int m)
{
    if (inext >= n || inext < 0 || jnext >= m || jnext < 0)
    {
        return 0;
    }

    // 走到沒走過的地方
    if (array[inext][jnext] == 0)
    {
        check_number = check_number - 1;
    }

    array[inext][jnext]++;
    all_count =  all_count + 1;
    
    return 1;
}

/* 印出陣列 */
void print(int n, int m)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }

    return;
}

int main()
{
    int n, m;
    int ibug, jbug; // 目前位置
    int k;
    srand(time(NULL));
    
    /* 請輸入 n */
    while (1)
    {
        printf("請輸入 n (2 <= n <=40) = ");
        scanf("%d", &n);
        if (n >= 2 && n <= 40)
        {
            break;
        }
    }

    /* 請輸入 m */
    while (1)
    {
        printf("請輸入 m (2 <= m <=20) = ");
        scanf("%d", &m);
        if (m >= 2 && m <= 20)
        {
            break;
        }
    }

    /* 輸入起始點 */
    while(1)
    {
        printf("請輸入起始點 (n m) = ");
        scanf("%d %d", &ibug, &jbug);
        if (ibug > 0 && ibug < n && jbug > 0 && jbug < m)
        {
            break;
        }
    }

    check_number = n * m;

    while(1)
    {
        k = rand() % 8;

        if (move(ibug+imove[k], jbug+jmove[k], n, m) == 1)
        {
            ibug = ibug + imove[k];
            jbug = jbug + jmove[k];
        }

        if (all_count > 50000) // 超過 50000 步
        {
            break;
        }

        if (check_number == 0) // 走完了
        {
            break;
        }
    }

    print(n, m); // 印出陣列

    printf("總步數: %d\n", all_count); // 印出總步數

    return 0;
}
