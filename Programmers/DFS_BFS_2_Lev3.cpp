#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool visited[201]{ false, };  // ��� false�� �ʱ�ȭ.


void Dfs(const vector<vector<int>>& computers, int here) {

	visited[here] = true;

	for (int i = 0; i < computers.size(); i++) {
		if (computers[here][i] == 1 && !visited[i]) {// ���� ����Ǿ� �ְ� �湮���� �ʾ�����.
			Dfs(computers, i);
		}
	}
}



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;



	Dfs(computers, 0); // 0��° computer ���� ����.
	// Dfs ���� ������ visited�� false�� �����ִ� ��ǻ�͵��� �湮���� ���� ��ǻ��.

	//��� ������ 0��° ��ǻ�Ϳ� ����Ǿ� �ִ°��� �ƴϱ� ������
	// 0��° ��ǻ�ͷ� dfs ���ȴµ� �湮 ���� ���� ��ǻ�͵��� ���� dfs ��������.
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (std::count(computers[i].begin(), computers[i].end(), 1) == 1) {  //�ڱ� �ڽ� ����� ������ ��尡 ������	
				answer++;
			}
			else {
				Dfs(computers, i);
				answer++;
			}
		}
	}

	//// ��� ��� üũ �ߴµ��� �湮���� ���� ������ ������ ȥ�� �ִ� ����. 
	//for (int i = 0; i < n; i++) {
	//	if (visited[i] == false) {
	//		answer++;  // �湮���� ���� ��ǻ�� �߽߰� ++
	//	}
	//}

	return answer + 1;
}

int main() {
	vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };

	cout << solution(3, computers);

	return 0;
}