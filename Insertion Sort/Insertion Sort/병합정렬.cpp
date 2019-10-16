//* 병합정렬
// - 분할 정복이라는 알고리즘 디자인 기법에 근거하여 만들어진 정렬 방법이다.
/// 1단계 : 분할 : 해결이 용이한 단계까지 문제를 분할 해 나간다.
/// 2단계 : 정복 : 해결이 용이한 수준까지 분할된 문제를 해결한다.
/// 3단계 : 결합 : 분할해서 해결한 결과를 결합하여 마무리한다.
// 요는 분할해서 정렬하고 결합하는것이다.

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int * sortArr = (int *)malloc(sizeof(int)*(right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid) {
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main() {
	int arr[7] = { 3,2,4,1,7,6,5 };
	int i;
	printf("%d", sizeof(arr) / sizeof(int) - 1);
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}