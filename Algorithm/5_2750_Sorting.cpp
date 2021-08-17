#include <iostream>

void quickSort(int *arr,int start,int end) {
	if (start >= end) { return; }

	int pivot = start;
	int i = start+1;
	int j = end;
	int temp;

	while (i <= j) {
		while (arr[i] > arr[pivot]&& i<=end) {
			i++;
		}
		while (arr[j] < arr[pivot] && j > start) {
			j--;
		}
		if (i >= j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		quickSort(arr, start, j - 1);
		quickSort(arr, j + 1, end);
	}
}
void selectionSort(int* arr, int start, int end) {
	int min,temp;
	for (int i = start; i < end; i++) {
		min = i;
		for (int j = i + 1; j < end+1; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {
	const int max = 1001;
	int array[max];
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> array[i];
	}
	selectionSort(array, 0, N - 1);
	//quickSort(array,0,N-1);
	
	for (int i = 0; i < N; i++) {
		std::cout << array[i] << std::endl;
	}

	return 0;
}