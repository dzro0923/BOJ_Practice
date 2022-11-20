#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int count = 0;
	int number = 1;

	while (1) {
		// number를 증가시켜 가는 도중 666이 포함될 경우 count를 증가시킴
		// 최종적으로 count가 N과 같아질 경우 해가 됨.

		int check_6 = 0;
		int num = number;

		// 수를 자릿수별로 검사하여 6이 3번 연속되는지 확인하기
		while (num > 0) {
			int digit = num % 10;
			if (digit == 6)
				check_6++;
			else {
				check_6 = 0;
			}

			if (check_6 == 3) {
				count++;
				break;
			}
			num = num / 10;
		}

		if (count == N) {
			break;
		}
		number++;
	}
	printf("%d\n", number);
}