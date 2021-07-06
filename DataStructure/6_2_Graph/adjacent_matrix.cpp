#define _CRT_SECURE_NO_WARNINGS 1

// adjacent matrix
// 邻接矩阵

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// 顶点数目的最大值


//#define INFINITY 最大int值	// 代表无穷
typedef char VertexType;
typedef int EdgeType;

// 邻接矩阵存储图
typedef struct {
	VertexType vex[MaxVertexNum];				// 顶点表
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// 邻接矩阵，边表
	int vexnum, arcnum;			// 图的当前顶点数和边数/弧数
}MGraph;

// 邻接矩阵存储带权图
typedef struct {
	VertexType vex[MaxVertexNum];				// 顶点表
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// 边的权值
	int vexnum, arcnum;			// 图的当前顶点数和边数/弧数
}MGraphWithValue;



int GetSubscript(MGraph& G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vex[i] == x)
			return i;
	}
}

// 基本操作

// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(MGraph& G, VertexType x, VertexType y);

// 列出图G中与结点x邻接的边
void Neighbors(MGraph& G, VertexType x);

// 插入新结点
bool InsertVertex(MGraph& G, VertexType x);

// 删除顶点
bool DeleteVertex(MGraph& G, VertexType x);

// 增加一条边
bool AddEdge(MGraph& G, VertexType x, VertexType y);

// 删除一条边，若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
bool RemoveEdge(MGraph& G, VertexType x, VertexType y);

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(MGraph& G, VertexType x);

// 找图G中顶点x的第一个邻接点的下一个邻接点
int NextNeighbor(MGraph& G, VertexType x, VertexType y);

//// 获取权值
//int GetEdgeValue(MGraph& G, x, y);
//
//// 设置权值
//bool SetEdgeValue(MGraph& G, x, y, v);


// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	if (G.edge[i][j])
		return true;
	else
		return false;
}


// 列出图G中与结点x邻接的边
void Neighbors(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	// arr 记录邻接矩阵中为1的下标
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


// 插入新结点
bool InsertVertex(MGraph& G, VertexType x) {
	G.vex[G.vexnum] = x;
	return true;
}


// 删除顶点
bool DeleteVertex(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MaxVertexNum; j++) {
		// 设置行为0
		G.edge[i][j] = 0;
		// 设置列为0
		G.edge[j][i] = 0;
	}
	// 字符0代表该元素为空
	G.vex[i] = '0';
	// 时间复杂度 O(|V|)
	return true;
}


// 增加一条边
bool AddEdge(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	G.edge[i][j] = 1;
	G.edge[j][i] = 1;
	return true;
}


// 找图G中顶点x的第一个邻接点
int FirstNeighbor(MGraph& G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// 找图G中顶点x的第一个邻接点y的下一个邻接点
int NextNeighbor(MGraph& G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// 从后一个位置开始遍历，重新找到第一次出现的1，几位下一个邻接点
	for (j; j < MaxVertexNum; j++) {
		if (G.edge[i][j])
			return j;
	}
}
