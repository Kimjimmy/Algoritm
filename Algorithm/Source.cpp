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

	v.push_back(T(90, "박한울"));
	v.push_back(T(52, "김지일"));
	v.push_back(T(52, "김무한"));
	v.push_back(T(14, "박오후"));
	v.push_back(T(84, "박비수"));
	v.push_back(T(96, "박마규"));

	sort(v.begin(), v.end());

	// 강의에서는 for 문 안에 그냥 int i를 썻다.

	// for (int i = 0; i < v.size(); i++)
	for (vector<T>::size_type i = 0; i != v.size(); i++) {

		cout << "v의 " << i + 1 << "번째 원소 :: " << v[i] << endl;  
		// vector< ? >  => ? 에 들가는 클래스가 pair 이기 때문에 
		// << 를 따로 정의 안해주고 v[i].second 이런식으로 써도 된다.
		// 내가 만든 객체였으면 따로 정의를 해줬어야 한다.

	}

	return 0;
}