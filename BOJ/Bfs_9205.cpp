#include<iostream>
#include<vector>
#include<queue>


using std::cout; using std::cin;
using std::vector;

vector<std::pair<int, int>> graph;

int t, n;
bool visited[101];

void bfs() {
	std::queue<std::pair<int, int>> que;

	int start_x = graph.begin()->first;
	int start_y = graph.begin()->second;

	que.push({ start_x,start_y });

	visited[0] = true;

	while (!que.empty()) {
		std::pair<int, int> cur = que.front();
		que.pop();

		// graph[n+1] �� �������� �佺Ƽ�� ��� ��ǥ pair(x,y)
		if (cur.first == graph[n + 1].first && cur.second == graph[n + 1].second) {
			cout << "happy" << '\n';
			return;
		}
		for (int i = 1; i <= n + 1; i++) {
			if (visited[i]) continue; // �̹� �湮 ������ 
			int distance = std::abs(graph[i].first - cur.first) + std::abs(graph[i].second - cur.second);
			if (distance <= 1000) { // �Ÿ��� 1000 ���� ��Ҹ� �߰�.
				que.push(graph[i]);
				visited[i] = true;
			}
		}
	}

}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n;
		int m = n + 2;
		while (m--) {
			int x, y;
			cin >> x >> y;
			graph.push_back({ x,y });
		}
		bfs();

		std::fill_n(visited, n + 2, false); // visited �迭 �ʱ�ȭ.
		graph.clear(); // �׷��� �ʱ�ȭ
	}


	return 0;
}

