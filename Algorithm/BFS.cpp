#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adjacent{ 9 };
vector<bool> visited(9,false);
queue<int> q;

void BFS(int start) {
	q.push(start);
	cout << "Visit : " << start << endl;
	visited[start] = true;
	
	while (!q.empty()) {
		auto next = q.front();	
		q.pop();

		for (int i = 0; i < adjacent[next].size(); i++) {
			if (!visited[adjacent[next][i]]) {
				q.push(adjacent[next][i]);
				cout << "Visit : " << adjacent[next][i] << endl;
				visited[adjacent[next][i]] = true;
			}
		}		
	 }
}
void initMarks() {
	
	for (auto elem : visited) {	
		elem = false;
	}

}
void BFS() {
	BFS(0);
}
bool search(int start, int end) {   // 엔지니어 대한민국(유튜브) 'Graph에서 두지점의 경로 찾기'  
	initMarks();
	queue<int> temp;

	temp.push(start);
	visited[start] = true;

	while (!temp.empty()) {
		int next = temp.front();
		temp.pop();
		if (next == end) return true;
		for (int elem : adjacent[next]) {		
			if (!visited[elem]) {
				temp.push(elem);
				visited[elem] = true;
			}
		}
		
	}
	return false;
}


int main() {
	
	adjacent[0].push_back(1);
	

	adjacent[1].push_back(3);
	adjacent[1].push_back(2);

	adjacent[2].push_back(3);
	
	adjacent[3].push_back(5);
	adjacent[3].push_back(4);

	adjacent[4].push_back(3);

	adjacent[5].push_back(3);
	adjacent[5].push_back(6);
	adjacent[5].push_back(7);

	adjacent[6].push_back(5);
	adjacent[6].push_back(8);

	adjacent[7].push_back(5);

	adjacent[8].push_back(6);

	BFS();
	cout << '\n';


	cout << boolalpha <<search(1, 8);
	return 0;
}