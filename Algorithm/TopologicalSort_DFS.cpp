#include<iostream>
#include<vector>
#include<stack>

using std::cout;
using std::vector;
using std::stack;


// 1. BFS( ť �̿�) �� �����ϴ� ����� 2. DFS( ���) �� �����ϴ� ����� �ִ�.
//  DFS (��͸� �̿�)�� ������ ��������.

vector<vector<int>> adjacent{8,vector<int>() };  // ���� ��带 ��Ÿ���� ���� ����.

bool visited[8];

// �������� ���ϰ� deque�̳� list�� �տ��� ���� ����־� ���鼭 �ص� �ǰ� 
// vector�� push_back �ؼ� ���������� reverse ���൵ �ȴ�.
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

	// ��� ��忡 ���ؼ�
	for (int i = 1; i < adjacent.size(); i++) {
		if (!visited[i]) {  // �湮 ���� �ʾ�����
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