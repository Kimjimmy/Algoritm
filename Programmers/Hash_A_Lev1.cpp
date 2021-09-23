#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>	

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> d;

	// 없는 key값을 추가하면 자료형 default 값이 들어간다. d["lena"] 라고 하면은 d 는 빈 unordered_map인데 lena가 들어가면서 value는 0으로 들어간다.
	// 그 d[i] 값을 ++ 해줬으니깐 1이 된다. 즉 이름 값이 불릴때 몇번 들어가는지 수를 샌다고 보면된다.
	for (auto& elem : participant)d[elem]++;

	// 완주한 사람들의 이름을 뺀다.
	for (auto& elem : completion) d[elem]--;

	//========= 여기 까지 마치면 각 참여자 이름에 해당하는 value는 0 아니면 1이 되어있는데 값이 1인 사람이 완주하지 못한 사람인것이다.
	for (auto& elem : d) {
		if (elem.second > 0) {
			answer = elem.first;
			return answer;
		}
	}
}

int main() {
	vector<string> p = { "josipa", "nikola","vinko","marina","filipa" };
	vector<string> c = { "josipa", "nikola","marina","filipa" };


	cout << solution(p, c) << endl;

	return 0;
}