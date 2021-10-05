#include <string>
#include <vector>
#include<queue>


using namespace std;


vector<pair<int, int>> nodes[101];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

bool visited[101];

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	
	for (size_t i = 0; i < costs.size(); i++) {
		int node1 = costs[i][0];
		int node2 = costs[i][1];
		int cost = costs[i][2];

		nodes[node1].push_back(make_pair(node2, cost));
		nodes[node2].push_back(make_pair(node1, cost));
	}

	// 0번째 노드 에서 부터 시작.
	for (int i = 0; i < nodes[0].size(); i++) {
		int key = nodes[0][i].second;
		int next = nodes[0][i].first;
		pq.push(make_pair(key, next));
	}
	visited[0] = true;

	while (!pq.empty()) {
		int distance = pq.top().second;
		int cur = pq.top().first;
		pq.pop();

		// 방문하지 않았으면은
		if (!visited[cur]) {
			visited[cur] = true;
			answer += distance;
			for (size_t i = 0; i < nodes[cur].size(); i++) {
				int next = nodes[cur][i].first;
				int key = nodes[cur][i].second;
				if (!visited[next])pq.push(make_pair(key, next));
			}
		}
	}


	return answer;
}
