#define _CRT_SECURE_NO_WARNINGS 1

// ��������

#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[], int n);
// �������򣨴��ڱ���
void InsertionSort2(int A[], int n);
// �Ż������۰��������
void InsertionSort3(int A[], int n);

void InsertionSort(int A[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {		// ����Ԫ�ز��뵽���ź����������
		if (A[i] < A[i - 1]) {		// ��A[i]�ؼ���С��ǰ��
			temp = A[i];			// ��temp�ݴ�A[i]
			for (j = i - 1; j >= 0 && A[j] > temp; --j) {	// �������ǰ�����ź����Ԫ��
				A[j + 1] = A[j];	// ���д���temp��Ԫ�ض�����Ųλ
			}
			A[j + 1] = temp;		// ���Ƶ�����λ��
		}
	}
	// �߼�����
	// �ռ临�Ӷ�O(1)
	// ʱ�临�Ӷ�:��Ҫ���ԶԱȹؼ��֡��ƶ�Ԫ�أ�����n��Ԫ�أ�����Ҫn-1�˴���
	// ��������ԭ������ֻ��Ҫ�Ƚϣ�Ȼ��Ƚ�n-1�Σ�ֻ��O(n)
	// ������ԭ��Ϊ����O(n^2)
	// ƽ��ʱ�临�Ӷȣ�O(n^2)
	// �㷨�ȶ��ԣ��ȶ�
}


// �������򣨴��ڱ���
void InsertionSort2(int A[], int n) {
	int i, j;
	for (i = 2; i < n; i++) {		// ����Ԫ�ز��뵽���ź����������
		if (A[i] < A[i - 1]) {		// ��A[i]�ؼ���С��ǰ��
			A[0] = A[i];			// ��A[0]����ڱ��ݴ�A[i]
			for (j = i - 1; A[j] > A[0]; --j) {	// �������ǰ�����ź����Ԫ��
				A[j + 1] = A[j];	// ���д���A[0]��Ԫ�ض�����Ųλ
			}
			A[j + 1] = A[0];		// ���Ƶ�����λ��
		}
	}
	// �ŵ㣺j����Ҫÿ��ѭ�����ж�>0��
}


// �Ż������۰��������
void InsertionSort3(int A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++) {		// ���ν�A[2]~A[n]���뵽ǰ�����źõ�������
		A[0] = A[i];				
		low = 1;high = i - 1;		// �����۰���ҵķ�Χ
		while (low <= high) {		// �۰���ң�Ĭ�ϵ�������
			mid = (low + high) / 2; // ȡ�м��
			if (A[mid] > A[0])		
				high = mid - 1;		// ��������ӱ�
			else
				low = mid + 1;		// �����Ұ��ӱ�
		}
		for (i = j - 1; j >= high + 1; --j)
			A[j + 1] = A[j];		// ����Ԫ��
		A[high + 1] = A[0];			// �������
	}
}

// ������������� - ����O(n^2)

// ֱ�Ӳ���������ϰ
void InsertionSortPractice(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

void IS1(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}



//  23 24  6  9  3 35
//   6 23 24
// ֱ�Ӳ�������Ĵ���ʵ��

void IS2(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}


void IS3(int A[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (A[i] < A[i - 1]) {
			temp = A[i];
			for (j = i - 1; j >= 0 && A[j] > temp; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
	}
}


// ���ڱ�
void IS4(int A[], int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			for (j = i - 1; j >= 0 && A[j] > A[0]; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}


// �۰��������
void IS5(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			int low = 0, high = i - 1, mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (arr[mid] > temp) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}


// ��������
void IS6(int arr[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			for(j = i - 1; j >=0 && arr[j] > temp; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}


// �۰��������
int IS7(int arr[], int n) {
	int i, j, temp;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			int low = 0, high = i - 1, mid;
			while (low < high) {
				mid = (low + high) / 2;
				if (arr[mid] > temp) 
					high = mid - 1;
				else 
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}