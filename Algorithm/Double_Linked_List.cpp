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
	// �� �տ��� ��� ����
	Node<T>* insertFront(T value) {
		Node<T>* p = new Node<T>(value);

		if (head == nullptr) {  // ����Ʈ�� ���Ұ� ������
			head = p;
			//head->prev = nullptr;  // ���� ��� nullptr�� ����.  ====>  �� �����൵ �Ǵ±��� Node struct ������ �����ϴ� �κп��� �����.
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
		if (tail == nullptr) {  // ����Ʈ�� ���Ұ� ������
			head = p;
			//head->prev = nullptr;  // ���� ��� nullptr�� ����.  ====>  �� �����൵ �Ǵ±��� Node struct ������ �����ϴ� �κп��� �����.
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
		if (n->next == nullptr) { // n�� �ǵ��� ��� 
			p = insertBack(value);
		}
		else { // �߰��̳� �� ���� ���.
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
		if (n == nullptr) return;  // n�� nullptr�̸� �Լ� ����.

		//// 4���� case�� �����غ����Ѵ�.
		//// �����Ϸ��� ��� n�� 1. ����Ʈ�� ������ ����� ���.  2. head ����ΰ�� 3. tail ����ΰ��, 4. �߰� ����ΰ��.
		if (n->next == nullptr && n->prev == nullptr) { // 1���� ��� : (���� if(size==1)�϶� �̷��� �ص� �ȴ�.
			delete n;
			tail = head = nullptr;
			size--;
		}
		else if (n->prev == nullptr) { // 2�� ���̽�
			n->next->prev = nullptr;
			head = n->next;
			delete n;
			size--;
		}
		else if (n->next == nullptr) { // 3�� ���̽�
			n->prev->next = nullptr;
			tail = n->prev;
			delete n;
			size--;
		}
		else { // 4�� ���̽�
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
		std::cout << "���Ḯ��Ʈ : [ ";
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << " ]" << "�� ���� ���� : " << size << std::endl;
	}
	void reversePrint() {
		Node<T>* p = tail;
		std::cout << "���Ḯ��Ʈ : [ ";
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->prev;
		}
		std::cout << " ]" << "�� ���� ���� : " << size << std::endl;
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
	std::cout << "dll�� ���Ҹ� ������ ����Ʈ �մϴ� : " << std::endl;
	dll.print();
	std::cout << '\n';
	std::cout << "dll�� ���Ҹ� ������ ����Ʈ �մϴ� : " << std::endl;
	dll.reversePrint();
	std::cout << '\n';
	std::cout << "3��° ���� �ڿ��� 13�� �߰��մϴ�." << std::endl;
	std::cout << '\n';

	dll.insertAfter(dll.getNode(6),13);
	std::cout << "dll�� ���Ҹ� ������ ����Ʈ �մϴ� : " << std::endl;

	dll.print();

	return 0;
}