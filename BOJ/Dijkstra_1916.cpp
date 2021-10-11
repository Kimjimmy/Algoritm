#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::pair; using std::vector;

int n, m;
int u, v, p;

const int INF = 987654321;
int d[1001];


struct Edge {
	int dest;
	int cost;
	Edge(int _dest, int _cost) :dest(_dest), cost(_cost) {}
	bool operator<(const Edge& e)const {
		return cost > e.cost;
	}
};

vector<Edge> edges[100001];

void dijkstra(int start,int dest) {
	int answer = 0;
	std::priority_queue<Edge, vector<Edge>> pq;
	pq.push(Edge(start,0));
	d[start] = 0;


while (!pq.empty()) {
		int cur = pq.top().dest;
		int cur_cost = pq.top().cost;
		pq.pop();

		if (cur == dest) {
			cout << cur_cost;
			return;
		}

		// relax 해준 노드면 무시.
		if (d[cur] < cur_cost)continue;

		for (auto elem : edges[cur]) {
			int next = elem.dest;
			int next_cost = elem.cost;
			if (d[next] > d[cur] + next_cost) {
				d[next] = d[cur] + next_cost;
				pq.push(Edge(next, d[next]));
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	std::fill_n(d+1, n, INF);
	while (m--) {
		cin >> u >> v >> p;
		edges[u].push_back(Edge(v, p));
	}
	int x, y;
	cin >> x >> y;
	dijkstra(x, y);

	return 0;
}
