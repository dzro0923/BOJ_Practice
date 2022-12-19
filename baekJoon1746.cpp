/*
	N개, M개의 문자열을 각각 비교하여

	두 집단에 모두 속하는 문자열의 개수와 그 문자열을 정렬된 상태로 출력하기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>	// 각 500000개가 될 수 있는 N,M개의 문자열을 가변길이 문자열로서 표현하기 위함
#include <algorithm>	// 결과 벡터를 정렬하여 표시하기 위함

using namespace std;
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	vector<string> result;	// 마지막에 sort(result.begin(), result.end()); 를 이용해 정렬된 형태로 출력해줄 것임
	vector<string> non_heard_name;
	non_heard_name.resize(N);	// 런타임에러 방지하기 위해 미리 사이징해주기
	
	char temp[21]; // 여기에 넣어줬다가 non~ 가변길이 벡터에 넣어줄 것임 중간단계 위한 변수


	// 들어본 적 없는 인원 명단
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		non_heard_name[i] = temp;
	}
	sort(non_heard_name.begin(), non_heard_name.end()); // 이진탐색을 하려면 해당 탐색물이 정렬된 상태여야 한다.
	// 시간 복잡도를 위한 이진탐색
	// binary_search(a, b, c);  --> a : 시작 / b: 끝 / c: 찾고자 하는 것

	// 본 적 없는 인원 명단을 입력받음과 동시에 non_heard_name 명단에 존재하는 이름인지 비교해보기.
	for (int i = 0; i < M; i++) {
		scanf("%s", temp);
		if (binary_search(non_heard_name.begin(), non_heard_name.end(), temp)) {	// non_heard_name 명단에 존재한다면.
			result.push_back(temp); // result 가변배열에 집어넣어라.
		}
	}
	sort(result.begin(), result.end()); // 정렬된 상태로 출력해주기 위한 sort
	//cout << result.size() << '\n';
	printf("%d\n", result.size());

	for (int i = 0; i < result.size(); i++) {
		//cout << result[i] << '\n';
		printf("%s\n", result[i].c_str());
	}

}