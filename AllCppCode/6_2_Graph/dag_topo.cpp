#define _CRT_SECURE_NO_WARNINGS 1

// 拓扑排序
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef int VertexType;
typedef int InfoType;

// 边表结点--弧结点
typedef struct ArcNode {
	int adjvex;					// 该弧所指向的顶点的位置
	struct ArcNode* nextarc;	// 指向下一条弧结点的指针
	InfoType info;				// 网的边权值
}ArcNode;

// 顶点表结点
typedef struct VNode {
	VertexType data;		// 顶点信息
	ArcNode* firstarc;		// 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct {
	AdjList vertices;		// 邻接表
	int vexnum, arcnum;		// 图的顶点数和弧数
}Graph;

typedef int ElemType;

// 链式栈——栈的结构体基本和单链表没有区别，主要区别在于操作的实现
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}SNode, * LinkStack;

void InitStack(LinkStack& S);					// 初始化
bool IsEmpty(LinkStack S);					// 判空
bool Push(LinkStack& S, ElemType x);			// 入栈
bool Pop(LinkStack& S, ElemType& x);			// 出栈
bool GetTop(LinkStack S, ElemType& x);			// 获取栈顶元素
bool GetStackLength(LinkStack S, int& length);	// 获取栈的长度
void PrintStack(LinkStack S);					// 打印当前栈

void InitStack(LinkStack& S) {
	S = NULL;
}

bool IsEmpty(LinkStack S) {
	if (S == NULL)
		return true;
	else
		return false;
}

bool Push(LinkStack& S, ElemType x) {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL) return false;
	p->data = x;
	p->next = S;
	S = p;
	return true;
}

bool Pop(LinkStack& S, ElemType& x) {
	SNode* p = S;
	if (IsEmpty(S)) return false;
	x = S->data;
	S = S->next;
	p = NULL;
	free(p);
	return true;
}

bool GetTop(LinkStack S, ElemType& x) {
	if (IsEmpty(S)) return false;
	x = S->data;
	return true;
}

bool GetStackLength(LinkStack S, int& length) {
	if (S == NULL) {
		length = 0;
	}
	LinkNode* p = S;
	length = 0;
	while (p != NULL) {
		p = p->next;
		length++;
	}
	return true;
}

void PrintStack(LinkStack S) {
	printf("打印当前栈的内容->:\n");
	if (S == NULL) {
		printf("栈空~~~~\n");
		return;
	}
	LinkNode* p = S;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 当前顶点入度
int indegree[MaxVertexNum];
// 记录拓扑序列
int print[MaxVertexNum];

bool TopologicalSort(Graph G) {
	// 栈，保存度为0的顶点
	LinkStack S;
	InitStack(S);
	for (int i = 0; i < G.vexnum; i++) {
		if (indegree[i] == 0) {
			Push(S, i);
		}
	}
	int count = 0;
	while (!IsEmpty(S)) {
		Pop(S, i);
		print(count++) = i;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
			//
			v = p->adjvex;
			if (!(--indegreee[v]))
				Push(S, v);
		}
	}
	if (count < G.vexnum)
		return false;
	else
		return true;
}

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(Graph G, VertexType x);

// 找图G中顶点x的第一个邻接点的下一个邻接点
int NextNeighbor(Graph G, VertexType x, VertexType y);


int GetSubscript(Graph G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vertices[i].data == x)
			return i;
	}
}

// 找图G中顶点x的第一个邻接点
int FirstNeighbor(Graph G, VertexType x) {
	int i = GetSubscript(G, x);
	ArcNode* p = G.vertices[i].firstarc;
	if (p->nextarc) {
		return p->nextarc->adjvex;
	}
	else {
		return -1;
	}
}


// 找图G中顶点x的第一个邻接点y的下一个邻接点
int NextNeighbor(Graph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	ArcNode* p = G.vertices[i].firstarc;
	while (p->adjvex != j) {
		p = p->nextarc;
	}
	return p->nextarc->adjvex;
}

void visit(VertexType v) {
	printf("%d ", v);
}

bool visited[MaxVertexNum];

// DFS算法实现逆拓扑排序

void DFSTraverse(Graph G) {
	for (int v = 0; v < G.vexnum; ++v)
		visited[v] = false;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v) {
	
	visited[v] = true;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) 
		if (!visited[w]) {
			DFS(G, w);
		}
	visit(v);		// 输出顶点
}