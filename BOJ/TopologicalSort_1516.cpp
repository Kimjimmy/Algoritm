#include<iostream>
#include<vector>
#include<queue>



using std::cin; using std::cout; using std::vector;

int n;
vector<std::pair<int, int>> adjacent[501];
int indegree[501];
int time[501], result[501];
std::queue<int> que;

void topologicalSort() {
	// 모든 노드에 대해서	
	for (int i = 1; i < n; i++) {
		if (indegree[i] == 0) {
			que.push(i);
			result[i] = time[i];
		}
	}

	// 모든 노드에 대해서 ( 정확히 n 번 돌면서 )
	for (int i = 1; i <= n; i++) {
		int cur = que.front();
		que.pop();
		for (size_t j = 0; j < adjacent[cur].size(); j++) {
			int next = adjacent[cur][j].second;
			result[next] = std::max(result[next], result[cur] + time[next]);
			if (--indegree[next] == 0) {

				que.push(next);
			}
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);

	cin.tie(nullptr);

	int x;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		cin >> x;
		while (x != -1) {

			adjacent[x].push_back(std::make_pair(time[i], i));
			indegree[i]++;
			cin >> x;
		}
	}

	topologicalSort();

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}