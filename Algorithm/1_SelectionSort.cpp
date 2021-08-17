#include<iostream>

using namespace std;
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
template<int n>
void selectionSort(int(&arr)[n]) {
	for (int i = 0; i < n-1; i++) {
		int location = i; // 작은 값의 index를 저장.
		for (int j = i + 1; j < n; j++) {
			if (arr[location] > arr[j]) {
				location = j;
			}
		}
		swap(arr[location], arr[i]);
	}
}

int main() {

	int a[10] = { 1,6,10,4,5,9,3,2,8,7};
	selectionSort(a);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}