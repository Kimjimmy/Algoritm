#include<iostream>
#include<vector>
#include<stack>
#include<cmath>

using namespace std;
int n;

//int start = 0;
//int end = 2;

void move(int n, int s, int t) {
	int other = 6 - s - t;
	if (n == 1) {
		cout << s << " " << t << '\n';
	}
	else {
		move(n - 1, s, other);
		move(1, s, t);
		move(n - 1, other, t);
	}
}

int main() {
	std::cin >> n;
	cout << (1 << n) - 1 << '\n';
	move(n, 1, 3);


	return 0;
}