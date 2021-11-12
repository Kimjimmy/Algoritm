#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

constexpr auto INF = 1234567;

using std::cout; using std::cin;
using std::vector;


// < Prim >
// 모든 노드의 key값과 selected 값을 초기화한다.

int n, m, a, b, c;

vector<std::pair<int, int>> adjancent[1001];
int key[1001];  // key 값
bool selected[1001]; // 선택 됐는지.


int prim(int start) {
	int answer = 0;

	// 모든 노드의 key값과 selected 값을 초기화한다.
	std::fill_n(key, n + 1, INF);

	// 시작점을 시작으로 선택 시작
	// key 값은 0으로 selected는 true 로
	key[start] = 0;
	selected[start] = true;

	// 모든 노드들이 선택될 때까지.
	int cnt = 1;
	int cur = start;
	while (cnt <= n - 1) {
		// 선택된 노드의 인접한 노드의 key값 변경 해주기.
		int next, cost;
		for (size_t i = 0; i < adjancent[cur].size(); i++) {

			next = adjancent[cur][i].first;
			cost = adjancent[cur][i].second;

			if (selected[next])continue;
			if (key[next] > cost) {
				key[next] = cost;
			}
		}
		// 아직 선택되지 않은 노드들 중에 key값이 가장 작은 노드 선택.
		int min_cost = INF;
		int min_idx = -1;
		for (size_t i = 1; i <= n; i++) {
			if (selected[i])continue;
			if (min_cost > key[i]) {
				min_cost = key[i];
				min_idx = i;
			}
		}
		cnt++; // 선택 됐으니깐 cnt 증가.
		answer += min_cost;
		selected[min_idx] = true;
	}

	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		adjancent[a].push_back({ b,c });
		adjancent[b].push_back({ a,c });
	}

	cout << prim(1);

	return 0;
}