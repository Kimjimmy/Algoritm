#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int v, e, a, b;
long long c;

vector<pair<int, int>> edges[100001];
// or vector<vector<pair<int,int>>> edges 
int visited[10001];

struct cmp { // �ε�ȣ ������ ���������� greater<> ������ �켱 ����ť�� �ݴ��̴�. (������ https://blog.naver.com/wldlf94/222504680475 )
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)const {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;  // default�� greater �ε� less�� �ٲ����.



void prim(int start) {

	// 1�� ��� ���� ����. prim �˰����� ������ �ƴ� ������ ����.
	// ��� �����ϴ����� �߿����� ����.
	visited[start] = true;

	for(auto elem: edges[start]){
		int next = elem.first;
		int key = elem.second;
		pq.push(make_pair(next, key));
	}

	int answer = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cur_key = pq.top().second;
		pq.pop();

		if (!visited[cur]) {
			visited[cur] = true;
			answer += cur_key;
			for (size_t i = 0; i < edges[cur].size(); i++) {
				int next = edges[cur][i].first;
				int key = edges[cur][i].second;
				pq.push(make_pair(next, key));
			}
		}

	}
	cout << answer;

}

int main() {

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	prim(1);
	return 0;
}