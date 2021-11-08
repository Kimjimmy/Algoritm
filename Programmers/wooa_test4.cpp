#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	
	int cnt = 0;
	for(int i=0;i<s.length();i++){
		int prev =i - 1;
		if (prev < 0)prev = 0;
		int cur = i;
		
		if (s[cur] == s[prev]) {
			cnt++;
		}
		else {
			answer.push_back(cnt);
			cnt = 1;
		}
		if (i == s.length() - 1)answer.push_back(cnt);
	}
	if (s[0] == s[s.length() - 1]) {
		int first = *answer.begin();
		int last = *(answer.end()-1);
		int sum = first + last;
		answer.erase(answer.begin());
		answer.erase(answer.end() - 1);
		answer.push_back(sum);
	}
	sort(answer.begin(), answer.end());
	
	

	return answer;
}
int main() {
	for (auto elem : solution("wowwow")) {
		cout << elem;
	}
	return 0;
}