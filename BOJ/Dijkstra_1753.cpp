#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cin;
using std::vector;

// �ִ� ��� ����  single source (one to all) ����
// ���ͽ�Ʈ�� Ǯ��
// 1. ��� ��带 �����ϰ� ��� d[v] = INF, d[s]=0;
// 2. ���� ���� ���� ����� ������ ������ �ּ� ���� relaxation.
// 3. ��尡 ���� ���� �ɶ����� �ݺ�.

const int INF = 99999;

int v,e, k;
int start, t, w;
vector<vector<std::pair<int,int>>> edge;
vector<int> node;
vector<int> s;
int answer[20001];

void Dijkstra(int k) {
	
	std::fill_n(node.begin()+1, k-1, INF);
	std::fill_n(node.begin()+ k + 1, v - k, INF);
	node[k] = 0;

	while (s.size() < v) {  // ����� ������ ������.
		int min = std::min_element(node.begin()+1, node.end()) - node.begin();
		int x = *std::min_element(node.begin() + 1, node.end());
		s.push_back(min);
		answer[min] = x;

		for (int i = 0; i < edge[min].size(); i++) {
			int next = edge[min][i].first;
			auto itr = std::find(s.begin(), s.end(), next);
			if (itr == s.end()) {
				if (node[next] > node[min] + edge[min][i].second) {
					node[next] = node[min] + edge[min][i].second;
					
				}
			}
		}
		node[min] = INF + 1;;		

	}
	for (int i = 1; i <= v; i++) {
		if (answer[i] == INF) {
			std::cout << "INF" << '\n';
		}
		else {
			std::cout << answer[i] << '\n';
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;  // ��� ����, ���� ����

	edge.resize(v+1);
	
	s.reserve(v+1);
	node.resize(v+1);
	
	cin >> k; // ���� ��� ��ȣ
	for (int i = 0; i < e; i++) {
		cin >> start >> t >> w;
		
		edge[start].push_back(std::make_pair(t, w));
	}

	Dijkstra(k);



	return 0;
}