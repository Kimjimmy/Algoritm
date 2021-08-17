#include<iostream>
#include<array>

using namespace std;

int sorted[8];   // 정렬 배열은 반드시 전역 변수로 선언.

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
template<int n>
void merge(int(&arr)[n], int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else {
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}
	while (j<=end) { // 왼쪽 전멸
		sorted[k] = arr[j];
		k++;
		j++;
	}
	while (i <= mid) {
		sorted[k] = arr[i];
		k++;
		i++;
	}
	k--;
	while (k >= 0) {
		arr[start+k] = sorted[k];
		k--;
	}

}
template<int n>
void mergeSort(int(&arr)[n],int start,int end) {  // 절반으로 나눈다.
//void mergeSort(T& arr){
	int mid = (start + end) / 2;

	if (start < end) {
		// divide
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		// conquer
		merge(arr, start, mid, end);
	}
	else {
		return;
	}

}

int main() {

	int arr[]= { 7,6,5,8,3,5,9,1};
	
	// 
	mergeSort(arr,0,7);
	

	for (int i = 0; i <sizeof(arr)/sizeof(int);i++) {
		cout << arr[i] << " ";
	}
	return 0;
}