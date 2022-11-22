#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX 500

int N, M;
int item;
int ground[MAX][MAX];



int main() {
	scanf("%d %d %d", &N, &M, &item);
	// �Է¹޴� NM ��� ���� �� �ּҰ��� �ִ밪�� ��� ���� �ӽ� ����
	int max_height = 0;
	int min_height = 256;
	//int inventory = item;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ground[i][j]);
			
			if (ground[i][j] < min_height) {
				min_height = ground[i][j];
			}
			else if (ground[i][j] > max_height) {
				max_height = ground[i][j];
			}
		}
	}

	// �ݺ����� ���� N * M �ݰ��� ���� ���̸� �Է����־���,
	// max_height���� ���� ���� ������ ���̸�, min_height���� ���� ���� ������ ���̸� �־��־���.

	// min_height ~ max_height���� ���� ���� �޲ٰų� �İų� �ϴ� �۾��� �ݺ��غ���, ���� ���� �ð��� �ɸ��� ���̸� ���� ���̷� ��´�.

	int time = 0, min_Time = INT_MAX;
	int height_result = 256; // �ִ� ���� 256�̹Ƿ� �ٿ������� �����ظ� ã�´�
	// height_result = max_height �� �ξ ���������?

	for (int i = max_height; i >= min_height; i--) {
		time = 0;
		int inventory = item;

		// ���� ���� ���̺����� ���� ���� ���̺����� �������س��̸� �������ָ� NM����� ���� �۾����ֱ�
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				// ���� ���� ���� ���̿� ���غ��� Task(�޲ٱ�/�ı�)�� ���� �ݺ�����
				// ���� �ҿ� �ð��� ���� ���� �츮�� ���ؾ��� ���� ����
				int whatTask = ground[j][k] - i;
				// whatTask�� ���: i�� ���� ������ (whatTask ��ŭ)���� => ��� �ı� (�κ��丮 1 �߰�, �ð��� 2�� �ҿ�)
				// whatTask�� ����: i�� ���� ������ (whatTask ��ŭ)���� => ��� �޲ٱ� (�κ��丮 1 ����, �ð��� 1�� �ҿ�)

				if (whatTask < 0) {			// ��� �޲ٱ�
					time = time - whatTask;
					inventory += whatTask;	// whatTask�� �����ӿ� ����
				}
				else if (whatTask > 0) {	// ��� �ı�
					time = time + (2*whatTask);
					inventory += whatTask;
				}
			}
		}
		// ������ ���̷� Task�ݺ��ߴµ� �κ��丮�� ���ڸ���? --> �Ұ����� �������� ��
		if (inventory >= 0) {		// �κ��丮 ���ų� �� 0�϶�
			if (time < min_Time) {	//�ִܼҿ�ð� ã��
				min_Time = time;
				height_result = i;
			}
		}
	}

	printf("%d %d\n", min_Time, height_result);
	return 0;
}