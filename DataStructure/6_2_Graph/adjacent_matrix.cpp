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
	VertexType vex[MaxVertexNum];				// �����
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// �ڽӾ��󣬱߱�
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

// �ڽӾ���洢��Ȩͼ
typedef struct {
	VertexType vex[MaxVertexNum];				// �����
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// �ߵ�Ȩֵ
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͱ���/����
}MGraphWithValue;



int GetSubscript(MGraph& G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vex[i] == x)
			return i;
	}
}

// ��������

// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(MGraph& G, VertexType x, VertexType y);

// �г�ͼG������x�ڽӵı�
void Neighbors(MGraph& G, VertexType x);

// �����½��
bool InsertVertex(MGraph& G, VertexType x);

// ɾ������
bool DeleteVertex(MGraph& G, VertexType x);

// ����һ����
bool AddEdge(MGraph& G, VertexType x, VertexType y);

// ɾ��һ���ߣ��������(x, y)�������<x, y>���ڣ����ͼG��ɾ���ñ�
bool RemoveEdge(MGraph& G, VertexType x, VertexType y);

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(MGraph& G, VertexType x);

// ��ͼG�ж���x�ĵ�һ���ڽӵ����һ���ڽӵ�
int NextNeighbor(MGraph& G, VertexType x, VertexType y);

//// ��ȡȨֵ
//int GetEdgeValue(MGraph& G, x, y);
//
//// ����Ȩֵ
//bool SetEdgeValue(MGraph& G, x, y, v);


// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	if (G.edge[i][j])
		return true;
	else
		return false;
}


// �г�ͼG������x�ڽӵı�
void Neighbors(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	// arr ��¼�ڽӾ�����Ϊ1���±�
	//int arr[MaxVertexNum] = { 0 };
	//int k = 0;
	for (int j = 0; j < MaxVertexNum; j++) {
		//if (G.edge[i][j]) {
		//	arr[k] = j;
		//	k++;
		//}
		if (G.edge[i][j]) {
			printf("%c ", G.vex[j]);
		}
	}
}


// �����½��
bool InsertVertex(MGraph& G, VertexType x) {
	G.vex[G.vexnum] = x;
	return true;
}


// ɾ������
bool DeleteVertex(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MaxVertexNum; j++) {
		// ������Ϊ0
		G.edge[i][j] = 0;
		// ������Ϊ0
		G.edge[j][i] = 0;
	}
	// �ַ�0�����Ԫ��Ϊ��
	G.vex[i] = '0';
	// ʱ�临�Ӷ� O(|V|)
	return true;
}


// ����һ����
bool AddEdge(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	G.edge[i][j] = 1;
	G.edge[j][i] = 1;
	return true;
}


// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// ��ͼG�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�
int NextNeighbor(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// �Ӻ�һ��λ�ÿ�ʼ�����������ҵ���һ�γ��ֵ�1����λ��һ���ڽӵ�
	for (j; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}
