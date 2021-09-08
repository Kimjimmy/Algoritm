#include<iostream>
#include<queue>
#include<string>
using std::endl;
using std::cout;

template<typename T>
class BinarySearchTree {
private:

	template<typename T>
	struct Node {
		Node<T>* left;
		Node<T>* right;
		T data;
		Node(T _data) :data(_data) { left = nullptr; right = nullptr; }

	};


	Node<T>* root;

	void insertRecur(Node<T>* n, T val) {
		Node<T>* newNode = new Node<T>(val);
		if (val == n->data) return;   // 트리에 이미 같은 key값을 가지고 있으면 그냥 return
		else if (val > n->data) {
			if (n->right != nullptr) {
				n = n->right;
				insertRecur(n, val);
			}
			else {
				n->right = newNode;
			}
		}
		else if (val < n->data) {
			if (n->left != nullptr) {
				n = n->left;
				insertRecur(n, val);
			}
			else {
				n->left = newNode;
			}
		}

	}
	void insertFormal(T val) {
		Node<T>* newNode = new Node<T>(val);
		Node<T>* temp = nullptr;  // newNode를 한 칸뒤에서 종종 따라다닐 예정.( 부모노드를 까먹지 않으려고)

		Node<T>* current = root;  // 맨처음에 루트랑 비교해서 크면 오른쪽 작으면 왼쪽으로 계속 이동시킴

		while (current != nullptr) {
			temp = current;// temp 한테 지금의 내 위치 가리키게 하고 나는 한칸 밑으로 이동.
			if (current->data < newNode->data) {
				current = current->right;
			}
			else if (current->data > newNode->data) {
				current = current->left;
			}
			else {// 삽입하려는 값이 현재 노드랑 같은 경우 삽입 불가 메시지 출력.
				cout << "Already exists node can't be inserted " << endl;
				delete newNode;
				return;
			}
		}
		if (temp->data < newNode->data) {
			temp->right = newNode;
		}
		else {
			temp->left = newNode;
		}


	}
	void removeNode(Node<T>* delNode, Node<T>* parentNode) {
		// 삭제는 3가지 케이스가 있다. 1.자식노드 0개인 노드 삭제 ,  2. 자식노드 1개인 노드 삭제, 3. 자식노드 2개인 노드삭제.

		if (delNode->left == nullptr && delNode->right == nullptr) {  // 1번 자식이 0 개 일때
			if (delNode == root) root = nullptr;  // 삭제하려는 노드가 root 노드일때
			else {
				if (parentNode->left == delNode) {
					parentNode->left = nullptr;
				}
				else {
					parentNode->right = nullptr;
				}
				//delete delNode;  밑에서 묶어서 처리해줘도 된다.

			}
		}
		else if (delNode->left == nullptr || delNode->right == nullptr) {  //case 2번 자식이 1개일때
			Node<T>* childNode = (delNode->left == nullptr) ? delNode->right : delNode->right;
			if (delNode == root) { // 삭제하려는 노드가 root 노드일때
				root = childNode;
			}
			if (parentNode->left == delNode) {
				parentNode->left = childNode;
			}
			else {
				parentNode->right = childNode;
			}
			// delete delNode;

		}
		else {   // 둘다 자식이 존재할때
			// delNode = treeSuccessor(delNode); // 원래는 이렇게 Successor을 구해야되는데
			// successor는 노드가 left, right 뿐 아니라 parent 도 가지고 있어야 구할수 있다.
			Node<T>* successor = delNode;
			Node<T>* successor_parent = successor;

			successor = delNode->right;
			while (successor->left) {
				successor_parent = successor;
				successor = successor->left;
			}
			delNode->data = successor->data;
			removeNode(successor, successor_parent);
			return;
		}

		delete delNode;
	}

public:
	BinarySearchTree() { root = nullptr;}

	bool isEmpty() { return root == nullptr; }
	Node<T>* getRoot() { return root; }
	int getSize() {
		return isEmpty() ? 0 : getSize(root);  // => 아래 코드랑 합쳐서 어떻게 이런생각을하지..
	}

	int getSize(Node<T>* node) {
		if (node == nullptr)return 0;
		return 1 + getSize(node->right) + getSize(node->left);    //   => 진짜 천재적인 발상이다 어떻게 이런 생각을 하지..
	}

	int getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}
	int getLeafCount(Node<T>* node) {
		if (node == nullptr)return 0;
		if (node->left == nullptr && node->right == nullptr) return 1;
		return getLeafCount(node->left) + getLeafCount(node->right);
	}
	int getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}

	int getHeight(Node<T>* n) {
		if (n == nullptr) return 0;
		int r_height = getHeight(n->right);
		int l_height = getHeight(n->left);
		return(r_height > l_height) ? r_height + 1 : l_height + 1;
	}

	void insert(T val) {
		if (root == nullptr) { // 노드가 비었을때.
			Node<T>* newNode = new Node<T>(val);
			root = newNode;
		}
		else {
			insertFormal(val);
			//  insertRecur(this->root, val) //  <- 이 recursive 한 것도  써보기!
		}

	}

	void remove(T val) {  // 삭제 하려면 우선 노드를 찾아야된다.
		// 삭제는 3가지 케이스가 있다. 1.자식노드 0개인 노드 삭제 ,  2. 자식노드 1개인 노드 삭제, 3. 자식노드 2개인 노드삭제.
		if (this->isEmpty()) { cout << "Tree is Empty" << endl; return; }

		// 우선 삭제할 노드를 값을 통해 찾는다.
		Node<T>* delNode = root;
		Node<T>* parentNode = nullptr;  // 삭제할때 댕글링 포인터를 만들지 않기 위해서 구해준다.
		while (delNode != nullptr && delNode->data != val) {
			parentNode = delNode;
			delNode = (delNode->data > val ? delNode->left : delNode->right);
		}
		if (delNode == nullptr) {
			cout << "Key is not in tree" << endl;
			return;
		}
		removeNode(delNode, parentNode);
	}
	void inorder(Node<T>* node) {
		
		if(node != nullptr) {
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}
	void levelOrder() {
		cout << "Level-Order: [";
		if (!isEmpty()) {
			std::queue<Node<T>*> q;
			q.push(root);
			
			while (!q.empty()) {
				Node<T>* temp = q.front();
				q.pop();
				if (temp != nullptr) {
					cout << temp->data << " ";
					q.push(temp->left);
					q.push(temp->right);
				}		
			}
		}
		cout << "]" << endl;
	}

	Node<T>* searchIter(T val) {  // 두가지 방법 1. 재귀함수 2. iterative 하게  둘다 구현해보기
		Node<T>* temp = root;
		while (temp!=nullptr ) {
			if (temp->data == val) { 
			return temp;
			}
			if (temp->data > val) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		cout << "찾으려는 원소는 존재하지 않습니다" << endl;
		return nullptr;
	}
	Node<T>* searchRecur(Node<T>* node, T val) {
		if (node == nullptr) return nullptr;
		if (val < node->data) {
			searchRecur(node->left, val);
		}
		else if (val > node->data) {
			searchRecur(node->right, val);
		}
		else {
			return node;
		}
	}
};
int main() {
	BinarySearchTree<int> tree;

	// 10개 node 삽입
	tree.insert(35);
	tree.insert(18);
	tree.insert(7);
	tree.insert(26);
	tree.insert(12);
	tree.insert(3);
	tree.insert(68);
	tree.insert(22);
	tree.insert(30);
	tree.insert(99);

	// Calculate
	cout << "전체 노드개수 : " << tree.getSize() << endl;
	cout << "leaf 노드개수 : " << tree.getLeafCount() << endl;
	cout << "이진트리 높이 : " << tree.getHeight() << endl;

	// Traversal
	cout << "inorder 로 출력 : " << endl;
	tree.inorder(tree.getRoot());	cout << endl;
	cout << "levelOrder 로 출력 : " << endl;
	tree.levelOrder();

	// 삭제
	cout << "==== 노드 3 삭제 ====" << endl;
	tree.remove(3);
	tree.levelOrder();
	cout << "==== 노드 68 삭제 ====" << endl;
	tree.remove(68);
	tree.levelOrder();
	cout << "==== 노드 18 삭제 ====" << endl;
	tree.remove(18);
	tree.levelOrder();
	cout << "==== 노드 35 삭제 ====" << endl;
	tree.remove(35);
	tree.levelOrder();


	if (tree.searchIter(24)) {
		cout << "찾으려는 원소 24은 존재합니다" << endl;
	}
	
	


	// Last Calculate
	cout << "전체 노드개수 : " << tree.getSize() << endl;
	cout << "leaf 노드개수 : " << tree.getLeafCount() << endl;
	cout << "이진트리 높이 : " << tree.getHeight() << endl;

	return 0;
}