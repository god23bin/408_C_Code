#define _CRT_SECURE_NO_WARNINGS 1

// �ڽӱ���˳��+��ʽ�洢��

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// ������Ŀ�����ֵ

typedef char VertexType;
typedef int EdgeType;

// ��/��
typedef struct ArcNode {
	int adjvex;				// ��/��ָ���ĸ����
	struct ArcNode* next;	// ָ����һ������ָ��
	// InfoType info;		// ��Ȩֵ
}ArcNode;

// ����
typedef struct VNode {
	VertexType data;		// ������Ϣ
	ArcNode* first;			// ��һ����/��
}VNode, AdjList[MaxVertexNum];

// ���ڽӱ�洢��ͼ
typedef struct {
	AdjList vertices;		// �����ڽӱ�-������
	int vexnum, arcnum;		// ���ٸ���㣬��������
}ALGraph;
