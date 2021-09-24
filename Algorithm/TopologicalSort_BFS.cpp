#include<iostream>
#include<queue>
#include<vector>

using std::cout;
using std::vector;

// 1. BFS( ť �̿�) �� �����ϴ� ����� 2. DFS( ����, ���) �� �����ϴ� ����� �ִ�.
// BFS (ť�� �̿�)�� ������ ��������.

vector<vector<int>> adjacent{ 8,vector<int>()};  // ���� ��带 ��Ÿ���� ���� ����.
vector<int> indegree(8, 0);  // indegree�� ��Ÿ���� �迭
std::queue<int> answer; // ������ ���� queue
int result[8]{ 0, };  // ��� �迭.


template<typename T>
void topologicalSort(T& adjacent) {
	

	// ��� ������ ���ؼ�
	for (size_t i = 1; i < adjacent.size(); i++) {
		// incoming edge�� 0 �� ��带 queue �� push
		if (indegree[i] == 0) {
			answer.push(i);
		}
	}

	for (int i = 1; i <= 7; i++) {  // ��Ȯ�� n�� ���� ��� ��带 �� �� �ִ�.

		if (answer.empty()) {
			cout << " ����Ŭ�� �ֽ��ϴ�." << '\n';
			return;
		}

		int current = answer.front();
		answer.pop();
		result[i] = current;  // result �迭�� ����ְ�

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