#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


/* #1 첫 번째 풀이법 구글 검색으로 본 다른 사람 풀이보다 4배 정도 시간 절약 할 수 있었다.
   코드 마지막에 #2 두 번째 풀이도 있으니 참고하자.
*/
using std::cin; using std::cout;
using std::vector;

bool visited[10001];
vector<std::pair<int, int>> path(10001);
int cur, next;

void printPath(int start,int target) {
	if (path[target].first == start) {
		if (path[target].second == 0) cout << "D";
		else if (path[target].second == 1)cout << "S";
		else if (path[target].second == 2)cout << "L";
		else cout << "R";
	}
	else {
		printPath(start, path[target].first);
		if (path[target].second == 0) cout << "D";
		else if (path[target].second == 1)cout << "S";
		else if (path[target].second == 2)cout << "L";
		else cout << "R";
	}
	
}
void initialize() {
	std::fill_n(visited, 10001,false);
}
void bfs(int start,int target) {
	std::queue<int> que;
	que.push( start );
	visited[start] = true;
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				next = cur * 2;
				if (next > 9999) next = next % 10000;
			}
			else if (i == 1) {
				next = cur - 1;
				if (cur == 0)next = 9999;
			}
			else if (i == 2) {
				next = (cur % 1000) * 10 + (cur / 1000);
			}
			else {
				next = (cur / 10) + (cur % 10) * 1000;
			}
			if (!visited[next]) {
				que.push(next);
				visited[next] = true;
				path[next] = { cur,i };
				if (next == target) {
					printPath(start,target);
					return;
				}
			}
		}

	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, input1, input2;
	cin >> t;
	while (t--) {
		initialize();
		cin >> input1 >> input2;
		bfs(input1, input2);
		cout<< '\n';
		
	}
	

	return 0;
}

/*  #2 두 번째 풀이법 

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using std::cin; using std::cout;
using std::vector;

int visited[10001];

char list[] = { 'D','S','L','R' };

int cur, next;


void initialize() {
	std::fill_n(visited, 10001, false);
}
void bfs(int start, int target) {
	std::queue<std::pair<int,std::string>> que;
	que.push({ start,"" });
	visited[start] = true;
	while (!que.empty()) {
		cur = que.front().first;
		std::string cur_str = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				next = cur * 2;
				if (next > 9999) next = next % 10000;
			}
			else if (i == 1) {
				next = cur - 1;
				if (cur == 0)next = 9999;
			}
			else if (i == 2) {
				next = (cur % 1000) * 10 + (cur / 1000);
			}
			else {
				next = (cur / 10) + (cur % 10) * 1000;
			}
			if (!visited[next]) {
				que.push({ next, cur_str + list[i] });
				visited[next] = true;
				if (next == target) {
					cout << cur_str + list[i];
					return;
				}
			}
		}

	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, input1, input2;
	cin >> t;
	while (t--) {
		initialize();
		cin >> input1 >> input2;
		bfs(input1, input2);
		cout << '\n';

	}


	return 0;
}
*/
