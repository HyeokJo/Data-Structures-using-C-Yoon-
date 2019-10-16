#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2) {
	return n2 - n1;
	//return n1 - n2;
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	//힙에 넣었다가 빼는게 전부이지만 힙에 들어가는 자체가
	//이미 정렬이 된것을 의미한다.
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main() {
	int arr[4] = { 3,4,2,1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d", arr[i]);
	printf("\n");
	return 0;

}