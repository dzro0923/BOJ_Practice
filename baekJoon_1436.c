#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int count = 0;
	int number = 1;

	while (1) {
		// number�� �������� ���� ���� 666�� ���Ե� ��� count�� ������Ŵ
		// ���������� count�� N�� ������ ��� �ذ� ��.

		int check_6 = 0;
		int num = number;

		// ���� �ڸ������� �˻��Ͽ� 6�� 3�� ���ӵǴ��� Ȯ���ϱ�
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