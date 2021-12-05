#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using std::cin; using std::cout;
using std::vector;

char arr[] = { 'a','b','c','d' };
vector<char> vec(3);

int n = 4;

void r_permutation(int k, int r) {
	if (k == r) {
		for (int i = 0; i < r; i++) {
			cout << vec[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		vec[k] = arr[i];
		r_permutation(k + 1, r);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	r_permutation(0, 3);

	return 0;
}