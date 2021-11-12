#include<iostream>
#include<vector>
#include<queue>

constexpr auto INF = 1234567;

using std::cout; using std::cin;
using std::vector; using std::pair;


// < Prim >

int n, m, a, b, c;

vector<std::pair<int, int>> adjancent[1001];

bool visited[1001]; // ¼±ÅÃ µÆ´ÂÁö.
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) const {
		return a.second > b.second;
	}
};

int prim(int start) {
	int answer = 0;
	std::priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	visited[start] = true;

	for (auto elem : adjancent[start]) {
		int start = elem.first;
		int start_key = elem.second;
		pq.push({ start,start_key });
	}

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		if (!visited[cur]) {
			visited[cur] = true;
			answer += cur_cost;
			for (size_t i = 0; i < adjancent[cur].size(); i++) {
				int next = adjancent[cur][i].first;
				int next_key = adjancent[cur][i].second;
				if (visited[next]) continue;
				pq.push({ next,next_key });
			}
		}

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