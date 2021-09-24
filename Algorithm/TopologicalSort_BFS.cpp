#include<iostream>
#include<queue>
#include<vector>

using std::cout;
using std::vector;

// 1. BFS( 큐 이용) 로 구현하는 방법과 2. DFS( 스택, 재귀) 로 구현하는 방법이 있다.
// BFS (큐를 이용)로 구현한 위상정렬.

vector<vector<int>> adjacent{ 8,vector<int>()};  // 인접 노드를 나타내는 이중 벡터.
vector<int> indegree(8, 0);  // indegree를 나타내는 배열
std::queue<int> answer; // 순서를 담을 queue
int result[8]{ 0, };  // 결과 배열.


template<typename T>
void topologicalSort(T& adjacent) {
	

	// 모든 정점에 대해서
	for (size_t i = 1; i < adjacent.size(); i++) {
		// incoming edge가 0 인 노드를 queue 에 push
		if (indegree[i] == 0) {
			answer.push(i);
		}
	}

	for (int i = 1; i <= 7; i++) {  // 정확히 n번 돌면 모든 노드를 돌 수 있다.

		if (answer.empty()) {
			cout << " 싸이클이 있습니다." << '\n';
			return;
		}

		int current = answer.front();
		answer.pop();
		result[i] = current;  // result 배열에 담아주고

		for (int i = 0; i < adjacent[current].size(); i++) {
			int next = adjacent[current][i];
			if (--indegree[next] == 0) {
				answer.push(next);
			}
		}	
	}
}

int main() {
	adjacent[1].push_back(2);
	indegree[2] ++;

	adjacent[1].push_back(5);
	indegree[5]++;

	adjacent[2].push_back(3);
	indegree[3]++;

	adjacent[3].push_back(4);   
	indegree[4]++;

	/*adjacent[3].push_back(5);
	indegree[5]++;*/

	adjacent[4].push_back(6);
	indegree[6]++;

	adjacent[5].push_back(6);
	indegree[6]++;

	adjacent[6].push_back(7);
	indegree[7]++;

	topologicalSort(adjacent);

	for (auto elem : result) {
		cout << elem << " ";
	}

	return 0;
}