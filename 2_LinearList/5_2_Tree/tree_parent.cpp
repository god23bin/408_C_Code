#define _CRT_SECURE_NO_WARNINGS 1

// ˫�ױ�ʾ����˳��洢��

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30			// �����������

typedef char ElemType;

typedef struct {					// ���Ľ�㶨��
	ElemType data;					// ����Ԫ��
	int parent;						// ˫��λ����
}PTNode;

typedef struct {					// �������Ͷ���
	PTNode nodes[MAX_TREE_SIZE];	// ˫�ױ�ʾ
	int n;							// �����
}PTree;

// ������
bool InsertPTNode(PTNode& node);

// ɾ�����
// ����1 ֱ�ӽ�ĳ�ڵ��˫������Ϊ-1
// ����2 ֱ�ӽ����һ�����Ǹý��
// ���ɾ���Ĳ���Ҷ�ӽ���أ���
// ͨͨɾ������������н��

// ������Ҫ���ҵĺ���

// ����ĳ�����������ӽڵ�
bool FindSonNode(PTree& T);