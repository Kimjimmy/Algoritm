#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::vector; using std::pair;


int n; // 작업 수
int time[10001];
vector<int> work[10001];
int indegree[10001];
int dp[10001];

void tS() {
	std::queue<int> q;

	for (int i = 1; i <= n; i++) { // 모든 작업을 돌면서 indegree가 없는 작업 q에 푸쉬.
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();

		q.pop();
		for (auto elem : work[cur]) {
			dp[elem] = std::max(dp[elem], dp[cur] + time[elem]);
			if (--indegree[elem] == 0) {
				q.push(elem);
				// if 문 안에다가 dp 계산을 집어넣으면 반례 같은 상황이 나온다.
			}
		}
	}
	cout << *std::max_element(dp, dp + n + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int x;

	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			cin >> x;
			work[x].push_back(i);
		}
	}
	tS();
	return 0;
}