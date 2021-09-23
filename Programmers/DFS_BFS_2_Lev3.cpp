#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool visited[201]{ false, };  // 모두 false로 초기화.


void Dfs(const vector<vector<int>>& computers, int here) {

	visited[here] = true;

	for (int i = 0; i < computers.size(); i++) {
		if (computers[here][i] == 1 && !visited[i]) {// 서로 연결되어 있고 방문하지 않았으면.
			Dfs(computers, i);
		}
	}
}



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;



	Dfs(computers, 0); // 0번째 computer 부터 시작.
	// Dfs 돌고 나오면 visited에 false로 남아있는 컴퓨터들이 방문되지 않은 컴퓨터.

	//모든 노드들이 0번째 컴퓨터와 연결되어 있는것이 아니기 때문에
	// 0번째 컴퓨터로 dfs 돌렸는데 방문 되지 않은 컴퓨터들을 따로 dfs 돌려본다.
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (std::count(computers[i].begin(), computers[i].end(), 1) == 1) {  //자기 자신 말고는 인접한 노드가 없을때	
				answer++;
			}
			else {
				Dfs(computers, i);
				answer++;
			}
		}
	}

	//// 모든 노드 체크 했는데도 방문되지 않은 노드들은 완전히 혼자 있는 노드들. 
	//for (int i = 0; i < n; i++) {
	//	if (visited[i] == false) {
	//		answer++;  // 방문되지 않은 컴퓨터 발견시 ++
	//	}
	//}

	return answer + 1;
}

int main() {
	vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };

	cout << solution(3, computers);

	return 0;
}