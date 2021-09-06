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
	SingleLList() :head(nullptr) {}; // ������

	~SingleLList() {
		Node<T>* delNode;
		while (head->next != nullptr) {
			delNode = head;
			head = head->next;
			delete delNode;
		}
	};// �Ҹ���

	// index��° ��ġ�� ���ο� ��� �߰�
	void addNode(int index, T data) {
		if (index < 0)return;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;

		if (index == 0) { // ù��° ���ҿ� �߰��Ϸ��� �ϸ�

			// ����Ʈ�� ����� ���
			if (head == nullptr) head = newNode;

			//����Ʈ�� ���� �ʾ��� ���
			else {
				newNode->next = head->next;
				head = newNode;
			}
			size++;
		}
		else {  // ù��° ���Ұ� �ƴ϶��
			Node<T>* prev = head;
			for (int i = 1; i < index && prev != nullptr; i++) {
				prev = prev->next;
			}
			newNode->next = prev->next;
			prev->next = newNode;
			size++;
		}
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

	//������ ��� ����.
	void deleteFinal() {
		if (head == nullptr) {// empty ����Ʈ���� �����Ұ��� ����.
			cout << " �� ����Ʈ �Դϴ� . " << endl;
			return;
		}
		Node<T>* p = head; // �޸� free�� ���� tmp ���� ����.
		while (p->next->next != nullptr) {
			p = p->next;
		}
		p->next = p->next->next;
		delete(p->next);
		size--;
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
		}

		if (p->next == nullptr) {
			cout << "������� " << data << " �� ����Ʈ �ȿ� �����ϴ�." << endl;
			return;
		}



		delNode = p->next;
		p->next = p->next->next;
		delete delNode;
		size--;


	}

	// ����Ʈ ���� �����ֱ�
	void showList()const {
		Node<T>* p = head;
		cout << "Single Linked List : [ ";

		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << " ]" << "total elements are : "
			<< size << endl;
	}

	// k��° ��� ����.
	Node<T>* getNode(int k)const {
		if (head == nullptr || k > size) return nullptr;

		Node<T>* p = head;
		for (int i = 1; i < k && p->next != nullptr; i++) {
			p = p->next;
		}
		cout << "p�� �ּҴ� : " << &p << endl;
		return p;
	}

	// get head ��� ����.
	Node<T>* getHead() { return head; }

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
		if (cnt == size + 1) cout << "ã������ ���� �����ϴ�." << endl;
		return 0;
	}


	//============= �Ʒ� ���ʹ� Youtube �����Ͼ� ���ѹα��� Linked List �˰��� ���� ����Ǯ�̸� ���� ���� functions


	//�ڿ��� k��° ��� �˻�.
	int kthToLast(Node<T>* n, int k) {
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

	// ������ ��常 �ְ� �� ��� �����ϱ�.
	void deleteNode(Node<T>** n) {

		cout << " value of n : " << n << endl;
		cout << " address of *n : " << &(*n) << endl;
		cout << " value of *n : " << *n << endl;
		cout << (*n)->data << endl;

		if ((*n)->next == nullptr) { // if last node  
			deleteFinal(); // �� �Լ� �����ϸ� �̷��� ���� �����Ÿ� �Ϸ����� ��� �־���..

			//====================== �Ʒ��� �Ϸ����� ���� deleteFinal() ���� ���ָ� �ɰ� �Ϸ����� ������ �ڵ� ==============
			//delete (*n)->next;
			//(*n) = nullptr;  // �̰� nullptr�� ������൵ 5��° ���� �״�� �ִ±���...
			//(*n)->data = NULL;
			//=============================================================================================================

			// size--;  --> deleteFinal()���� �ϱ� ������ ���ص� �ȴ�.
		}
		else {
			Node<T>* del_node = (*n)->next;
			(*n)->data = (*n)->next->data;
			(*n)->next = (*n)->next->next;
			delete del_node;
			size--;
		}
	}

	// �־��� �� int x �� �������� ���� �����Ŵ� ���� ���� ū�Ŵ� ���������� �����ÿ�.
	void partitionBy(int x) {
		Node<T>* p = head;
		if (p == nullptr) return; // ���Ḯ��Ʈ�� ��尡 ������ ����.

		Node<T>* head_ptr = nullptr;
		Node<T>* head_end_ptr = nullptr;
		Node<T>* tail_ptr = nullptr;
		Node<T>* tail_end_ptr = nullptr;


		while (p != nullptr) {
			if (p->data < x && head_ptr == nullptr) {
				head_ptr = p;
				head_end_ptr = p;
			}
			else if (p->data < x) {
				head_end_ptr->next = p;
				head_end_ptr = p;
			}
			else if (p->data >= x && tail_ptr == nullptr) {
				tail_ptr = p;
				tail_end_ptr = p;
			}
			else {
				tail_end_ptr->next = p;
				tail_end_ptr = p;
			}
			p = p->next;
		}
		
		head_end_ptr->next = tail_ptr;
		tail_end_ptr->next = nullptr;
		head = head_ptr;
		
	}



	int toInt(Node<T>* n) {
		int sum = 0;
		int j=1;
		while (n != nullptr) {
			sum += n->data*j;
			n = n->next;
			j *= 10;
		}
		return sum;
	}

	// Digit �ջ� �˰��� ���� (��, 1���ڸ����� header�� �´�.)
	Node<T>* sumOfDigit(Node<T>* n, Node<T>* m) {
		Node<T>* newNode = new Node<T>;  // ������ ���
		head = newNode;

		int a = toInt(n);
		int b = toInt(m);

		int c = a + b; // c = 87621

		int sum = a + b;
		int cnt = 0; // 
		while (c != 0) {  // �ڸ��� ����
			c = c / 10;
			cnt++;
		}
		Node<T>* p = head;
		int input_data = 0;
		for (int i = 0; i < cnt-1; i++) {
			input_data = sum % 10;
			sum /= 10;
			p->data = input_data;
			size++;
			p->next = new Node<T>;
			p = p->next;
		}
		input_data = sum % 10;
		sum /= 10;
		p->data = input_data;
		p->next = nullptr;
		size++;
		
		return newNode;

	}



	// �Ųٷ� �����ϰ� ����  --> ȸ�� üũ �Լ��� ���� �Լ�.
	Node<T>* reverseAndClone(Node<T>* n) {
		Node<T>* h = nullptr;
		while (n != nullptr) {
			Node<T>* temp = new Node<T>; 
			temp->data = n->data;
			temp->next = h;
			h = temp;
			n = n->next;
		}
		return h;
	}
	bool isEqual(Node<T>* n, Node<T>* m) {
		while (n != nullptr&& m!=nullptr) {
			if (n->data != m->data) return false;
			else {
				n = n->next;
				m = m->next;
			}
		}
		return n == nullptr && m==nullptr;
	}

	// ȸ������ �ƴ��� üũ�Ͻÿ�.
	bool isPalindrome() {
		Node<T>* p = head;
		Node<T>* reversed = reverseAndClone(p);
		return isEqual(p, reversed);
	}


};

int main() {
	/*SingleLList<int> sll;

	sll.addNode(0, 66);
	sll.addNode(1, 9);
	sll.addNode(2, 18);
	sll.addNode(3, 33);
	sll.addNode(4, 20);
	sll.showList();

	auto fifth_ptr = sll.getNode(5);

	sll.deleteNode(&fifth_ptr);

	sll.showList();

	sll.addNode(4, 42);
	sll.addNode(5, 8);
	sll.addNode(6, 30);

	sll.showList();

	sll.partitionBy(21);

	sll.showList();*/

	/*SingleLList<int> input1;
	input1.addNode(0, 1);
	input1.addNode(1, 7);
	input1.addNode(2, 3);
	input1.addNode(3, 8);
	input1.addNode(4, 7);
	cout << "input1 ����Ʈ ��� " << endl;
	input1.showList();

	SingleLList<int> input2;
	input2.addNode(0, 8);
	input2.addNode(1, 4);
	input2.addNode(2, 3);
	input2.addNode(3, 1);
	input2.addNode(4, 5);
	cout << "input2 ����Ʈ ��� " << endl;
	input2.showList();

	SingleLList<int> output;
	cout << " �� ����Ʈ�� ���� ����Ʈ�� ����ֱ� : " << endl;
	output.sumOfDigit(input1.getHead(), input2.getHead());
	output.showList();*/

	SingleLList<char> l1;
	l1.addNode(0, 'm');
	l1.addNode(1, 'a');
	l1.addNode(2, 'd');
	l1.addNode(3, 'a');
	l1.addNode(4, 'm');
	l1.showList();
	cout << "ȸ������ �ƴ��� üũ�մϴ�. " << endl;
	cout << l1.isPalindrome();

	return 0;
}