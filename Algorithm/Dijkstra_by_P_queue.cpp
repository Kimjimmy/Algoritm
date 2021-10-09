#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cin; using std::cout;
using std::vector;

int v, e, k;
int start, end, w;
const int INF = 999999;
vector<vector<std::pair<int, int>>> edge;
int d[20001];
int prev[20001];

struct cmp {
	bool operator()(std::pair<int,int> a ,std::pair<int,int> b	){
		return a.second > b.second;
	}
};

void Dijkstra(int start) {
	std::priority_queue<std::pair<int,int>,vector<std::pair<int,int>>,cmp> pq;
	d[start] = 0;
	
	pq.push(std::make_pair(start, 0));

	while (!pq.empty()) {
		int cur =pq.top().first;
		int d_cur = pq.top().second;
		pq.pop();
		
		// 현재 노드가 이미 처리된 적 있는 노드면 다음 노드.
		if (d[cur] < d_cur)continue;  // 여기를 생각을 못했었네.. 블로그 <알고리즘 - '그래프 문제유형'> 에 관련 내용 적어놓았음.

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int next_dist = edge[cur][i].second;

			if (d[next] > d[cur] + next_dist) {
				d[next] = d[cur] + next_dist;
				prev[next] = cur;
				pq.push(std::make_pair(next, d[next]));
			}
		}
	}

}
void printPath(int s, int t) {
	if (prev[t] == -1) {
		return;
	}
	printPath(s, prev[t]);
	cout << t << " >> ";
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); std::cout.tie(nullptr);


	cin >> v >> e >> k;
	edge.resize(v+1);
	std::fill_n(d + 1, v, INF);   // 아니면 v+1 해보기.

	std::fill_n(prev+1, v, -1);
	
	for (int i = 0; i < e; i++) {
		cin >> start >> end >> w;
		edge[start].push_back(std::make_pair(end, w));
	}
	Dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}

	cout << k << " >> ";
	printPath(k, 4);




	return 0;
}