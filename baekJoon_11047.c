#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, K;	// N:동전의 종류, K:동전을 조합해 만들 가치의 총합
int A[10];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int count = N - 1;
	int result = 0;

	while (K > 0) {
		if (A[count] > K) {
			count--;
		}
		else {
			K = K - A[count];
			result++;
		}
	}

	printf("%d", result);
}
