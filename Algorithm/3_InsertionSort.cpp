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
//	for (int i = 0; i < 9; i++) {  // 10�� �ݺ�.
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
			// for ������ �ϸ� �̹� ���ĵ� ���� ���ڸ� ���� �� Ž���ϴ°Ŷ� ��ȿ����.
			// while �������� �ϴ°� ���� ������. ( ���� ����Ʈ�� �˰��������� ȿ����)

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


