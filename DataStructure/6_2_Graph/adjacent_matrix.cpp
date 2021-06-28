#define _CRT_SECURE_NO_WARNINGS 1

// adjacent matrix
// �ڽӾ���

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// ������Ŀ�����ֵ


//#define INFINITY ���intֵ	// ��������
typedef char VertexType;
typedef int EdgeType;

// �ڽӾ���洢ͼ
typedef struct {
	char Vex[MaxVertexNum];		// �����
	int Edge[MaxVertexNum];		// �ڽӾ��󣬱߱�
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

// �ڽӾ���洢��Ȩͼ
typedef struct {
	VertexType Vex[MaxVertexNum];		// �����
	EdgeType Edge[MaxVertexNum];		// �ߵ�Ȩֵ
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͱ���/����
}MGraphWithValue;


// ��������

// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(MGraph& G, EdgeType x, EdgeType y);

// �г�ͼG������x�ڽӵı�
void Neighbors(MGraph& G, EdgeType x);

// �����½��
bool InsertVertex(MGraph& G, x);

// ɾ������
bool DeleteVertex(MGraph& G, x);

// ����һ����
bool AddEdge(MGraph& G, x, y);

// ɾ��һ���ߣ��������(x, y)�������<x, y>���ڣ����ͼG��ɾ���ñ�
bool RemoveEdge(MGraph& G, x, y);

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
bool FirstNeighbor(MGraph& G, x);

// ��ȡȨֵ
int GetEdgeValue(MGraph& G, x, y);

// ����Ȩֵ
bool SetEdgeValue(MGraph& G, x, y, v);


// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(MGraph& G, EdgeType x, EdgeType y) {
	
}

