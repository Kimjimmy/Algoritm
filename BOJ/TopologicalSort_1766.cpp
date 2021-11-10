#include<iostream>
#include<vector>
#include<queue>

using std::cout; using std::cin;
using std::vector;

int n, m;
vector<int> books[32001];
int indegree[32001];

void tS() {
	std::priority_queue<int, vector<int>, std::greater<int>> pq;  // pq는 작은 값이 top()에 존재하게끔.

	// 모든 책을 검색해 indegree가 0인 책을 찾아 pq에 넣어준다.
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	for (int j = 0; j < n; j++) { // 모든 책에 대해서
		int cur = pq.top();
		cout << cur << " ";
		pq.pop();
		for (auto elem : books[cur]) {
			if (--indegree[elem] == 0) {
				pq.push(elem);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	int a, b;

	while (m--) {
		cin >> a >> b;
		books[a].push_back(b);
		indegree[b]++;
	}
	tS();
	return 0;
}