# 資料結構實習[Week13 - 二元樹刪除]
---
## 新增 Insert
- 根據上上禮拜新增二元樹之方法，多接一條==back==回父節點。
![](https://i.imgur.com/4VHTUos.jpg)
- 定義及宣告
```c=
    struct tree {
        int data;     
        struct tree *back;
        struct tree *Left;  
        struct tree *Right; 
    };
```
- [Week11 - 二元樹](https://hackmd.io/kphU6xlCROG0aRac3awalQ?view)

## 刪除 Delete
- [情況1] : 欲刪除值(del)為**樹葉節點**
    - 假設為右子樹
        1.
        ![](https://i.imgur.com/oLma71P.jpg)
        2.
        ![](https://i.imgur.com/0D2qxCA.jpg)
        ```
        del->back->Right = NULL;
        free(del);
        ```
- [情況2] : 欲刪除值**只有一邊有子樹**
    - 假設只有右子樹
        - 刪除值為root : root往下移
            1.![](https://i.imgur.com/AMD6b4H.jpg)
            2.![](https://i.imgur.com/A95IpEq.jpg)
        - 刪除值為父節點的右節點
            1.![](https://i.imgur.com/KVGs7OK.jpg)
            2.![](https://i.imgur.com/vrA1wU6.jpg)
            ```
            del->back->Right = del->Right;
            del->Right->back = del->back;
            free(del);
            ```
        - 刪除值為父節點的左節點 : (同理右節點情況)

:::warning
上述兩種情況所舉的範例都只有用其中一邊子樹來做說明喔!!!
:::
- [情況3] : 欲刪除值**同時有左右子樹**
    - 有兩種方法，選擇一種就可以(==左子樹找最大值== OR ==右子樹找最小值==)
    - 假設從左子樹找最大值
        - 先將temp指向欲刪除位置(del)之**左子節點**
        - 若左子節點沒有右節點(```temp->Right == NULL```) : 為最大值
        1.![](https://i.imgur.com/3nidkth.jpg)
        2.![](https://i.imgur.com/WOluIJh.jpg)
        3.![](https://i.imgur.com/vpVBfdu.jpg)
            ```c=
            if(temp->Left != NULL){//若temp左邊還有值
			    temp->Left->back = del;
		    }
            ```
        - 若左子節點有右節點(```temp->Right != NULL```)
        1.![](https://i.imgur.com/8vsE7aF.jpg)
        2.![](https://i.imgur.com/jDdtcnY.jpg)
        3.![](https://i.imgur.com/pSsFySP.jpg)

---

## 課堂練習
### 1.BinaryTree
> 請根據Week11二元樹實作，新增**刪除**功能，並將結果以**前序表示法**印出來。
:::info
### 注意
1.若輸入的數已經存在樹中，請輸出==already exist.==，並請重新輸入。
2.若欲刪除的數不在樹中，請輸出==does not exist in the tree.==，並請重新輸入。
3.直到輸入**選項0**才結束程式。
:::
輸出結果:
```
[1] Add [2] Delete [0] Exit:1
Insert a number:20
Preorder:20
----------------------

[1] Add [2] Delete [0] Exit:1
Insert a number:35
Preorder:20 35
----------------------

[1] Add [2] Delete [0] Exit:1
Insert a number:12
Preorder:20 12 35
----------------------

[1] Add [2] Delete [0] Exit:2
Delete a number:20
Preorder:12 35
----------------------

[1] Add [2] Delete [0] Exit:1
Insert a number:12
12 already exist.
Preorder:12 35
----------------------

[1] Add [2] Delete [0] Exit:1
Insert a number:13
Preorder:12 35 13
----------------------

[1] Add [2] Delete [0] Exit:2
Delete a number:12
Preorder:35 13
----------------------

[1] Add [2] Delete [0] Exit:2
Delete a number:35
Preorder:13
----------------------

[1] Add [2] Delete [0] Exit:2
Delete a number:14
14 does not exist in the tree.
Preorder:13
----------------------

[1] Add [2] Delete [0] Exit:2
Delete a number:13
Preorder:
----------------------

[1] Add [2] Delete [0] Exit:2
Preorder:
----------------------

[1] Add [2] Delete [0] Exit:0

--------------------------------
```
