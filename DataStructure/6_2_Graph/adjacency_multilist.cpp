#define _CRT_SECURE_NO_WARNINGS 1

// �ڽӶ��ر�-�洢����ͼ

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30

typedef char VertexType;

// �߽��
typedef struct ArcNode {
	int i, j;				// �ߵ�����������
	int info;				// Ȩֵ
	struct ArcNode* iLink;	// �����ڶ���i����һ����
	struct ArcNode* jLink;	// �����ڶ���j����һ����
}ANode;

// ������
typedef struct VertexNode {
	VertexType data;		// ������
	ANode* firstedge;		// ��ö��������ĵ�һ����
}VNode, AdjMultiList[MaxVertexNum];