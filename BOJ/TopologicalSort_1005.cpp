#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::vector;

int N, K, W;
vector<int> graph[1001];
int time[1001];
int result_time[1001];
int indegree[1001];


void solve(int W) {

	std::queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			que.push(i);
			result_time[i] = time[i];
		}
	}

	while (!que.empty()) {
		int cur = que.front();

		if (cur == W) { // 목적지 도착.
			cout << result_time[cur] << '\n';
			return;
		}
		que.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (result_time[next] < result_time[cur] + time[next]) {
				result_time[next] = result_time[cur] + time[next];
			}

			indegree[next]--;

			if (indegree[next] == 0) {
				que.push(next);
			}
		}
	}

}
void initiate() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}
	std::fill_n(time + 1, N, 0);
	std::fill_n(result_time + 1, N, 0);   // +1 안해주면 틀린다... 고생 좀 했다..
	std::fill_n(indegree + 1, N, 0);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}
		while (K--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		cin >> W;

		solve(W);
		initiate();
	}
	return 0;
}