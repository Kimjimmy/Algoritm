#include<iostream>
#include<boost/type_index.hpp>

using namespace std;

template <int n>
void print(int (&arr)[n]) {

	//cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
	//int size = sizeof(arr[0]) / sizeof(T);   // sizeof(T) 에서 T가 int* 라 4byte 구나..

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

template<int n>
void heapify(int(&arr)[n], int root ,int max) {
	// root 부터 0 까지
	for(int i=root;i>=0;i--){

		// root 의 자식이 1개 일때 처리.
		if (i * 2 + 2 >max) {
			if (arr[i* 2 + 1] > arr[i]) {
				std::swap(arr[i * 2 + 1],arr[i]);
			}
		}
		else { // root 자식이 2개일 때
			while (arr[i] < arr[i * 2 + 1] || arr[i] < arr[2 * i + 2]) {
				arr[2 * i+1] > arr[2 * i + 2]? std::swap(arr[2 * i+1], arr[i]) : std::swap(arr[2 * i + 2], arr[i]);
				}
			}
		}
	
}
	
template<int n>
void heapSort(int(&arr)[n]) {
	int max = n - 1;
	int root;
	while (max >= 1) {

		if (max % 2 == 1) {
			root = max / 2;
		}
		else {
			root = (max - 2) / 2;
		}

		heapify(arr, root, max);
		std::swap(arr[max], arr[0]);
		max--;
	}
	
	
}


int main() {
	int arr[] = { 16,14,10,8,3,50,18,1,19,6,13,20};

	cout << " befor HeapSort ===================" << endl;
	print(arr); cout << endl;
	cout << " after HeapSort ===================" << endl;
	heapSort(arr);
	print(arr);
	
	return 0;
}