#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSort(int(&arr)[10], int start, int end) {

	if (start >= end) { return; }  // �̰Ÿ� ��� ���� �ظ̴�.
	// start�� end ���� ũ�ų� ���ٶ�� �Ҹ��� ���Ұ� 1����� �Ҹ���.

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