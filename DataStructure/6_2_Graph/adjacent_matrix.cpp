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
	char Vex[MaxVertexNum];		// 顶点表
	int Edge[MaxVertexNum];		// 邻接矩阵，边表
	int vexnum, arcnum;			// 图的当前顶点数和边数/弧数
}MGraph;

// 邻接矩阵存储带权图
typedef struct {
	VertexType Vex[MaxVertexNum];		// 顶点表
	EdgeType Edge[MaxVertexNum];		// 边的权值
	int vexnum, arcnum;			// 图的当前顶点数和边数/弧数
}MGraphWithValue;


// 基本操作

// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(MGraph& G, EdgeType x, EdgeType y);

// 列出图G中与结点x邻接的边
void Neighbors(MGraph& G, EdgeType x);

// 插入新结点
bool InsertVertex(MGraph& G, x);

// 删除顶点
bool DeleteVertex(MGraph& G, x);

// 增加一条边
bool AddEdge(MGraph& G, x, y);

// 删除一条边，若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
bool RemoveEdge(MGraph& G, x, y);

// 找图G中顶点x的第一个邻接点
bool FirstNeighbor(MGraph& G, x);

// 获取权值
int GetEdgeValue(MGraph& G, x, y);

// 设置权值
bool SetEdgeValue(MGraph& G, x, y, v);


// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(MGraph& G, EdgeType x, EdgeType y) {
	
}

