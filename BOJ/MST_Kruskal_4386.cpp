#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using std::cout; using std::cin;
using std::vector;



struct Edge {
	int node[2];
	double cost;
	Edge(int _a, int _b, double _cost) :cost(_cost) {
		node[0] = _a;
		node[1] = _b;
	}
	bool operator<(const Edge& e)const {
		return cost < e.cost;
	}
};
vector<std::pair<double, double>> nodes;
vector<Edge> edges;

double x, y, distance;
int n;
int parent[101];
int tree_size[101];
int findSet(int a) {
	if (parent[a] == a) return a;
	return findSet(parent[a]);
}
void unionSet(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (tree_size[a] > tree_size[b]) {
		parent[b] = a;
		tree_size[b] += tree_size[a];
	}
	else {
		parent[a] = b;
		tree_size[a] += tree_size[b];
	}
}

// kruskal 이용
// 1.make-set ( 모든 노드 개별 집합으로 표현 )
// 2.edge들을 오름차순 정렬.
// 3.모든 엣지에 대해서 작은거 부터 find , union
// 4. 선택한 엣지가 n-1개 일때까지.
void mst() {
	double answer = 0.00f;
	for (int i = 0; i < n + 1; i++) { // 0 번 노드 부터 사용
		parent[i] = i;
	}
	std::fill_n(tree_size, n + 1, 1);
	std::sort(edges.begin(), edges.end());
	int cnt = 0;

	// 모든 엣지에 대해서
	for (int i = 0; i < edges.size() && cnt < n - 1; i++) {
		int node1 = edges[i].node[0];
		int node2 = edges[i].node[1];
		double temp_cost = edges[i].cost;

		// 두 노드의 부모가 다르면
		if (findSet(edges[i].node[0]) != findSet(edges[i].node[1])) {
			unionSet(edges[i].node[0], edges[i].node[1]);
			answer += temp_cost;
			cnt++;
		}
	}
	cout << std::fixed;
	cout.precision(2);
	cout << answer;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	nodes.reserve(n + 1);
	double _cost;
	int t = n;
	while (t--) { // 이거 진짜 조심해야겠다. 또 실수 했네 여기서 n-- 하니깐 밑에 for 문 들어가지도 못하고 바로 나오네 차라리 입력 for문으로 받아야겠다.
		cin >> x >> y;
		nodes.push_back({ x,y });
	}
	// 이 부분 dp 이용해서 풀어도 되는거 아닌가?
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double x_diff = nodes[j].first - nodes[i].first;
			double y_diff = nodes[j].second - nodes[i].second;
			distance = sqrt(std::pow(x_diff, 2) + std::pow(y_diff, 2));
			edges.push_back(Edge(i, j, distance));
		}
	}
	mst();


	return 0;
}

