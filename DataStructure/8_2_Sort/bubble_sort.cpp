#define _CRT_SECURE_NO_WARNINGS 1

// ½»»»ÅÅÐòÖ® ¡ª¡ª Ã°ÅÝÅÅÐò

#include <stdio.h>
#include <stdlib.h>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool flag = false;
		for (int j = n - 1; j > i; j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}