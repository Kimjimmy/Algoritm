#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>

using std::cout; using std::cin;
using std::vector;

int n;
std::string answer = "";
bool flag = true;
std::stack<int> st;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	int idx = 1;
	while (n--) {
		int cur;
		cin >> cur;
		while (idx <= cur) {
			st.push(idx++);
			answer += "+\n";
		}
		if (st.top() != cur) {
			cout << "NO\n";
			return 0;
		}
		st.pop();
		answer += "-\n";
	}
	cout << answer;

	return 0;
}