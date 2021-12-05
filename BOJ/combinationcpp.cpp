#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using std::cin; using std::cout;
using std::vector;

char arr[] = { 'a','b','c','d','e' };
vector<char> vec;

int n = 5;

void combination(int k, int r) {
	if (r == 0) {  // ���� ���� Ʈ�� 
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << '\n';
		return;
	}
	else if (k == n) {  // ���Ҹ� ���� �ʴٰ� k�� 
		return;
	}

	vec.push_back(arr[k]);
	combination(k + 1, r - 1);

	vec.pop_back();
	combination(k + 1, r);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	combination(0, 3);


	return 0;
}