#define _CRT_SECURE_NO_WARNINGS 1

// 希尔排序——分而治之，子表里面进行直接插入排序

#include <stdio.h>
#include <stdlib.h>

void ShellSort(int A[], int n);

void ShellSort(int A[], int n) {
	int d, i, j;
	// A[0] 只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	for (d = n / 2; d >= 1; d = d / 2) 	// 步长变化
		for (i = d + 1; i <= n; i++) 
			if (A[i] < A[i - d]) {		// 需要将A[i]插入有序增量子表
				A[0] = A[i];			// 暂存在A[0]
				for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];	// 记录后移，查找插入位置
				A[j + d] = A[0];		// 插入
			}
}
// d 5
// i 6					7
// A[6] < A[1]			A[7] < A[2]
// A[0] = A[6] = 13
// j = 1

// 练习
void ShellSort1(int arr[], int n) {
	int d, i, j, temp;
	for (d = n / 2; d >= 1; d /= 2) {
		for (i = d + 1; i < n; i++) {
			if (arr[i] < arr[i - d]) {
				temp = arr[i];
				for (j = i - d; j > 0 && arr[j] > temp; j -= d) {
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}


void ShellSort2(int arr[], int n) {
	int d, i, j, temp;
	for (d = d / 2; d >= 1; d = d / 2) {
		for (i = d + 1; i < n; i++) {
			if (arr[i] < arr[i - d]) {
				temp = arr[i];
				for (j = i - d; j > 0 && arr[j] > temp; j -= d) {
					arr[j + 1] = arr[j];
				}
				arr[j + 1] = temp;
			}
		}
	}
}



void ShellSort3(int arr[], int n) {
	int d, i, j, temp;
	for (d = d/2; d >= 1; d = d/2) {
		for (i = d + 1; i < n; i++) {
			if (arr[i] < arr[i - d]) {
				arr[i] = temp;
				for (j = i - d; j > 0 && arr[j] > temp; j = j - d) {
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}


void ShellSort4(int arr[], int n) {
	int d, i, j, temp;
	for (d = d/2; d >= 1; d /= 2) {
		for (i = d + 1; i < n; i++) {
			if (arr[i] < arr[i - d]) {
				for(j = i - d; j > 0 && arr[j] > temp; j -= d) {
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}
