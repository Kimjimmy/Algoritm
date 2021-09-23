#include<iostream>
#include <string>
#include <vector>

// 고득점 kit [Stack] - 주식 가격
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(),0);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	
	//auto&& itr = prices.begin();
	int j = 0;
	for (int i=0; i<prices.size();i++) {
		for (j=i+1; j < prices.size(); j++) {
				if(prices[i]<=prices[j]){
					answer[i]++;
				}
				else {
					answer[i]++;
					break;
				}			
		}
	}

	return answer;
}

int main() {
	vector<int> a = { 3,7,7,6,7 };
	for (auto elem : solution(a)) {
		cout << elem << "  ";
	}


	return 0;
}