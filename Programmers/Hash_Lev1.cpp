#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

template<typename T>
void printMulitset(const T& m) {
	for (const auto& elem : m) {
		cout << elem << " ";
	}
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	multiset<string> p, c;

	//vector에 있는 string 들을 multiset p,c 에 넣고.
	for (vector<string>::iterator itr = participant.begin(); itr != participant.end(); itr++) {
		p.insert(*itr);
	}
	for (vector<string>::iterator itr = completion.begin(); itr != completion.end(); itr++) {
		c.insert(*itr);
	}
	// competion에 있는 내용들을 participant에서 하나씩 지워나간다.
	// if participant에 중복된 내용이 있다면 completion에서도 같은 key 값이 중복될때 지운다.
	vector<string>::iterator itr = completion.begin();
	for (itr; itr != completion.end(); itr++) {
		p.erase(p.find(*itr));
	}

	printMulitset(p);

	multiset<string>::iterator itr2 = p.begin();
	answer.insert(0, *itr2);


	return answer;
}

int main() {
	vector<string> p = { "josipa", "nikola","vinko","marina","filipa" };
	vector<string> c = { "josipa", "nikola","marina","filipa" };


	cout << solution(p, c) << endl;
	return 0;
}