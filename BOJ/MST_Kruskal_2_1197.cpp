#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v, e;
int a, b;
long long c;

vector< pair<int, pair<int, int>>> edges;

int parent[10001];
int tree_size[10001];

int findSet(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = findSet(parent[x]);
	}
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
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}
	fill_n(tree_size, v, 1);
	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < e && cnt != v - 1; i++) {
		int y = edges[i].second.first;
		int x = edges[i].first;

		if (findSet(x) != findSet(y)) {
			answer += edges[i].second.second;
			Union(x, y);
			cnt++;

		}
	}
	cout << answer;

}
template<typename T>
bool compare(T a, T b) {
	return a.second.second < b.second.second;
}

int main() {
	cin >> v >> e;
	edges.reserve(v);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges.push_back(make_pair(a, make_pair(b, c)));
		//edges.push_back(make_pair(c,make_pair(b, a)));
	}
	sort(edges.begin(), edges.end(), compare<pair<int, pair<int, int>>>);
	kruskal();


	return 0;
}