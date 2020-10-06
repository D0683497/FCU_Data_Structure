# 資料結構實習 [複習]

---

## 課程大綱

* 前 3  週 : 複習
* 第 4  週 : 小考
* 第 5  週 : 陣列與結構
* 第 6  週 : 堆疊、佇列
* 第 7  週 : 鏈結串列
* 第 8  週 : 鏈結串列
* 第 9  週 : 期中上機考
* 第 10 週 : 樹
* 第 11 週 : 樹
* 第 12 週 : 圖形
* 第 13 週 : 圖形
* 第 14 週 : 赫序函數
* 第 15 週 : 排序演算法
* 第 16 週 : 小考
* 第 17 週 : 期末上機考
* 第 18 週 : 統籌

---

## 成績評定說明

+ 期中上機考 : **30%**
+ 期末上機考 : **30%**
+ 作業 : **15%**  [老師上課指派]
    + **嚴禁抄襲，凡抄襲或提供作業被抄襲者，該次作業以0分計算。**
    + 作業補交期限為**兩週**，分數打**7折。**
+ 課堂練習 : **10%**
    + 課堂練習未在課堂結束前繳交則該課堂練習分數為70，補交期限為**一週**，超過一週以0分計算。
+ 小考 : **10%**
+ 點名 : **5%**
    + 出席標準
        + 公假、喪假、重大傷病假、生理假**不扣分**。
        + 事假、一般病假每次扣出席**10分**。
        + 曠課每次扣**20分**。
---

## 助教與請益時間

+ 鄭羽辰 Email : b8459234@gmail.com
+ 劉俞萱 Email : d0712952@fcu.mail.edu.tw
+ 請益時間 : (一) 18:00~20:00 資電203

---

## 字串 String

| 函數名稱 | 功能 | 說明 |
| ---- | ---- | ---- |
| `strlen(char* str)` | 回傳字串長度 | 不包括 `\0` |
| `strcpy(char* str1, char* str2)` | 字串複製 | str1 複製 str2 |
| `strcat(char* str1, char* str2)` | 字串結合 | str1 + str2 |
| `strcmp(char* str1, char* str2)` | 字串排序 | str1 - str2。<br>大於回傳一個大於 0 的值<br>小於回傳小於 1 的值<br>等於回傳 0 |

+ 引入函式庫 `<string.h>`
+ 用法
	+ strlen
	```c
    printf("len: %d",strlen("Hello"));
    ```
    輸出結果：
    ```
    len: 5
    ```
	* strcpy
	```c
    char str[10];
    strcpy(str,"Hello");
    printf("strcpy: %s",str);
    ```
    輸出結果：
    ```
    strcpy: Hello
    ```
	* strcat
	```c
    char str[] = "He";
    strcat(str,"llo");
    printf("strcat: %s",str);
    ```
    輸出結果：
    ```
    strcat: Hello
    ```
	* strcmp
	```c
    char str1[] = "good";
	char str2[] = "girl";
    printf("strcmp: %d",strcmp(str1,str2));
    ```
    輸出結果：
    ```
    strcmp: 6
    ```

---

## 陣列 Array

+ 陣列是一種**結構性**的資料儲存空間
+ 是一組**相同型態**的連續變數，它們使用同一個變數名稱，而另外用一個**索引值**來指定使用第幾個變數
+ 語法
    + 變數型態 陣列名稱[元素個數 OR 陣列大小];
    + 例如 : 
    
    ```c=
    int Array_0[10] = {0};   //初始陣列元素值 (全部為0)
    int Array_1[5] = {1,2,3,4,5};
	int Array_3[] = {1,2,3};
	int Array_4[2][4] = {{1,2,3,4},{5,6,7,8}};   //二維陣列
    ---
    char Array_5[10];
    char Array_6[10] = {0};    //字串也可以做初始化
    char Array_7[6]="Hello";   // 字尾 "\0" 
    ```

---

## 副函式 Function

+ 是一種由使用者**自訂的函數**
+ 在被呼叫之前必須先定義或宣告
+ 語法

    + 傳回值型態  函數名稱(參數一型態  參數一名稱, 參數二型態  參數二名稱, ....)
    {
        變數宣告
         ...
         程式碼
         ...
          return  傳回值;
    }
    + 例如 : 遞迴
    
    
    ```c
    int factorial(int);  //宣告Function

    int main(){
        int n;
        printf("Input N!: ");
        scanf(" %d",&n);
        printf("%d! = %d\n",n,factorial(n));
    }

    int factorial(int n){
        if(n<3)
            return n;
        return n*factorial(n-1);
    } 
    ```
    ```c
    輸入 N : 6
    執行結果 : N! = 720
    ```
* 河內塔 Tower of Hanoi
    
    >有三根杆子a，b，c。a杆上有 N 個 (N>1) 穿孔圓盤，盤的尺寸由下到上依次變小。要求按下列規則將所有圓盤移至 c 杆，並計算出移動次數：
    >1. 每次只能移動一個圓盤
    >2. 大盤不能疊在小盤上面
    >
    >![](https://i.imgur.com/s6oq9Zr.png)
    >提示：先把 a 塔頂部的 (N-1) 塊盤移動到 b 塔，再把 a 塔剩下的大盤移到 c，最後把 b 塔的 (N-1) 塊盤移到 c。
    
    
    * 例如:

            請輸入穿孔圓盤數量 n : 3

            移動套環 a --> c
            移動套環 a --> b
            移動套環 c --> b
            移動套環 a --> c
            移動套環 b --> a
            移動套環 b --> c
            移動套環 a --> c

            移動次數 7
---

# 檔案處理

* 開檔
 
    |函數名稱(mode)|功能說明|
    |:------:|------|
    |"r"	|開啟一個文字檔，供程式讀取。|
    |"w"	|開啟一個文字檔，供程式將資料寫入此檔案內。如果磁碟內不包含這個檔案，則系統會自行建立這個檔案。如果磁碟內包含這個檔案，則此檔案內容會**被蓋過而消失**。|
    |"a"	|開啟一個文字檔，供程式將資料**寫入此檔案的末端**。如果此檔案不存在，則系統會自行建立此檔案。|

    * 例如
    ```c
    FILE* fp = fopen("test.txt","r");
    ```
    
* 關檔
    * 檔案在關閉前會將檔案緩衝區資料寫入磁碟檔案內，否則檔案緩衝區資料會遺失。
    * 例如
    ```c
    fclose(fp);
    ```
* 讀檔
    * 從**檔案指標所指的檔案**讀取資料。
    * 例如
    ```c
    int num;
    char word[10];
    fscanf(fp,"%d",&num);
    fscanf(fp,"%s",word);
    ```
* 寫檔
    * 格式與 fscanf 一樣
    * 例如
    ```c
    char word[10];
    fprintf(fp,"%s",word);
    ```

* 範例
    ```c
    #include <stdio.h> 
                                                                                
    int main() {

        FILE *fp = fopen("test.txt", "w"); 
        
        if(!fp) { 
            printf("檔案開啟失敗，無法寫入檔案"); 
            return 1; 
        } 
        
        fprintf(fp, "%s\t%d\n", "A", 100);
        fprintf(fp, "%s\t%d\n", "B", 90);
        fprintf(fp, "%s\t%d\n", "C", 80);    
        fclose(fp);
        
        FILE *fp2 = fopen("test.txt", "r");
        
        if(!fp2) { 
            printf("檔案開啟失敗，無法讀入檔案"); 
            return 1; 
        } 
    
        char name[2]; 
        int score; 
        printf("名字\t分數\n"); 
        
        while(fscanf(fp2, "%s\t%d", name, &score) != EOF) { 
            printf("%s\t%d\n", name, score); 
        } 
        
        fclose(fp2);
        return 0; 
    
    }
    ```
    輸出結果:
    ```
    名字    分數
    A       100
    B       90
    C       80
    ```
    
---

# 課堂測驗
### 1. 99乘法、進制轉換
>請設計一C/C++程式，利用FOR迴圈敘述，計算九九乘法表(1x1...1x9、2x1...    2x9、9x1...9x9)，並將乘積結果分別以**十進位**、**八進制**與**十六進制**，依下列表格形式列印出來：
>
* 十進位

|  |  1  |  2  | ... |  9  |
|:--------:|:---:|:---:| --- |:---:|
|    1     |  1  |  2  | ... |  9  |
|    2     |  2  |  4  | ... | 18  |
|    3     |  3  |  6  | ... | 27  |
|   ...    | ... | ... | ... | ... |
|    9     |  9  | 18  | ... | 81  |

* 八進位

| |  1  |  2  | ... |  9  |
|:--------:|:---:|:---:| --- |:---:|
|    1     |  1  |  2  | ... |  11  |
|    2     |  2  |  4  | ... | 22  |
|    3     |  3  |  6  | ... | 33  |
|   ...    | ... | ... | ... | ... |
|    9     |  11  | 22  | ... | 121  |

* 十六進位

|  |  1  |  2  | ... |  9  |
|:--------:|:---:|:---:| --- |:---:|
|    1     |  1  |  2  | ... |  9  |
|    2     |  2  |  4  | ... | 12  |
|    3     |  3  |  6  | ... | 1b  |
|   ...    | ... | ... | ... | ... |
|    9     |  9  | 12  | ... | 51  |


---

### 2.最大公因數與最小公倍數
>利用**輾轉相除法**，求出兩數的最大公因數與最小公倍數(**必須使用副函式**)，直到兩個數字皆是0，才結束程式

````
    輸入兩個數字 : 20 14
    最大公因數 : 2
    最小公倍數 : 140
    輸入兩個數字 : 63 54
    最大公因數 : 9
    最小公倍數 : 378
    ...
    輸入兩個數字 : 0 0
````

### 3.學生資料

>請撰寫一C程式，以亂數產生某班25位學生的資料(每位學生資料包括：學生姓名、計概、與微積分兩科成績)，資料限制條件如下說明。
    **1.每位學生之姓名為三個相同之大寫英文字母，不得重複。如AAA、FFF、….等。
    2.所有成績均為介於40~100之間的整數，可重複。
    3.可印出亂數產生之原始資料，列印格式如格式一。
    4.按每位學生之平均成績高低由高至低排列印出。平均成績相同時，則以計概成績較高者為優先排列。列印格式如格式二。
    5.上述要求，請提供如下操作選擇畫面進行循環式操作選擇，直至程式結束。
    6.每一操作選項(除結束程式執行外)請寫成一副程式來完成。
    7.若第一選項(1)未執行，則選項(2)、(3)均應拒絕執行。又若重新產生原始資料，則相關結果亦應隨著改變。**

操作選項表：
```
(1) 原始資料產生
(2) 列印原始資料
(3) 列印排序成績
(4) 結束程式執行
```

執行結果範例：
* 格式一：
```
學生姓名  計概成績  微積分成績
------------------------------
 RRR      XXX      XXX
 CCC      XXX      XXX
 ...
 ...
 BBB      XXX      XXX
```

* 格式二：
```
學生姓名  計概成績  微積分成績  平均成績   名次 
--------------------------------------------
 EEE       XXX       XXX       XXX       1
 BBB       XXX       XXX       XXX       2
 ...
 ...
 RRR       XXX       XXX       XXX       25
```

---

### 4.單字排序

>取一個文字檔案 **input.txt**，將其內所有的英文單字，轉換成**小寫**後，**排序**，再輸出至**output.txt**。
>1.文字檔案中的所有英文單字皆為20個字元以內。
2.除以空白間隔單字外，並沒有其他標點符號。


* input.txt
```
C is a general purpose imperative computer programming language supporting structured programming lexical variable scope and recursion while a static type system prevents many unintended operations
By design C provides constructs that map efficiently to typical machine instructions and therefore it has found lasting use in applications that had formerly been coded in assembly language including operating systems as well as various application software for computers ranging from supercomputers to embedded system
```
* output.txt
```
a
a
and
and
application
applications
as
as
assembly
been
by
c
c
...
```
