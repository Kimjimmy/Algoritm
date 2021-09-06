#include<iostream>
#include<list>
#include<string>
//#include<string.h> // strlen 함수를 이용하기 위해서

using namespace std;

//char input[100000];  // string으로 받을수도있는데 char도 한번 써보고 싶었다.

string input="";
list<char> str;


int main() {
	unsigned int m;
	char order;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> input;  // 띄어씌기나 엔터 전까지만 input에 저장한다.

	// cin.ignore(100, '\n');  -> 안해줘도 된다 어짜피 cin은 개행문자가 버퍼에 남아있더라도 무시한다.
	cin >> m;

	// str에 입력한 문자열 넣어주고
	for (size_t i = 0; i < input.length(); i++) {
		str.push_back(input[i]);
	}
	//list<char> str(input.begin(), input.end());

	
	list<char>::iterator cursor = str.end();  // 처음에 커서 뒤에서 부터 시작.

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
				cursor = str.erase(--cursor); // 꼭 cursor로 받아줘야한다 안그러면 오류 난다.
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
