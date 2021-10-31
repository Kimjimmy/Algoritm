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

	// �������� �־��� ó�� ���� �丶�� ��ġ�� que�� ���� �ִ´�. ���� ���ʹ� �⺻���� dfs �˰��� ����.
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
			// ��ȿ ��ǥ�� ����� continue
			if (next_x <0 || next_x>n - 1 || next_y<0 || next_y>m - 1) {
				continue;
			} // �丶�䰡 ���� ���;���, �湮���� �ʾҴٸ�
			if (visited[next_x][next_y] < 0 && graph[next_x][next_y] == 0) {
				visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
				graph[next_x][next_y] = 1;
				que.push({ next_x,next_y });
			}
		}
	}
	/* ��� �κ� */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ������ �׷����� ������ �丶�䰡 ������ -1 ���.
			if (graph[i][j] == 0) {
				cout << -1;
				return;
			}
		}
	}
	// �ƴ϶�� ���������� while�� �������� x,y��ǥ�� visited �� ���.
	cout << visited[cur_x][cur_y];
	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];

			// �������� �־����� ���� �丶�� x,y ��ǥ�� bfs ������� �ϱ� ���� start vector��  pair�� �־��ش�.
			if (graph[i][j] == 1) {
				start.push_back({ i,j });
			}
		}
	}
	// visited �迭 -1�� �ʱ�ȭ.
	// ������ 0���� �ʱ�ȭ �ϳ�, �������� �丶�䰡 �̹� ���� ���� ���¸� 0�� ����϶�� ������ -1�� �ʱ�ȭ.( bfs �Լ� �ȿ��� ++ ���ٿ���)
	for (int i = 0; i < n; i++) {
		std::fill_n(visited[i] + 0, m, -1);
	}
	bfs();

	return 0;
}