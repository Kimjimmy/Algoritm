#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> vec = { {1,2},{4,5,6},{5,6,7} };

int main() {
	//vec.erase(vec.begin() + 2);

	auto it = std::find(vec.begin(), vec.end(), vector<int>{4});

	if (it == vec.end()) {
		cout << "문장 끝이다 ";
		return 0;
	}
	//cout <<(*it)[0] << endl;
	
	for (auto elem : vec) {
		for (auto e : elem) {
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}