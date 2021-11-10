#include<iostream>
#include<vector>
#include<queue>

using std::cout; using std::cin;
using std::vector;

int n, m;
vector<int> books[32001];
int indegree[32001];

void tS() {
	std::priority_queue<int, vector<int>, std::greater<int>> pq;  // pq�� ���� ���� top()�� �����ϰԲ�.

	// ��� å�� �˻��� indegree�� 0�� å�� ã�� pq�� �־��ش�.
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	for (int j = 0; j < n; j++) { // ��� å�� ���ؼ�
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