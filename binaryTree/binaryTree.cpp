#include <iostream>

using namespace std;

struct Node {
	int value;
	struct Node* left;
	struct Node* right;

	Node(int data) {
		value = data;
		left = nullptr;
		right = nullptr;
	}
};

struct Node* root = nullptr;

void addNodeToTree(struct Node* oldNode, struct Node* newNode) {
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

void printTree(struct Node* node) {
	if (node == nullptr) {
		return;
	}

	printTree(node->left);
	cout << node->value << "  ";
	printTree(node->right);


}

void clearTree(struct Node* node) {
	if (node == nullptr) {
		return;
	}

	clearTree(node->right);
	clearTree(node->left);
	delete node;
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

/*        [5]
		/   \
	  []     []
	 /  \   /  \

*/