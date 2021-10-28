#include<iostream>
#include<vector>
#include<queue>

using std::cin; using std::cout;
using std::vector;
int n, m;
vector<int> friends[10001];
int visited[501];
int answer;

void bfs(int start) {
	std::queue<int> que;
	que.push(start);
	visited[start]++;
	

	while (!que.empty()) {
		int me = que.front();
		que.pop();
		if (visited[me] > 2) return;
		for (size_t i = 0; i < friends[me].size(); i++) {
			int my_friend = friends[me][i];
			if (!visited[my_friend]) {
				que.push(my_friend);
				visited[my_friend] = visited[me] + 1;
				answer++;
			}
		}
	}
		
}

int main() {
	
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		friends[x].push_back(y);
		friends[y].push_back(x);
	}
	bfs(1);
	cout << answer;

	return 0;
}