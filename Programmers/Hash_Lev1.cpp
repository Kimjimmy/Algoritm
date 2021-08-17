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

	//vector�� �ִ� string ���� multiset p,c �� �ְ�.
	for (vector<string>::iterator itr = participant.begin(); itr != participant.end(); itr++) {
		p.insert(*itr);
	}
	for (vector<string>::iterator itr = completion.begin(); itr != completion.end(); itr++) {
		c.insert(*itr);
	}
	// competion�� �ִ� ������� participant���� �ϳ��� ����������.
	// if participant�� �ߺ��� ������ �ִٸ� completion������ ���� key ���� �ߺ��ɶ� �����.
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