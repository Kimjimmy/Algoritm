#include<iostream>
#include<queue>


using namespace std;

//	- 예제(요세푸스 문제)
//	1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다.
//	이제 순서대로 K번째 사람을 제거한다.한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
//	이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
//	원에서 사람들이 제거되는순서를 (N,K)요세푸스 순열이라고 한다. 예를들어 (7,3)-요세푸스 순열은 <3,6,2,7,5,1,4> 이다.
//	입력 : test case 갯수, N, K(첫째줄에 N과 K가 빈칸을 사이에 두고 순서대로 주어진다. 1<=K<=N<=5,000 )
//	출력 : (N,K) 요세푸스 순열을 출력.

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
	// 1.... n 까지 queue에 들어갔다.

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

	// arr를 이용해서 range based for문 사용하려고 했는데 동적할당한 arr는 range based for loop을 사용할수 없다. ===> vector를 애용하자!!
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[n - 1] << ">";

}