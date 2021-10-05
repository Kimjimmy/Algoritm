#include<iostream>
#include<list>
#include<string>
//#include<string.h> // strlen �Լ��� �̿��ϱ� ���ؼ�

using namespace std;

//char input[100000];  // string���� ���������ִµ� char�� �ѹ� �Ẹ�� �;���.

string input="";
list<char> str;


int main() {
	unsigned int m;
	char order;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> input;  // ���⳪ ���� �������� input�� �����Ѵ�.

	// cin.ignore(100, '\n');  -> �����൵ �ȴ� ��¥�� cin�� ���๮�ڰ� ���ۿ� �����ִ��� �����Ѵ�.
	cin >> m;

	// str�� �Է��� ���ڿ� �־��ְ�
	for (size_t i = 0; i < input.length(); i++) {
		str.push_back(input[i]);
	}
	//list<char> str(input.begin(), input.end());

	
	list<char>::iterator cursor = str.end();  // ó���� Ŀ�� �ڿ��� ���� ����.

	for (unsigned int i = 0; i < m; i++) {
		cin >> order;
		switch (order)
		{
		case 'L':
			if (cursor != str.begin()) {
				cursor--;
				break;
			}
			break;
		case 'D':
			if (cursor != str.end()) {
				cursor++;
				break;
			}
			break;
		case 'B':
			if (cursor != str.begin()) {
				cursor = str.erase(--cursor); // �� cursor�� �޾�����Ѵ� �ȱ׷��� ���� ����.
				break;
			}
			break;
		case 'P': 
			cin >> order;
			str.insert(cursor, order);
			break;
		
		
		}
	}

	for (auto elem : str) cout << elem;

	return 0;
}
