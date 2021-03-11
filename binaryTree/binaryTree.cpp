#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;

	Node(int data) {
		value = data;
		left = nullptr;
		right = nullptr;
	}
};

#define getValue(node)(node->value)
#define getLeftChild(node)(node->left)
#define getRightChild(node)(node->right)


Node* root = nullptr;


void addNodeToTree(Node* oldNode, Node* newNode) {
	if (root == nullptr) {
		root = newNode;
		return;
	}

	if (oldNode->value > newNode->value) {
		//add node to left side of tree
		if (oldNode->left == nullptr) {
			oldNode->left = newNode;
			return;
		}
		addNodeToTree(oldNode->left, newNode);
	}

	if (oldNode->value < newNode->value) {
		//add node to right side of tree
		if (oldNode->right == nullptr) {
			oldNode->right = newNode;
			return;
		}
		addNodeToTree(oldNode->right, newNode);
	}
}

void printTree(Node* node) {
	if (node == nullptr) {
		return;
	}
	printTree(getLeftChild(node));
	cout << getValue(node) << "  ";
	printTree(getRightChild(node));


}

void clearTree(Node* node) {
	if (node == nullptr) {
		return;
	}

	clearTree(getRightChild(node));
	clearTree(getLeftChild(node));
	delete node;
	root = nullptr;
}


void buildTreeFromArray(int* arrayOfValues, int size) {
	for (int i = 0; i < size; i++) {
		addNodeToTree(root, new Node(arrayOfValues[i]));
	}
}

int main() {
	buildTreeFromArray(new int[] {5, 3, 10, 4, 2, 15, 25, 20}, 8);

	printTree(root);
	clearTree(root);
	return 0;
}

/*  

          (5)
		 /   \
	   (3)   (7)
	   / \   / \
    
*/