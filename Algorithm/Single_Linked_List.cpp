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
	int size; // 리스트안의 노드 개수

public:
	SingleLList() :head(nullptr) {size =0}; // 생성자
	~SingleLList() {    // 소멸자
		Node<T>* delNode;
		while (head->next != nullptr) {
			delNode = head;
			head = head->next;
			delete delNode;
		}
	}; 
	Node<T>* getHead() { return head; }

	// index번째 위치에 새로운 노드 추가
	void addNode(int index,T data) {  
		if (index < 0)return;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;

		if (index == 0) { // 첫번째 원소에 추가하려고 하면

			// 리스트가 비었을 경우
			if(head == nullptr) head = newNode;

			//리스트가 비지 않았을 경우
			else {
				newNode->next = head->next;
				head = newNode;
			}
			size++;
		}
		else {  // 첫번째 원소가 아니라면
			Node<T>* prev =head;
			for (int i = 1; i < index && prev != nullptr; i++) {
				prev = prev->next;
			}
			newNode->next = prev->next;
			prev->next = newNode;
			size++;
		}
	}

	// 특정 값의 노드 삭제   노드를 삭제하려면 바로 직전 노드를 알아야한다.
	void deleteNode(T data) { 
		
		if (head == nullptr) {
			cout << "빈 리스트입니다 ." << endl;
			return;
		}
		
		// 삭제하려는 데이터가 첫번째 노드이면.
		if (head->data == data) { deleteFirst(); return; }

		Node<T>* delNode;
		Node<T>* p = head;

		while (p->next->data != data && p->next != nullptr) {
			p = p->next;

			if (p->next == nullptr) {
				cout << "지우려는 " << data << " 가 리스트 안에 없습니다." << endl;
				return;
			}
		}
		
		
		
			delNode = p->next;
			p->next = p->next->next;
			delete delNode;
			size--;
		

	}
	// 첫번째 노드 삭제.
	void deleteFirst() { 
		if (head == nullptr) {// empty 리스트에는 삭제할것이 없다.
			cout << " 빈 리스트 입니다 . " << endl;
			return; 
		}
		Node<T>* tmp = head; // 메모리 free를 위해 tmp 변수 생성.
		head = head->next;
		delete tmp;
		size--;
	}

	// 리스트 원소 보여주기
	void showList()const {  
		Node<T>* p = head;
		cout << "연결리스트 : [ ";
		while (p!= nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << " ]" << "총 원소 개수 : " << size << endl;
	}

	// 리스트 탐색. 찾으면 찾은 노드 인덱스 리턴 없으면 0 리턴.
	int findList(T data)const {  
		if (head == nullptr) {
			cout << "빈 리스트입니다. " << endl;
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
		if (cnt == size+1) cout << "찾으려는 값이 없습니다." << endl;
		return 0;
	}
	int kthToLast(Node<T>* n,int k) {
		if (n == nullptr) {
			return 0;
		 }
		int cnt = kthToLast(n->next, k) + 1;
		if (cnt == k) {
			cout << "k 번째 데이터는 " << n->data << " 입니다." << endl;
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
	cout << "찾으려는 값을 입력하시오: ";
	cin >> input;
	cout << input << " 은 " << sll.findList(input) << " 번째 에 있습니다." << endl;
	cout << endl;

	cout << "지우려는 값을 입력하세요: ";
	cin >> input;
	
	sll.deleteNode(input);
	sll.showList();
	cout << endl;

	cout << "찾으려는 값을 입력하시오: ";
	cin >> input;
	cout << input << " 은 " << sll.findList(input) << " 번째 에 있습니다." << endl;
	cout << endl;

	cout << "뒤에서 k 번째 데이터는 -> k 입력하세요: ";
	cin >> input;
	sll.kthToLast(sll.getHead(), 3);
	cout << endl;
	return 0;
}