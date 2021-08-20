#include<iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int max = *max_element(priorities.begin(), priorities.end());
	while (true)
	{
		for (int i = 0; i < priorities.size(); ++i)
		{
			if (priorities[i] == max)
			{
				++answer;

				if (i == location)
					return answer;

				priorities[i] = 0;
				max = *max_element(priorities.begin(), priorities.end());
			}
		}
	}
}
int main() {
	vector<int> p = {3,4,3 };
	int a = 0;
	cout << solution(p, a);

	return 0;
}