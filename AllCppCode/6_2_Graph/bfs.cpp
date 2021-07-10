#define _CRT_SECURE_NO_WARNINGS 1

// 广度优先遍历

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
int FirstNeighbor(Graph G, VertexType x);

// 找图G中顶点x的第一个邻接点的下一个邻接点
int NextNeighbor(Graph G, VertexType x, VertexType y);




void visit(VertexType v) {
	printf("%d ", v);
}


typedef struct LinkNode {		// 链式队列结点
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {				// 链式队列
	LinkNode* front, * rear;	// 队列的队头、队尾指针
	// int length;				// 可以加多变量，记录长度
}LinkQueue;

// 不带头结点的基本操作
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

// 不带头结点
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// 不带头结点判空
bool IsEmpty(LinkQueue Q) {
	//if (Q.front == Q.rear == NULL) 判空会失败
	if (Q.front == Q.rear && Q.rear == NULL)
		return true;
	else
		return false;
}

// 不带头结点入队
bool EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// 在空队列中插入第一个元素
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// 新结点插入到rear后面
		Q.rear = s;			// rear指向新结点
	}
	return true;
}

// 不带头结点出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == NULL)
		return false;		// 空队
	LinkNode* p = Q.front;	// p指向此次出队的元素
	x = p->data;			// 用x返回队头元素
	Q.front = p->next;		// 修改front指针
	if (Q.rear == p) {		// 此次是最后一个结点
		Q.front = NULL;		// front指向NULL
		Q.rear = NULL;		// rear指向NULL
	}
	free(p);				// 释放结点空间
	return true;
}

int GetSubscript(Graph G, VertexType x) {
	for (int i = 0; i < MAXTEX; i++) {
		if (G.vertex[i] == x)
			return i;
	}
}

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(Graph G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// 找图G中顶点x的第一个邻接点y的下一个邻接点
int NextNeighbor(Graph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// 从后一个位置开始遍历，重新找到第一次出现的1，几位下一个邻接点
	for (j; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}

bool visited[MAXTEX];		// 访问标记数组
LinkQueue Q;

void BFSTraverse(Graph G) {
	for (int i = 0; i < G.vexnum; ++i)
		visited[i] = false;				// 初始化访问标记数组
	InitQueue(Q);						// 初始化辅助队列
	for (int i = 0; i < G.vexnum; ++i)	// 从0号顶点开始遍历
		if (!visited[i])				// 对每个连通分量调用一次BFS
			BFS(G, i);					// vi未被访问过，那么从vi开始BFS
}

// 广度优先遍历
void BFS(Graph G, int v) {	// 从顶点v出发，广度优先遍历图G
	visit(v);				// 访问初始顶点v
	visited[v] = true;		// 对v做已访问标记
	EnQueue(Q, v);			// 顶点v入队列Q
	while (!IsEmpty(Q)) {	
		DeQueue(Q, v);		// 顶点v出队列
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
			// 检测v所有邻接点
			if (!visited[w]) {		// w为v的尚未访问的邻接顶点
				visit(w);			// 访问顶点w
				visited[w] = true;	// 对w做已访问标记
				EnQueue(Q, w);		// 顶点w入队列
			}
		}
	}
}