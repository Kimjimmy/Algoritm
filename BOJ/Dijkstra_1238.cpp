#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cin;
using std::cout;
using std::vector;

int n, m, x;
int u, v, dist;
const int INF = 99999;
vector<std::pair<int, int>> edges[1001];
int d[1001][1001]; // start ���� target ������ �ִ� �Ÿ� ������ �迭.
int answer[1001] ; // ���� ���� ������ �迭.

struct cmp {
	bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
		return a.second > b.second;
	}
};

void input() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> dist;
		edges[u].push_back(std::make_pair(v, dist));
	}
}
void Dijkstra(int start) {

	//std::fill_n(d, 1001 * 1001, INF);  // ó���� �̷��� �ؼ� ����.
	std::fill(&d[start][1], &d[start][n+1], INF);
	std::priority_queue<std::pair<int, int>,vector<std::pair<int,int>>,cmp> pq;

	d[start][start] = 0;
	pq.push({ start,0 });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cur_d = pq.top().second;
		pq.pop();

		if (start != x && cur == x) {  // ���Ⱑ Key Point!!
			answer[start] += cur_d;
			break;
		}
		if (d[start][cur] < cur_d ) continue; // �̹� relax �� ���� �ǳ� ��.

		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].first;
			int next_dist = edges[cur][i].second;

			if (d[start][next] > d[start][cur] + next_dist) {
				d[start][next] = d[start][cur] + next_dist;
				pq.push(std::make_pair(next, d[start][next]));
				
			}
		}
	}

}

void solve() {
	input();

	for (int i = 1; i <= n; i++) { // ��� ��忡 ���ؼ�
		Dijkstra(i);
	}

	for (int i = 1; i <= n; i++) {
		answer[i] += d[x][i];
	}

	cout << *std::max_element(answer+1, answer+1+n);
	
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solve();

	return 0;
}