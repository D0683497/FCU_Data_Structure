# 資料結構實習[Week12-樹]

## MAX/MIN Tree

- MAX
    - 樹中每一個點，都不能比其孩子還要小
- MIN
    - 樹中每一個點，都不能比其孩子還要大

## 引線二元樹 threaded binary tree

### 由來

常見二元樹

![](https://i.imgur.com/lF0Tm2C.jpg)

空間浪費問題

樹葉節點：leaf node EX：G、F、E、D 各還會空兩個NULL Link

解決辦法
- 讓他接回另一個node
- 最左與最右樹葉節點則接回root node

![](https://i.imgur.com/MHUN4Sl.jpg)

- 常件二元樹結構

```c=
struct tree {
    int data;     
    struct tree *Left;  
    struct tree *Right; 
};
```

- 引線二元樹
```c=
struct thtree {
    int data;     
    bool thLeft;//0表示左分支為正常Link，反之為引線
    struct tree *Left;
    bool thRight;//0表示右分支為正常Link，反之為引線
    struct tree *Right; 
};
```

## 課堂練習

### MAX threaded binary tree

用`Linked List`實作引線二元樹，並完成以下要求：
需實作功能清單
達成 MAX Tree 的特性
實作功能包含：
1. 插入
2. 刪除
3. 輸出樹目前的樣子
4. 讀取右or左引線

功能清單
```
MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:
```

#### 各功能規範

- 功能1
    - 插入時須滿足Complete的特性
    - 若輸入的數為**0**時，才印出上列要求，否則請**繼續輸入**。
    - 若輸入的數已經存在樹中，請輸出==already exit.==，並請**重新輸入**。
    - 0 不加入於樹中
    - 插入後結果需滿足 MAX Tree 特性
- 功能2 ==加分題==
    - 完成需輸出==Complete Delete==
    - 刪除後結果需滿足 MAX Tree 特性
- 功能3
    - 輸出格式為`中序排序`
- 功能4
    - 輸入要找尋的節點，回傳左右引線所連結的node值
        - 若其非為引線（threaded），則輸出==Not a threaded==

範例輸出
```=

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:1
10
8
7
6
5
4
5
already exit.
2
1
0
End Insert

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:2
1
Complete Delete

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:3
6 8 5 10 4 7 2

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:4
4
Left:10
Right:7

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:1
3
0

MAX threaded binary tree
--------
1. Insert
2. Delete
3. Print
4. Print threaded
--------
choose your operation:4
6
Left:Not a threaded
Right:8
```
