#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// vector, pair ��� std:: �ȿ� �ִ�.

bool compare(pair<string, pair<int,int> > a, pair<string, pair<int,int> > b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
};

int main() {
	
	//std::vector<std::pair<int, std::string>> v;
	// ���� pair
	
	// typedef std::pair<int, int> T;

	using T = pair<int, int>;
	using F = pair<string, T > ;
	vector < pair <string, T> > v;

	
	v.push_back(pair<string, T>("������", T(90, 19961222)));
	v.push_back(pair<string, T>("������", T(95, 19931029)));
	v.push_back(pair<string, T>("���ѿ�", T(97, 19930322)));
	v.push_back(pair<string, T>("�̻��", T(85, 19991019)));
	v.push_back(pair<string, T>("������", T(95, 19960402)));
	
	 
	sort(v.begin(), v.end(),compare);

	/*for (std::vector<F>::size_type i = 0; i != v.size(); i++) {

	}*/
	// ���� ǥ���� ���ݴ� �־�δ�.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << endl;
	}

	return 0;
}