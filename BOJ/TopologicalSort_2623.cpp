#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using std::cout; using std::cin;
using std::vector;

// 위상정렬 문제 DFS / BFS로 풀이 가능.

int N, M;
int a, b, c;
vector<int> adjancent[1001];
int indegree[1001];
int input[1001];

void topologicalSort() {
	vector<int> answer;
	std::queue<int> q;

	// indegree 가 0인 작업 넣는다.
	for (int i = 1; i < N + 1; i++) {
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		answer.push_back(cur);
		q.pop();
		for (size_t i = 0; i < adjancent[cur].size(); i++) {
			int next = adjancent[cur][i];
			if ((--indegree[next]) == 0) { // 하나 감소 시켰는데 indegree가 0이면 q에 푸쉬.
				q.push(next);
			}

		}
	}
	if (answer.size() != N) {
		cout << 0 << '\n';
		return;
	}
	for (auto elem : answer) {
		cout << elem << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// 입력 받기 부터 못하네 개 벌거지 같은놈.
	cin >> N >> M;
	while (M--) {
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> input[i];
		}
		for (int i = 0; i < a - 1; i++) {
			adjancent[input[i]].push_back(input[i + 1]);
			indegree[input[i + 1]]++;
		}
	}
	topologicalSort();

	return 0;
}

