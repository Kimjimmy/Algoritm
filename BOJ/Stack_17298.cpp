#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using std::cout; using std::cin;
using std::vector;

int n;
int result[1000001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	std::stack<std::pair<int, int>> st;
	cin >> n;
	int cnt = 0;
	std::fill_n(result + 1, n, -1);
	int size = n;
	while (n--) {
		int a;
		cin >> a;
		cnt++;

		while (!st.empty() && st.top().first < a) {
			result[st.top().second] = a;
			st.pop();
		}

		st.push({ a,cnt });
	}
	for (int i = 1; i <= size; i++) {
		cout << result[i] << " ";
	}

	return 0;
}