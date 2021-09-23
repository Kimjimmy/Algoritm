#include<iostream>
#include<queue>
#include<vector>

using std::cin;
using std::cout;

int n, m, k;
int a, b;
std::vector<std::vector<int>> adjacent{ 10001, };
int visited[10001];
std::queue<int> que;

void Bfs(int start) {
	que.push(start);
	visited[start]++;
	
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		for (int i = 0; i < adjacent[current].size(); i++) {
			int next = adjacent[current][i];
			if (visited[next]==-1) {
				que.push(next);
				visited[next] = visited[current] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	
	std::fill_n(visited, n + 1, -1);

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	Bfs(k);
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}