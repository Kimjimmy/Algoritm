#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	const int day = 1;
	while (!progresses.empty()) {
		for (vector<int>::size_type i = 0; i != progresses.size(); i++) {
			if (progresses[i] + day * speeds[i] >= 100) {
				q.push(i);
				progresses.erase(progresses.begin() + i);
				speeds.erase(speeds.begin() + i);
				i--;
			}
		}
	}
	int count = 0;
	int* array = new int[progresses.size()];
	for (int i = 0; i != progresses.size(); i++) {
		array[i] = q.front();
		q.pop();
	}
	for (int i = 0; i != progresses.size(); i++) {
		if (count == array[i]) {
			++count;
			int cur = count;
			for (int j = 0; j < i; j++) {
				if (cur == array[j]) {
					++cur;
				}
			}
			answer.push_back(cur);
		}
	}


	return answer;
}