/*
	쉬운 최단거리

	지도가 주어졌을 때, 모든 지점에 대해 목표지점까지의 거리 구하기
	(가로, 세로로만 이동 가능 / 지도: N*M_maximum1000)

	다이나믹 프로그래밍으로 풀이 가능하지 않을까?
	=> X, BFS로 탐색하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility> // 큐에 들어가는 구조체가 int, int 형의 pair를 이룰 수 있도록
#include <algorithm>

using namespace std;
int N, M;
int map[1001][1001];
int result[1001][1001]; // 각 위치별 목표까지의 최단거리를 담는 2차원 배열
int dx[4] = { 0,0,1,-1 }; // x 좌표
int dy[4] = { 1,-1,0, 0 }; // y 좌표
// 현위치를 기준으로
// +(0,1): 아래로 한 칸  /  +(0,-1): 위로 한 칸  /  +(1,0): 오른쪽로 한 칸  /  +(-1,0): 왼쪽으로 한 칸

queue<pair<int, int>> Queue;
// 각 요소를 Queue.first와 Queue.second로 접근 가능

int main() {
	scanf("%d %d", &N, &M); // N*M 지도 입력받기

	// result를 -1로 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result[i][j] = -1;
		}
	}

	/*
		* 0: 갈 수 없는 땅  / 1: 갈 수 있는 땅  / 2: 목표 지점
		*
		다이나믹 프로그래밍을 적용하기 전,
		갈 수 없는 땅인 위치는 0을 출력하고,
		원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다는 것을 기억하자.

		원래 갈 수 있는 땅인 부분 중에서 도달할 수 없다
	*/

	// 지도의 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			// 입력받는 map의 원소가 2, 즉 목적지라면 result를 0으로
			if (map[i][j] == 2) {
				Queue.push({ i,j });
				result[i][j] = 0;
			}
		}
		// 이 시점에서 result는 목표:0을 제외 나머지 부분은 -1이 되어있음.
	}

	// BFS 해주기
	while (!Queue.empty()) {
		int current_X = Queue.front().first;
		int current_Y = Queue.front().second;

		Queue.pop();

		// 현위치로부터 상하좌우을 순회해봄.
		for (int i = 0; i < 4; i++) {
			int nx = current_X + dx[i];
			int ny = current_Y + dy[i];

			// 상하좌우 순회하며 범위가 벗어나는 경우 continue
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			
			// 이미 방문했던(-1 이 아닌) 위치이거나, 방문한 적이 없더라도 갈 수 없는 길이라면 continue
			if (map[nx][ny] == 0 || result[nx][ny] != -1)
				continue;

			// 거리 1 증가 _ 가중치(거리)는 1로 고정이기 때문
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