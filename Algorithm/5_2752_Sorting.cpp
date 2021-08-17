#include <iostream>

using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

}
void insertionSort(int *arr, int start, int end) {

	for (int i = start; i < end-1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
		int j = i;
		while (arr[j] < arr[j - 1]&&j>0) {
			swap(arr[j], arr[j - 1]);
			j--;
		}

		// 아래처럼 간단히도 할 수 있다.
		/*while (arr[j] > arr[j + 1] && j >= 0)
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}*/
	


	}
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	insertionSort(arr, 0, 10);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}




	return 0;
}