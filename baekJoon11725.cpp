/*
	��Ʈ ���� Ʈ���� �־�����.
	Ʈ���� ��Ʈ�� 1�̶�� ������ �� �� ����� �θ� ���ϴ� ���α׷� 

	N : (>= 100000) ����� ����
	N-1 ���� �ٿ� Ʈ�� �󿡼� ����� ������ �־��ش�.

	��� : ù �ٺ��� N-1�� �ٿ� �� ����� �θ� ��带 2�� ������ ������� ����Ѵ�.
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
	//result[v] = v;  --> �׸� �׷��� ���, �� ���� ������ ��� ��尡 �ڱ� �ڽ� ����Ŵ miss,,
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