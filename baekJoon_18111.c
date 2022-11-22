#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX 500

int N, M;
int item;
int ground[MAX][MAX];



int main() {
	scanf("%d %d %d", &N, &M, &item);
	// 입력받는 NM 행렬 원소 중 최소값과 최대값을 얻기 위한 임시 변수
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

	// 반복문을 통해 N * M 반경의 지대 높이를 입력해주었고,
	// max_height에는 가장 높은 지대의 높이를, min_height에는 가장 낮은 지대의 높이를 넣어주었다.

	// min_height ~ max_height까지 전부 땅을 메꾸거나 파거나 하는 작업을 반복해보고, 가장 적은 시간이 걸리는 높이를 기준 높이로 삼는다.

	int time = 0, min_Time = INT_MAX;
	int height_result = 256; // 최대 높이 256이므로 줄여나가며 최적해를 찾는다
	// height_result = max_height 로 두어도 상관없을까?

	for (int i = max_height; i >= min_height; i--) {
		time = 0;
		int inventory = item;

		// 가장 낮은 높이블럭부터 가장 높은 높이블럭까지 최종기준높이를 변경해주며 NM행렬을 돌며 작업해주기
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				// 땅을 가장 낮은 높이와 비교해보며 Task(메꾸기/파기)를 정해 반복해줌
				// 최종 소요 시간이 적은 것이 우리가 정해야할 기준 높이
				int whatTask = ground[j][k] - i;
				// whatTask가 양수: i가 현재 층보다 (whatTask 만큼)낮음 => 블록 파기 (인벤토리 1 추가, 시간은 2초 소요)
				// whatTask가 음수: i가 현재 층보다 (whatTask 만큼)높음 => 블록 메꾸기 (인벤토리 1 감소, 시간은 1초 소요)

				if (whatTask < 0) {			// 블록 메꾸기
					time = time - whatTask;
					inventory += whatTask;	// whatTask가 음수임에 유의
				}
				else if (whatTask > 0) {	// 블록 파기
					time = time + (2*whatTask);
					inventory += whatTask;
				}
			}
		}
		// 설정된 높이로 Task반복했는데 인벤토리가 모자르다? --> 불가능한 행위였던 것
		if (inventory >= 0) {		// 인벤토리 남거나 딱 0일때
			if (time < min_Time) {	//최단소요시간 찾기
				min_Time = time;
				height_result = i;
			}
		}
	}

	printf("%d %d\n", min_Time, height_result);
	return 0;
}