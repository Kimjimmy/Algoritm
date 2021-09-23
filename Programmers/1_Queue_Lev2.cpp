#include <string>
#include<iostream>
#include <vector>
#include<queue>

// 고득점 kit [Queue] - 기능 개발
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;
	queue<int> days_of_done; // 작업별 소요일.
	
	for (size_t i = 0; i < progresses.size(); i++) {
		int res = 100 - progresses[i];
		if (res % speeds[i] != 0) res += speeds[i];
		days_of_done.push(res / speeds[i]);
	}

	int i = 0;
	auto x = days_of_done.front();

	days_of_done.pop();
	answer.push_back(1);
	
	while (!days_of_done.empty()) {

		if (x < days_of_done.front()) {
			x = days_of_done.front();

			days_of_done.pop();
			answer.push_back(1);
			i++;
		}
		else {
			days_of_done.pop();
			answer[i]++;
		}
	}
	
	return answer;
}

int main() {
	vector<int> p = { 14,25,25,16,25 };
	vector<int> s = { 4,5,5,4,1 };
	for (const auto& elem : solution(p, s)) {
		cout << elem << " ";
	}
	return 0;
}