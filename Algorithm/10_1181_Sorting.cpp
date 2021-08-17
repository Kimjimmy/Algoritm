#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//string a[20000];

int n;

bool compare(string a, string b) {
	// ���̰� ª�� ���� ���� Ȯ��.
	if (a.length() < b.length()) {
		return 1;
	} 
	else if (a.length() > b.length()) {
		return 0;
	}
	else {  // ���̰� ���� ��쿡�� 
		return a < b;   // string ���̺귯���� ���������� �񱳵ǰ� �س��� �Լ��� �ִ�.
	}                   // �׷��� ��.
}

int main() {
	// �ܾ�� N �� 1<=N<=20,000 ���� �־������� c++ sort �˰����� ����ص� �ȴ�.
	
	
	int num;
	cin >> num;
	string* arr = new string[num];

	for (int i = 0; i < num;i++) {
		cin >> arr[i];		
	}

	std::sort(arr,arr+num,compare);

	for (int i = 0; i < num; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) {  // ���� �ܾ ������ �Էµ� ��쿡�� �� ������ ����Ѵ�.
			continue;
		}
		else {
			cout << arr[i] << endl;
		}
	}
	return 0;
}