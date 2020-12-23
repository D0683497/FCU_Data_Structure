# 資料結構實習[Week14-圖 Graph]

> 下下禮拜12/30要小考!!

## 相鄰矩陣 Adjacency Matrix

- 說明 : G=(V,E)為一**無向圖**，宣告一個nxn的二維矩陣，其中若為1則表示有此邊，若為0，則不存在此邊。
- 圖示 ![](https://i.imgur.com/RnHJklF.png)

## 相鄰串列 Adjacency List

- 圖示 ![](https://i.imgur.com/WUxDss2.png)
- 宣告
    ```
    struct node{
        int data;
        node *link;
    }
    struct node Ｎode;
    ```
- 說明
    - 有多少節點，宣告其結構陣列大小
    - 在相鄰矩陣中將數字1之位置存到相鄰串列中
    - 假設目前```Node[i].link == NULL```，則將新節點加入至link
    - 其他則一直往後尋找，直到NULL

## 深度優先搜尋法 DFS

- 說明
    1. 先拜訪起始點V。
    2. 選擇與V相鄰但尚未被拜訪的頂點W。
    3. 再以W為起始點。
    4. 重複步驟1到3，直到所有頂點皆被訪問過結束。
- 圖示 ![](https://i.imgur.com/EKx4lGV.png)
    > DFS : ABEFCDG

## 廣度優先搜尋法 BFS

- 說明
    1. 先拜訪起始點V。
    2. 拜訪與V相鄰且未被訪問的頂點。
    3. 重複步驟1與2，直到所有與V相鄰的頂點皆被訪問後尋找下一層頂點。
- 圖示 ![](https://i.imgur.com/wpLm03H.png)
    > BFS : ABCDEFG

---

## 課堂練習

### 1.Adjacency Matrix

```
輸入點和邊數，再輸入其連接的邊，轉換成相鄰矩陣並印出
```

#### 輸出結果

```
Insert the number of nodes : 4
Insert the number of edges : 5
Insert the edge1 : 0 1
Insert the edge2 : 0 3
Insert the edge3 : 2 1
Insert the edge4 : 2 3
Insert the edge5 : 3 2
--------------------------------
Adjacency Matrix
0 1 0 1
0 0 0 0 
0 1 0 1
0 0 1 0
Insert the number of nodes : 0
```

#### 注意

1. 若節點數量為0，則結束程式，否則繼續輸入
2. 連接的邊中間用空格隔開

### 2.Adjacency List

```
請讀入一檔案==input.txt==，將其中的相鄰矩陣轉成相鄰串列並印出，且印出其DFS追蹤。
```

> **加分**！！！！**一起印出BFS**

#### 輸出結果

```
Adjacency Matrix
0 1 1 0 0 0 0
1 0 0 1 1 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0


Adjacency List
0 ->1 ->2
1 ->0 ->3 ->4 ->5
2 ->0 ->6
3 ->1
4 ->1
5 ->1
6 ->2

DFS : 0,1,3,4,5,2,6
BFS : 0,1,2,3,4,5,6
```

#### input.txt

```
0 1 1 0 0 0 0
1 0 0 1 1 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
```
