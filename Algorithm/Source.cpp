#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;


ostream& operator<< (ostream& o,const std::pair<int,string>& p) {
	o << p.second << "  , " << p.first;
	return o;
}

int main() {

	using T = pair<int, string>;

	vector<pair<int,string>> v;

	v.push_back(T(90, "���ѿ�"));
	v.push_back(T(52, "������"));
	v.push_back(T(52, "�蹫��"));
	v.push_back(T(14, "�ڿ���"));
	v.push_back(T(84, "�ں��"));
	v.push_back(T(96, "�ڸ���"));

	sort(v.begin(), v.end());

	// ���ǿ����� for �� �ȿ� �׳� int i�� ����.

	// for (int i = 0; i < v.size(); i++)
	for (vector<T>::size_type i = 0; i != v.size(); i++) {

		cout << "v�� " << i + 1 << "��° ���� :: " << v[i] << endl;  
		// vector< ? >  => ? �� �鰡�� Ŭ������ pair �̱� ������ 
		// << �� ���� ���� �����ְ� v[i].second �̷������� �ᵵ �ȴ�.
		// ���� ���� ��ü������ ���� ���Ǹ� ������ �Ѵ�.

	}

	return 0;
}