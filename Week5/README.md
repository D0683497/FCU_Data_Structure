# 資料結構實習[Week5-結構與陣列]
---

## 聯合 Union
- 聯合(union)宣告類似結構。但它的欄位是**共享同一記憶體空間**；也就是在一個時間點**只有一個欄位是作用的**。
- 宣告
    ```c=
    union [union tag]
    {
       member definition;
       member definition;
       ...
       member definition;
    };
    [one or more union variables]; 
    ```
- 例如
    ```c=
    union item{
	    int intNum;
	    float floatNum;
	    char word[10];
    };

    union item data,data1;//data與data1皆是union item的變數
    ```
---
## 列舉 enum
- 是一種複合型別，用來定義**新的資料型別**。一般來說，我們使用列舉時，將其視為一種符號(Symbol)。
- 例如
    ```c=
    enum Seasons{
	    SPRING,
	    SUMMER,
	    AUTUMN,
	    WINTER,
    };
    int main(void){
	
	    enum Seasons season = AUTUMN;//season為enum的變數名稱

	    if(season == AUTUMN){
		    printf("Now is autumn.");
	    }
	    else{
		    printf("Now is not autumn.");
	    }
    }
    ```
    執行結果
    ```
    Now is autumn.
    ```

---   
## 傳統矩陣相乘

- ==相乘成立的必要條件 : A的行必須等於B的列==
- 例如 : 矩陣A * 矩陣B
     ![](https://i.imgur.com/UZBpUeJ.jpg)
     - 相乘結果C ==(A的行,B的列)==
     
     - 圖示
     ![](https://i.imgur.com/k5F2g9e.jpg)
     ![](https://i.imgur.com/VJZkcuV.jpg)
     ![](https://i.imgur.com/67xjNfU.jpg)
---
## 稀疏矩陣


| 矩陣     |            儲存方式            |
| -------- |:------------------------------:|
| 完全矩陣 |        每一個元素都儲存        |
| 稀疏矩陣 | 只儲存==非零元素==的**位置**及其**元素值** |

- 相較於完全矩陣，稀疏矩陣較節省空間。
- 列、行均以遞增方式儲存。
- 每個元素以 **<row, col, value>** 來表示。
    ```c=
    typedef struct {
        int row;  //行
        int col;  //列 
        int value;   
    }term;
    ```
- 圖示
    ![](https://i.imgur.com/2jwS9Kv.jpg)
    ![](https://i.imgur.com/aA8ct9S.jpg)
    
---
## 稀疏矩陣快速轉置
- 計算原始矩陣每一==行==中元素的個數 (row_terms)
- 由前一步驟計算轉置矩陣中每一列之起始位置 (starting_pos)
    ```
    starting_pos[i] = starting_pos[i-1]+row_terms[i-1];
    ```
- 將元素一個一個移至正確位置
    ==取出後將starting_pos該位置值+1，下次放置在下一格==
    ![](https://i.imgur.com/x8QFg37.jpg)

---
## 課堂練習
### 1.傳統矩陣相乘
> 製作一可計算矩陣相乘之程式，**需判斷兩矩陣是否能進行相乘，若不能請重新輸入**，需照以下格式輸入。
> 
執行畫面:
```
請輸入矩陣A(m*n)的大小: 3 2(使用者輸入)
請依序輸入二維陣列A(3*2)的元素內容: (使用者輸入)
1 2
0 4
3 0
請輸入矩陣B(m*n)的大小: 2 3(使用者輸入)
請依序輸入二維陣列B(2*3)的元素內容: (使用者輸入)
1 2 0
2 0 1
矩陣相乘結果:
5 2 2
8 0 4
3 6 0

請輸入矩陣A(m*n)的大小: 0 1(使用者輸入)
請重新輸入!!!!
請輸入矩陣A(m*n)的大小: 2 2(使用者輸入)
請依序輸入二維陣列A(2*2)的元素內容: (使用者輸入)
1 2 
2 0 
...
...
...

```

### 2.稀疏矩陣
> 將第一題的結果用**稀疏矩陣**方式做儲存。
> 
輸出範例:
```
稀疏矩陣:
尺寸: 3*3 項目數: 7
index   row     col     value
1       0       0       5
2       0       1       2
3       0       2       2
4       1       0       8
5       1       2       4
6       2       0       3
7       2       1       6
```

### 3.轉置矩陣
> 將第一題的結果用**稀疏矩陣快速轉置**方式輸出，並以完全矩陣方式顯示出來。
> 
輸出範例:
```
轉置矩陣:
尺寸: 3*3
5 8 3
2 0 6
2 4 0
```
---
測資1:
```
6 3
5 0 0
0 0 0
0 3 0
0 0 2
0 0 0
1 0 0
3 5
0 0 0 0 2
0 0 4 3 0
0 1 0 0 0
```
測資2:
```
4 5
0  -2  0  0   -1
-5  0  0  2   0
0   3  0  4   4
0   0  0  -2  -2
5 2
0   0
-1  0
6   3
0   -1
2   1
```
