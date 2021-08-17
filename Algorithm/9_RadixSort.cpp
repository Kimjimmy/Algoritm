#include<iostream>
#include<queue>

using std::endl;
using std::cout;

std::queue<int> que[10];

template <int n>
void print(int(&arr)[n]) {

	//cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
	//int size = sizeof(arr[0]) / sizeof(T);   // sizeof(T) ���� T�� int* �� 4byte ����..

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void radixSort(int* arr,const int length) {
	// �ִ� ���ϱ�.
	int maxValue = 0;
	for (int i = 0; i < length; i++) {
		if (maxValue <= arr[i]) maxValue = arr[i];
	}
	// �ִ� �ڸ��� ���ϱ�.
	int radix=1;  // �ִ� �ڸ���
	for (; radix < maxValue; radix *= 10) {}
	// �ִ� �ڸ��� ���ϱ� ver2.( ���� ���� ) 
	//int k = 1;// �ִ� �ڸ���
	//while (maxValue / 10) {
	//	k *= 10;
	//	maxValue /= 10;
	//}

	// queue ���ٰ� 1���ڸ� 10���ڸ� 100���ڸ� ���� ���� ���´� �����鼭 ���� �Ϸ��.
	for (int k = 1; k < radix; k*=10) {
		for (int j = 0; j < length; j++) { // ��� �迭 Ž���ϸ鼭 queue�� ���� �ִ´�.
			if (arr[j] < k) que[0].push(arr[j]);
			else {
				que[(arr[j] / k) % 10].push(arr[j]);
			}
		}
		// que[0] ~ que[9]���� ����� ������ ���������� ������ ���� �ݺ���.
		for (int p=0, j = 0; j < 10; j++) {
			while (que[j].empty() == false) { // ť�� ������� true �ƴϸ� false ����
					arr[p] = que[j].front(); // �ϳ��� ���鼭 �迭�� �ٽ� ����.
					que[j].pop();
					p++;
			}
		}
	}
}

int main() {

	int arr[10] = { 10, 28, 498, 2, 15, 8, 67, 0, 3, 100 };
	const int length = 10;
	radixSort(arr, length);
	print(arr);



	return 0;
}