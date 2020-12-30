# 資料結構實習[Week15-圖 Graph]

> 從 12/23 12:00 至 12/29 23:59，開放補交全部的作業

> 檔名：學號-姓名-補交的週數 EX:D0753499-鄭羽辰-Week7

> 請壓縮上傳

> 下禮拜12/30要小考!!

## 擴張樹

### 特性

1. 包含樹的所有頂點
2. 只包含某些的邊

![](https://i.imgur.com/oDY0CCJ.png)

### DFS 擴張樹

DFS:A-&gt;B-&gt;D-&gt;H-&gt;E-&gt;F-&gt;C-&gt;G

![](https://i.imgur.com/yA4nSVM.png)

### BFS 擴張樹

BFS:A-&gt;B-&gt;C-&gt;D-&gt;E-&gt;F-&gt;G-&gt;H

![](https://i.imgur.com/qvhuEeq.png)

## 加權樹

給予圖上每一邊一個權值

![](https://i.imgur.com/wm0byNH.png)

## 最小成本擴張樹

- MST (Minimum Cost Spanning Tree)
- 總和權值（成本）為最小的擴張樹
- 若總節點數為n，則會有n-1個邊

## Kruskal’s 演算法

1. 每次加入一個邊
2. 加入的順序，由成本小至大加入(加入後不得形成迴圈)
3. 重複2直至完成全部的串鏈

```
1.A-&gt;B //1
2.A-&gt;C //2
3.F-&gt;H //3
4.C-&gt;F //4
5.G-&gt;H //6
6.B-&gt;D //7
7.D-&gt;H //8  -&gt; A-&gt;C-&gt;F-&gt;H-&gt;D-&gt;B-&gt;A 形成迴圈，取消
8.E-&gt;H //9
```

## Prim’s 演算法

1. 每次加入一個邊
2. 另出P、U頂點集合，P是目前以連結節點、U是所有節點集合
3. 找出目前最小的成本連結(加入後不得形成迴圈)
5. 重複3直至完成全部的串鏈

```
P={A}
U={A B C D E F G H}
1.P={A B} //1
2.P={A B C} //2
3.P={A B C F} //4
4.P={A B C F H} //3
5.P={A B C F H G} //6
6.P={A B C F H G D} //7
7.P={A B C F H G D H} //8 -&gt; 產生迴圈、取消
8.P={A B C F H G D E} //9
```

---

## 課堂練習

### 1. 完成Kruskal’s 產生最小生成樹演算法之程式

#### input.txt

```
0 3 1 14 5 10 6 20
1 4 0 14 2 11 3 21 6 19
2 2 1 11 3 23
3 3 2 23 1 21 4 9
4 3 3 9  5 30 6 25
5 4 0 10 4 30 6 13 7 15
6 4 0 20 1 19 4 25 5 13
7 1 5 15
```

#### ANS:

```
Kruskal Algorithm
--------------
1th : Link:3-4 Weight:9
2th : Link:0-5 Weight:10
3th : Link:1-2 Weight:11
4th : Link:5-6 Weight:13
5th : Link:1-0 Weight:14
6th : Link:7-5 Weight:15
7th : Link:6-1 Weight:19
Waring:It cause the cycle
7th : Link:0-6 Weight:20
Waring:It cause the cycle
7th : Link:1-3 Weight:21
--------------
End
```

### 2.完成Prim’s 產生最小成本樹演算法之程式

以1開始搜尋

#### input.txt

```
0 3 1 14 5 10 6 20
1 4 0 14 2 11 3 21 6 19
2 2 1 11 3 23
3 3 2 23 1 21 4 9
4 3 3 9  5 30 6 25
5 4 0 10 4 30 6 13 7 15
6 4 0 20 1 19 4 25 5 13
7 1 5 15
```

#### ANS:

```
Prim Algorithm
--------------
1th : Link:1-2 Weight:11
2th : Link:0-1 Weight:14
3th : Link:0-5 Weight:10
4th : Link:5-6 Weight:13
5th : Link:5-7 Weight:15
6th : Link:6-1 Weight:19
Waring:It cause the cycle
6th : Link:0-6 Weight:20
Waring:It cause the cycle
6th : Link:1-3 Weight:21
7th : Link:4-3 Weight:9
--------------
End
```

### (加分題) 3.完成Sollin,s 產生最小生成樹演算法之程式

