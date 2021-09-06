#include<iostream>
#include<algorithm> // for std::swap

//  heap 완성본.  다른곳에서는 전부 index 0을 -1로 두고 index 1부터 했는데 나는 index 0 부터 해서 시작했다.

using std::endl;
using std::cout;

template<typename T>
class MaxHeap {
private:
	T data;
	int size;
	int max_size;
	T* heap_arr;

public:
	MaxHeap(int _max_size = 10) {
		max_size = _max_size;
		heap_arr = new T[_max_size]{ -1 };
		size = 0;
	}
	bool isEmpty()const { return size == 0; }
	T top() { return heap_arr[0]; }
	void traverse()const {
		for (int i = 0; i < size; i++) {
			cout << heap_arr[i] << "  ";
		}
	}

	void pop();
	void insert(T data);
	void upHeapify(int index);
	void downHeapify(int index);

};
template<typename T>
void MaxHeap<T>::upHeapify(int index) {

	int current = index;
	if (current == 0) return;  // recursive -> base camp
	int parent = (index - 1) / 2;
	if (heap_arr[parent] < heap_arr[current]) {
		std::swap(heap_arr[parent], heap_arr[current]);
	}
	upHeapify(parent);
}
template<typename T>
void MaxHeap<T>::downHeapify(int index) {
	int selectChild;
	//int left = index * 2 + 1;
	//int right = index << 1 + 2;   // 비트 연산이나 *2나 똑같은거다.

	//// 일단 자식이 있는지 부터 확인.  왼쪽 자식이 없으면 오른쪽 자식도 당연히 없는거라 왼쪽 자식 부터 체크.
	//if (left < size && heap_arr[index] < heap_arr[left]) {  // 왼쪽 자식이 존재하고 , 부모가 자식보다 작을때 스왑.
	//	selectChild = left;
	//}
	//if(righ)

	// ^^^ 나는 위에 처럼 하면 안된다. 자식이 size를 초과할경우 유효하지 않는 인덱스를 가지고 있는거라 if 문에서 heap_arr[left] 없는 인덱스의 값을 가져오는꼴.
	int left = index * 2 + 1 < size ? index * 2 + 1 : -1;
	int right = index * 2 + 2 < size ? index * 2 + 2 : -1;

	if (left == -1) {  // 왼쪽 자식이 없으면 오른쪽도 없는거다.
		return;
	}
	else if (left != -1 && right == -1) {  // 왼쪽만 있는 경우
		selectChild = left;
	}
	else { // 둘다 있는 경우
		selectChild = (heap_arr[left] > heap_arr[right] ? left : right);
	}
	if (heap_arr[selectChild] > heap_arr[index]) {
		std::swap(heap_arr[selectChild], heap_arr[index]);
		downHeapify(selectChild);
	}
}
template<typename T>
void MaxHeap<T>::insert(T data) {
	if (size + 1 >= max_size) {
		cout << "여유 공간이 없습니다." << endl;
		return;
	}
	if (size == 0) { heap_arr[size++] = data; return; }
	heap_arr[size] = data;
	upHeapify(size);
	size++;
}
template<typename T>
void MaxHeap<T>::pop() {
	if (!size) {
		cout << "빈 heap 입니다." << endl;
		return;
	}
	std::swap(heap_arr[0], heap_arr[--size]);
	downHeapify(0);
}


int main() {

	MaxHeap<int> h;
	cout << h.isEmpty() << endl;
	h.insert(10);
	h.insert(20);
	h.insert(30);
	h.insert(40);
	h.traverse();
	cout << '\n';
	cout << "가장 위에 있는 값은 : " << h.top() << "입니다." << endl;
	h.pop();
	h.traverse();
	cout << endl;
	h.insert(70);
	h.traverse();
	cout << endl;
	h.pop();
	h.traverse();
	return 0;
}