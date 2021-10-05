#include<iostream>
#include<vector>
#include<queue>

using std::cin;
using std::cout;

int n, m;
int row, node;

std::vector<std::vector<int>> adjacent{ 32001, };
std::queue<int> answer;
std::vector<int> indegree(32001);


void topologicalSort() {
	//모든 노드에 대해서 
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			answer.push(i);
		}
	}
	// 모든 노드에 대해서
	for (int j = 0; j < n; j++) {
		int current = answer.front();
		cout << current << " ";
		answer.pop();


		for (int elem : adjacent[current]) {
			if (--indegree[elem] == 0) {
				answer.push(elem);
			}
		}
	}
}



int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> row >> node;
		adjacent[row].push_back(node);
		indegree[node]++;
	}
	topologicalSort();

	return 0;
}