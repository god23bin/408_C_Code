#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 30			// ������Ŀ�����ֵ


#define INFINITE 2147483647
typedef char VertexType;
typedef int EdgeType;

// �ڽӾ���洢��Ȩͼ
typedef struct {
	VertexType vex[MaxVertexNum];				// �����
	EdgeType edge[MaxVertexNum][MaxVertexNum];	// �ߵ�Ȩֵ
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͱ���/����
}Graph;

void Dijkstra(Graph G, VertexType v);

void Dijkstra(Graph G, VertexType v) {

}