#define _CRT_SECURE_NO_WARNINGS 1

// Floyd���Ĵ���


void Floyd() {
	// ... ׼������������ͼ����Ϣ��ʼ������A��path
	for (int k = 0; k < n; K++) {		// ������Vk��Ϊ��ת��
		for (int i = 0; i < n; i++) {	// ������������iΪ�кţ�jΪ�к�
			for (int j = 0; j < n; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) {	// ��VkΪ��ת���·������
					A[i][j] = A[i][k] + A[k][j];	// �������·������
					path[i][j] = k;					// ��ת��
				}
			}
		}
	}
}