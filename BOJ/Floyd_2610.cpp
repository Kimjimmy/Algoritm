#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using std::cout; using std::cin;
using std::vector;

int N, M;
const int INF = 987654321;
bool visited[101];
vector<int> graph[101];
std::map<int, vector<int>> team_member;
vector<int> team_leaders;
int d[101][101];


void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

void bfs(int start, int idx) {
	std::queue<int> que;
	que.push(start);
	visited[start] = true;
	team_member[idx].push_back(start);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				que.push(next);
				team_member[idx].push_back(next);

			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;

	// dp 초기화.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)d[i][j] = 0;
			else {
				d[i][j] = INF;
			}
		}
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		d[a][b] = 1;
		d[b][a] = 1;
	}
	int team_idx = 0; // 팀 넘버
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i, ++team_idx);

		}
	}
	floyd();

	int leader = 0;
	// 대표 선정하기.  맵에 팀 번호, 멤버 번호 있다.
	for (size_t i = 1; i <= team_member.size(); i++) {
		int pivot = INF;
		for (int j = 0; j < team_member[i].size(); j++) {
			int max = 0;
			int cur = team_member[i][j];
			for (int k = 0; k < team_member[i].size(); k++) {
				if (j == k)continue;
				int next = team_member[i][k];
				max = std::max(max, d[cur][next]);
			}
			if (max < pivot) {
				pivot = max;
				leader = cur;
			}
		}
		team_leaders.push_back(leader);
	}

	// 출력하기
	cout << team_idx << '\n';
	std::sort(team_leaders.begin(), team_leaders.end());
	for (auto elem : team_leaders) {
		cout << elem << '\n';
	}


	return 0;
}

