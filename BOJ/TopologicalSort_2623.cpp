#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using std::cout; using std::cin;
using std::vector;

// �������� ���� DFS / BFS�� Ǯ�� ����.

int N, M;
int a, b, c;
vector<int> adjancent[1001];
int indegree[1001];
int input[1001];

void topologicalSort() {
	vector<int> answer;
	std::queue<int> q;

	// indegree �� 0�� �۾� �ִ´�.
	for (int i = 1; i < N + 1; i++) {
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		answer.push_back(cur);
		q.pop();
		for (size_t i = 0; i < adjancent[cur].size(); i++) {
			int next = adjancent[cur][i];
			if ((--indegree[next]) == 0) { // �ϳ� ���� ���״µ� indegree�� 0�̸� q�� Ǫ��.
				q.push(next);
			}

		}
	}
	if (answer.size() != N) {
		cout << 0 << '\n';
		return;
	}
	for (auto elem : answer) {
		cout << elem << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	// �Է� �ޱ� ���� ���ϳ� �� ������ ������.
	cin >> N >> M;
	while (M--) {
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> input[i];
		}
		for (int i = 0; i < a - 1; i++) {
			adjancent[input[i]].push_back(input[i + 1]);
			indegree[input[i + 1]]++;
		}
	}
	topologicalSort();

	return 0;
}

