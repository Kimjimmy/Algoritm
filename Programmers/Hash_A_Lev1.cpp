#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>	

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> d;

	// ���� key���� �߰��ϸ� �ڷ��� default ���� ����. d["lena"] ��� �ϸ��� d �� �� unordered_map�ε� lena�� ���鼭 value�� 0���� ����.
	// �� d[i] ���� ++ �������ϱ� 1�� �ȴ�. �� �̸� ���� �Ҹ��� ��� ������ ���� ���ٰ� ����ȴ�.
	for (auto& elem : participant)d[elem]++;

	// ������ ������� �̸��� ����.
	for (auto& elem : completion) d[elem]--;

	//========= ���� ���� ��ġ�� �� ������ �̸��� �ش��ϴ� value�� 0 �ƴϸ� 1�� �Ǿ��ִµ� ���� 1�� ����� �������� ���� ����ΰ��̴�.
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