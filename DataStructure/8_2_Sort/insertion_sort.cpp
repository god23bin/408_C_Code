#define _CRT_SECURE_NO_WARNINGS 1

// 插入排序

#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[], int n);
// 插入排序（带哨兵）
void InsertionSort2(int A[], int n);
// 优化——折半插入排序
void InsertionSort3(int A[], int n);

void InsertionSort(int A[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {		// 将个元素插入到已排好序的序列中
		if (A[i] < A[i - 1]) {		// 若A[i]关键字小于前驱
			temp = A[i];			// 用temp暂存A[i]
			for (j = i - 1; j >= 0 && A[j] > temp; --j) {	// 检查所有前面已排好序的元素
				A[j + 1] = A[j];	// 所有大于temp的元素都往后挪位
			}
			A[j + 1] = temp;		// 复制到插入位置
		}
	}
	// 逻辑清晰
	// 空间复杂度O(1)
	// 时间复杂度:主要来自对比关键字、移动元素，若有n个元素，则需要n-1趟处理
	// 最好情况：原本有序，只需要比较，然后比较n-1次，只需O(n)
	// 最坏情况：原本为逆序，O(n^2)
	// 平均时间复杂度：O(n^2)
	// 算法稳定性：稳定
}


// 插入排序（带哨兵）
void InsertionSort2(int A[], int n) {
	int i, j;
	for (i = 2; i < n; i++) {		// 将个元素插入到已排好序的序列中
		if (A[i] < A[i - 1]) {		// 若A[i]关键字小于前驱
			A[0] = A[i];			// 用A[0]这个哨兵暂存A[i]
			for (j = i - 1; A[j] > A[0]; --j) {	// 检查所有前面已排好序的元素
				A[j + 1] = A[j];	// 所有大于A[0]的元素都往后挪位
			}
			A[j + 1] = A[0];		// 复制到插入位置
		}
	}
	// 优点：j不需要每轮循环都判断>0了
}


// 优化——折半查找排序
void InsertionSort3(int A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++) {		// 依次将A[2]~A[n]插入到前面已排好的序列中
		A[0] = A[i];				
		low = 1;high = i - 1;		// 设置折半查找的范围
		while (low <= high) {		// 折半查找（默认递增有序）
			mid = (low + high) / 2; // 取中间点
			if (A[mid] > A[0])		
				high = mid - 1;		// 查找左半子表
			else
				low = mid + 1;		// 查找右半子表
		}
		for (i = j - 1; j >= high + 1; --j)
			A[j + 1] = A[j];		// 后移元素
		A[high + 1] = A[0];			// 插入操作
	}
}

// 对链表插入排序 - 还是O(n^2)

// 直接插入排序练习
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
// 直接插入排序的代码实现

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


// 带哨兵
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


// 折半插入排序
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


// 插入排序
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


// 折半插入排序
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