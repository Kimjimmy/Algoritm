#include<iostream>
#include<algorithm>




// 백준 Q 10989.
// 데이터의 개수가 N (1 <= N <= 10,000,000 ) 이 주어진다고 문제에 나왔다.
// 우선 데이터 크기가 천만으로 크기 때문에 o(n^2) 알고리즘으로 풀면 안된다.
// 더군다나 nlogn 에다가 천만을 넣어도 2억이 조금 넘는다. 채점 시스템에서는 2억번 정도면 오답처리를 할 정도로 많은 연산량이다.
// 그렇기 때문에 이런 문제는 범위조건이 주어지기 이기때문에 카운팅 소팅(계수정렬)과 같은 알고리즘을 사용하면 문제를 해결 할 수 있다.
// 시간 복잡도 o(n)
// 계수 정렬 같은 경우에는 문제의 데이터 (N) 의 개수가 아무리 많다고 하더라도,
// 특정 범위 조건이 주어지면 효과적으로 문제를 풀수있도록 해준다.

using std::endl;
using std::cout;
using std::cin;

int input[10001] = { 0, };
// int input[10001];   이렇게 배열을 전역변수로 두면 안의 모든 인덱스는 0 으로 초기화된다.

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	// 데이터의 개수 입력.
	cin >> n;
	int x;
	// 데이터의 개수만큼 해당 인덱스의 숫자 증가.
	for (int i = 0; i < n; i++) {
		cin >> x;
		input[x]++;
	}
	// 10001까지 반복하면서 출력.
	for (int i = 0; i < 10001; i++) {
		while (input[i] != 0) {
			cout << i << '\n';
			input[i]--;
		}
	}
	

	return 0;
}