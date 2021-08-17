#include<iostream>
#include<queue>

using std::endl;
using std::cout;

std::queue<int> que[10];

template <int n>
void print(int(&arr)[n]) {

	//cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
	//int size = sizeof(arr[0]) / sizeof(T);   // sizeof(T) 에서 T가 int* 라 4byte 구나..

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void radixSort(int* arr,const int length) {
	// 최댓값 구하기.
	int maxValue = 0;
	for (int i = 0; i < length; i++) {
		if (maxValue <= arr[i]) maxValue = arr[i];
	}
	// 최대 자릿수 구하기.
	int radix=1;  // 최대 자릿수
	for (; radix < maxValue; radix *= 10) {}
	// 최대 자리수 구하기 ver2.( 보기 쉽게 ) 
	//int k = 1;// 최대 자리수
	//while (maxValue / 10) {
	//	k *= 10;
	//	maxValue /= 10;
	//}

	// queue 에다가 1의자리 10의자리 100의자리 따로 따로 꺼냈다 넣으면서 정렬 완료됨.
	for (int k = 1; k < radix; k*=10) {
		for (int j = 0; j < length; j++) { // 모든 배열 탐색하면서 queue에 집어 넣는다.
			if (arr[j] < k) que[0].push(arr[j]);
			else {
				que[(arr[j] / k) % 10].push(arr[j]);
			}
		}
		// que[0] ~ que[9]까지 저장된 값들을 순차적으로 뺴내기 위한 반복문.
		for (int p=0, j = 0; j < 10; j++) {
			while (que[j].empty() == false) { // 큐가 비었으면 true 아니면 false 리턴
					arr[p] = que[j].front(); // 하나씩 빼면서 배열에 다시 저장.
					que[j].pop();
					p++;
			}
		}
	}
}

int main() {

	int arr[10] = { 10, 28, 498, 2, 15, 8, 67, 0, 3, 100 };
	const int length = 10;
	radixSort(arr, length);
	print(arr);



	return 0;
}