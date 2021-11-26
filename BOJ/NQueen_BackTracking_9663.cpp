#include<iostream>
#include<vector>

using std::cin; using std::cout;

int n, answer;
int cols[16];

bool promising(int level) {  // 대각선, 세로에 다른 퀸 없는지 검사.
	if (level == 1)return true;  // 첫번째 퀸은 어디든 가능.
	for (int i = level - 1; i >= 1; i--) { // 현재 레벨 전 퀸들 전부 검사.
		// 대각선 검사. ( 두 지점 가로 차이랑 = 세로 차이랑 같으면 대각선.
		if (std::abs(cols[level] - cols[i]) == (level - i)) {
			return false;
		} // 세로 검사.
		else if (cols[i] == cols[level]) {
			return false;
		}
	}
	return true;  // 전부 검사했는데도 false 안되면 true;
}

void nQueen(int level) {

	for (int i = 1; i <= n; i++) {
		cols[level] = i;

		if (promising(level)) { // cols[level]이 i가 될 수 있다면
			if (level == n) {
				answer++;
				return;
			}
			nQueen(level + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int level = 1;
	nQueen(level); // 1 부터 시작.
	cout << answer;
	return 0;
}