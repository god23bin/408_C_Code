#define _CRT_SECURE_NO_WARNINGS 1

// 串的链式存储

#include <stdio.h>
#include <stdlib.h>


//typedef struct StringNode{
//	char ch;	// 每个结点存1个字符，存储密度低
//	struct StringNode* next;
//}StringNode, * String;

typedef struct StringNode {
	char ch[4];	// 每个结点存4个字符，存储密度高
	struct StringNode* next;
}StringNode, * String;

