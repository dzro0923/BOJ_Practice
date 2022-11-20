/*
	체스판 다시 칠하기

	입력받는 체스판의 크기는 N*M
	입력받는 크기 중 아무데서나 골라서 8*8 사이즈의 Black/White가 정렬된 체스판을 만들어야 한다.

	결론적으로 색칠을 마친 체스판은 첫 블록의 색이 
	Black인 것과, White인 것으로 나뉘게 된다.

	결과적으로 나올 수 있는 두  종류의 체스판과 내가 골라서 8*8로 나눈 체스판의 다른 부분의 개수(최솟값)를 출력해줘야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;	// 체스판의 크기
char board[51][51];


// 나올 수 있는 최종 두 가지 유형의 체스판의 초기화
// 최상단 좌측의 요소가 'B'인 것과 'W'인 것만이 가능




char board_B[8][8] = { {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'} };

char board_W[8][8] = { {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'},
			   {'W','B','W','B','W','B','W','B'},
			   {'B','W','B','W','B','W','B','W'} };

int ckeck_Black(int a, int b);
int check_White(int a, int b);

int main(void) {
	//printf("체스판의 크기를 입력해 주세요 \n"); // 입력받을 체스판의 크기 : N * M
	scanf("%d %d", &N, &M);

	//체스판의 각 보드는 B, W 중 하나의 '문자'로 이루어져있다.
	//체스판의 입력
	//printf("체스판의 요소를 입력해주세요: \n");

	for (int i = 0; i < N; i++) {
		scanf("%s", &board[i]);
	}
	

	int min = N*M;
	// 8 * 8 크기로 자르고, 칠해야 하는 개수의 최솟값 찾기
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int num_B = 0;
			int num_W = 0;

			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (board_B[k][l] != board[i + k][j + l])
						num_B++;
					if (board_W[k][l] != board[i + k][j + l])
						num_W++;
				}
			}
			if (min > num_B)
				min = num_B;
			if (min > num_W)
				min = num_W;
		}
	}
	printf("%d", min);
}