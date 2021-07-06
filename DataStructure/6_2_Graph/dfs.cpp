#define _CRT_SECURE_NO_WARNINGS 1

// 深度优先遍历

#include <stdio.h>
#include <stdlib.h>

#define MAXTEX 30

typedef int VertexType;
typedef int EdgeType;
typedef int ElemType;


// 邻接矩阵
typedef struct Graph {
	VertexType vertex[MAXTEX];
	EdgeType edge[MAXTEX][MAXTEX];
	int vexnum, arcnum;
}Graph;

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(Graph& G, VertexType x);

// 找图G中顶点x的第一个邻接点的下一个邻接点
int NextNeighbor(Graph& G, VertexType x, VertexType y);


int GetSubscript(Graph& G, VertexType x) {
	for (int i = 0; i < MAXTEX; i++) {
		if (G.vertex[i] == x)
			return i;
	}
}

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(Graph& G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// 找图G中顶点x的第一个邻接点y的下一个邻接点
int NextNeighbor(Graph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// 从后一个位置开始遍历，重新找到第一次出现的1，几位下一个邻接点
	for (j; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}

void visit(VertexType v) {
	printf("%d ", v);
}

bool visited[MAXTEX];

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
