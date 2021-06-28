#define _CRT_SECURE_NO_WARNINGS 1

// 邻接表法（顺序+链式存储）

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// 顶点数目的最大值

typedef char VertexType;
typedef int EdgeType;

// 边/弧
typedef struct ArcNode {
	int adjvex;				// 边/弧指向哪个结点
	struct ArcNode* next;	// 指向下一条弧的指针
	// InfoType info;		// 边权值
}ArcNode;

// 顶点
typedef struct VNode {
	VertexType data;		// 顶点信息
	ArcNode* first;			// 第一条边/弧
}VNode, AdjList[MaxVertexNum];

// 用邻接表存储的图
typedef struct {
	AdjList vertices;		// 声明邻接表-顶点们
	int vexnum, arcnum;		// 多少个结点，多少条边
}ALGraph;
