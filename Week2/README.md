# 資料結構實習 [複習Week2]
---

## 課前說明

### 課堂規定
1. 不要太吵鬧
2. 去廁所前來前面說一聲
3. 有問題舉手

### 檔案上傳與命名規則
1. 資料夾壓縮後上傳
2. 資料夾命名規則 `學號.7z` ex: D0123456.7z
3. 小題命名規則 `題號.題目名稱` ex: 2.最大公因數與最小公倍數.c

### 練習與作業無準確的評量機制
1. 練習 & 作業評分表
    - 輸出結果錯誤 -100
    - 輸出格式錯誤 -20
    - 檔案名稱錯誤 -10
    - 抄襲 －50~100
2. 缺席：當次練習評分按照補交分數(7折)
3. 曠課：當次練習一律0分計算
4. 本堂課不會直接提供完整程式碼


## 結構 Struct
* 協助我們將相同或相關的變數整合成一個。
* 用法

    >struct <結構型態>
    {
        <欄項資料型態> <欄項變數名稱>;
        <欄項資料型態> <欄項變數名稱>;
         ：　　　　   　：
    } 變數1，變數2...;
    
    >變數.欄項變數名稱
    指標變數->欄項變數名稱

* 例如

    ```c=
    struct Student {
        char name[20];
        char sex;
        int score;
    } stu[50];
    
    strcpy(stu[0].name, "Mark");
    stu[0].score=100;
    printf("%s %d",stu[0].name,stu[0].score);
    ```
* 自訂型態 : **typedef**
    * 宣告 : ```typedef struct tag { member-list } type-name;```
    
    * 例如 
        ```c=
        typedef struct Student stus;
        ```
    * 範例
    ```c=
    typedef struct Student {
        char name[20];
        char sex;
        int score;
    } stus;
    stus stu[50];
    
    int main(void){
        strcpy(stu[0].name, "Mark");
        stu[0].score=100;
        printf("%s %d",stu[0].name,stu[0].score);
    } 
    ```
---

### 指標 Pointer
* 指標 : ==記憶體的位置。==
* 指標變數 : ==內容為存放某一記憶體位置==，用來存取位址，其本身也有自己的位址
* 語法:
    * &：取得變數的位址
    *  *：使用指標取得某個記憶體的內容
    *  <資料型態> *指標變數名稱;
    * 例如
        ``` c=
        int a; // 一個整數
        int *a; // 一個指向整數的指標
        ```
* 範例
 ```c=
    int num = 20;
    int *ptr;  //宣告ptr為一儲存int位址之變數
    ptr = &num;  //ptr儲存num之位址
    printf("ptr的值:%p\n",ptr);
    printf("ptr的位址:%p\n",&ptr);
    printf("ptr的值連接的值:%d\n",*ptr);

    printf("num的值:%d\n",num);
    printf("num的位址:%p\n",&num);
```
執行結果:
```
    ptr的值:0062FE1C
    ptr的位址:0062FE10
    ptr的值連接的值:20
    num的值:20
    num的位址:0062FE1C
```
圖示


|     位址     | 值           | 變數名稱 |
|:------------:| ------------ | -------- |
| ==0062FE1C== | 20           | num      |
|   0062FE10   | ==0062FE1C== | ptr      |


* **陣列本身是指標的一種**
    * 陣列名稱用來參考至陣列的第一個元素的記憶體位址
    * ㄧ維陣列:
        ```c=
            int x[10] = {0};
            int* ptr = x;
            for(i=0; i<10; i++){
                x[i] = i;
                printf("%p %p %d\n",&x[i], ptr+i,x[i]);
	        }
        ```
        執行結果:
        ```
        000000000062FDB0 000000000062FDB0 0
        000000000062FDB4 000000000062FDB4 1
        000000000062FDB8 000000000062FDB8 2
        000000000062FDBC 000000000062FDBC 3
        000000000062FDC0 000000000062FDC0 4
        000000000062FDC4 000000000062FDC4 5
        000000000062FDC8 000000000062FDC8 6
        000000000062FDCC 000000000062FDCC 7
        000000000062FDD0 000000000062FDD0 8
        000000000062FDD4 000000000062FDD4 9
        ```
    * 二維陣列:
        ```c=
            int i,j,a[3][3] = {0};
            int* p=a;

            for(i=0;i<3;i++){
                for(j=0;j<3;j++){

                    a[i][j] = i*3+j;
                    printf("%p %p %d %d\n",&a[i][j],p+i*3+j,a[i][j],*(p+i*3+j));
                }
            }
        ```
        執行結果:
        ```
        000000000062FDE0 000000000062FDE0 0 0
        000000000062FDE4 000000000062FDE4 1 1
        000000000062FDE8 000000000062FDE8 2 2
        000000000062FDEC 000000000062FDEC 3 3
        000000000062FDF0 000000000062FDF0 4 4
        000000000062FDF4 000000000062FDF4 5 5
        000000000062FDF8 000000000062FDF8 6 6
        000000000062FDFC 000000000062FDFC 7 7
        000000000062FE00 000000000062FE00 8 8
        ```
* **動態記憶體配置** 
    * malloc()：動態配置空間
    * free()：釋放空間
    * 例如
    ```c=
        int* n=(int*)malloc(sizeof(int));
        *n = 200;
        printf("%d %p",*n,n);
    ```
    執行結果
    ```
        200 00C81400
    ```
    * 補充
    ```c=
    char* word;//宣告指標變數word指向1個字元
    word = (char*)malloc(sizeof(char)*5);//產生空間，可以放置5個字元
    ```

## 課堂練習
### 1.學生成績
> 產生某班50位學生的資料，每位學生資料包括：學生姓名、號碼、計概、與微積分兩科成績，資料限制條件如下說明。
> 1.學生姓名由==name.txt==讀入。
2.每位學生之號碼為**照順序**1~50號。
3.所有成績均為介於70~100之間的整數，亂數產生，可重複。
4.可輸出學生資料，輸出格式如格式一，名稱為==student.txt。==
5.按每位學生之平均成績高低由高至低排列印出。平均成績相同時，則以**計概**成績較高者為優先排列。列印格式如格式二。

* name.txt
```
Larry Garrett Jerry Michael Patrick Melody Leland Sebastian Alex Willy Johnny Thomas Peter Nancy Connor Christopher Roy Seth Adrian Dakota Eduardo Carlos Jeremiah Jared Aaron Jensen Ryan Cole Dylan Charles Gavin Alvin Walter Ian Kieran Andrew Pete William Anthony Cole Cameron Joseph Eric Betty Carson Clyde Jaime Matthew Kevin Mickey 
```
* 格式ㄧ
```
學生姓名  號碼    
----------------
 Larry     1      
 Garrett   2      
 ...
 ...
 Mickey    50    
```
* 格式二
```
學生姓名  計概成績  微積分成績  平均成績  名次 
--------------------------------------------
 Dakota      XXX       XXX      XXX     1
 Walter      XXX       XXX      XXX     2
 ...
 ...
 Carson      XXX       XXX      XXX     50
```
---

### 2.空間配置
>利用亂數取20個A~Z的**大寫英文字母(可重複)**，並由**大到小**排序。
:::info
  需使用malloc搭配指標方式，不可使用陣列。  
:::

輸出結果
```
原始字母:
R U H L G R M R Y N K D M H S E K V C Q

排序結果:
C D E G H H K K L M M N Q R R R S U V Y
```

### 3.微分處理
>寫出一個多項式的結構，包含係數和次方。
>一開始先輸入一個值，代表這個多項式一共有多少項
```=
give me a number:%d
```
>一次輸入兩個數，先後代表係數和次方，ㄧ直到輸入到最後一項，或是兩個都為0為止
```=
Coefficient:%d
Power:%d
```
>印出到現在所有的項
```=
3x^2 + 4x^4 + 5x^1 + 5x^0
```
>然後從大到小排列
```=
4x^4 + 3x^2 + 5x^1 + 5x^0
```
>列出可微分的次數直到0
```=
0階:4x^4 + 3x^2 + 5x^1 + 5x^0
1階:16x^3 + 6x^1 + 5x^0
2階:48x^2 + 6x^0
3階:96x^1
4階:96x^0
5階:0
```
:::info
加分題：
用malloc去令空間
結構不能用&rarr;去附值
:::