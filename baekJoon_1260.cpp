#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m; // ���� vertex�� ������ edge�� ����
int s, e; // ���� ���� ������ �� ���� ==> ���� �մ� ���� ���ȴ�.
int v; // Ž�� �����ϴ� ����

vector<vector<int>> adjArray; // vector - vector�� ����
vector<int> visited;  // DFS
vector<int> visited2; // BFS	
queue<int> q;// BFS�� Ȱ���� ť

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}


/*
void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		for (int j = 0; j < adjArray[i].size(); j++)
			cout << adjArray[i][j] << " ";

		cout << endl;
	}
}
*/

void aDFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 0; i < adjArray[v].size(); i++) {
		int x = adjArray[v][i];
		if (visited[x] == 0)
			aDFS(x);
	}
}

void DFS(int v) {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}

	if (visited[v] == 0)
		aDFS(v);
}

void BFS(int s) {
	
	for (int i = 1; i <= n; i++)
		visited2[i] = 0;

	visited2[s] = 1;
	cout << s << " ";
	q.push(s);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i<adjArray[u].size(); i++) {
			int x = adjArray[u][i];
			if (visited2[x] == 0) {
				visited2[x] = 1;
				cout << x << " ";
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m >> v;
	adjArray.resize(n + 1);
	visited.resize(n + 1);
	visited2.resize(n + 1);

	for (int i = 0; i < m;  i++) {
		cin >> s >> e;
		AddEdge(s, e);
	}
	

	for (int i = 1; i <= n; i++) {
		sort(adjArray[i].begin(), adjArray[i].end());
	}

	DFS(v);
	cout << '\n';
	BFS(v);

	return 0;
}