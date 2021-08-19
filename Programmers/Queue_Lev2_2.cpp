#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>


using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> que;
	
	// 큐에 삽입하고. & 최고값 찾고.
	
	int index = 0;
	
	for (auto& elem : priorities) {
		que.push(make_pair(elem,index));
		index++;		
	}
	sort(priorities.begin(),priorities.end(),std::greater<int>());

	while (!que.empty()) {
		if (que.front().first >= priorities[answer]) {
			answer++;
			if (location == que.front().second) {
				return answer;
			}
			que.pop();
		}
		else {
			que.push(que.front());
			que.pop();

		}
	}


	return answer;
}

int main() {
	vector<int> p = {1,1,9,1,1,1 };
	int a = 0;
	cout << solution(p, a);

	return 0;
}