#define _CRT_SECURE_NO_WARNINGS 1

// 十字链表-存储有向图

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30

typedef char VertexType;

// 弧结点
typedef struct ArcNode {
	int tailvex;			// 弧尾顶点编号
	int headvex;			// 弧头顶点编号
	//int info;				// 权值
	struct ArcNode* hlink;	// 弧头相同的下一条弧
	struct ArcNode* tlink;	// 弧尾相同的下一条弧
}ArcNode;

// 顶点结点
// 用数组顺序存储顶点
typedef struct VertexNode {
	VertexType data;		// 数据域
	ArcNode* firstin;		// 该顶点作为弧头的第一条弧
	ArcNode* firstout;		// 该顶点作为弧尾的第一条弧
}VNode, OrthogonalList[MaxVertexNum];