/*
	���� �ִܰŸ�

	������ �־����� ��, ��� ������ ���� ��ǥ���������� �Ÿ� ���ϱ�
	(����, ���ηθ� �̵� ���� / ����: N*M_maximum1000)

	���̳��� ���α׷������� Ǯ�� �������� ������?
	=> X, BFS�� Ž���ϱ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility> // ť�� ���� ����ü�� int, int ���� pair�� �̷� �� �ֵ���
#include <algorithm>

using namespace std;
int N, M;
int map[1001][1001];
int result[1001][1001]; // �� ��ġ�� ��ǥ������ �ִܰŸ��� ��� 2���� �迭
int dx[4] = { 0,0,1,-1 }; // x ��ǥ
int dy[4] = { 1,-1,0, 0 }; // y ��ǥ
// ����ġ�� ��������
// +(0,1): �Ʒ��� �� ĭ  /  +(0,-1): ���� �� ĭ  /  +(1,0): �����ʷ� �� ĭ  /  +(-1,0): �������� �� ĭ

queue<pair<int, int>> Queue;
// �� ��Ҹ� Queue.first�� Queue.second�� ���� ����

int main() {
	scanf("%d %d", &N, &M); // N*M ���� �Է¹ޱ�

	// result�� -1�� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result[i][j] = -1;
		}
	}

	/*
		* 0: �� �� ���� ��  / 1: �� �� �ִ� ��  / 2: ��ǥ ����
		*
		���̳��� ���α׷����� �����ϱ� ��,
		�� �� ���� ���� ��ġ�� 0�� ����ϰ�,
		���� �� �� �ִ� ���� �κ� �߿��� ������ �� ���� ��ġ�� -1�� ����Ѵٴ� ���� �������.

		���� �� �� �ִ� ���� �κ� �߿��� ������ �� ����
	*/

	// ������ ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			// �Է¹޴� map�� ���Ұ� 2, �� ��������� result�� 0����
			if (map[i][j] == 2) {
				Queue.push({ i,j });
				result[i][j] = 0;
			}
		}
		// �� �������� result�� ��ǥ:0�� ���� ������ �κ��� -1�� �Ǿ�����.
	}

	// BFS ���ֱ�
	while (!Queue.empty()) {
		int current_X = Queue.front().first;
		int current_Y = Queue.front().second;

		Queue.pop();

		// ����ġ�κ��� �����¿��� ��ȸ�غ�.
		for (int i = 0; i < 4; i++) {
			int nx = current_X + dx[i];
			int ny = current_Y + dy[i];

			// �����¿� ��ȸ�ϸ� ������ ����� ��� continue
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			
			// �̹� �湮�ߴ�(-1 �� �ƴ�) ��ġ�̰ų�, �湮�� ���� ������ �� �� ���� ���̶�� continue
			if (map[nx][ny] == 0 || result[nx][ny] != -1)
				continue;

			// �Ÿ� 1 ���� _ ����ġ(�Ÿ�)�� 1�� �����̱� ����
			result[nx][ny] = result[current_X][current_Y] + 1;
			Queue.push({ nx, ny });

		}
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				printf("0 ");
			else {
				printf("%d ", result[i][j]);
			}
		}
		printf("\n");
	}
}