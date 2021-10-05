#include<iostream>
#include<vector>
#include<algorithm>

// < Kruskal>
// 1.공집합에서 시작
// 2. make-set
// 3. 엣지들 오름차순 정렬
// 4. n-1이 될때까지 find- union 반복.

using std::cin;
using std::vector;



struct Edge {
	int node[2];
	int cost;
	Edge(int a, int b, int _cost) :cost(_cost) {
		node[0] = a;
		node[1] = b;
	}
	bool operator<(const Edge& edge) const{
		return cost < edge.cost;
	}
};

int n, m, a, b, c;
vector<Edge> edges;
int parent[1001];
int tree_size[1001];

int findSet(int x) {
	if (parent[x] != x) {
		parent[x] = findSet(parent[x]);
	}
	return parent[x];
}
void Union(int a, int b) {
	int x = findSet(a);
	int y = findSet(b);
	if (tree_size[x] > tree_size[y]) {
		parent[y] = x;
		tree_size[x] += tree_size[y];
	}
	else {
		parent[x] = y;
		tree_size[y] += tree_size[x];
	}

}
void kruskal() {
	// make-set
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	std::fill_n(tree_size, n, 1);  // union을 할때 큰게 작은거 밑으로 들어가기위한 tree_size 배열 1로 초기화.
	std::sort(edges.begin(), edges.end()); // 오름 차순 정렬
	int answer = 0;
	int cnt = 0;
	for (size_t i = 0; i < edges.size() && cnt != n - 1; i++) {
		int x = edges[i].node[0];
		int y = edges[i].node[1];
		if (findSet(x) != findSet(y)) {
			answer += edges[i].cost;
			cnt++;
			Union(x, y);
		}
	}
	std::cout << answer;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;
	edges.reserve(m);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	kruskal();



	return 0;
}