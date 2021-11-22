#include<iostream>
#include<algorithm>

using std::cout; using std::cin;

int n;
int num[10];

int main() {

	cin >> n;

	for (;;) {
		num[n % 10]++;
		n = n / 10;
		if (n == 0) break;
	}
	int answer = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 6 || i == 9)continue;
		answer = std::max(num[i], answer);
	}
	answer = std::max((num[6] + num[9] + 1) / 2, answer);  // 반올림 스킬.

	cout << answer;


	return 0;
}