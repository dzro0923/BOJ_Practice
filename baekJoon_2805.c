#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N, M;
long long low, high, mid;
long long max_tall;
long long result;
long long* Tree;

int main() {
	scanf("%d %d", &N, &M);
	Tree = (long long*)malloc(N * sizeof(long long));

	long long tallest_Tree = 0;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &Tree[i]);
		
		if (tallest_Tree < Tree[i])
			tallest_Tree = Tree[i];
	}

	low = 1;
	high = tallest_Tree;
	max_tall = 0;
	

	while (low <= high) {

		// mid 값으로 나무들을 잘라줄 것임(절단기 높이)
		mid = (low + high) / 2;

		// 각각의 나무를 베어서 남은 값을  result에 넣어줌
		for (int i = 0; i < N; i++) {
			if (Tree[i] > mid)
				result += (Tree[i] - mid);
		}

		if (result < M) {
			high = mid - 1;
		}
		else {
			if (max_tall < mid) {
				max_tall = mid;
			}
			low = mid + 1;
		}
		result = 0;

	}

	printf("%lld", max_tall);
	free(Tree);
	return 0;
}