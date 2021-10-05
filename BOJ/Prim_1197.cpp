#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int v, e, a, b;
long long c;

vector<pair<int, int>> edges[100001];
// or vector<vector<pair<int,int>>> edges 
int visited[10001];

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;



void prim(int start) {
	// 0번 노드 부터 시작. prim 알고리즘은 엣지가 아닌 노드부터 시작.
	// 어디서 시작하는지는 중요하지 않음.
	visited[start] = true;

	for (size_t i = 0; i < edges[start].size(); i++) {
		int next = edges[start][i].first;
		int key = edges[start][i].second;
		pq.push(make_pair(next, key));
	}

	int answer = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cur_key = pq.top().second;
		pq.pop();

		if (!visited[cur]) {
			visited[cur] = true;
			answer += cur_key;
			for (size_t i = 0; i < edges[cur].size(); i++) {
				int next = edges[cur][i].first;
				int key = edges[cur][i].second;
				pq.push(make_pair(next, key));
			}
		}

	}
	cout << answer;

}

int main() {

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	prim(1);
	return 0;
}