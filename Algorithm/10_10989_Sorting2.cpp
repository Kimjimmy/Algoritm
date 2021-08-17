#include<iostream>
#include<algorithm>
#include <queue>

// 계수정렬이 radix Sort 인줄 알고 착각하고 문제 풀었다. 아래의 코드는 radix 정렬.

// 백준 Q 10989.
// 데이터의 개수가 N (1 <= N <= 10,000,000 ) 이 주어진다고 문제에 나왔다.
// 우선 데이터 크기가 천만으로 크기 때문에 o(n^2) 알고리즘으로 풀면 안된다.
// 더군다나 nlogn 에다가 천만을 넣어도 2억이 조금 넘는다. 채점 시스템에서는 2억번 정도면 오답처리를 할 정도로 많은 연산량이다.
// 그렇기 때문에 이런 문제는 범위조건이 주어지기 이기때문에 카운팅 소팅(계수정렬)과 같은 알고리즘을 사용하면 문제를 해결 할 수 있다.
// 계수 정렬 같은 경우에는 문제의 데이터 (N) 의 개수가 아무리 많다고 하더라도,
// 특정 범위 조건이 주어지면 효과적으로 문제를 풀수있도록 해준다.

using std::endl;
using std::cout;
using std::cin;

int input[10001] = { 0, };
std::queue<int> que[10];

void radixSort(int* arr, int n) {
	// 제일 큰수 구하고
	int maxNumber=0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxNumber) {
			maxNumber = arr[i];
		}
	}
	// 제일 큰수의 자리수( 제일 큰 자리수 ) 구하고
	int radix=1;
	while (maxNumber >= radix) {
		radix *= 10;
	}  // 제일 큰 수의 자리수 구하기.
	// for (; radix < maxValue; radix *= 10) {}

	// 0~9까지 있는 que에 삽입.
	for (int i = 1; i < radix; i *= 10) {
		for (int j = 0; j < n; j++) { // 다 돌면서 
			if (arr[j] < i) {  // i 보다 작으면 que[0]에 넣어준다.
				que[0].push(arr[j]);
			}
			else {
				que[(arr[j] / i) % 10].push(arr[j]);

			}
		}
		// que 밖으로 순서대로 뺴내고,다음 자리수 배교.
		for (int z = 0,p=0; z < 10; z++) {
			while (!que[z].empty()) {
				arr[p] = que[z].front();  // 맨 위를 리턴.
				que[z].pop();  // front()는 리턴만 해주니 pop()으로 que의 원소를 없애주지 않으면 while문 무한루프를 돌게 된다.
				p++;
			}
		}
	}
}

int main() {
	int n = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	radixSort(input,n);

	for (int i = 0; i < 10001; i++) {
		while (input[i] != 0) {
			cout << input[i] << '\n';
			input[i]--;
		}
	}

	return 0;
}