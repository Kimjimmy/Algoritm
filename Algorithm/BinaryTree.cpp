#include<iostream>

using namespace std;
template<typename T>
class BinaryTree;

template<typename T>
class Node {
	 friend class BinaryTree<T>;
private:
	T data;
	Node* left;
	Node* right;
	
public:
	Node() : value(0), left(nullptr), right(nullptr) {};
	Node(T _data) :data(_data), right(nullptr), left(nullptr){};
	Node(T _data, Node* _left, Node* _right):data(_data),left(_left),right(_right){};
	~Node() {};
};


template<typename T>
class BinaryTree {
private:
	Node<T>* root;

public:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {
	}
	Node<T>* createNode(T data) {
		Node<T>* newNode = new Node<T>;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = data;
		return newNode;
	};
	void setRoot(Node<T>* _root) {
		root = _root;
	}
	Node<T>* getRoot() {
		return root;
	}
	void visit(Node<T>* current) {
		cout << current->data << " ";
	}
	void preorder(Node<T>* current) {
		if (current != nullptr) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}
	void postorder(Node<T>* current) {
		if (current != nullptr) {
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
	void inorder(Node<T>* current) {
		if (current != nullptr) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}

	bool isEmpty() { return root = nullptr; }

};

int main() {
	BinaryTree<char> tree;

	// create Node
	Node<char>* d = new Node<char>('0', nullptr, nullptr);
	// Node<char>* d = tree.createNode('0');  위랑 똑같은 식 main에서 동적 할당 해주는가 함수에서 해주나 차이
	Node<char>* e = new Node<char>('4', nullptr, nullptr);
	// Node<char>* e = tree.createNode('4');
	Node<char>* f = new Node<char>('5', nullptr, nullptr);
	//Node<char>* f = tree.createNode('5');
	Node<char>* b = new Node<char>('1', d, e);
	Node<char>* c = new Node<char>('2', f, nullptr);
	Node<char>* a = new Node<char>('7', b, c);

	tree.setRoot(a);

	cout << "preorder >> ";
	tree.preorder(tree.getRoot());
	cout << endl;

	cout << "inorder >> ";
	tree.inorder(tree.getRoot());
	cout << endl;

	cout << "postorder >> ";
	tree.postorder(tree.getRoot());
	cout << endl;

	return 0;
}
