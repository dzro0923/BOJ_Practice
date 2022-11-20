/*
	����̰� �־��� M���� ���� �� �� ���� ������ �ִ��� Ǫ�� ����

	������ ������ 1<= N <= 500000 ���� ������ ũ��.

	M���� ������ N���� �ϳ��� ���ϰ� �Ǹ� �ð����⵵�� ������ Ŀ��

	���� �Է¹��� ������ ��������/������������ ������ �� ���� side������ ���ϸ� �ȴ�.
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
	return end; // �� �κ��� key���� �̻��� �Ǵ� ù �ε���
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
	if (arr[end] == target) { // ������ ���Ҹ� ����ų ��
		return end + 1;
	}
	return end; // �� �κ��� key���� �ʰ��� �Ǵ� ù �ε���
}

void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
			left++;
		while (arr[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
			right--;
		if (left <= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
			left++;
			right--;
		}
	} while (left <= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 

  /* recursion */
	if (L < right)
		quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 

	if (left < R)
		quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}

int main() {
	int N, M;
	scanf("%d", &N); // ����̰� ������ ���� ī���� ����
	
	// ����̰� ���� ī�忡 ���� ��
	for (int i = 0; i < N; i++) {
		scanf("%d", &Have[i]);
	}

	scanf("%d", &M); // ���� ���� ī���� ���� 

	// ���� ��� ī�忡 ���� ��
	for (int j = 0; j < M; j++) {
		scanf("%d", &Compare[j]);
	}

	// ����̰� ������ �Ͱ�, ���� ��� ��θ� �������ش�.
	quickSort(Have, 0, N-1);

	/*
		�� ���� ���Ŀ� �ش� �迭�� ������� �� ���ĵ� ����� ���δ�.

		for (int i = 0; i < N; i++) {
		printf("%d", Have[i]);
		}	
	*/

	int lower;
	int upper;

	for (int i = 0; i < M; i++) {	//Compare�� ũ�� ��ŭ / But size�� Have�� ũ��
		lower = Lower_bound(Have, Compare[i], N);
		upper = Upper_bound(Have, Compare[i], N);
		int result = upper - lower;
		printf("%d ", result);
	}
}