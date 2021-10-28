#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::vector;

int n, m;
vector<int> friends[101];
int visited[101];
int answer[101];

void dfsAll(int start) {
	std::queue<int> que;
	que.push(start);
	visited[start]++;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (size_t i = 0; i < friends[cur].size(); i++) {
			int next = friends[cur][i];
			if (visited[next] < 0) {
				que.push(next);
				visited[next] = visited[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		answer[start] += visited[i];  // ��¥�� �ڱ� �ڽ��� ���� 0�̶� �����൵ �������.
	}
}
void resetVisited() {
	std::fill_n(visited + 1, n, -1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	int x, y;
	while (m--) {
		cin >> x >> y;
		friends[x].push_back(y);
		friends[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) { // ��� ��忡 ���ؼ� DFS
		resetVisited(); // visited �ʱ�ȭ
		dfsAll(i);
	}
	cout << std::min_element(answer + 1, answer + 1 + n) - answer;
	return 0;
}