#define _CRT_SECURE_NO_WARNINGS 1

// ������ȱ���

#include <stdio.h>
#include <stdlib.h>

#define MAXTEX 30

typedef int VertexType;
typedef int EdgeType;
typedef int ElemType;


// �ڽӾ���
typedef struct Graph {
	VertexType vertex[MAXTEX];
	EdgeType edge[MAXTEX][MAXTEX];
	int vexnum, arcnum;
}Graph;


// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(Graph G, VertexType x);

// ��ͼG�ж���x�ĵ�һ���ڽӵ����һ���ڽӵ�
int NextNeighbor(Graph G, VertexType x, VertexType y);




void visit(VertexType v) {
	printf("%d ", v);
}


typedef struct LinkNode {		// ��ʽ���н��
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {				// ��ʽ����
	LinkNode* front, * rear;	// ���еĶ�ͷ����βָ��
	// int length;				// ���ԼӶ��������¼����
}LinkQueue;

// ����ͷ���Ļ�������
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

// ����ͷ���
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// ����ͷ����п�
bool IsEmpty(LinkQueue Q) {
	//if (Q.front == Q.rear == NULL) �пջ�ʧ��
	if (Q.front == Q.rear && Q.rear == NULL)
		return true;
	else
		return false;
}

// ����ͷ������
bool EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// �ڿն����в����һ��Ԫ��
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// �½����뵽rear����
		Q.rear = s;			// rearָ���½��
	}
	return true;
}

// ����ͷ������
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == NULL)
		return false;		// �ն�
	LinkNode* p = Q.front;	// pָ��˴γ��ӵ�Ԫ��
	x = p->data;			// ��x���ض�ͷԪ��
	Q.front = p->next;		// �޸�frontָ��
	if (Q.rear == p) {		// �˴������һ�����
		Q.front = NULL;		// frontָ��NULL
		Q.rear = NULL;		// rearָ��NULL
	}
	free(p);				// �ͷŽ��ռ�
	return true;
}

int GetSubscript(Graph G, VertexType x) {
	for (int i = 0; i < MAXTEX; i++) {
		if (G.vertex[i] == x)
			return i;
	}
}

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(Graph G, VertexType x) {
	int i = GetSubscript(G, x);
	for (int j = 0; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}


// ��ͼG�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�
int NextNeighbor(Graph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	j = j + 1;	// �Ӻ�һ��λ�ÿ�ʼ�����������ҵ���һ�γ��ֵ�1����λ��һ���ڽӵ�
	for (j; j < MAXTEX; j++) {
		if (G.edge[i][j])
			return j;
	}
}

bool visited[MAXTEX];		// ���ʱ������
LinkQueue Q;

void BFSTraverse(Graph G) {
	for (int i = 0; i < G.vexnum; ++i)
		visited[i] = false;				// ��ʼ�����ʱ������
	InitQueue(Q);						// ��ʼ����������
	for (int i = 0; i < G.vexnum; ++i)	// ��0�Ŷ��㿪ʼ����
		if (!visited[i])				// ��ÿ����ͨ��������һ��BFS
			BFS(G, i);					// viδ�����ʹ�����ô��vi��ʼBFS
}

// ������ȱ���
void BFS(Graph G, int v) {	// �Ӷ���v������������ȱ���ͼG
	visit(v);				// ���ʳ�ʼ����v
	visited[v] = true;		// ��v���ѷ��ʱ��
	EnQueue(Q, v);			// ����v�����Q
	while (!IsEmpty(Q)) {	
		DeQueue(Q, v);		// ����v������
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
			// ���v�����ڽӵ�
			if (!visited[w]) {		// wΪv����δ���ʵ��ڽӶ���
				visit(w);			// ���ʶ���w
				visited[w] = true;	// ��w���ѷ��ʱ��
				EnQueue(Q, w);		// ����w�����
			}
		}
	}
}