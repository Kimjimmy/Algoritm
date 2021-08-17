#include <iostream>

using namespace std;

int arr[1000001];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

}
void quickSort(int *arr, int start, int end) {
	if (start >= end)return;
	int pivot=start;
	int i = start + 1;
	int j = end;

	while(i <= j) {
		while (arr[i] < arr[pivot] && i <= end) {
			i++;
		}
		while (arr[j] > arr[pivot] && j > start) {
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
	

	int N;

	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}




	return 0;
}