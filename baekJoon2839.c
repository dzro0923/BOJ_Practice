/*
	상근이가 설탕 배달을 한다.
	설탕을 N 킬로그램 배달해야 하는데, 봉지는 3킬로그램과 5킬로그램 봉지가 있다.

	예를 들어 N = 18kg 일 때, 
	(5킬로 * 3 + 3킬로) or (3킬로 * 6 ) 중에 선택할 수 있는 것
	더 적은 개수의 봉지를 이용하는 것.

	만약 정확하게 N 킬로그램을 만들 수 없다면 -1 출력하기

*/

/*
	더 무거운 킬로그램으로 먼저 나누는 그리디한 알고리즘으로 풀 수 있을 것이다.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 3 <= N <= 5000
int N;

int main() {
	//printf("몇 킬로그램의 설탕을 운반할까요? :  ");
	scanf("%d", &N);
	int sugar = N;
	int count = 0;

	/*
		while문을 통해서 직접 N과 무게비교를 통해 
		5로 나뉘어질 때는 5를 빼고, 아니면 3을 빼는 식으로 접근 시
		런타임 에러가 발생.

		런타임을 줄일 수 있는 방법이 있을까?

		N은 무조건 3이상이다.
		크게 보았을 때 N = 18이면 3kg * 6, 6봉지가 아닌,
		5kg 3봉지에 3kg 1봉지가 되는 식의 항상 5kg 봉지가 우선시 되는 것을 볼 수 있다.

	
		N이 15, 20등 5의 배수일 경우 볼 것도 없이 N/5가 된다.	
	*/

	while (sugar >= 0) {
		if (sugar % 5 == 0) {	// 5로 나누어 떨어지는, 즉 N이 5의 배수일 경우
			count += sugar / 5;
			printf("%d\n", count);
			break;
		}
		else {
			sugar = sugar - 3;
			count++;

			if (sugar < 0) {
				printf("-1");
				break;
			}
		}
	}
	return 0;
}
