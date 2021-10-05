#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using std::endl;
using std::cout;
using std::cin;

int n, m, v;
int start, end;
std::vector<int> vertex[1001];
std::vector<bool> visited(1001, false);
std::queue<int> q;

void dfs(int v) {
	std::vector<int> copy[1001];
	int size = sizeof(vertex) / sizeof(vertex[0]); // size = 1001
	for (int i = 0; i < size; i++) {
		copy[i].assign(vertex[i].begin(), vertex[i].end());
	}
	cout << v << " ";
	visited[v] = true;
	for (int i = 0; i < copy[v].size(); i++) {
		int next = *std::min_element(copy[v].begin(), copy[v].end());
		std::vector<int>::iterator next_index = std::min_element(copy[v].begin(), copy[v].end());
		if (!visited[next]) {
			dfs(next);
		}
		copy[v].erase(next_index);  // 인접 리스트에서 없애준다.
		i--;
	}

}
void bfs(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << " ";
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		std::sort(vertex[next].begin(), vertex[next].end());

		for (int elem : vertex[next]) {
			if (!visited[elem]) {
				q.push(elem);
				visited[elem] = true;
				cout << elem << " ";
			}
		}
	}
}
void initMarks() {
	for (auto&& elem : visited) {
		elem = false;
	}
}


int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		vertex[start].push_back(end);
		vertex[end].push_back(start);
	}
	dfs(v);
	initMarks();
	cout << endl;
	bfs(v);


	return 0;
}