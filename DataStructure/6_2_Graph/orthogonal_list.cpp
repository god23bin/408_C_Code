#define _CRT_SECURE_NO_WARNINGS 1

// ʮ������-�洢����ͼ

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30

typedef char VertexType;

// �����
typedef struct ArcNode {
	int tailvex;			// ��β������
	int headvex;			// ��ͷ������
	//int info;				// Ȩֵ
	struct ArcNode* hlink;	// ��ͷ��ͬ����һ����
	struct ArcNode* tlink;	// ��β��ͬ����һ����
}ArcNode;

// ������
// ������˳��洢����
typedef struct VertexNode {
	VertexType data;		// ������
	ArcNode* firstin;		// �ö�����Ϊ��ͷ�ĵ�һ����
	ArcNode* firstout;		// �ö�����Ϊ��β�ĵ�һ����
}VNode, OrthogonalList[MaxVertexNum];