#include<iostream>


template<typename T>
struct Node {
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node() {
		next = nullptr;
		prev = nullptr;
	}
	Node(T value) :data(value) {
		prev = nullptr;
		next = nullptr;
	}
};
template<typename T>
class DLList {
	Node<T>* head;
	Node<T>* tail;
	size_t size;
public:
	DLList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	};
	~DLList() {
		while (size > 0) deleteFront();
		// XXX empty the list
	}
	// 맨 앞에다 노드 삽입
	Node<T>* insertFront(T value) {
		Node<T>* p = new Node<T>(value);

		if (head == nullptr) {  // 리스트에 원소가 없을때
			head = p;
			//head->prev = nullptr;  // 이전 노드 nullptr로 설정.  ====>  아 안해줘도 되는구나 Node struct 생성자 생성하는 부분에서 해줬다.
			//head->next = nullptr;                 
			tail = head;
			++size;
		}
		else {
			p->next = head;
			head->prev = p;
			head = p;
			++size;
		}
		return p;
	}
	Node<T>* insertBack(T value) {
		Node<T>* p = new Node<T>(value);
		if (tail == nullptr) {  // 리스트에 원소가 없을때
			head = p;
			//head->prev = nullptr;  // 이전 노드 nullptr로 설정.  ====>  아 안해줘도 되는구나 Node struct 생성자 생성하는 부분에서 해줬다.
			//head->next = nullptr;                 
			tail = head;
			++size;
		}
		else {
			p->prev = tail;
			tail->next = p;
			tail = p;
			++size;
		}
		return p;
	}
	Node<T>* insertAfter(Node<T>* n, T value) {
		Node<T>* p = new Node<T>(value);
		if (n->next == nullptr) { // n이 맨뒤일 경우 
			p = insertBack(value);
		}
		else { // 중간이나 맨 앞일 경우.
			Node<T>* p = new Node<T>(value);
			p->next = n->next;
			p->prev = n;
			n->next->prev = p;
			n->next = p;
			++size;
		}
		return p;
	}
	void deleteFront() {
		deleteNode(getHead());
	}
	void deleteBack() {
		deleteNode(getTail());
	}
	void deleteNode(Node<T>* n) {
		if (n == nullptr) return;  // n이 nullptr이면 함수 종료.

		//// 4가지 case를 생각해봐야한다.
		//// 삭제하려는 노드 n이 1. 리스트의 유일한 노드인 경우.  2. head 노드인경우 3. tail 노드인경우, 4. 중간 노드인경우.
		if (n->next == nullptr && n->prev == nullptr) { // 1번의 경우 : (물론 if(size==1)일때 이렇게 해도 된다.
			delete n;
			tail = head = nullptr;
			size--;
		}
		else if (n->prev == nullptr) { // 2번 케이스
			n->next->prev = nullptr;
			head = n->next;
			delete n;
			size--;
		}
		else if (n->next == nullptr) { // 3번 케이스
			n->prev->next = nullptr;
			tail = n->prev;
			delete n;
			size--;
		}
		else { // 4번 케이스
			n->prev->next = n->next;
			n->next->prev = n->prev;
			delete n;
			size--;
		}


	}
	Node<T>* getHead() { return head; }
	Node<T>* getTail() { return tail; }
	Node<T>* getNode(int index) {
		Node<T>* p = head;
		while (--index) {
			p = p->next;
		}
		return p;
	}

	void print() {
		Node<T>* p = head;
		std::cout << "연결리스트 : [ ";
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << " ]" << "총 원소 개수 : " << size << std::endl;
	}
	void reversePrint() {
		Node<T>* p = tail;
		std::cout << "연결리스트 : [ ";
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->prev;
		}
		std::cout << " ]" << "총 원소 개수 : " << size << std::endl;
	}
};

int main() {
	DLList<int> dll;
	dll.insertFront(7);
	dll.insertFront(5);
	dll.insertFront(2);
	dll.insertFront(3);
	dll.insertFront(8);
	dll.insertFront(9);
	std::cout << "dll의 원소를 정방향 프린트 합니다 : " << std::endl;
	dll.print();
	std::cout << '\n';
	std::cout << "dll의 원소를 역방향 프린트 합니다 : " << std::endl;
	dll.reversePrint();
	std::cout << '\n';
	std::cout << "3번째 원소 뒤에다 13을 추가합니다." << std::endl;
	std::cout << '\n';

	dll.insertAfter(dll.getNode(6),13);
	std::cout << "dll의 원소를 정방향 프린트 합니다 : " << std::endl;

	dll.print();

	return 0;
}