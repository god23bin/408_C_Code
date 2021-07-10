#define _CRT_SECURE_NO_WARNINGS 1

// �ڽӱ���˳��+��ʽ�洢��

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// ������Ŀ�����ֵ

typedef char VertexType;
typedef int EdgeType;

// ��/��
typedef struct ArcNode {
	int adjvex;				// ��/��ָ���ĸ����
	struct ArcNode* next;	// ָ����һ������ָ��
	// InfoType info;		// ��Ȩֵ
}ArcNode;

// ����
typedef struct VNode {
	VertexType data;		// ������Ϣ
	ArcNode* first;			// ��һ����/��
}VNode, AdjList[MaxVertexNum];

// ���ڽӱ�洢��ͼ
typedef struct {
	AdjList vertices;		// �����ڽӱ�-������
	int vexnum, arcnum;		// ���ٸ���㣬��������
}ALGraph;


int GetSubscript(ALGraph G, VertexType x) {
	for (int i = 0; i < MaxVertexNum; i++) {
		if (G.vertices[i].data == x)
			return i;
	}
}

// ��������

// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(ALGraph G, VertexType x, VertexType y);

// �г�ͼG������x�ڽӵı�
void Neighbors(ALGraph G, VertexType x);

// �����½��
bool InsertVertex(ALGraph G, VertexType x);

// ɾ������
bool DeleteVertex(ALGraph G, VertexType x);

// ����һ����
bool AddEdge(ALGraph G, VertexType x, VertexType y);

// ɾ��һ���ߣ��������(x, y)�������<x, y>���ڣ����ͼG��ɾ���ñ�
bool RemoveEdge(ALGraph G, VertexType x, VertexType y);

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
int FirstNeighbor(ALGraph G, VertexType x);

// ��ͼG�ж���x�ĵ�һ���ڽӵ����һ���ڽӵ�
int NextNeighbor(ALGraph G, VertexType x, VertexType y);

//// ��ȡȨֵ
//int GetEdgeValue(ALGraph G, x, y);
//
//// ����Ȩֵ
//bool SetEdgeValue(ALGraph G, x, y, v);

// �ж�ͼG�Ƿ���ڱ�<x, y> ��(x, y)
bool Adjacent(ALGraph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	// pָ������1λ���ϵ�first���ͷ���
	ArcNode* p = G.vertices[i].first;
	// ��ʼ�������Ƿ������y���
	while (p->adjvex != j) {
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
		return true;
	// ʱ�临�Ӷ�O(1)��O(|V|)
	// ��õ��������ͷ�����棬������Ҳ���
}

// �г�ͼG������x�ڽӵı�
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


// �����½��
bool InsertVertex(ALGraph G, VertexType x) {
	G.vertices[G.vexnum].data = x;
	G.vertices[G.vexnum].first = NULL;
}


// ɾ������
bool DeleteVertex(ALGraph G, VertexType x) {
	int i = GetSubscript(G, x);
	// ����Ϊ�ַ�0����ʾ��λ��Ϊ��
	G.vertices[i].data = '0';
	// ɾ��x����Ӧ�ı߱�
	ArcNode* p = G.vertices[i].first;
	ArcNode* q;
	while (p) {
		// q ָ���ɾ���
		q = p;
		p = p->next;
		
		q->adjvex = NULL;
		free(q);
	}
	G.vertices[i].first = NULL;

	// ���������߱�ɾ��ʣ�µĸý��
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
	// ʱ�临�Ӷ� ���O(1)�O(E)
}


// ���ӱ߽�㣬��G���±�Ϊi��λ�õ����������adjvexΪj�Ľ��
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

// ����һ����
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

// ��ͼG�ж���x�ĵ�һ���ڽӵ�
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


// ��ͼG�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�
int NextNeighbor(ALGraph G, VertexType x, VertexType y) {
	int i = GetSubscript(G, x);
	int j = GetSubscript(G, y);
	ArcNode* p = G.vertices[i].first;
	while (p->adjvex != j) {
		p = p->next;
	}
	return p->next->adjvex;
}