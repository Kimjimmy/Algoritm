#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::vector;


int n;
int graph[129][129];
bool is_same = true;
int arr[2];

void solve(int n, int a, int b) {

	if (n == 1) {  // base case
		arr[graph[a][b]]++;
		return;
	}
	int pivot = graph[a][b];
	bool is_same = true;

	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (pivot != graph[i][j]) {
				is_same = false;
				break;
			}
		}
		if (!is_same)break;
	}

	if (!is_same) {
		solve(n / 2, a, b);
		solve(n / 2, a + n / 2, b);
		solve(n / 2, a, b + n / 2);
		solve(n / 2, a + n / 2, b + n / 2);
	}
	else {
		arr[graph[a][b]]++;
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	solve(n, 0, 0);

	cout << arr[0] << '\n' << arr[1];


	return 0;
}