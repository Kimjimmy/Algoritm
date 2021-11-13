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

// kruskal �̿�
// 1.make-set ( ��� ��� ���� �������� ǥ�� )
// 2.edge���� �������� ����.
// 3.��� ������ ���ؼ� ������ ���� find , union
// 4. ������ ������ n-1�� �϶�����.
void mst() {
	double answer = 0.00f;
	for (int i = 0; i < n + 1; i++) { // 0 �� ��� ���� ���
		parent[i] = i;
	}
	std::fill_n(tree_size, n + 1, 1);
	std::sort(edges.begin(), edges.end());
	int cnt = 0;

	// ��� ������ ���ؼ�
	for (int i = 0; i < edges.size() && cnt < n - 1; i++) {
		int node1 = edges[i].node[0];
		int node2 = edges[i].node[1];
		double temp_cost = edges[i].cost;

		// �� ����� �θ� �ٸ���
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
	while (t--) { // �̰� ��¥ �����ؾ߰ڴ�. �� �Ǽ� �߳� ���⼭ n-- �ϴϱ� �ؿ� for �� ������ ���ϰ� �ٷ� ������ ���� �Է� for������ �޾ƾ߰ڴ�.
		cin >> x >> y;
		nodes.push_back({ x,y });
	}
	// �� �κ� dp �̿��ؼ� Ǯ� �Ǵ°� �ƴѰ�?
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

