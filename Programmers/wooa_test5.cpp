#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
	int answer = 0;

	map<string, int> menu_profit;
	map<string, int> profit;

	vector<vector<string>> ings_profit(ings.size());

	for (int i = 0; i < ings.size(); i++) {
		ings_profit[i] = split(ings[i], ' ');
		profit[ings_profit[i][0]] = stoi(ings_profit[i][1]);
	}
	
	vector<vector<string>> menu_vec(menu.size());

	for (int i = 0; i < menu.size(); i++) {
		menu_vec[i] = split(menu[i], ' ');

		string ingredient = menu_vec[i][1];
		int total_cost = 0;
		string temp = "";
		for (size_t j = 0; j < ingredient.length(); j++) {
			total_cost += profit[temp+ingredient[j]];
		}

		menu_profit[menu_vec[i][0]] = stoi(menu_vec[i][2])-total_cost;
	}

	vector<vector<string>> sell_vec(sell.size());

	for (int i = 0; i < sell.size(); i++) {
		sell_vec[i] = split(sell[i], ' ');

		int cnt = stoi(sell_vec[i][1]);
		answer += menu_profit[sell_vec[i][0]] * cnt;
	}
	
	return answer;
}

int main() {
	vector<string> ings = { "x 25", "y 20", "z 1000" };
	vector<string> menu = { "AAAA xyxy 15", "TTT yy 30", "BBBB xx 30" };
	vector<string> sell = { "BBBB 3", "TTT 2" };
	cout << solution(ings, menu, sell);
	return 0;
}