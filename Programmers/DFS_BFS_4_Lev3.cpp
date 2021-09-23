#include <string>
#include<iostream>
#include <vector>
#include<stack>
#include<algorithm>

using namespace std;

string current;
stack<string > st;
bool flag;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	std::sort(tickets.begin(), tickets.end());


	st.push("ICN");


	while (tickets.size()) {
		flag = true;
		current = st.top();

		size_t i;
		for (i = 0; i < tickets.size(); i++) {
			if (tickets[i][0] == current) {
				st.push(tickets[i][1]);
				tickets.erase(tickets.begin() + i);
				flag = false;
				break;
			}
		}
		if (i == tickets.size() && flag) {  // 고립된 노드로 들어갔거나, size()가 줄어들어 i랑 똑같아 지거나.
			answer.push_back(st.top());
			st.pop();
		}
	}

	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}


	std::reverse(answer.begin(), answer.end());

	return answer;
}


int main() {

	vector<vector<string>> tickets = { {"ICN", "JFK" }, {"HND", "IAD"},{"JFK", "HND"} };
	vector<vector<string>> tickets2 = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "SFO"},{"ATL", "ICN"} };
	vector<vector<string>> tickets3 = { {"ICN", "AOO"}, { "AOO", "BOO" }, { "BOO", "COO" }, { "COO", "DOO" }, { "DOO", "EOO" }, { "EOO", "DOO" }, { "DOO", "COO" }, { "COO", "BOO" }, { "BOO", "AOO" } };

	for (auto elem : solution(tickets3)) {
		cout << elem << " ";
	}

	// ["ICN", "AOO", "BOO", "COO", "DOO", "EOO", "DOO", "COO", "BOO", "AOO"]

	return 0;
};