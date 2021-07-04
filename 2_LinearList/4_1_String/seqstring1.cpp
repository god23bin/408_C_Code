#define _CRT_SECURE_NO_WARNINGS 1

// ��̬����ʵ�֣�����˳��洢��

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
	String sub;	// �����ݴ��Ӵ�
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
			++i;
		else
			return i;	// �����Ӵ��������е�λ��
	}
	return 0;	// S�в�������T��ȵ��Ӵ�
}

int Index_KMP(String S, String T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;				// �����ȽϺ����ַ�
		}
		else {
			j = next[j];		// ģʽ�������ƶ�
		}
	}
	if (j > T.length)
		return i - T.length;	// ƥ��ɹ�
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
			// ��pi = pj����next[j + 1] = next[j] + 1
			next[i] = j;
		}
		else {
			// ������j = next[j]��ѭ������
			j = next[j];
		}
	}
}

int Index_KMP(String S, String T) {
	int i = 1, j = 1;
	int next[T.length + 1];
	get_next(T, next); // ��ģʽ����next����
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