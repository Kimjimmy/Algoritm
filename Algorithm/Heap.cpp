#include<iostream>
#include<algorithm> // for std::swap

//  heap �ϼ���.  �ٸ��������� ���� index 0�� -1�� �ΰ� index 1���� �ߴµ� ���� index 0 ���� �ؼ� �����ߴ�.

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
	//int right = index << 1 + 2;   // ��Ʈ �����̳� *2�� �Ȱ����Ŵ�.

	//// �ϴ� �ڽ��� �ִ��� ���� Ȯ��.  ���� �ڽ��� ������ ������ �ڽĵ� �翬�� ���°Ŷ� ���� �ڽ� ���� üũ.
	//if (left < size && heap_arr[index] < heap_arr[left]) {  // ���� �ڽ��� �����ϰ� , �θ� �ڽĺ��� ������ ����.
	//	selectChild = left;
	//}
	//if(righ)

	// ^^^ ���� ���� ó�� �ϸ� �ȵȴ�. �ڽ��� size�� �ʰ��Ұ�� ��ȿ���� �ʴ� �ε����� ������ �ִ°Ŷ� if ������ heap_arr[left] ���� �ε����� ���� �������²�.
	int left = index * 2 + 1 < size ? index * 2 + 1 : -1;
	int right = index * 2 + 2 < size ? index * 2 + 2 : -1;

	if (left == -1) {  // ���� �ڽ��� ������ �����ʵ� ���°Ŵ�.
		return;
	}
	else if (left != -1 && right == -1) {  // ���ʸ� �ִ� ���
		selectChild = left;
	}
	else { // �Ѵ� �ִ� ���
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
		cout << "���� ������ �����ϴ�." << endl;
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
		cout << "�� heap �Դϴ�." << endl;
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
	cout << "���� ���� �ִ� ���� : " << h.top() << "�Դϴ�." << endl;
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