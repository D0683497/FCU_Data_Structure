# 資料結構實習[Week11 - 樹]

## 二元樹 Binary Tree

![](https://i.imgur.com/lF0Tm2C.jpg)

### 圖示

![](https://i.imgur.com/C4zVDUF.jpg)

### 定義及宣告
    
- 用鏈結串列表示
- [鏈結串列 Linked List](https://hackmd.io/RQu47VgZRTWGXG1M16j9VQ?view)

```c=
struct tree {
    int data;             
    struct tree *Left;  
    struct tree *Right; 
};
```
### 說明

#### 若 root 為**NULL**，將節點設為**root**

![](https://i.imgur.com/Kx5ecQP.jpg)

#### 若已經有 root **(令ptr = root)**

##### 欲新增值較 ptr 小

- 若 `ptr->Left == NULL`，則將新增值接到 `ptr->Left`

![](https://i.imgur.com/1cXp7b0.jpg)

- 若 `ptr->Left != NULL`，則持續往下追蹤

##### 欲新增值較 ptr 大

- 若 `ptr->Right == NULL`，則將新增值接到 `ptr->Right`

![](https://i.imgur.com/2s7um5e.jpg)

- 若 `ptr->Right != NULL`，則持續往下追蹤

##### 欲新增值 == ptr

- 顯示已存在，且不加入樹。
    
#### 圖示

![](https://i.imgur.com/VeOwQVV.jpg)

##### 欲新增值```30```到樹

- 因為 `30 > ptr`，且 `ptr->Right != NULL`，所以**往右追蹤**

![](https://i.imgur.com/YCCMirn.jpg)

- ptr 指到 `35`

- 因為 `30 < ptr`，且 `ptr->Left == NULL`，所以接到 `ptr->Left`

![](https://i.imgur.com/NcIGJ7p.jpg)
        
---

## 二元樹追蹤(Traversal)

### 定義

- L : 拜訪左子樹
- V : 印出節點
- R : 拜訪右子樹

### 追蹤

- **中序追蹤(Inorder)** : **LVR**
- **前序追蹤(Preorder)** : **VLR**
- **後序追蹤(Postorder)** : **LRV**

### 範例

![](https://i.imgur.com/dc5Z5mL.jpg)

- 中序追蹤(Inorder) : `A * B + C * D - E`
- 前序追蹤(Preorder) : `- + * A B * C D E`
- 後序追蹤(Postorder) : `A B * C D * + E -`

---

## 課堂練習

### BinaryTree

請用 `Linked List` 實作二元樹，並印出以下要求 : 
1. 前序追蹤(Preorder)
2. 中序追蹤(Inorder)
3. 最大及最小值
4. 樹葉節點

注意!!!
- 若輸入的數為 **0** 時，才印出上列要求，否則請**繼續輸入**。
- 若輸入的數已經存在樹中，請輸出 `already exit.`，並請**重新輸入**。
- 0 不加入於樹中。

輸出結果
```
Insert a number : 18
Insert a number : 22
Insert a number : 20
Insert a number : 32
Insert a number : 18
18 already exit.
Insert a number : 11
Insert a number : 9
Insert a number : 0
---------------------------------
Preorder  : 18 11 9 22 20 32
Inorder   : 9 11 18 20 22 32
MAX : 32
MIN : 9
LeafNodes : 9 20 32
```

> **加分!!!**：一併完成**後序追蹤(Postorder)**

輸出結果
```
Insert a number : 18
Insert a number : 22
Insert a number : 20
Insert a number : 32
Insert a number : 18
18 already exist.
Insert a number : 11
Insert a number : 9
Insert a number : 0
---------------------------------
Preorder  : 18 11 9 22 20 32
Inorder   : 9 11 18 20 22 32
Postorder : 9 11 20 32 22 18
MAX : 32
MIN : 9
LeafNodes : 9 20 32
```
