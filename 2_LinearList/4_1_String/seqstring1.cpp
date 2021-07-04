#define _CRT_SECURE_NO_WARNINGS 1

// 静态数组实现（定长顺序存储）

#include <stdio.h>

#define MAXLEN 255

typedef struct {
	char ch[MAXLEN];
	int length;
}String;


bool StrAssign(String& T, char* ch);
bool StrCopy(String& T, String S);
bool StrEmpty(String S);
int StrLength(String S);
bool ClearString(String& S);
bool DestroyString(String& S);
bool Concat(String& T, String S1, String S2);

bool SubString(String& Sub, String S, int postion, int length);
int StrCompare(String S, String T);
int Index(String S, String T);
int Index_KMP(String S, String T, int next[]);


void get_next(String T, int next[]);
int Index_KMP(String S, String T);



int StrLength(String S) {
	return S.length;
}

bool SubString(String& Sub, String S, int postion, int length) {
	if (postion + length - 1 > S.length)
		return false;
	for (int i = postion; i < postion + length; i++) {
		Sub.ch[i - postion + 1] = S.ch[i];
	}
	Sub.length = length;
	return true;
}


int StrCompare(String S, String T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}


int Index(String S, String T) {
	int i = 1, n = StrLength(S), m = StrLength(T);
	String sub;	// 用于暂存子串
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
			++i;
		else
			return i;	// 返回子串在主串中的位置
	}
	return 0;	// S中不存在与T相等的子串
}

int Index_KMP(String S, String T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;				// 继续比较后面字符
		}
		else {
			j = next[j];		// 模式串向右移动
		}
	}
	if (j > T.length)
		return i - T.length;	// 匹配成功
	else
		return 0;
}

void get_next(String T, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] = T.ch[j]) {
			++i;
			++j;
			// 若pi = pj，则next[j + 1] = next[j] + 1
			next[i] = j;
		}
		else {
			// 否则令j = next[j]，循环继续
			j = next[j];
		}
	}
}

int Index_KMP(String S, String T) {
	int i = 1, j = 1;
	int next[T.length + 1];
	get_next(T, next); // 求模式串的next数组
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}