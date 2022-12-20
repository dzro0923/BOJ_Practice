/*
	루트 없는 트리가 주어진다.
	트리의 루트를 1이라고 정했을 때 각 노드의 부모를 구하는 프로그램 

	N : (>= 100000) 노드의 개수
	N-1 개의 줄에 트리 상에서 연결된 정점을 주어준다.

	출력 : 첫 줄부터 N-1개 줄에 각 노드의 부모 노드를 2번 노드부터 순서대로 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int s, e;

queue<int> q;
vector<vector<int>> adjArray;
vector<int> visited;
vector<int> result;

void aDFS(int v) {
	visited[v] = 1;
	//result[v] = v;  --> 그림 그려본 결과, 이 문장 있으면 모든 노드가 자기 자신 가리킴 miss,,
	for (int i = 0; i < adjArray[v].size(); i++) {
		int x = adjArray[v][i];
		if (visited[x] == 0) {
			result[x] = v;
			aDFS(x);
		}
	}
}

void DFS() {
	for (int v = 1; v <= N; v++) {
		visited[v] = 0;
	}

	for (int v = 1; v <= N; v++) {
		if (visited[v] == 0) {
			aDFS(v);
		}
	}
}

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	adjArray.resize(N + 1);
	visited.resize(N + 1);
	result.resize(N + 1);

	for (int i = 1; i < N; i++) {
		cin >> s >> e;
		AddEdge(s, e);
	}
	
	DFS();

	for (int i = 2; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}