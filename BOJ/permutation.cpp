#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using std::cin; using std::cout;
using std::vector;

char arr[] = { 'a','b','c','d' };


int n = 4;

void permutation(int k,int r) {
	if (k == r) {
		for (int i = 0; i < r; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = k; i < n; i++) {
		std::swap(arr[i], arr[k]);
		permutation(k + 1,r);
		std::swap(arr[k], arr[i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	permutation(0,3);

	return 0;
}