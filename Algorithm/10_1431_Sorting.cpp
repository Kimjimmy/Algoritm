#include<iostream>
#include<algorithm>
#include<string>

using std::endl;
using std::cout;
using std::cin;

int getSum(std::string s) {

	int a,sum = 0;
	for (int i = 0; i < s.length(); i++) { 
		if ((s[i] - '0') <= 9 && s[i] - '0' >= 0) {   // ������ ��쿡�� ���Ѵ�.
			a = s[i] - '0';
			sum += a;
		}
		
	}

	return sum;
}


// struct Compare ���� bool compare �ؼ� �Լ� ����°� �� ������, �ѹ� �غ��� �; �ϴ� �̷��� �ѹ� �غô�.
// ���� bool compare�� �ٽ� ����� ����.
struct Compare {

	bool operator () (const std::string& a, const std::string& b) {
		if (a.length() < b.length()) { // a, b ���̰� �ٸ��� ª������ �����´�.
			return 1;
		}
		else if (a.length() == b.length()) {  // ���̰� ���ٸ�.
			int aSum = getSum(a);
			int bSum = getSum(b);
			// ���ڿ� ���Ե� ������ ���� ���� �ٸ��ٸ�.
			if (aSum != bSum) {
				if (aSum < bSum) {
					return true;
				}
				else return false;
			}
			else {  // ���� ���� ���ٸ�
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