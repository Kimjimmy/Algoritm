#include<iostream>

using namespace std;


template<typename T>
class SingleLList {
private:

	template<typename T>
	struct Node {
		T data;
		Node<T>* next;
	};


	Node<T>* head; // head
	int size; // ����Ʈ���� ��� ����

public:
	SingleLList() :head(nullptr) {size =0}; // ������
	~SingleLList() {    // �Ҹ���
		Node<T>* delNode;
		while (head->next != nullptr) {
			delNode = head;
			head = head->next;
			delete delNode;
		}
	}; 
	Node<T>* getHead() { return head; }

	// index��° ��ġ�� ���ο� ��� �߰�
	void addNode(int index,T data) {  
		if (index < 0)return;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;

		if (index == 0) { // ù��° ���ҿ� �߰��Ϸ��� �ϸ�

			// ����Ʈ�� ����� ���
			if(head == nullptr) head = newNode;

			//����Ʈ�� ���� �ʾ��� ���
			else {
				newNode->next = head->next;
				head = newNode;
			}
			size++;
		}
		else {  // ù��° ���Ұ� �ƴ϶��
			Node<T>* prev =head;
			for (int i = 1; i < index && prev != nullptr; i++) {
				prev = prev->next;
			}
			newNode->next = prev->next;
			prev->next = newNode;
			size++;
		}
	}

	// Ư�� ���� ��� ����   ��带 �����Ϸ��� �ٷ� ���� ��带 �˾ƾ��Ѵ�.
	void deleteNode(T data) { 
		
		if (head == nullptr) {
			cout << "�� ����Ʈ�Դϴ� ." << endl;
			return;
		}
		
		// �����Ϸ��� �����Ͱ� ù��° ����̸�.
		if (head->data == data) { deleteFirst(); return; }

		Node<T>* delNode;
		Node<T>* p = head;

		while (p->next->data != data && p->next != nullptr) {
			p = p->next;

			if (p->next == nullptr) {
				cout << "������� " << data << " �� ����Ʈ �ȿ� �����ϴ�." << endl;
				return;
			}
		}
		
		
		
			delNode = p->next;
			p->next = p->next->next;
			delete delNode;
			size--;
		

	}
	// ù��° ��� ����.
	void deleteFirst() { 
		if (head == nullptr) {// empty ����Ʈ���� �����Ұ��� ����.
			cout << " �� ����Ʈ �Դϴ� . " << endl;
			return; 
		}
		Node<T>* tmp = head; // �޸� free�� ���� tmp ���� ����.
		head = head->next;
		delete tmp;
		size--;
	}

	// ����Ʈ ���� �����ֱ�
	void showList()const {  
		Node<T>* p = head;
		cout << "���Ḯ��Ʈ : [ ";
		while (p!= nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << " ]" << "�� ���� ���� : " << size << endl;
	}

	// ����Ʈ Ž��. ã���� ã�� ��� �ε��� ���� ������ 0 ����.
	int findList(T data)const {  
		if (head == nullptr) {
			cout << "�� ����Ʈ�Դϴ�. " << endl;
			return 0;
		}
		Node<T>* p = head;
		int cnt = 1;
		while (p != nullptr) {
			if (p->data == data) {
				return cnt;
			}
			p = p->next;
			cnt++;
		}
		if (cnt == size+1) cout << "ã������ ���� �����ϴ�." << endl;
		return 0;
	}
	int kthToLast(Node<T>* n,int k) {
		if (n == nullptr) {
			return 0;
		 }
		int cnt = kthToLast(n->next, k) + 1;
		if (cnt == k) {
			cout << "k ��° �����ʹ� " << n->data << " �Դϴ�." << endl;
			return 0;
		}
		return cnt;
	}
};



int main() {
	SingleLList<int> sll;
	
	sll.addNode(0, 4);
	sll.addNode(1, 5);
	sll.addNode(2, 6);
	sll.addNode(3,8);
	sll.addNode(4, 9);
	sll.showList();

	int input;
	cout << "ã������ ���� �Է��Ͻÿ�: ";
	cin >> input;
	cout << input << " �� " << sll.findList(input) << " ��° �� �ֽ��ϴ�." << endl;
	cout << endl;

	cout << "������� ���� �Է��ϼ���: ";
	cin >> input;
	
	sll.deleteNode(input);
	sll.showList();
	cout << endl;

	cout << "ã������ ���� �Է��Ͻÿ�: ";
	cin >> input;
	cout << input << " �� " << sll.findList(input) << " ��° �� �ֽ��ϴ�." << endl;
	cout << endl;

	cout << "�ڿ��� k ��° �����ʹ� -> k �Է��ϼ���: ";
	cin >> input;
	sll.kthToLast(sll.getHead(), 3);
	cout << endl;
	return 0;
}