#include<iostream>
#include<vector>

using std::cin; using std::cout;

int n, answer;
int cols[16];

bool promising(int level) {  // �밢��, ���ο� �ٸ� �� ������ �˻�.
	if (level == 1)return true;  // ù��° ���� ���� ����.
	for (int i = level - 1; i >= 1; i--) { // ���� ���� �� ���� ���� �˻�.
		// �밢�� �˻�. ( �� ���� ���� ���̶� = ���� ���̶� ������ �밢��.
		if (std::abs(cols[level] - cols[i]) == (level - i)) {
			return false;
		} // ���� �˻�.
		else if (cols[i] == cols[level]) {
			return false;
		}
	}
	return true;  // ���� �˻��ߴµ��� false �ȵǸ� true;
}

void nQueen(int level) {

	for (int i = 1; i <= n; i++) {
		cols[level] = i;

		if (promising(level)) { // cols[level]�� i�� �� �� �ִٸ�
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
	nQueen(level); // 1 ���� ����.
	cout << answer;
	return 0;
}