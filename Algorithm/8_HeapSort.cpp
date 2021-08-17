#include<iostream>
#include<boost/type_index.hpp>
#include<functional>

using namespace std;

template <int n>
void print(int(&arr)[n]) {

	//cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << endl;
	//int size = sizeof(arr[0]) / sizeof(T);   // sizeof(T) 에서 T가 int* 라 4byte 구나..

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
	//if (right< size) { // 오른쪽 자식 노드가 존재하고 
	//	if (arr[root] < arr[right] || arr[root] < arr[left]) { // 왼쪽이나 오른쪽 둘중에 하나라도 root보다 크면
	//		// arr[right] > arr[left] ? swap(arr[root], arr[right]) : swap(arr[root], arr[left]);  // 큰 걸로 스왑.
	//		if (arr[right] > arr[left]) {
	//			largest = right;
	//			swap(arr[root], arr[right]);
	//		}
	//		else
	//		{
	//			swap(arr[root], arr[left]);
	//			largest = left;
	//		}
	//		maxHeapify(arr,largest , size); // 바꾼곳을 기준으로 다시 힙피파이 이때 반대편은 당연히 heap이 된 상태이다.
	//	 }
	// }
	//else if((left < size)&& (arr[root]<arr[left])){// 오른쪽은 없는 상태에서 왼쪽이 존재하고 root 보다 왼쪽이 더 크면
	//		swap(arr[left], arr[root]);  // 왼쪽이랑 스왑.
	//		maxHeapify(arr, left,size); // 왼쪽을 기준으로 다시 힙피파이 이때 오른쪽은 당연히 heap이 된 상태.

	//}  
	//====================================나는 위에처럼 이렇게 했는데 다른거 보면 보통 아래처럼 함.=============================================

	int largest;
	if ((left < size ) && (arr[left] > arr[root])) { // left 는 항상 존재하는데 left < n 해준 이유는 리프 노드로 내려갔을때 이 코드 실행 안되게 하려고 그럼.
		                                          //왼쪽이 루트보다 크면 일단 왼쪽이 큰걸로 지정.
		largest = left;
	}
	else largest = root;   // 아니면 루트를 큰걸로 지정.
	if ((right < size) && (arr[right] > arr[largest])) { // 오른쪽이 존재하고 큰걸로 지정한거보다 크면
		largest = right;
	}
	if (largest != root) {
		swap(arr[root], arr[largest]);
		maxHeapify(arr, largest, size);  // 내부 노드 다시 힙피파이. 이 때 반대편은 이미 힙 특성상 힙 조건을 만족한다고 할 수 있다.
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
	// 처음으로 맥스힙 만들어주고
	// 맨 마지막과 루트값 바꿔주고, 배열 사이즈 하나 줄여줌
	// 다시한번 맥스 힙피파이 해주면서 반복하면 결국 배열은 끝에서부터 큰값들이 차곡차곡 싸임.
	
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