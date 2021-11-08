#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using std::string; using std::vector;
using std::cin; using std::cout;

string str = "17";
std::set<int> output;

void permutation(int k,int r) {
	if (k == r) {
		int num = 0;
		for (int i = 0; i < r; i++) {
			num = num * 10 + (str[i] - '0');
		}
		if(num) output.insert(num);
	}
	for (int i = k; i < str.length(); i++) {
		std::swap(str[i], str[k]);
		permutation(k + 1, r);
		std::swap(str[i], str[k]);
	}
	
}
bool sosu(int num) {
	if (num < 2)return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) { // i를 생각없이 0으로 나눴다. 소수를 구할때는 2부터 나누면 된다. 
		if (!(num%i)) return false; // 나머지가 0 이면 소수가 아니다.
	}
	return true;
}

int solution() {
	int answer = 0;
	//output.reserve(std::pow(2, str.length()));
	for (int i = 1; i <= str.length(); i++) {
		permutation(0,i);
	}
	
	
	for (std::set<int>::iterator itr = output.begin(); itr != output.end(); itr ++) {
		if (sosu(*itr)) answer++;
	}

	return answer;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cout <<	solution();


	return 0;
}