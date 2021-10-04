#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> costs(101, vector<int>(3));
int p_size[101];
int parent[101];

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

template<typename T>
int findSet(T& parent, int x) {
	if (parent[x] != x) parent[x] = findSet(parent, parent[x]);

	return parent[x];
}
void Union(int a, int b) {
	int x = findSet(parent, a);
	int y = findSet(parent, b);
	if (p_size[x] > p_size[y]) {
		parent[y] = x;
		p_size[x] += p_size[y];
	}
	else {
		parent[x] = y;
		p_size[y] += p_size[x];
	}
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	// make -set
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	fill_n(p_size, n, 1);  // 트리 사이즈 측정을 위해 모두 1로 초기화.

	// 엣지 오름차순 정렬.
	sort(costs.begin(), costs.end(), compare);

	int cnt = 0;
	for (size_t i = 0; i < costs.size() && cnt != n - 1; i++) {
		if (findSet(parent, costs[i][0]) != findSet(parent, costs[i][1])) {
			cnt++;
			Union(costs[i][0], costs[i][1]);
			answer += costs[i][2];
		}
	}

	return answer;
}

int main() {
	costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
	cout << solution(4, costs);

	return 0;
}