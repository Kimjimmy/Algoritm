#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::vector;

int v,e;  // ������ ����
int a, b;
long long c; // ����ġ 

int parent[10001];
int tree_size[10001];

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b,int _distance) :distance(_distance) {
		node[0] = a;
		node[1] = b;
	}
	bool operator <(const Edge& e)const {
		return distance < e.distance;
	}
};

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

void Kruskal(vector<Edge>& edge) {
	// parent �迭 �ʱ�ȭ
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}
	std::fill_n(tree_size, v, 1);  // Ʈ�� ������ ������ ���� Ʈ�� ������ ��� 1�� �ʱ�ȭ.
	long long sum = 0;
	int cnt = 0;  // ���� �߰��� ���� ����.

	for (int i = 0; i < e && cnt!=v-1; i++) {
		int x = edge[i].node[0];
		int y = edge[i].node[1];
		if (findSet(x) != findSet(y)) {
			sum += edge[i].distance;
			Union(x, y);
			cnt++;
		}
	}
	cout << sum;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Edge> edge;

	cin >> v >> e;
	edge.reserve(v);



	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge.push_back(Edge(a, b, c));
	}

	std::sort(edge.begin(), edge.end());

	Kruskal(edge);

	return 0;
}