#include<iostream>
#include<vector>
#include<algorithm>

using std::cin; using std::cout;
using std::vector;

int n, k;
int weight[101];
int value[101];
int opt[101][100001];

void dp(int n, int k) {

	// 0 행에 0 으로 초기화.
	for (int i = 0; i <= n; i++) {
		opt[i][0] = 0;
	}

	// 0 열에 0 으로 초기화.
	for (int j = 0; j <= k; j++) {
		opt[0][j] = 0;
	}
	// 순환식 풀이
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (weight[i] > j) {
				opt[i][j] = opt[i - 1][j];
				//cout << opt[i][j] << " ";
				continue;
			}
			if (opt[i - 1][j] > opt[i - 1][j - weight[i]] + value[i]) {
				opt[i][j] = opt[i - 1][j];
				//cout << opt[i][j] << " ";
			}
			else {
				opt[i][j] = opt[i - 1][j - weight[i]] + value[i];
				//cout << opt[i][j] << " ";
			}
		}
		//cout << '\n';
	}
	// 정답 출력.
	cout << opt[n][k];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	dp(n, k);




	return 0;
}