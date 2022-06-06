#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define true 1
#define false 0


typedef struct {
	int r[MAXSIZE + 1];
	int length;
}SqList;


void swap(SqList* L, int i, int j) {
	int k;
	k = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = k;
}

void show(SqList* L) {
	int i;
	for (i = 1; i < L->length; i++)
		printf(" %d", L->r[i]);
}


void BubbleSort0(SqList* L) {
	int i, j;
	for (i = 1; i <= L->length; i++) {
		for (j = i + 1; j <= L->length; j++) {
			if (L->r[i] > L->r[j]) {
				swap(L, i, j);
				show(L);
				printf("\n");
			}
		}
	}
}

void BubbleSort(SqList* L) {
	int i, j;
	
	int flag = true;
	for (i = 1; i <= L->length && flag; i++) {
		flag = false;
		for (j = L->length; j > i; j--) {
			if (L->r[j] < L->r[j - 1]) {
				swap(L, j, j - 1);
				flag = true;
			}
		}
		show(L);
		printf("\n");
	}
}

void SelectSort(SqList* L) {
	int i, j, min;
	for (i = 1; i <= L->length; i++) {
		min = i;
		for (j = i + 1; j <= L->length; j++) {
			if (L->r[min] > L->r[j])
				min = j;
		}
		if (min != i)	swap(L, min, i);
		show(L);
		printf("\n");
	}
}

void InsertSort(SqList* L) {
	int i, j;
	for (i = 2; i < L->length; i++) {
		if (L->r[i] < L->r[i - 1]) {
			L->r[0] = L->r[i];
			for (j = i - 1; j > 0 && L->r[0] < L->r[j]; j--) {
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];
		}
		show(L);
		printf("\n");
	}

}

void ShellSort(SqList* L) {
	int i, len = L->length;
	do {
		len = len / 2 + 1;
		for (i = 1; (i + len) <= L->length; i++) {
			if (L->r[i] > L->r[i + len])
				swap(L, i, i + len);
		}
	} while (len != 1);
	printf("대략적인 순서로 배열\n");
	show(L);
	printf("단순 삽입 정렬 수행：\n");
	InsertSort(L);
}

void HeapSort(SqList* L) {
	int i;
	for (i = L->length / 2; i > 0; i--) {
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i >= 1; i--) {
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
		show(L);
		printf("\n");
	}
}

void HeapAdjust(SqList* L, int s, int m) {
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j++) {
		if (j < m && L->r[j] < L->r[j + 1])
			++j;
		if (temp >= L->r[j])
			break;
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;
}

int main(void) {
	int i;
	
	SqList* L = (SqList*)malloc(sizeof(SqList));
	L->length = 9;
	int arr[10] = { 114,135,156,181,119,156,172,146,183,177 };
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("정렬하기 전에：\n");
	show(L);
	printf("\n");


	printf("버블 정렬:\n");
	BubbleSort0(L);
	
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("정통 버블 정렬：\n");
	BubbleSort(L);
	
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("단순 선택 정렬：\n");
	SelectSort(L);
	
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("직접 삽입 정렬：\n");
	InsertSort(L);
	
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("힐 소트：\n");
	ShellSort(L);
	
	for (i = 0; i < 10; i++)
		L->r[i + 1] = arr[i];
	printf("힙 정렬：\n");
	HeapSort(L);



	return 0;
}
 
