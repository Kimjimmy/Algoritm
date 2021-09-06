#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::endl;



//   index를 0이 아닌 1부터 사용한다.
// 나머지는 -1로 다 채운다.
class MaxHeap {
private:
	int size{};  // int size{0} ; 랑 같은 말이다.
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
	if (i > size) return; //  인덱스 i 가 총 원소 개수보다 클때 return 근데 이럴일이 없지
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
		vect.push_back(0);  // vector 는 동적할당해서 자동으로 capacity 늘려주니깐 편리하다.
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
		cout << "네 비었습니다." << endl;
	}
	else {
		cout << "구현에 문제가 생겼습니다." << endl;
	}
	pq->insertItem(10);
	pq->insertItem(20);
	pq->insertItem(120);
	cout << pq->extractMax();
	return 0;
}