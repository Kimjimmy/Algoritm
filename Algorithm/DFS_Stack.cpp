#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

//std::vector<std::vector<int>> adjacent(9);  // 1부터 쓸거다.
//std::vector<bool> visited(9,false);  //1 부터 사용.

std::vector<int> adj_list[10];
bool visited[10] = { false, };
std::stack<int> st;

// 인접 리스트로 구하기.

void DFS(int start) {
	


	std::vector<int> adj_copy[10];
	for (int i = 0; i < 10; i++) {
		adj_copy[i].assign(adj_list[i].begin(), adj_list[i].end());
	}

	// adj_copy->assign(adj_copy->begin(), adj_list->end());

	int current = start;
	st.push(current);
	visited[current] = true;
	std::cout << "Visit : " << current << "\n";

	while (!st.empty()) {
		
		current = st.top();

		if (adj_copy[current].empty()) {  // 아무것도 연결 안되었다면?
			st.pop();
		}
		for (unsigned int i = 0; i < adj_copy[current].size(); i++) {

			
			// int next = adj_copy[current][i];
			int next = *std::min_element(adj_copy[current].begin(), adj_copy[current].end());  // 인접한 정점중에서 가장 작은 수를 찾는다
			std::vector<int>::iterator next_index = std::min_element(adj_copy[current].begin(), adj_copy[current].end());
			adj_copy[current].erase(next_index);  // 인접 리스트에서 없애준다.

			if (!visited[next]) {  // 방문하지 않은 곳이라면
				st.push(next);
				visited[next] = true;
				std::cout << "Visit : " << next << "\n";
				break;       // <----- 요놈이 키포인트다. 
			}
		}
			
	}

	
}

// std::vector<int> adj_list[1001];
//bool visited[1001] = { false, };
//std::stack<int> st;


int main() {
	adj_list[0].push_back(1);
	adj_list[0].push_back(2);
	adj_list[0].push_back(3);

	adj_list[1].push_back(4);
	adj_list[1].push_back(5);
	adj_list[1].push_back(0);

	adj_list[2].push_back(0);
	adj_list[2].push_back(7);

	adj_list[3].push_back(0);

	adj_list[4].push_back(1);
	adj_list[4].push_back(5);

	adj_list[5].push_back(1);
	adj_list[5].push_back(4);

	adj_list[6].push_back(7);

	adj_list[7].push_back(2);
	adj_list[7].push_back(8);
	adj_list[7].push_back(6);

	adj_list[8].push_back(7);

	DFS(0);

	return 0;
}