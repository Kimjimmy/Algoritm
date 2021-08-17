#include<iostream>
#include<boost/type_index.hpp>
#include<functional>

using namespace std;

template <int n>
void print(int(&arr)[n]) {

	//cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
	//int size = sizeof(arr[0]) / sizeof(T);   // sizeof(T) ���� T�� int* �� 4byte ����..

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

template<int n>
void maxHeapify(int(&arr)[n], int root,int size) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int largest;
	// ===================================================================================================================================
	//if (right< size) { // ������ �ڽ� ��尡 �����ϰ� 
	//	if (arr[root] < arr[right] || arr[root] < arr[left]) { // �����̳� ������ ���߿� �ϳ��� root���� ũ��
	//		// arr[right] > arr[left] ? swap(arr[root], arr[right]) : swap(arr[root], arr[left]);  // ū �ɷ� ����.
	//		if (arr[right] > arr[left]) {
	//			largest = right;
	//			swap(arr[root], arr[right]);
	//		}
	//		else
	//		{
	//			swap(arr[root], arr[left]);
	//			largest = left;
	//		}
	//		maxHeapify(arr,largest , size); // �ٲ۰��� �������� �ٽ� �������� �̶� �ݴ����� �翬�� heap�� �� �����̴�.
	//	 }
	// }
	//else if((left < size)&& (arr[root]<arr[left])){// �������� ���� ���¿��� ������ �����ϰ� root ���� ������ �� ũ��
	//		swap(arr[left], arr[root]);  // �����̶� ����.
	//		maxHeapify(arr, left,size); // ������ �������� �ٽ� �������� �̶� �������� �翬�� heap�� �� ����.

	//}  
	//====================================���� ����ó�� �̷��� �ߴµ� �ٸ��� ���� ���� �Ʒ�ó�� ��.=============================================

	int largest;
	if ((left < size ) && (arr[left] > arr[root])) { // left �� �׻� �����ϴµ� left < n ���� ������ ���� ���� ���������� �� �ڵ� ���� �ȵǰ� �Ϸ��� �׷�.
		                                          //������ ��Ʈ���� ũ�� �ϴ� ������ ū�ɷ� ����.
		largest = left;
	}
	else largest = root;   // �ƴϸ� ��Ʈ�� ū�ɷ� ����.
	if ((right < size) && (arr[right] > arr[largest])) { // �������� �����ϰ� ū�ɷ� �����Ѱź��� ũ��
		largest = right;
	}
	if (largest != root) {
		swap(arr[root], arr[largest]);
		maxHeapify(arr, largest, size);  // ���� ��� �ٽ� ��������. �� �� �ݴ����� �̹� �� Ư���� �� ������ �����Ѵٰ� �� �� �ִ�.
	}
}


template<int n>
void heapSort(int(&arr)[n]) {
	int root = (n-1)/2;
	int size = n;
	
	for (int i = root; i >= 0; i--){
		maxHeapify(arr, i,size);
	}
	for (int i = n-1; i >= 1; i--) {
		swap(arr[0], arr[i]);
		size--;
		maxHeapify(arr, 0, size);
	}
	// ó������ �ƽ��� ������ְ�
	// �� �������� ��Ʈ�� �ٲ��ְ�, �迭 ������ �ϳ� �ٿ���
	// �ٽ��ѹ� �ƽ� �������� ���ָ鼭 �ݺ��ϸ� �ᱹ �迭�� ���������� ū������ �������� ����.
	
}


int main() {
	int arr[] = { 4,5,2,3,7,1,8,9,6,10 };

	cout << " befor HeapSort ===================" << endl;
	print(arr); cout << endl;

	cout << " after HeapSort ===================" << endl;
	heapSort(arr);
	print(arr);

	return 0;
}