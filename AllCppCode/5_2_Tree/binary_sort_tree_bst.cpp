#define _CRT_SECURE_NO_WARNINGS 1

// ����������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �������������
typedef struct BSTNode {
	int key;
	struct BSTNode* lchild, * rchild;
}BSTNode,* BSTree;

// ����
BSTNode* BST_Search(BSTree T, int key);
BSTNode* BST_Search_Recursion(BSTree T, int key);

// ����
int BST_Insert(BSTree& T, int k);
int BST_Insert_Recursion(BSTree& T, int k);

// ����
// ����str[]�еĹؼ������н�������������
void CreateBST(BSTree& T, int str[], int n);

// ɾ��
// ���1��ɾ��Ҷ�ӽ�� => ����Ӱ������������ṹ
// ���2����ɾ���Ľ��ֻ��������������������ֱ�������������ԭ�ȵ�λ�þͿ�����
// ���3��ɾ���Ľ��������������������ô��ֱ��1)����2)
//        - 1) �����������������½ǵĽ������ý��Ϳ�����,��Ϊ�����µĽ��ֵ������������С��
//        - 2) �����������������½ǵĽ������ý��Ϳ�����,��Ϊ�����µĽ��ֵ��������������
bool BST_Delete(BSTree& T, int key);

// �ڶ����������в���ֵΪ key �Ľ��
BSTNode* BST_Search(BSTree T, int key) {
	while (T != NULL && key != T->key) {	// ���ջ���ڸ����ֵ�������ѭ��
		if (key < T->key)
			T = T->lchild;		// С�ڣ������������ϲ���
		else
			T = T->rchild;		// ���ڣ������������ϲ���
	}
	return T;
	// ��ռ临�Ӷ�O(1)
}

BSTNode* BST_Search_Recursion(BSTree T, int key) {
	if (T == NULL)	
		return NULL;	// ����ʧ��
	if (key == T->key)
		return T;		// ���ҳɹ�
	else if (key < T->key)
		return BST_Search_Recursion(T->lchild, key);	// ������������
	else
		return BST_Search_Recursion(T->rchild, key);	// ������������
	// ��ռ临�Ӷ�O(h)
}

int BST_Insert(BSTree& T, int k) {
	while (T) {
		if (k == T->key)		// ���д�����ͬ�ؼ��ֽ�㣬����ʧ��
			return 0;
		else if (k < T->key)
			T = T->lchild;		// С�ڣ������������ϲ���
		else
			T = T->rchild;
	}
	if (T == NULL) {	// ��Ϊ�գ��²���Ľ��Ϊ�����
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;		// ����1������ɹ�
	}
}

int BST_Insert_Recursion(BSTree& T, int k) {
	if (T == NULL) {	// ��Ϊ�գ��²���Ľ��Ϊ�����
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;		// ����1������ɹ�
	}
	else if (k == T->key)		// ���д�����ͬ�ؼ��ֽ�㣬����ʧ��
		return 0;
	else if (k < T->key)		// ���뵽T��������
		return BST_Insert(T->lchild, k);
	else                        // ���뵽T��������
		return BST_Insert(T->rchild, k);
	// ��ռ临�Ӷ�O(h)
}

// ����str[]�еĹؼ������н�������������
void CreateBST(BSTree& T, int str[], int n) {
	T = NULL;		// ��ʼ��T
	int i = 0;
	while (i < n) {	// ���ν�ÿ���ؼ��ֲ��뵽������������
		BST_Insert(T, str[i]);
		i++;
	}
}

// ɾ��
// ���1��ɾ��Ҷ�ӽ�� => ����Ӱ������������ṹ
// ���2����ɾ���Ľ��ֻ��������������������ֱ�������������ԭ�ȵ�λ�þͿ�����
// ���3��ɾ���Ľ��������������������ô��ֱ��1)����2)
//        - 1) �����������������½ǵĽ������ý��Ϳ�����,��Ϊ�����µĽ��ֵ������������С��
//        - 2) �����������������½ǵĽ������ý��Ϳ�����,��Ϊ�����µĽ��ֵ��������������
bool BST_Delete(BSTree& T, int key) {
	if (T == NULL) return false;
	// �����ֻ�и���㣬���Ҵ�ɾ���Ľ����Ǹ���㡣
	if (T->key == key && T->lchild == NULL && T->rchild == NULL) {
		free(T);
		T->key = -1;
		return true;
	}
	// �ҵ�Ҫɾ���Ľ��
	BSTNode* p = BST_Search(T, key);
	BSTNode* q;		// ��¼˫�׽��ĵ�ַ
	BSTNode* s;		// ��ʱ����ָ��
	if (p->lchild == NULL && p->rchild == NULL) {
		p->key = -1;
		p = NULL;
		free(p);
	}
	else if (p->lchild == NULL && p->rchild != NULL) {	// ������Ϊ��
		q = p;			// ��qָ��p����qָ��Ҫɾ�����
		p = p->rchild;	// ֱ����pָ�������Һ��ӣ��ͷŵ�q���ɾ���Ľ��
		free(q);
	}
	else if (p->rchild == NULL && p->lchild != NULL) {	// ������Ϊ��
		q = p;			// ��qָ��p����qָ��Ҫɾ�����
		p = p->lchild;	// ֱ����pָ���������ӣ��ͷŵ�q���ɾ���Ľ��
		free(q);
	}
	else {
		// ������������Ϊ��
		// ��ǰ��������ý�㣬�ҵ�ǰ����ǰ����������������
		// �����ҵ��������������½��
		q = p;			// ��qָ��p����qָ��Ҫɾ�����
		s = p->lchild;	// sָ��p��������
		while (s->rchild != NULL) {
			q = s;
			s = s->rchild;	// Ѱ�������������µĽ�㣬���Ҵ�ɾ����ǰ��
		}

		// �����������Ҳ�Ľ��ֵ���Ƶ����p�С�
		memcpy(&p->key, &s->key, sizeof(int));
		// ���������Ҳ�Ľ��s�ض�����������
		// �޸�˫�׽��q�������ָ��ָ��s����������s������������Ϊ�ա�
		p->rchild = s->lchild;
		free(s);
	}
}


