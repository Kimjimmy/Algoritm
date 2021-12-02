#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout;
using std::vector;

int arr[65][65];
int n;

void solve(int n, int a, int b) {

	if (n == 1) {
		cout << arr[a][b];
		return;
	}

	bool is_same = true;

	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (arr[i][j] != arr[a][b]) {
				is_same = false;
				break;
			}
		}
		if (!is_same) break;
	}

	if (is_same) {
		cout << arr[a][b];
	}
	else {
		int half = n / 2;
		cout << "(";
		solve(n / 2, a, b);
		solve(n / 2, a, b + half);
		solve(n / 2, a + half, b);
		solve(n / 2, a + half, b + half);
		cout << ")";
	}


}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	std::string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	solve(n, 0, 0);


	return 0;
}