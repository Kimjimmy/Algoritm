#include<iostream>
#include<vector>

using std::endl;
using std::cout;


std::vector<std::vector<int>> adjacent = { 7 ,std::vector<int>(7,0)} ;  // ��������� ǥ�� (V x V) ���
std::vector<bool> visited(adjacent.size(), false);

// �׷����� ǥ���ϴ� ������� �ΰ����� �ִ�.

// < 1. Adjacency Matrix>
// 1. �׷����� vertex ���� ��ķ� ǥ���ؼ� �����ϸ� 1, �ƴϸ� 0���� ����°�.

// < 2. Adjacency list>
// 2. �迭�� ���(vertex)���� �����ϰ� �� �迭�� �ִ� ������ ������ ������ Linked list�� ǥ���ϴ� ��. (���� ��� X)

void DFS(int here) {     // �̰� �׷����� ������ķ� ǥ�������� DFS �ϴ� ��

	cout << "visit " << here << '\n';
	visited[here] = true;

	for (int i = 0; i < adjacent.size(); i++) {
		if (adjacent[here][i] != 0 && !visited[i]) {

			DFS(i);
		}
	}
}

//  ==========================================================
//   �Ʒ��� < 2. Adjacency list> �� �׷����� ǥ�������� DFS 

// 0 index�� �Ⱦ��� 1�� ���� ���ű� ������ +1 �������� �Ҵ�.
std::vector<std::vector<int>> adjacent2(9); // ��������Ʈ�� ǥ��.  �ε����� ������ ���ϱ� �Ǳ� �ƴµ�.. ��
std::vector<bool> visited2(adjacent2.size(), false);  // adjacent2[0].size() �� adjacent2.size()�� �ٸ��� ó���˾Ҵ�.
                                                      // �տ��� ���� ������ �����ְ� , �ڿ��� ���� ������ �����ش�.


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