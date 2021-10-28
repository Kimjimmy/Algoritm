#define _CRT_SECURE_NO_WARNINGS  // scanf ����ϱ� ����

#include<iostream>
#include<vector>
#include<queue>

using std::cout; using std::cin;
using std::vector;

int n, m;
int graph[101][101];
int visited[101][101];
int cur_x, cur_y, next_x, next_y;

// ���� ����
int dx[] = { 0,-1,0,1 }; // �� �� �� ��
int dy[] = { -1,0,1,0 }; // �� �� �� ��

void bfs(int x, int y) {
	std::queue<std::pair<int, int>> que;
	que.push({ x,y });
	visited[x][y]++;

	while (!que.empty()) {
		cur_x = que.front().first;
		cur_y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dx[i];
			next_y = cur_y + dy[i];
			// ��ǥ�� ��ȿ ������ ������ continue
			if (next_x<1 || next_y<1 || next_x>n || next_y>m) continue;
			// �ѹ��� �湮���� �ʾҰ� , graph�� ���� 1�̸�
			if (!visited[next_x][next_y] && graph[next_x][next_y] == 1) {
				que.push({ next_x,next_y });
				visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
			}
			if (next_x == n && next_y == m) {
				cout << visited[next_x][next_y];
				return;
			}
		}

	}
}

int main() {
	//std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs(1, 1); // ������ �׻� (1,1)

	// ó������ �Ʒ��� ���� �Է����� �־����� �׷����� �޾Ҵ�.

	/*cin >> n >> m;
	int** arr = new int*[n];

	cin.ignore(10, '\n');
	for (unsigned int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			a = cin.get();
			arr[i][j] = a - '0';
		}
		cin.ignore(10, '\n');
	}
	cout << Bfs(arr);*/

	return 0;
}