#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// 顶点数目的最大值


#define INFINITE 2147483647
typedef char VertexType;
typedef int EdgeType;

// 邻接矩阵存储带权图
typedef struct {
	VertexType vex[MaxVertexNum];				// 顶点表
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// 边的权值
	int vexnum, arcnum;			// 图的当前顶点数和边数/弧数
}Graph;

void Dijkstra(Graph G, VertexType v);

void Dijkstra(Graph G, VertexType v) {

}