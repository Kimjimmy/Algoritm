#include<iostream>
#include<algorithm>
#include<string>

using std::endl;
using std::cout;
using std::cin;

int getSum(std::string s) {

	int a,sum = 0;
	for (int i = 0; i < s.length(); i++) { 
		if ((s[i] - '0') <= 9 && s[i] - '0' >= 0) {   // 숫자인 경우에만 더한다.
			a = s[i] - '0';
			sum += a;
		}
		
	}

	return sum;
}


// struct Compare 말고 bool compare 해서 함수 만드는게 더 빠른데, 한번 해보고 싶어서 일단 이렇게 한번 해봤다.
// 내일 bool compare로 다시 만들어 보기.
struct Compare {

	bool operator () (const std::string& a, const std::string& b) {
		if (a.length() < b.length()) { // a, b 길이가 다르면 짧은것이 먼저온다.
			return 1;
		}
		else if (a.length() == b.length()) {  // 길이가 같다면.
			int aSum = getSum(a);
			int bSum = getSum(b);
			// 글자에 포함된 숫자의 합이 서로 다르다면.
			if (aSum != bSum) {
				if (aSum < bSum) {
					return true;
				}
				else return false;
			}
			else {  // 숫자 합이 같다면
				return a < b;
			}
		}
		else {
			return false;
		}

	}
};


int main() {
	int num;
	cin >> num;

	std::string* arr = new std::string[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	std::sort(arr, arr + num, Compare());

	for (int j = 0; j < num; j++) {
		cout << arr[j] << " ";
	}
	

	return 0;
}