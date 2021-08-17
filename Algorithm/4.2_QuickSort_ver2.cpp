#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSort(int(&arr)[10], int start, int end) {
	if (start >= end) { return; } // 원소가 1개일떄 그냥 그대로 return;
	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (arr[i] > arr[pivot]&& i<=end) {
			i++;
		}
		while (arr[j] < arr[pivot]&& j>start) {
			j--;
		}
		if (i >= j) {
			swap(arr[j], arr[pivot]);
		}
		else {
			swap(arr[i], arr[j]);
		}
	}
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
	
	
}


int main() {
	int arr[10] = {10,9,2,7,6,5,8,4,3,1 };

	quickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

