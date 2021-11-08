#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int index_cnt[4];
int cnt_max = 0;
vector<int> solution(vector<int> arr) {
	vector<int> answer;
	
	for (int i = 1; i <= 3;i++) {
		index_cnt[i]= count(arr.begin(), arr.end(), i);
		cnt_max > index_cnt[i]? cnt_max=cnt_max : cnt_max = index_cnt[i];
	}

	for (int i = 1; i <= 3; i++) {
		answer.push_back(cnt_max - index_cnt[i]);
	}
	
	return answer;
}
int main() {
	vector<int> arr{ 2,1,3,1,2,1 };
	solution(arr);
	return 0;
}