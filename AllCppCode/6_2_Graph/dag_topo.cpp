#define _CRT_SECURE_NO_WARNINGS 1

// ��������
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef int VertexType;
typedef int InfoType;

// �߱���--�����
typedef struct ArcNode {
	int adjvex;					// �û���ָ��Ķ����λ��
	struct ArcNode* nextarc;	// ָ����һ��������ָ��
	InfoType info;				// ���ı�Ȩֵ
}ArcNode;

// �������
typedef struct VNode {
	VertexType data;		// ������Ϣ
	ArcNode* firstarc;		// ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MaxVertexNum];

typedef struct {
	AdjList vertices;		// �ڽӱ�
	int vexnum, arcnum;		// ͼ�Ķ������ͻ���
}Graph;

typedef int ElemType;

// ��ʽջ����ջ�Ľṹ������͵�����û��������Ҫ�������ڲ�����ʵ��
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}SNode, * LinkStack;

void InitStack(LinkStack& S);					// ��ʼ��
bool IsEmpty(LinkStack S);					// �п�
bool Push(LinkStack& S, ElemType x);			// ��ջ
bool Pop(LinkStack& S, ElemType& x);			// ��ջ
bool GetTop(LinkStack S, ElemType& x);			// ��ȡջ��Ԫ��
bool GetStackLength(LinkStack S, int& length);	// ��ȡջ�ĳ���
void PrintStack(LinkStack S);					// ��ӡ��ǰջ

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
	printf("��ӡ��ǰջ������->:\n");
	if (S == NULL) {
		printf("ջ��~~~~\n");
		return;
	}
	LinkNode* p = S;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// ��ǰ�������
int indegree[MaxVertexNum];
// ��¼��������
int print[MaxVertexNum];

bool TopologicalSort(Graph G) {
	// ջ�������Ϊ0�Ķ���
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

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(Graph G, VertexType x);

// ��ͼG�ж���x�ĵ�һ���ڽӵ����һ���ڽӵ�
int NextNeighbor(Graph G, VertexType x, VertexType y);


int GetSubscript(Graph G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vertices[i].data == x)
			return i;
	}
}

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
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


// ��ͼG�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�
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

// DFS�㷨ʵ������������

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
	visit(v);		// �������
}