#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using std::cout; using std::cin;
using std::vector;

int N;
std::stack<int> st;
vector<int> building;
int answer;

void solve() {
	for(int i = 0; i < N; i++) {
		
		while (!st.empty() && st.top() <= building[i]) {
			st.pop();
		}
		st.push(building[i]);
		answer += st.size() - 1;
	}
	cout << answer;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	int size = N;
	while (size--) {
		int a;
		cin >> a;
		building.push_back(a);
	}
	solve();



	return 0;
}