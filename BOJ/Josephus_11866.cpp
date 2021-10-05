#include<iostream>
#include<queue>


using namespace std;

//	- ����(�似Ǫ�� ����)
//	1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����.
//	���� ������� K��° ����� �����Ѵ�.�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������.
//	�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�.
//	������ ������� ���ŵǴ¼����� (N,K)�似Ǫ�� �����̶�� �Ѵ�. ������� (7,3)-�似Ǫ�� ������ <3,6,2,7,5,1,4> �̴�.
//	�Է� : test case ����, N, K(ù°�ٿ� N�� K�� ��ĭ�� ���̿� �ΰ� ������� �־�����. 1<=K<=N<=5,000 )
//	��� : (N,K) �似Ǫ�� ������ ���.

void josephus(int n, int k);

int main() {

	int k, n;
	cin >> n;
	cin >> k;

	josephus(n, k);

	return 0;

}
void josephus(int n, int k) {
	queue<int> survivors;
	int* arr = new int[n];

	for (int i = 1; i <= n; ++i) survivors.push(i);
	// 1.... n ���� queue�� ����.

	int j = 1;
	int i = 0;
	while (!survivors.empty()) {

		if (j == k) {
			arr[i++] = survivors.front();
			survivors.pop();
			j = 1;
		}
		else {
			survivors.push(survivors.front());
			survivors.pop();
			j++;
		}
	}

	// arr�� �̿��ؼ� range based for�� ����Ϸ��� �ߴµ� �����Ҵ��� arr�� range based for loop�� ����Ҽ� ����. ===> vector�� �ֿ�����!!
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[n - 1] << ">";

}