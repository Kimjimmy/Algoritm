#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adjacent{ 9 };
vector<bool> visited(9,false);
queue<int> q;

void BFS(int start) {
	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {
		auto next = q.front();
		cout << "Visit : " << next << endl;
		
		q.pop();

		for (int i = 0; i < adjacent[next].size(); i++) {
			if (!visited[adjacent[next][i]]) {
				q.push(adjacent[next][i]);
				visited[adjacent[next][i]] = true;
			}
		}		
	 }
}


int main() {
	
	adjacent[0].push_back(1);
	adjacent[0].push_back(2);
	adjacent[0].push_back(3);

	adjacent[1].push_back(4);
	adjacent[1].push_back(5);
	adjacent[1].push_back(0);

	adjacent[2].push_back(0);
	adjacent[2].push_back(7);

	adjacent[3].push_back(0);

	adjacent[4].push_back(1);
	adjacent[4].push_back(5);

	adjacent[5].push_back(1);
	adjacent[5].push_back(4);

	adjacent[6].push_back(7);

	adjacent[7].push_back(2);
	adjacent[7].push_back(8);
	adjacent[7].push_back(6);

	adjacent[8].push_back(7);

	BFS(0);

	return 0;
}