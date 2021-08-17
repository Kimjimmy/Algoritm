#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//void insertionSort(int(&arr)[10]) {
//
//
//	for (int i = 0; i < 9; i++) {  // 10번 반복.
//
//		for (int j = i + 1; j > 0; j--) {
//			if (arr[j-1] > arr[j ]) {
//				swap(arr[j-1], arr[j]);
//			}
//		}
//	}
//
//}
// void insertionSort(int& arr[10])
void insertionSort(int(&arr)[10]) {
	for (int i = 0; i < 9; i++) {

		//for (int j = i; j >0; j--) {
			// for 문으로 하면 이미 정렬된 이전 숫자를 전부 다 탐색하는거라 비효율적.
			// while 문장으로 하는게 삽입 정렬임. ( 멈출 포인트를 알고있음으로 효율적)

		int j = i;
		while (arr[j] > arr[j + 1]&& j>=0)
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}


int main() {
	int arr[10] = { 10,6,4,2,3,1,9,8,10,7 };

	insertionSort(arr);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}


