#include<iostream>
#include<vector>
#include<algorithm>


using std::cout; using std::cin;
using std::vector;

int n, m;
const int INF = 987654321;
vector<std::pair<int, int>> graph[101];
int dist[101][101];


void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	// 초기화.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)dist[i][j] = 0;
			else { dist[i][j] = INF; }
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		dist[a][b] = std::min(dist[a][b], c);
	}
	floyd();

	// 정답 출력.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] == INF ? cout << 0 << " " : cout << dist[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}

