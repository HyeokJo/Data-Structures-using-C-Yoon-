// * 삽입정렬
//	- 정렬이 완료된 부분과 완료되지 않은 부분으로 나뉘어 있다.
//	  정렬 대상을 두 부분으로 나눠서, 정렬 안된 부분에 있는 데이터를
//	  정렬 된 부분의 특정 위치에 삽입 해 가면서 정렬을 진행하는 알고리즘이다.

#include <stdio.h>

void InserSort(int arr[], int n) {
	int insData;	//정렬데이터 저장위치
	int j;

	for (int i = 1; i < n; i++) {
		insData = arr[i];	//정렬대상 저장
		for (j = i - 1; j >= 0; j--) {	// j = i - 1인것에 주의
			if (arr[j] > insData)	//i의 -1인 인덱스(arr[j])가 i인덱스보다 크다면
				arr[j + 1] = arr[j];	//j+1 인덱스를 j인덱스로 하고 j--
										// j+1 인덱스라고 i 인덱스라고 생각하면 안된다.
			else
				break;	//j인덱스보다 i인덱스가 더 크다면 그 자리가 삽입자리다.
		}
		arr[j + 1] = insData;	//삽입자리에 정렬, 제일 작다면(for문을 다 돌았다면) j는 -1이 되고
								//arr[-1 + 1]이 되어 arr[0]자리 즉 제일 앞이 된다.
	}
}

int main() {
	int arr[5] = { 5,3,2,4,1 };

	InserSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;

}