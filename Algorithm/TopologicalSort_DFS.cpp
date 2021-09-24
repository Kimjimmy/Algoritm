#include<iostream>
#include<vector>
#include<stack>

using std::cout;
using std::vector;
using std::stack;


// 1. BFS( 큐 이용) 로 구현하는 방법과 2. DFS( 재귀) 로 구현하는 방법이 있다.
//  DFS (재귀를 이용)로 구현한 위상정렬.

vector<vector<int>> adjacent{8,vector<int>() };  // 인접 노드를 나타내는 이중 벡터.

bool visited[8];

// 스택으로 안하고 deque이나 list로 앞에다 원소 집어넣어 가면서 해도 되고 
// vector로 push_back 해서 넣은다음에 reverse 해줘도 된다.
stack<int> st;  


void DFS_TS(int t) {
	visited[t] = true;
	for (int i = 0; i < adjacent[t].size(); i++) {
		int next = adjacent[t][i];
		if (!visited[next]) {
			DFS_TS(next);
		}
	}
	st.push(t);
}

template<typename T>
void topologicalSort(T& adjacent) {

	// 모든 노드에 대해서
	for (int i = 1; i < adjacent.size(); i++) {
		if (!visited[i]) {  // 방문 하지 않았으면
			DFS_TS(i);
		}
	}
}


int main() {

	adjacent[1].push_back(2);
	

	adjacent[1].push_back(5);
	
	adjacent[2].push_back(3);
	
	adjacent[3].push_back(4);
	

	adjacent[4].push_back(6);
	

	adjacent[5].push_back(6);


	adjacent[6].push_back(7);
	

	topologicalSort(adjacent);

	for (int i = 0; i < 7;i++) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}