#define _CRT_SECURE_NO_WARNINGS 1

// ������ʽ�洢

#include <stdio.h>
#include <stdlib.h>


//typedef struct StringNode{
//	char ch;	// ÿ������1���ַ����洢�ܶȵ�
//	struct StringNode* next;
//}StringNode, * String;

typedef struct StringNode {
	char ch[4];	// ÿ������4���ַ����洢�ܶȸ�
	struct StringNode* next;
}StringNode, * String;

