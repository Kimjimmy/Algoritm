#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>

using std::cout; using std::cin;
using std::deque; using std::string;

int n, t;
string p;
string s_arr;

deque<int> split(string input, char delimeter) {
	deque<int> answer;

	input.erase(input.begin()); //input.erase(0)  '['  지움
	input.erase(input.end() - 1);                  // ']'  지움


	std::stringstream ss(input);
	string num = "";
	while (getline(ss, num, delimeter)) {
		answer.push_back(std::stoi(num));
	}
	return answer;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;

		cin.ignore(10, '\n');
		getline(cin, s_arr);

		deque<int> arr = split(s_arr, ',');

		bool is_error = false;
		bool reverse = false;

		for (size_t i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				//std::reverse(arr.begin(), arr.end());
				reverse = !reverse;
			}
			else {
				if (arr.empty()) {
					cout << "error\n";
					is_error = true;
					break;
				}
				if (reverse) {
					arr.pop_back();
				}
				else {
					arr.pop_front();
				}
			}
		}
		// 출력
		if (!is_error) {
			if (arr.empty()) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				if (reverse) {
					for (auto ritr = arr.rbegin(); ritr != arr.rend(); ritr++) {
						if (ritr == arr.rend() - 1) {
							cout << *ritr;
							break;
						}
						cout << *ritr << ",";
					}
				}
				else {
					for (int i = 0; i < arr.size(); i++) {
						if (i == arr.size() - 1) {
							cout << arr[i];
							break;
						}
						cout << arr[i] << ",";
					}
				}
				cout << "]\n";
			}
		}
		s_arr.clear();
	}

	return 0;

}