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
vector<int> p;			// ���տ��� �θ���
vector<int> ranks;		// ���տ��� rank
vector<Edge> result;	// ũ�罺Į �˰����� ����� ����(���õ� ������)

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


	// ������ (��� ���� - 1) ���� �Ǿ��� �� ����Ŭ�� ���� Ʈ���� �������
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

	// �׽�Ʈ Ƚ���� ����
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		// ��� ������ ����
		cin >> N;

		// N * N �� �Է��� �޴´�.
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

