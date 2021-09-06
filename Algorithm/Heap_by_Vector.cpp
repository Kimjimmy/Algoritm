#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::endl;



//   index�� 0�� �ƴ� 1���� ����Ѵ�.
// �������� -1�� �� ä���.
class MaxHeap {
private:
	int size{};  // int size{0} ; �� ���� ���̴�.
	vector<int> vect = { -1 };

	int parent(int i) { return i >> 1; } //i /2
	int left(int i) { return i << 1; } // i*2
	int right(int i) {return (i << 1) + 1;}  // i*2 +1

public:
	bool isEmpty() const { return size == 0; }
	int getMax()const { return vect[1]; };
	void insertItem(int val);
	void shiftUp(int i);
	int extractMax();
	void shiftDown(int i);
};

void MaxHeap::shiftUp(int i) {
	if (i > size) return; //  �ε��� i �� �� ���� �������� Ŭ�� return �ٵ� �̷����� ����
	if (i == 1) return;
	if (vect[parent(i)] < vect[i]) {
		std::swap(vect[parent(i)], vect[i]);
		
	}
	shiftUp(parent(i));
}
void MaxHeap::shiftDown(int i) {
	if (i > size) return;
	int swapId = i;
	if (left(i) <= size && vect[i] < vect[left(i)]) {
		swapId = left(i);
	}
	if (right(i) <= size && vect[swapId] < vect[right(i)]) {
		swapId = right(i);
	}
	if (swapId != i) {
		std::swap(vect[i], vect[swapId]);
		shiftDown(swapId);
	}
	return;
}

void MaxHeap::insertItem(int val) {
	if (size + 1 >= vect.size()) {
		vect.push_back(0);  // vector �� �����Ҵ��ؼ� �ڵ����� capacity �÷��ִϱ� ���ϴ�.
	}
	vect[++size] = val;
	shiftUp(size);
	return;
}
int MaxHeap::extractMax() {
	int maxNum = vect[1];
	std::swap(vect[1], vect[size--]);
	shiftDown(1);
	return maxNum;
}

int main() {
	MaxHeap* pq = new MaxHeap();
	if (pq->isEmpty()) {
		cout << "�� ������ϴ�." << endl;
	}
	else {
		cout << "������ ������ ������ϴ�." << endl;
	}
	pq->insertItem(10);
	pq->insertItem(20);
	pq->insertItem(120);
	cout << pq->extractMax();
	return 0;
}