#define _CRT_SECURE_NO_WARNINGS 1

// 邻接多重表-存储无向图

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30

typedef char VertexType;

// 边结点
typedef struct ArcNode {
	int i, j;				// 边的两个顶点编号
	int info;				// 权值
	struct ArcNode* iLink;	// 依附于顶点i的下一条边
	struct ArcNode* jLink;	// 依附于顶点j的下一条边
}ANode;

// 顶点结点
typedef struct VertexNode {
	VertexType data;		// 数据域
	ANode* firstedge;		// 与该顶点相连的第一条边
}VNode, AdjMultiList[MaxVertexNum];