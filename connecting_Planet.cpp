#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N;
const int MAX = 1000;
int planet[MAX][MAX];

typedef struct {
	int start;
	int end;
	int weight;
} Edge;

bool operator>(Edge a, Edge b) {
	return (a.weight > b.weight);
}

priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;


int n, m;
int s, e, w;
vector<int> p;			// 집합에서 부모노드
vector<int> ranks;		// 집합에서 rank
vector<Edge> result;	// 크루스칼 알고리즘의 결과를 저장(선택된 간선들)

void Make_Set(int x) {
	p[x] = x;
	ranks[x] = 0;
}

int Find_Set(int x) {
	if (p[x] != x)
		p[x] = Find_Set(p[x]);

	return p[x];
}

void Union(int x, int y) {
	int x1 = Find_Set(x);
	int y1 = Find_Set(y);

	if (ranks[x1] > ranks[y1])
		p[y1] = x1;
	else {
		p[x1] = y1;
		if (ranks[x1] == ranks[y1])
			ranks[y1] == ranks[y1] + 1;
	}
}

void Kruskal() {
	for (int i = 1; i <= N; i++)
		Make_Set(i);


	// 간선이 (노드 개수 - 1) 개가 되었을 때 사이클이 없는 트리가 만들어짐
	while (result.size() < N - 1) {
		int start = minHeap.top().start;
		int end = minHeap.top().end;

		if (Find_Set(start) != Find_Set(end)) {
			Union(start, end);
			result.push_back(minHeap.top());
		}
		minHeap.pop();
	}
}

int main() {

	// 테스트 횟수를 설정
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		// 노드 개수의 설정
		cin >> N;

		// N * N 의 입력을 받는다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> planet[i][j];
			}
		}


		p.resize(N + 1);
		ranks.resize(N + 1);

		Edge edge;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				edge.start = i + 1;
				edge.end = j + 1;
				edge.weight = planet[i][j];

				minHeap.push(edge);
			}
		}


		Kruskal();

		int cost = 0;
		for (int i = 0; i < result.size(); i++) {
			cost += result[i].weight;
		}

		cout << "Total Cost: " << cost << endl;

		while (!minHeap.empty()) {
			minHeap.pop();
		}
		
		p.clear();
		ranks.clear();
		result.clear();
	}
	return 0;
}

