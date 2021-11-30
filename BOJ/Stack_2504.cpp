#include<iostream>
#include<vector>
#include<string>
#include<stack>


using std::cin; using std::cout;
using std::vector;



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	std::string str;

	std::stack<char> st;

	int sum = 0;
	int num = 1;
	cin >> str;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push('(');
			num *= 2;
		}
		else if (str[i] == '[') {
			st.push('[');
			num *= 3;
		}
		else if (str[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				if (str[i - 1] == '(') {
					sum += num;
				}
				num /= 2;
				st.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else {
			if (!st.empty() && st.top() == '[') {
				if (str[i - 1] == '[') {
					sum += num;
				}
				num /= 3;
				st.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	if (st.empty())cout << sum;
	else cout << 0;


	return 0;
}