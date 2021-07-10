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


int GetSubscript(ALGraph G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vertices[i].data == x)
			return i;
	}
}

// 基本操作

// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(ALGraph G, VertexType x, VertexType y);

// 列出图G中与结点x邻接的边
void Neighbors(ALGraph G, VertexType x);

// 插入新结点
bool InsertVertex(ALGraph G, VertexType x);

// 删除顶点
bool DeleteVertex(ALGraph G, VertexType x);

// 增加一条边
bool AddEdge(ALGraph G, VertexType x, VertexType y);

// 删除一条边，若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
bool RemoveEdge(ALGraph G, VertexType x, VertexType y);

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(ALGraph G, VertexType x);

// 找图G中顶点x的第一个邻接点的下一个邻接点
int NextNeighbor(ALGraph G, VertexType x, VertexType y);

//// 获取权值
//int GetEdgeValue(ALGraph G, x, y);
//
//// 设置权值
//bool SetEdgeValue(ALGraph G, x, y, v);

// 判断图G是否存在边<x, y> 或(x, y)
bool Adjacent(ALGraph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	// p指向数组1位置上的first这个头结点
	ArcNode* p = G.vertices[i].first;
	// 开始往后找是否有这个y结点
	while (p->adjvex != j) {
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
		return true;
	// 时间复杂度O(1)到O(|V|)
	// 最好的情况就在头结点后面，最坏就是找不到
}

// 列出图G中与结点x邻接的边
void Neighbors(ALGraph G, VertexType x) {
	int i = GetSubscript(G, x);
	int j = 0;
	ArcNode* p = G.vertices[i].first;
	while (p) {
		j = p->adjvex;
		printf("%c ", G.vertices[j].data);
		p = p->next;
	}
}


// 插入新结点
bool InsertVertex(ALGraph G, VertexType x) {
	G.vertices[G.vexnum].data = x;
	G.vertices[G.vexnum].first = NULL;
}


// 删除顶点
bool DeleteVertex(ALGraph G, VertexType x) {
	int i = GetSubscript(G, x);
	// 设置为字符0，表示该位置为空
	G.vertices[i].data = '0';
	// 删除x结点对应的边表
	ArcNode* p = G.vertices[i].first;
	ArcNode* q;
	while (p) {
		// q 指向待删结点
		q = p;
		p = p->next;
		
		q->adjvex = NULL;
		free(q);
	}
	G.vertices[i].first = NULL;

	// 遍历整个边表，删除剩下的该结点
	ArcNode* pre = NULL;
	for (int j = 0; j < MaxVertexNum; j++) {
		p = G.vertices[j].first;
		pre = p;
		while (p) {
			if (p->adjvex == i) {
				pre->next = p->next;
				p->next = NULL;
				free(p);
				break;
			}
			else {
				pre = p;
				p = p->next;
			}
		}

	}
	// 时间复杂度 最好O(1)最坏O(E)
}


// 增加边结点，在G中下标为i的位置的链表上添加adjvex为j的结点
bool AddArcNode(ALGraph G, int i, int j) {
	ArcNode* p = G.vertices[i].first;
	while (p->next) {
		p = p->next;
	}
	ArcNode* s = (ArcNode*)malloc(sizeof(ArcNode));
	if (s == NULL)
		return false;
	s->adjvex = j;
	p->next = s;
	s->next = NULL;
	return true;
}

// 增加一条边
bool AddEdge(ALGraph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	//AddArcNode(G, i, j);
	//AddArcNode(G, j, i);
	if (AddArcNode(G, i, j) && AddArcNode(G, j, i))
		return true;
	else
		return false;
	return true;
}

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(ALGraph G, VertexType x) {
	int i = GetSubscript(G, x);
	ArcNode* p = G.vertices[i].first;
	if (p->next) {
		return p->next->adjvex;
	}
	else {
		return -1;
	}
}


// 找图G中顶点x的第一个邻接点y的下一个邻接点
int NextNeighbor(ALGraph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	ArcNode* p = G.vertices[i].first;
	while (p->adjvex != j) {
		p = p->next;
	}
	return p->next->adjvex;
}