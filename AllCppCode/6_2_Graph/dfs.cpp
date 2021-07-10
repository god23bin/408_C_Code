#define _CRT_SECURE_NO_WARNINGS 1

// ������ȱ���

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30

typedef int VertexType;
typedef int EdgeType;
typedef int ElemType;


// �ڽӾ���
typedef struct Graph {
	VertexType vertex[MaxVertexNum];
	EdgeType edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}Graph;

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(Graph G, VertexType x);

// ��ͼG�ж���x�ĵ�һ���ڽӵ����һ���ڽӵ�
int NextNeighbor(Graph G, VertexType x, VertexType y);


int GetSubscript(Graph G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vertex[i] == x)
			return i;
	}
}

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(Graph G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// ��ͼG�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�
int NextNeighbor(Graph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// �Ӻ�һ��λ�ÿ�ʼ�����������ҵ���һ�γ��ֵ�1����λ��һ���ڽӵ�
	for (j; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}

void visit(VertexType v) {
	printf("%d ", v);
}

bool visited[MaxVertexNum];

void DFSTraverse(Graph G) {
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = false;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v) {
	visit(v);
	visited[v] = true;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		if (!visited[w])
			DFS(G, w);
}
