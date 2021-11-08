#include <string>
#include <vector>
#include<iostream>
//#include<cctype>;

using namespace std;
double stime,ftime;

string solution(double time, vector<vector<string>> plans) {
	string answer = "";
	
	for (int i = 0; i < plans.size(); i++) {
		bool possible = true;
		double total_time = 0;
		string st = plans[i][1];
		size_t sz;
		auto stime = stod(st, &sz);
		if (st[sz] == 'P') { stime += 12.0f; }
		
		string dt = plans[i][2];
		size_t sz2;
		auto ftime = stod(dt, &sz2);
		if (st[sz2] == 'P') { ftime += 12.0f; }

		if (stime < 18.0f) {
			total_time += 18.0f - stime;
		}
		if (ftime > 13.0f) {
			total_time += ftime - 13.0f;
		}
		if (time <= total_time)possible = false;
		if (possible)answer += plans[i][0];
	}
	
	return answer;
}

int main() {
	vector<vector<string>> plans = { {"¿¤¿¡ÀÌ", "3PM", "2PM"},{"È«Äá", "11PM", "9AM" } };
	cout << solution(3.5, plans);
	return 0;
}