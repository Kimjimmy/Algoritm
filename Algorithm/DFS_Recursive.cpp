#include<iostream>
#include<vector>

using std::endl;
using std::cout;


std::vector<std::vector<int>> adjacent = { 7 ,std::vector<int>(7,0)} ;  // 인접행렬의 표현 (V x V) 행렬
std::vector<bool> visited(adjacent.size(), false);

// 그래프를 표현하는 방법에는 두가지가 있다.

// < 1. Adjacency Matrix>
// 1. 그래프의 vertex 들을 행렬로 표시해서 인접하면 1, 아니면 0으로 만드는것.

// < 2. Adjacency list>
// 2. 배열에 노드(vertex)들을 나열하고 각 배열에 있는 노드들의 인접한 노드들을 Linked list로 표현하는 것. (순서 상관 X)

void DFS(int here) {     // 이건 그래프를 인접행렬로 표시했을때 DFS 하는 법

	cout << "visit " << here << '\n';
	visited[here] = true;

	for (int i = 0; i < adjacent.size(); i++) {
		if (adjacent[here][i] != 0 && !visited[i]) {

			DFS(i);
		}
	}
}

//  ==========================================================
//   아래는 < 2. Adjacency list> 로 그래프를 표현했을때 DFS 

// 0 index는 안쓰고 1번 부터 쓸거기 때문에 +1 공간으로 할당.
std::vector<std::vector<int>> adjacent2(9); // 인접리스트의 표현.  인덱스를 값으로 쓰니깐 되긴 됐는데.. ㅇ
std::vector<bool> visited2(adjacent2.size(), false);  // adjacent2[0].size() 랑 adjacent2.size()랑 다르네 처음알았다.
                                                      // 앞에껀 열의 개수를 말해주고 , 뒤에껀 행의 개수를 말해준다.


void DFS2(int here) {

	visited2[here] = true;
	cout << "visit2 : " << here << '\n';

	for (int i = 0; i < adjacent2[here].size(); i++) {
		int next = adjacent2[here][i];
		if (!visited2[next]) {
			DFS2(next);
		}
	}
}


//void dfsAll() {
//	visited = std::vector<bool>(adjacent2_size, false);
//	for (int i = 0; i < adjacent2_size; i++) {
//		if (!visited[i]) {
//			Dfs(i);
//		}
//	}
//}


int main() {
	cout << "============== DFS ===================" << endl;

	adjacent[0][1] = 1;
	adjacent[0][2] = 1;
	adjacent[1][0] = 1;
	adjacent[1][3] = 1;
	adjacent[1][4] = 1;
	adjacent[2][0] = 1;
	adjacent[2][6] = 1;
	adjacent[3][1] = 1;
	adjacent[4][1] = 1;
	adjacent[4][5] = 1;
	adjacent[5][4] = 1;
	adjacent[6][2] = 1;

	DFS(0);

	cout << "============== DFS2 ===================" << endl;
	adjacent2[1].push_back(2);
	adjacent2[1].push_back(3);
	adjacent2[1].push_back(8);

	adjacent2[2].push_back(1);
	adjacent2[2].push_back(7);

	adjacent2[3].push_back(1);
	adjacent2[3].push_back(4);
	adjacent2[3].push_back(5);

	adjacent2[4].push_back(3);
	adjacent2[4].push_back(5);

	adjacent2[5].push_back(3);
	adjacent2[5].push_back(4);

	adjacent2[6].push_back(7);

	adjacent2[7].push_back(2);
	adjacent2[7].push_back(6);
	adjacent2[7].push_back(8);

	adjacent2[8].push_back(1);
	adjacent2[8].push_back(7);

	DFS2(1);

	
	return 0;
}