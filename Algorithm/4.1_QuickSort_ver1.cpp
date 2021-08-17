#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSort(int(&arr)[10], int start, int end) {

	if (start >= end) { return; }  // 이거를 계속 몰라서 해맸다.
	// start가 end 보다 크거나 같다라는 소리는 원소가 1개라는 소리다.

	int pivot = start;
	int maxIndex, minIndex;

	for (int i = start+1; i <= end; i++) {
		if (arr[pivot] < arr[i]) {
			maxIndex = i;
			break;
		}
		else { maxIndex = pivot; }
	}
	for (int j = end; j >= start; j--) {
		if (arr[pivot] > arr[j]) {
			minIndex = j;
			break;
		}
		else { minIndex = pivot; }
	}
	if (maxIndex >= minIndex) {
		swap(arr[minIndex], arr[pivot]);
		pivot = minIndex;
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
	else {
		swap(arr[minIndex], arr[maxIndex]);
		quickSort(arr, start, end);
	}
}


int main() {
	int arr[10] = { 5,6,4,2,3,1,9,8,10,7 };

	quickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}