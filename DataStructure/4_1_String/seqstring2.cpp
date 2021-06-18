#define _CRT_SECURE_NO_WARNINGS 1

// 动态分配实现（堆分配存储）

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* ch;
	int length;
}String;