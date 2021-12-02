#include<iostream>
#include<vector>

using std::cin; using std::cout;
using std::vector;

int n, r, c;

int solve(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}
	int half = 1 << n - 1;
	if (r < half && c < half) {
		return solve(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half * half + solve(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return 2 * half * half + solve(n - 1, r - half, c);
	}
	else {
		return 3 * half*half + solve(n - 1, r - half, c - half);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> r >> c;

	solve(n, r, c);





	return 0;
}