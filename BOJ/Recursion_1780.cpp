#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::vector;

int n;
int arr[2188][2188];
int result[3];

void solve(int n, int a, int b) {
	if (n == 1) {
		result[arr[a][b] + 1]++;
		return;
	}
	bool is_same = true;
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (arr[a][b] != arr[i][j]) {
				is_same = false;
				break;
			}
		}
		if (!is_same)break;
	}
	if (is_same) {
		result[arr[a][b] + 1]++;
		return;
	}
	else {
		int temp = n / 3;
		solve(n / 3, a, b);
		solve(n / 3, a, b + temp);
		solve(n / 3, a, b + 2 * temp);
		solve(n / 3, a + temp, b);
		solve(n / 3, a + temp, b + temp);
		solve(n / 3, a + temp, b + 2 * temp);
		solve(n / 3, a + 2 * temp, b);
		solve(n / 3, a + 2 * temp, b + temp);
		solve(n / 3, a + 2 * temp, b + 2 * temp);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(n, 0, 0);

	cout << result[0] << '\n' << result[1] << '\n' << result[2];

	return 0;
}