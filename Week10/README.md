# 資料結構實習[Week10]

## 課前說明
- [你們的作業成績](https://docs.google.com/spreadsheets/d/1Je4PhvHGfK_QGgcurIFyvCcwSlBYeLDIX-u-rAXBtJs/edit?usp=sharing)
- 正課作業書面報告內容請依照老師要求。
- 每一次作業都要算**bigO**。
- 請注意不要出現以下寫法:
     ```c=
        void sum(int n){
            int count;
            ...
            ...
            ...
            return count;
        }
    ```
    前面回傳值是void，就不能再回傳一個值。
- 防呆判斷請做確實，當輸入不合規定的資料時，**必須請使用者重新輸入**，而不是直接結束程式。
- main 要記得加void 或 int
- 使用函式前要先宣告
- 加分題不用交到補交，不會加分

---
## 檔案處理
- fscanf()
    - 格式 : **fscanf(檔案指標,型態,變數名稱)**
    
        ```c=
        fscanf(fp,"%d",&num); // int
        fscanf(fp,"%s",word); // 字串
        ```
    - **遇到空白時，就會跳出來，不會繼續往下讀**。
- fgetc()
    - 格式 : **fgetc(變數名稱,變數大小,檔案指標)**
    - 一次讀一個**字元**。
:::info
### 注意!!!!!!
盡量使用**EOF**(End of file)來抓取測資，不要直接去數有幾筆測資。
:::
- [傳送門-檔案處理[複習]](https://hackmd.io/2O1poTTYRPKAnirC8Pbw9A)

## 樹 Tree
- 二元樹 Binary Tree
![](https://i.imgur.com/lF0Tm2C.jpg)
- 圖示
![](https://i.imgur.com/C4zVDUF.jpg)
- 定義及宣告
    - 用鏈結串列表示
    ```c=
    struct tree {
        int data;             
        struct tree *Left;  
        struct tree *Right; 
    };
    ```
- 以節點A而言
![](https://i.imgur.com/uJQ0EF9.jpg)
![](https://i.imgur.com/w8ukIRi.jpg)

---
## 課堂練習
### 1.toPrefix
> 請讀入名為==mid_109_input_2D==的txt檔案，將下列中置式轉成前置式，並求出值。

mid_109_input_2D.txt(==請勿修改==)
```
2*3*4+5-6*7
(8+5*2)%5-6/3
9-2*2+9%3/6
5*(4-9+2)-7+6%4
```
輸出結果
```
Infix : 2*3*4+5-6*7
Prefix : -+**2345*67
Result : -13

Infix : (8+5*2)%5-6/3
Prefix : -%+8*525/63
Result : 1

Infix : 9-2*2+9%3/6
Prefix : +-9*22/%936
Result : 5
...
...
```
### 2.Judging machine
> 讀入名為==Judging Test-1==的txt檔案，檔案內有多行<font color=red>中序算式</font>，判斷輸入的算式是否合法與合理
> 1. 請先判斷開檔是否成功，成功請輸出==File read success,begin test==字串，再跳行==輸出一行分格線==後，開始判斷
> 2. 若不合理不合法，請輸出此算式，並輸出==fail:不合理的理由==
> 3. 若合理合法，請輸出計算結果，並輸出==Pass test==
> 4. 結束時，先跳行==輸出一行分格線==後，輸出==File read end,test finish==字串並結束程式

:::info
### 不合理的理由有以下幾種
1. Symbol of operation errors(未知的運算符號)
    - 如`Judging Test-1`檔案中的第 1 , 2 行算式
    - 已知運算符號只有`+`、`-`、`*`、`/`、`^` 、`(`、`)`
2. The number of symbol errors (符號數量錯誤)
    - 如`Judging Test-1`檔案中的第 4 , 5 行算式
3. Parentheses errors (括號使用錯誤)
    - 如`Judging Test-1`檔案中的第 7 行算式

:::

Judging Test-1.txt(==測試檔案，正式測試時並非此檔案==)
```=
1。2+3
1?
2^2+3
1++2
1-2-
1+2-3
1+)2-1(
1+(2-1)
```

輸出結果
```=
File read success,begin test
----------------------------
row 1:1。2+3 => fail:Symbol of operation errors
row 2:1? => fail:Symbol of operation errors
row 3:7 => Pass test
row 4:1++2 => fail:The number of symbol errors
row 5:1-2- => fail:The number of symbol errors
row 6:0 => Pass test
row 7:1+)2-1( => fail:Parentheses errors
row 8:2 => Pass test
----------------------------
File read end,test finish
```

:::danger
####**加分機制**####
請讀入Jugement Test-3.txt
並完成上述判斷
[Week10 測資](https://hackmd.io/tVji5u60Sf-p8PTMdd6r1Q)
:::

---

# Week10-測資
---------
Judging Test-1.txt
```=
1。2+3
1?
2^2+3
1++2
1-2-
1+2-3
1+)2-1(
1+(2-1)
```
- 結果
```
File read success,begin test
----------------------------
row 1:1。2+3 => fail:Symbol of operation errors
row 2:1? => fail:Symbol of operation errors
row 3:7 => Pass test
row 4:1++2 => fail:The number of symbol errors
row 5:1-2- => fail:The number of symbol errors
row 6:0 => Pass test
row 7:1+)2-1( => fail:Parentheses errors
row 8:2 => Pass test
----------------------------
File read end,test finish
```
----------

Judging Test-2.txt
```=
1+3-4*9+9
1)(3
2*3+6
1+2-4*
2--3
(1+2)*2
1?
2+3*4
5+3*0
)(2+3
2+(3-3)
```
- 結果
```
File read success,begin test
----------------------------
row 1:-23 => Pass test
row 2:1)(3 => fail:Parentheses errors
row 3:12 => Pass test
row 4:1+2-4* => fail:The number of symbol errors
row 5:2--3 => fail:The number of symbol errors
row 6:6 => Pass test
row 7:1? => fail:Symbol of operation errors
row 8:14 => Pass test
row 9:5 => Pass test
row 10:)(2+3 => fail:Parentheses errors
row 11:2 => Pass test
----------------------------
File read end,test finish
```
----------
Judging Test-3.txt
```=
-+234
?+123
*32+4
12*3+
13@4+
12+*
1*3$5
1(2+3)*3
1+(2+3)*3
1+)2*1(
1+2*3-8/2
```
- 結果
```
row 1:1 => Pass test
row 2:?+123 => fail:Symbol of operation errors
row 3:*32+4 => fail:The number of symbol errors
row 4:5 => Pass test
row 5:13@4+ => fail:Symbol of operation errors
row 6:+* => fail:The number of symbol errors
row 7:1*3$5 => fail:Symbol of operation errors
row 8:1(2+3)*3 => fail:The number of symbol errors
row 9:16 => Pass test
row 10:1+)2*1( => fail:Parentheses errors
row 11:3 => Pass test
```
----------
