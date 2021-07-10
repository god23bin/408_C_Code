#define _CRT_SECURE_NO_WARNINGS 1

// 二叉排序树

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉排序树结点
typedef struct BSTNode {
	int key;
	struct BSTNode* lchild, * rchild;
}BSTNode,* BSTree;

// 查找
BSTNode* BST_Search(BSTree T, int key);
BSTNode* BST_Search_Recursion(BSTree T, int key);

// 插入
int BST_Insert(BSTree& T, int k);
int BST_Insert_Recursion(BSTree& T, int k);

// 构造
// 按照str[]中的关键字序列建立二叉排序树
void CreateBST(BSTree& T, int str[], int n);

// 删除
// 情况1，删除叶子结点 => 不会影响二叉排序树结构
// 情况2，若删除的结点只有左子树或右子树，就直接让这子树替代原先的位置就可以了
// 情况3，删除的结点有左右两个子树，那么就直接1)或者2)
//        - 1) 让其右子树中最左下角的结点替代该结点就可以了,因为最左下的结点值是右子树中最小的
//        - 2) 让其左子树中最右下角的结点替代该结点就可以了,因为最右下的结点值是左子树中最大的
bool BST_Delete(BSTree& T, int key);

// 在二叉排序树中查找值为 key 的结点
BSTNode* BST_Search(BSTree T, int key) {
	while (T != NULL && key != T->key) {	// 树空或等于根结点值，则结束循环
		if (key < T->key)
			T = T->lchild;		// 小于，则在左子树上查找
		else
			T = T->rchild;		// 大于，则在右子树上查找
	}
	return T;
	// 最坏空间复杂度O(1)
}

BSTNode* BST_Search_Recursion(BSTree T, int key) {
	if (T == NULL)	
		return NULL;	// 查找失败
	if (key == T->key)
		return T;		// 查找成功
	else if (key < T->key)
		return BST_Search_Recursion(T->lchild, key);	// 在左子树中找
	else
		return BST_Search_Recursion(T->rchild, key);	// 在右子树中找
	// 最坏空间复杂度O(h)
}

int BST_Insert(BSTree& T, int k) {
	while (T) {
		if (k == T->key)		// 树中存在相同关键字结点，插入失败
			return 0;
		else if (k < T->key)
			T = T->lchild;		// 小于，则在左子树上查找
		else
			T = T->rchild;
	}
	if (T == NULL) {	// 树为空，新插入的结点为根结点
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;		// 返回1，插入成功
	}
}

int BST_Insert_Recursion(BSTree& T, int k) {
	if (T == NULL) {	// 树为空，新插入的结点为根结点
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;		// 返回1，插入成功
	}
	else if (k == T->key)		// 树中存在相同关键字结点，插入失败
		return 0;
	else if (k < T->key)		// 插入到T的左子树
		return BST_Insert(T->lchild, k);
	else                        // 插入到T的右子树
		return BST_Insert(T->rchild, k);
	// 最坏空间复杂度O(h)
}

// 按照str[]中的关键字序列建立二叉排序树
void CreateBST(BSTree& T, int str[], int n) {
	T = NULL;		// 初始化T
	int i = 0;
	while (i < n) {	// 依次将每个关键字插入到二叉排序树中
		BST_Insert(T, str[i]);
		i++;
	}
}

// 删除
// 情况1，删除叶子结点 => 不会影响二叉排序树结构
// 情况2，若删除的结点只有左子树或右子树，就直接让这子树替代原先的位置就可以了
// 情况3，删除的结点有左右两个子树，那么就直接1)或者2)
//        - 1) 让其右子树中最左下角的结点替代该结点就可以了,因为最左下的结点值是右子树中最小的
//        - 2) 让其左子树中最右下角的结点替代该结点就可以了,因为最右下的结点值是左子树中最大的
bool BST_Delete(BSTree& T, int key) {
	if (T == NULL) return false;
	// 如果树只有根结点，并且待删除的结点就是根结点。
	if (T->key == key && T->lchild == NULL && T->rchild == NULL) {
		free(T);
		T->key = -1;
		return true;
	}
	// 找到要删除的结点
	BSTNode* p = BST_Search(T, key);
	BSTNode* q;		// 记录双亲结点的地址
	BSTNode* s;		// 临时查找指针
	if (p->lchild == NULL && p->rchild == NULL) {
		p->key = -1;
		p = NULL;
		free(p);
	}
	else if (p->lchild == NULL && p->rchild != NULL) {	// 左子树为空
		q = p;			// 让q指向p，即q指向要删除结点
		p = p->rchild;	// 直接让p指向它的右孩子，释放掉q这个删除的结点
		free(q);
	}
	else if (p->rchild == NULL && p->lchild != NULL) {	// 右子树为空
		q = p;			// 让q指向p，即q指向要删除结点
		p = p->lchild;	// 直接让p指向它的左孩子，释放掉q这个删除的结点
		free(q);
	}
	else {
		// 左右子树都不为空
		// 让前驱来代替该结点，找到前驱，前驱在左子树最右下
		// 所以找到左子树的最右下结点
		q = p;			// 让q指向p，即q指向要删除结点
		s = p->lchild;	// s指向p的左子树
		while (s->rchild != NULL) {
			q = s;
			s = s->rchild;	// 寻找左子树最右下的结点，即找待删结点的前驱
		}

		// 把左子树最右侧的结点值复制到结点p中。
		memcpy(&p->key, &s->key, sizeof(int));
		// 左子树最右侧的结点s必定无右子树。
		// 修改双亲结点q的左或右指针指向s的左子树，s的左子树可以为空。
		p->rchild = s->lchild;
		free(s);
	}
}


