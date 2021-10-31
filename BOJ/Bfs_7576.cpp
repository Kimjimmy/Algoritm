#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout; using std::cin;
using std::vector;

int graph[1001][1001];
int visited[1001][1001];
int m, n;

int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
vector<std::pair<int, int>> start;
int cur_x, cur_y, next_x, next_y;

void bfs() {
	std::queue<std::pair<int, int>> que;

	// 문제에서 주어진 처음 익은 토마토 위치를 que에 집어 넣는다. 이후 부터는 기본적인 dfs 알고리즘 실행.
	for (int i = 0; i < start.size(); i++) {
		int x = start[i].first;
		int y = start[i].second;
		que.push({ x,y });
		visited[x][y]++;
	}

	while (!que.empty()) {
		cur_x = que.front().first;
		cur_y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dx[i];
			next_y = cur_y + dy[i];
			// 유효 좌표에 벗어나면 continue
			if (next_x <0 || next_x>n - 1 || next_y<0 || next_y>m - 1) {
				continue;
			} // 토마토가 아직 안익었고, 방문하지 않았다면
			if (visited[next_x][next_y] < 0 && graph[next_x][next_y] == 0) {
				visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
				graph[next_x][next_y] = 1;
				que.push({ next_x,next_y });
			}
		}
	}
	/* 출력 부분 */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 아직도 그래프에 안익은 토마토가 있으면 -1 출력.
			if (graph[i][j] == 0) {
				cout << -1;
				return;
			}
		}
	}
	// 아니라면 마지막으로 while문 빠져나온 x,y좌표의 visited 값 출력.
	cout << visited[cur_x][cur_y];
	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];

			// 문제에서 주어지는 익은 토마토 x,y 좌표를 bfs 출발지로 하기 위해 start vector에  pair로 넣어준다.
			if (graph[i][j] == 1) {
				start.push_back({ i,j });
			}
		}
	}
	// visited 배열 -1로 초기화.
	// 보통은 0으로 초기화 하나, 문제에서 토마토가 이미 전부 익은 상태면 0을 출력하라고 했으니 -1로 초기화.( bfs 함수 안에서 ++ 해줄예정)
	for (int i = 0; i < n; i++) {
		std::fill_n(visited[i] + 0, m, -1);
	}
	bfs();

	return 0;
}