#define _CRT_SECURE_NO_WARNINGS 1

// ϣ�����򡪡��ֶ���֮���ӱ��������ֱ�Ӳ�������

#include <stdio.h>
#include <stdlib.h>

void ShellSort(int A[], int n);

void ShellSort(int A[], int n) {
	int d, i, j;
	// A[0] ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ���ѵ�
	for (d = n / 2; d >= 1; d = d / 2) 	// �����仯
		for (i = d + 1; i <= n; i++) 
			if (A[i] < A[i - d]) {		// ��Ҫ��A[i]�������������ӱ�
				A[0] = A[i];			// �ݴ���A[0]
				for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];	// ��¼���ƣ����Ҳ���λ��
				A[j + d] = A[0];		// ����
			}
}