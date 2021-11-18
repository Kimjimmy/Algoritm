#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using std::cout; using std::cin;
using std::vector;
int N;
vector<vector<int>> graph;

const int INF = 987654321;

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	cin >> N;
	graph.resize(N);

	// 입력 받으면서 초기화. dp 초기화.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 0) {
				graph[i].push_back(INF);
			}
			else {
				graph[i].push_back(a);
			}
		}
	}
	floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}

