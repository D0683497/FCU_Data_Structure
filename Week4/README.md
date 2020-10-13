# 資料結構實習[第一次小考][10/7]

[TOC]

-----

### 本次考場說明
- 考試時間為 10/07 早上9:25 - 11:55
- 考試期間請勿交頭接耳、當長頸鹿、互相討論。若有上述行為，視同作弊
- 對於試題或系統有問題時，請舉手等待助教過去，請勿大聲喧嘩與吵鬧
- 作弊者，++<font color=red>當次考試以零分計</font>++
- 提交題目時請提交一個**壓縮檔**。檔名為 : ==學號.7z==  eg.D0123456.7z
- 小題檔名為 : ==題號.c== eg.1.員工薪水.c
- 考完(離開前)請到前方找助教確認題目有提交成功。

-----
### 1.員工薪水(20%)
>請設計一C/C++程式，能讓使用者輸入三個員工的姓名及該員工平日(一到五)與假日(六和日)兩時段的每日工作時數(設各時段每日工作時數皆相同，且均以整數計)；之後，再依據使用者所輸入的資料，計算並印出每位員工**每周薪水、每月薪水、所得稅額、實領薪水**。
>(本題假設：平日的時薪為**3.49**美元，假日的時薪為**3.99**美元。)

:::success
### 上述名詞與其計算方式
1. ==每周薪水 = 平日工作時數x5(天)x平日時薪+假日工作時數2(天)x假日時薪==
2. ==每月薪水 = 每周薪水x4(週)==
3. ==所得稅額 = 每月薪水x7.5%==
4. ==實領薪水 = 每月薪水 - 所得稅額==
:::

:::info
### 題目限制
1. 員工姓名最大以**15字元**為限
2. 每周薪水、每月薪水均以**四捨五入**計算至**整數**後印出。
3. 所得稅額、實領薪水均以**四捨五入**計算至**小數第二位**後印出。
:::

執行畫面(測試資料)：(需依照格式輸入)
```
請輸入第1位員工姓名: Kevin
請輸入平日工作時數: 10
請輸入假日工作時數: 9
請輸入第2位員工姓名: Esther
請輸入平日工作時數: 8
請輸入假日工作時數: 7
請輸入第3位員工姓名: Isabella
請輸入平日工作時數: 6
請輸入假日工作時數: 7
```
輸出(測試資料)：(需依照格式輸出)
```
員工姓名　    每周總工作時數　 每周薪水　　每月薪水　 所得稅額　　實領薪水
=======================================================================
Kevin           68         246        984      73.80     910.20
Esther          54         195        780      58.50     721.50
Isabella        44         161        644      48.30     595.70
```
-----
### 2.組合字串(20%)
> 請設計一C/C++程式，讓使用者輸入一個字串，列印出該字串**總共有多少種組合字串，並且印出所有組合字串**。

>例如 : 輸入字串**abc**，則輸出由字元a、b、c所能排列出來6種的組合字串==abc==、==acb==、==bac==、==bca==、==cab==和==cba==。

:::info
### 題目限制
1. 字串長度最大以**6字元**為限
2. 字串中的字元不重複
:::

執行畫面(測試資料)：(需依照格式輸入及輸出)
```
輸入字串:abc
字串abc有6種組合字串:
abc
acb
bac
bca
cab
cba
```
-----
### 3.鏈結串列(30%)
>請設計一C/C++程式，並使用鏈結串列，提供**新增**、**刪除**、**列印**及**結束**功能

:::info
### 題目限制
1. 由**小至大**排序，
2. 若欲新增的數已經存在於串列中，請重新輸入。
:::

執行畫面(測試資料)：(需依照格式輸入及輸出)
```
操作選項表
==============
[1]加入資料
[2]刪除資料
[3]列印
[4]結束
輸入選項:1
Insert a number: 2
...
...
...
  操作選項表
==============
[1]加入資料
[2]刪除資料
[3]列印
[4]結束
輸入選項:2
Delete a number: 9
...
...
...
  操作選項表
==============
[1]加入資料
[2]刪除資料
[3]列印
[4]結束
輸入選項:3

2->5->7

  操作選項表
==============
[1]加入資料
[2]刪除資料
[3]列印
[4]結束
輸入選項:1
Insert a number: 7
7已經存在串列中

  操作選項表
==============
[1]加入資料
[2]刪除資料
[3]列印
[4]結束
輸入選項:4
```
-----
### 4.多項式相加(30%)
> 請設計一C/C++程式，由使用者輸入2個一元多次方程式，並分別建構成==兩個Linked List==。之後，供使用者選擇執行兩多項式之相加計算，並印出運算結果，請依照下列規則:

<!-- >1.多項式輸入為連續輸入下列格式：，且當輸入係數與次方皆為0時表示多項式輸入結束。
2.相同次方只會輸入一次，**不可重複輸入相同次方**。
3.多項式允許可不按次方大小順序輸入，但在多項式的Linked List 中必須按**次方大小**順序印出。**(由大至小)**。
4.若運算後的結果係數為零時，**不可將此次方印出** (即必須從多項式Linked List中移除)。 -->
:::info
### 題目限制
1. 多項式在輸入時請依照==係數 次方==，具體格式如下方範例所示
2. 當輸入係數與次方**皆為0**時表示多項式輸入**結束**
3. 當最後多項式之結果有次方的**係數為0**時，不可印出此次方
4. 相同次方只會輸入一次，同一個多項式**不可重複輸入相同次方**
5. 多項式最後的輸出結果，必須依照次方**大至小**排序
:::
執行畫面(測試資料)：(需依照格式輸入及輸出)
```
輸入多項式1(係數 次方): -3 1 (自行輸入)
輸入多項式1(係數 次方): 3 3
輸入多項式1(係數 次方): 1 2
輸入多項式1(係數 次方): 1 0
輸入多項式1(係數 次方): 0 0
--多項式1為: 3x^3+x^2-3x+1

輸入多項式2(係數 次方): 
...
--多項式2為: 

相加結果為: 
```