#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

constexpr auto INF = 1234567;

using std::cout; using std::cin;
using std::vector;


// < Prim >
// ��� ����� key���� selected ���� �ʱ�ȭ�Ѵ�.

int n, m, a, b, c;

vector<std::pair<int, int>> adjancent[1001];
int key[1001];  // key ��
bool selected[1001]; // ���� �ƴ���.


int prim(int start) {
	int answer = 0;

	// ��� ����� key���� selected ���� �ʱ�ȭ�Ѵ�.
	std::fill_n(key, n + 1, INF);

	// �������� �������� ���� ����
	// key ���� 0���� selected�� true ��
	key[start] = 0;
	selected[start] = true;

	// ��� ������ ���õ� ������.
	int cnt = 1;
	int cur = start;
	while (cnt <= n - 1) {
		// ���õ� ����� ������ ����� key�� ���� ���ֱ�.
		int next, cost;
		for (size_t i = 0; i < adjancent[cur].size(); i++) {

			next = adjancent[cur][i].first;
			cost = adjancent[cur][i].second;

			if (selected[next])continue;
			if (key[next] > cost) {
				key[next] = cost;
			}
		}
		// ���� ���õ��� ���� ���� �߿� key���� ���� ���� ��� ����.
		int min_cost = INF;
		int min_idx = -1;
		for (size_t i = 1; i <= n; i++) {
			if (selected[i])continue;
			if (min_cost > key[i]) {
				min_cost = key[i];
				min_idx = i;
			}
		}
		cnt++; // ���� �����ϱ� cnt ����.
		answer += min_cost;
		selected[min_idx] = true;
	}

	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		adjancent[a].push_back({ b,c });
		adjancent[b].push_back({ a,c });
	}

	cout << prim(1);

	return 0;
}