#include<iostream>
#include<vector>
#include<math.h>

using std::cin; using std::cout;
using std::vector;

int a, b, c;

int solve(int a, int b) {
	if (b <= 1) {
		return  a % c;
	}
	long long r = solve(a, b / 2);
	if (b % 2 == 0) {
		return r * r % c;
	}
	else {
		return (((r * r) % c)*(a%c)) % c;
	}

}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b >> c;


	cout << solve(a, b);



	return 0;
}