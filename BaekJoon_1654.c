/*
   영식이가 기존에 가지고 있던 K 개의 랜선,
   ( 이 때, K 개의 랜선의 길이는 입력받는다. )

   성원이는 영식이가 가진 길이가 제각각인 K개의 랜선을 같은 길이의 N개로 만들기를 원한다.

   만들 수 있는 최대 랜선의 길이를 구하라.

   즉, N개의 개수가 나오는 한에서의 K개의 랜선의 최장 길이를 구하라.


   4 11
   802
   743
   457
   539

   => 200
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_K 10001
long long have[MAX_K];
int K, N;      // 가지고 있는 랜선의 개수와, 랜선을 이용하여 나눌 랜선의 개수

long long low, high, mid;      // 이분 탐색 위한 매개변수
long long result;            // 출력값(정답)

int main() {
    //printf("가지고 있는 랜선과, 해당 랜선들을 이용하여 몇 개로 분할하고 싶으신가요 : ");
    long long max_have = 0;

    // 가지고 있는 랜선의 개수 K 입력받기
    scanf("%d %d", &K, &N);

    //printf("랜선의 길이를 각각 입력해주세요! ");


    for (int i = 0; i < K; i++) {
        scanf("%lld", &have[i]);

        // K개의 랜선 중 가장 큰 값을 max_have에 삽입
        if (max_have < have[i])
            max_have = have[i];
    }

    low = 1; // K는 1 이상이라는 조건
    high = max_have;

    result = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        // 랜선을 자르고 나눈 개수를 담을 변수 (N과의 비교)
        int cnt = 0;

        // 중간값으로 모든 랜선들을 나눈 몫을 cnt에 더해준다.
        for (int i = 0; i < K; i++) {
            cnt += have[i] / mid;
        }

        // 더 많이 or 같다
        // 조건 충족 혹은 더 크게 자를 수 있을 때
        if (cnt >= N) {
            low = mid + 1;

            // 가능한 한 가장 큰 길이를 결과값으로 내기 위해
            // mid 값을 result에 넣어줌
            // while 문 끝났을 때에는 result에 N개의 개수를 충족시키는 가장 큰 수가 들어가 있다.
            if (result < mid)
                result = mid;
        }
        else {   // cnt < N 개수 충족 못했을 때
            high = mid - 1;
        }
    }

    printf("%lld\n", result);
    return 0;
}