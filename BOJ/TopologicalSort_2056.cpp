#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::vector; using std::pair;


int n; // �۾� ��
int time[10001];
vector<int> work[10001];
int indegree[10001];
int dp[10001];

void tS() {
	std::queue<int> q;

	for (int i = 1; i <= n; i++) { // ��� �۾��� ���鼭 indegree�� ���� �۾� q�� Ǫ��.
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
				// if �� �ȿ��ٰ� dp ����� ��������� �ݷ� ���� ��Ȳ�� ���´�.
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