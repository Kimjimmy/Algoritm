#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//string a[20000];

int n;

bool compare(string a, string b) {
	// 길이가 짧은 순서 부터 확인.
	if (a.length() < b.length()) {
		return 1;
	} 
	else if (a.length() > b.length()) {
		return 0;
	}
	else {  // 길이가 같은 경우에는 
		return a < b;   // string 라이브러리에 사전순으로 비교되게 해놓는 함수가 있다.
	}                   // 그래서 편리.
}

int main() {
	// 단어개수 N 이 1<=N<=20,000 으로 주어졌으니 c++ sort 알고리즘을 사용해도 된다.
	
	
	int num;
	cin >> num;
	string* arr = new string[num];

	for (int i = 0; i < num;i++) {
		cin >> arr[i];		
	}

	std::sort(arr,arr+num,compare);

	for (int i = 0; i < num; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) {  // 같은 단어가 여러번 입력된 경우에는 한 번씩만 출력한다.
			continue;
		}
		else {
			cout << arr[i] << endl;
		}
	}
	return 0;
}