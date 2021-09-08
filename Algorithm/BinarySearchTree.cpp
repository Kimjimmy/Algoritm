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
		if (val == n->data) return;   // Ʈ���� �̹� ���� key���� ������ ������ �׳� return
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
		Node<T>* temp = nullptr;  // newNode�� �� ĭ�ڿ��� ���� ����ٴ� ����.( �θ��带 ����� ��������)

		Node<T>* current = root;  // ��ó���� ��Ʈ�� ���ؼ� ũ�� ������ ������ �������� ��� �̵���Ŵ

		while (current != nullptr) {
			temp = current;// temp ���� ������ �� ��ġ ����Ű�� �ϰ� ���� ��ĭ ������ �̵�.
			if (current->data < newNode->data) {
				current = current->right;
			}
			else if (current->data > newNode->data) {
				current = current->left;
			}
			else {// �����Ϸ��� ���� ���� ���� ���� ��� ���� �Ұ� �޽��� ���.
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
		// ������ 3���� ���̽��� �ִ�. 1.�ڽĳ�� 0���� ��� ���� ,  2. �ڽĳ�� 1���� ��� ����, 3. �ڽĳ�� 2���� ������.

		if (delNode->left == nullptr && delNode->right == nullptr) {  // 1�� �ڽ��� 0 �� �϶�
			if (delNode == root) root = nullptr;  // �����Ϸ��� ��尡 root ����϶�
			else {
				if (parentNode->left == delNode) {
					parentNode->left = nullptr;
				}
				else {
					parentNode->right = nullptr;
				}
				//delete delNode;  �ؿ��� ��� ó�����൵ �ȴ�.

			}
		}
		else if (delNode->left == nullptr || delNode->right == nullptr) {  //case 2�� �ڽ��� 1���϶�
			Node<T>* childNode = (delNode->left == nullptr) ? delNode->right : delNode->right;
			if (delNode == root) { // �����Ϸ��� ��尡 root ����϶�
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
		else {   // �Ѵ� �ڽ��� �����Ҷ�
			// delNode = treeSuccessor(delNode); // ������ �̷��� Successor�� ���ؾߵǴµ�
			// successor�� ��尡 left, right �� �ƴ϶� parent �� ������ �־�� ���Ҽ� �ִ�.
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
		return isEmpty() ? 0 : getSize(root);  // => �Ʒ� �ڵ�� ���ļ� ��� �̷�����������..
	}

	int getSize(Node<T>* node) {
		if (node == nullptr)return 0;
		return 1 + getSize(node->right) + getSize(node->left);    //   => ��¥ õ������ �߻��̴� ��� �̷� ������ ����..
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
		if (root == nullptr) { // ��尡 �������.
			Node<T>* newNode = new Node<T>(val);
			root = newNode;
		}
		else {
			insertFormal(val);
			//  insertRecur(this->root, val) //  <- �� recursive �� �͵�  �Ẹ��!
		}

	}

	void remove(T val) {  // ���� �Ϸ��� �켱 ��带 ã�ƾߵȴ�.
		// ������ 3���� ���̽��� �ִ�. 1.�ڽĳ�� 0���� ��� ���� ,  2. �ڽĳ�� 1���� ��� ����, 3. �ڽĳ�� 2���� ������.
		if (this->isEmpty()) { cout << "Tree is Empty" << endl; return; }

		// �켱 ������ ��带 ���� ���� ã�´�.
		Node<T>* delNode = root;
		Node<T>* parentNode = nullptr;  // �����Ҷ� ��۸� �����͸� ������ �ʱ� ���ؼ� �����ش�.
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

	Node<T>* searchIter(T val) {  // �ΰ��� ��� 1. ����Լ� 2. iterative �ϰ�  �Ѵ� �����غ���
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
		cout << "ã������ ���Ҵ� �������� �ʽ��ϴ�" << endl;
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

	// 10�� node ����
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
	cout << "��ü ��尳�� : " << tree.getSize() << endl;
	cout << "leaf ��尳�� : " << tree.getLeafCount() << endl;
	cout << "����Ʈ�� ���� : " << tree.getHeight() << endl;

	// Traversal
	cout << "inorder �� ��� : " << endl;
	tree.inorder(tree.getRoot());	cout << endl;
	cout << "levelOrder �� ��� : " << endl;
	tree.levelOrder();

	// ����
	cout << "==== ��� 3 ���� ====" << endl;
	tree.remove(3);
	tree.levelOrder();
	cout << "==== ��� 68 ���� ====" << endl;
	tree.remove(68);
	tree.levelOrder();
	cout << "==== ��� 18 ���� ====" << endl;
	tree.remove(18);
	tree.levelOrder();
	cout << "==== ��� 35 ���� ====" << endl;
	tree.remove(35);
	tree.levelOrder();


	if (tree.searchIter(24)) {
		cout << "ã������ ���� 24�� �����մϴ�" << endl;
	}
	
	


	// Last Calculate
	cout << "��ü ��尳�� : " << tree.getSize() << endl;
	cout << "leaf ��尳�� : " << tree.getLeafCount() << endl;
	cout << "����Ʈ�� ���� : " << tree.getHeight() << endl;

	return 0;
}