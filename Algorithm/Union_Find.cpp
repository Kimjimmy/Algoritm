#include<iostream>
#include<algorithm>
using namespace std;

int parent[10];
int size[10];



int findSet(int (&parent)[10], int x) {
	if (parent[x] != x) {
		parent[x] = findSet(parent, parent[x]);
	}
	return parent[x];
}

void Union(int(&parent)[10], int a, int b) {
	a = findSet(parent, a);
	b = findSet(parent, b);
	if (::size[a] < ::size[b]) { 
		parent[a] = b; 
		::size[b] = ::size[a] + ::size[b];
	}
	else { 
		parent[b] = a;
		::size[a] = ::size[a] + ::size[b];
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		parent[i] = i;
	 }
	fill_n(::size, 10, 1);
	
	Union(parent, 1, 2);
	Union(parent, 2, 3);
	Union(parent, 3, 4);
	Union(parent, 5, 6);
	Union(parent, 6, 7);
	Union(parent, 7, 8);

	cout << "1�� 5�� ����Ǿ� �ֳ���?" << '\n';
	if (findSet(parent, 1) == findSet(parent, 5)) {
		cout << " �� ����Ǿ� �ֽ��ϴ�.";
	}
	else {
		cout << "�ƴϿ� ���� �Ǿ� ���� �ʽ��ϴ�." << '\n';

	}
	cout << "================================" << '\n';
	Union(parent, 1, 6);
	cout << " 1 ��  6 ����." << '\n';
	cout << "================================" << '\n';

	cout << "1�� 5�� ����Ǿ� �ֳ���?" << '\n';
	if (findSet(parent, 1) == findSet(parent, 5)) {
		cout << " �� ����Ǿ� �ֽ��ϴ�.";
	}
	else {
		cout << "�ƴϿ� ���� �Ǿ� ���� �ʽ��ϴ�." << '\n';

	}
	

	return 0;
}