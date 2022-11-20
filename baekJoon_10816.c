/*
	상근이가 주어진 M개의 정수 중 몇 개를 가지고 있는지 푸는 문제

	정수의 범위가 1<= N <= 500000 으로 굉장히 크다.

	M개의 정수를 N개와 하나씩 비교하게 되면 시간복잡도가 굉장히 커짐

	따라서 입력받은 수들을 오름차순/내림차순으로 정렬한 후 가장 side수부터 비교하면 된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 500001

int N, M;
int Have[MAX];
int Compare[MAX];

int Lower_bound(int* arr, int target, int size) {
	int start = 0, end = size - 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return end; // 이 부분이 key보다 이상이 되는 첫 인덱스
}

int Upper_bound(int* arr, int target, int size) {
	int start = 0, end = size - 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	if (arr[end] == target) { // 마지막 원소를 가리킬 때
		return end + 1;
	}
	return end; // 이 부분이 key보다 초과가 되는 첫 인덱스
}

void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

  /* recursion */
	if (L < right)
		quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

int main() {
	int N, M;
	scanf("%d", &N); // 상근이가 가지는 숫자 카드의 개수
	
	// 상근이가 가진 카드에 적힌 수
	for (int i = 0; i < N; i++) {
		scanf("%d", &Have[i]);
	}

	scanf("%d", &M); // 비교할 숫자 카드의 개수 

	// 비교할 대상 카드에 적힌 수
	for (int j = 0; j < M; j++) {
		scanf("%d", &Compare[j]);
	}

	// 상근이가 가지는 것과, 비교할 대상 모두를 정렬해준다.
	quickSort(Have, 0, N-1);

	/*
		퀵 정렬 이후에 해당 배열을 출력했을 때 정렬된 모습을 보인다.

		for (int i = 0; i < N; i++) {
		printf("%d", Have[i]);
		}	
	*/

	int lower;
	int upper;

	for (int i = 0; i < M; i++) {	//Compare의 크기 만큼 / But size는 Have의 크기
		lower = Lower_bound(Have, Compare[i], N);
		upper = Upper_bound(Have, Compare[i], N);
		int result = upper - lower;
		printf("%d ", result);
	}
}