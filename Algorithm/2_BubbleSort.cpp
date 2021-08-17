#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int (&arr)[10]) {
	int max = 9;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < max; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
		max--;
	}
}

int main() {
	int arr[10] = { 5,6,4,2,3,1,9,8,10,7 };

	bubbleSort(arr);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}