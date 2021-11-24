#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using std::cout; using std::cin;
using std::vector;

int H, W;
int answer;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	std::stack<int> st;
	cin >> H >> W;

	int max = 0;

	while (W--) {
		int h;
		cin >> h;
		
		int cnt = 0;
		while (!st.empty() && st.top() < h) {

			// ���⿡ ���� ���� ���ҵ��� ���� max ���� �ٽ� ä�� ������ ���� ������.
			if (h > max && st.top()<=max) {  
				answer += max - st.top();
				st.pop();
			
			}
			else {
				answer += h - st.top();
				st.pop();
				cnt++;
			}
		}
		if (cnt) {
			for (int i = 0; i < cnt; i++) {
				st.push(h);
			}
		}

		max = std::max(max, h);  // ���� �ְ� ��.
		st.push(h);

	}
	cout << answer;

	return 0;
}