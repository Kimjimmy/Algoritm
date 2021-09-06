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
	SingleLList() :head(nullptr) {}; // 생성자

	~SingleLList() {
		Node<T>* delNode;
		while (head->next != nullptr) {
			delNode = head;
			head = head->next;
			delete delNode;
		}
	};// 소멸자

	// index번째 위치에 새로운 노드 추가
	void addNode(int index, T data) {
		if (index < 0)return;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;

		if (index == 0) { // 첫번째 원소에 추가하려고 하면

			// 리스트가 비었을 경우
			if (head == nullptr) head = newNode;

			//리스트가 비지 않았을 경우
			else {
				newNode->next = head->next;
				head = newNode;
			}
			size++;
		}
		else {  // 첫번째 원소가 아니라면
			Node<T>* prev = head;
			for (int i = 1; i < index && prev != nullptr; i++) {
				prev = prev->next;
			}
			newNode->next = prev->next;
			prev->next = newNode;
			size++;
		}
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

	//마지막 노드 삭제.
	void deleteFinal() {
		if (head == nullptr) {// empty 리스트에는 삭제할것이 없다.
			cout << " 빈 리스트 입니다 . " << endl;
			return;
		}
		Node<T>* p = head; // 메모리 free를 위해 tmp 변수 생성.
		while (p->next->next != nullptr) {
			p = p->next;
		}
		p->next = p->next->next;
		delete(p->next);
		size--;
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
		}

		if (p->next == nullptr) {
			cout << "지우려는 " << data << " 가 리스트 안에 없습니다." << endl;
			return;
		}



		delNode = p->next;
		p->next = p->next->next;
		delete delNode;
		size--;


	}

	// 리스트 원소 보여주기
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

	// k번째 노드 리턴.
	Node<T>* getNode(int k)const {
		if (head == nullptr || k > size) return nullptr;

		Node<T>* p = head;
		for (int i = 1; i < k && p->next != nullptr; i++) {
			p = p->next;
		}
		cout << "p의 주소는 : " << &p << endl;
		return p;
	}

	// get head 노드 리턴.
	Node<T>* getHead() { return head; }

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
		if (cnt == size + 1) cout << "찾으려는 값이 없습니다." << endl;
		return 0;
	}


	//============= 아래 부터는 Youtube 엔지니어 대한민국의 Linked List 알고리즘 영상 문제풀이를 토대로 만든 functions


	//뒤에서 k번째 노드 검색.
	int kthToLast(Node<T>* n, int k) {
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

	// 삭제할 노드만 주고 그 노드 삭제하기.
	void deleteNode(Node<T>** n) {

		cout << " value of n : " << n << endl;
		cout << " address of *n : " << &(*n) << endl;
		cout << " value of *n : " << *n << endl;
		cout << (*n)->data << endl;

		if ((*n)->next == nullptr) { // if last node  
			deleteFinal(); // 와 함수 재사용하면 이렇게 쉽게 끝낼거를 하루종일 잡고 있었네..

			//====================== 아래는 하루종일 위에 deleteFinal() 만들어서 써주면 될걸 하루종일 뻘짓한 코드 ==============
			//delete (*n)->next;
			//(*n) = nullptr;  // 이걸 nullptr로 만들어줘도 5번째 노드는 그대로 있는구나...
			//(*n)->data = NULL;
			//=============================================================================================================

			// size--;  --> deleteFinal()에서 하기 때문에 안해도 된다.
		}
		else {
			Node<T>* del_node = (*n)->next;
			(*n)->data = (*n)->next->data;
			(*n)->next = (*n)->next->next;
			delete del_node;
			size--;
		}
	}

	// 주어진 값 int x 를 기준으로 값이 작은거는 왼쪽 값이 큰거는 오른쪽으로 나누시오.
	void partitionBy(int x) {
		Node<T>* p = head;
		if (p == nullptr) return; // 연결리스트에 노드가 없을때 종료.

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

	// Digit 합산 알고리즘 문제 (단, 1의자리부터 header에 온다.)
	Node<T>* sumOfDigit(Node<T>* n, Node<T>* m) {
		Node<T>* newNode = new Node<T>;  // 리턴할 노드
		head = newNode;

		int a = toInt(n);
		int b = toInt(m);

		int c = a + b; // c = 87621

		int sum = a + b;
		int cnt = 0; // 
		while (c != 0) {  // 자리수 세기
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



	// 거꾸로 정렬하고 복사  --> 회문 체크 함수를 위한 함수.
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

	// 회문인지 아닌지 체크하시오.
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
	cout << "input1 리스트 출력 " << endl;
	input1.showList();

	SingleLList<int> input2;
	input2.addNode(0, 8);
	input2.addNode(1, 4);
	input2.addNode(2, 3);
	input2.addNode(3, 1);
	input2.addNode(4, 5);
	cout << "input2 리스트 출력 " << endl;
	input2.showList();

	SingleLList<int> output;
	cout << " 두 리스트의 합을 리스트에 집어넣기 : " << endl;
	output.sumOfDigit(input1.getHead(), input2.getHead());
	output.showList();*/

	SingleLList<char> l1;
	l1.addNode(0, 'm');
	l1.addNode(1, 'a');
	l1.addNode(2, 'd');
	l1.addNode(3, 'a');
	l1.addNode(4, 'm');
	l1.showList();
	cout << "회문인지 아닌지 체크합니다. " << endl;
	cout << l1.isPalindrome();

	return 0;
}