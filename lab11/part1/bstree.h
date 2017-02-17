#include <iostream>
#include <vector>

template <typename T>
struct Item {
	T val;
	Item<T>* left;
	Item<T>* right;
};

template <typename T>
class BSTree {
	public:
		BSTree();
		~BSTree();
		bool search(const T& value);
		bool empty();
		int size();
		void insert(const T& value);
		std::vector<T> inOrderTraversal();
		std::vector<T> preOrderTraversal();
		std::vector<T> postOrderTraversal();
	
	private:
		// Helper functions that a user should not have access to
		bool searchInTree(Item<T>* node, const T& value);
		Item<T>* insertInTree(Item<T>* node, const T& value);
		void inOrderTraversalHelper(std::vector<T>& list, Item<T>* node);
		void preOrderTraversalHelper(std::vector<T>& list, Item<T>* node);
		void postOrderTraversalHelper(std::vector<T>& list, Item<T>* node);
		
		// Private Variables
		Item<T>* root;
		int counter;
};

template <typename T>
BSTree<T>::BSTree() {
	root = NULL;
	counter = 0;
}

template <typename T>
BSTree<T>::~BSTree() {
	delete root;
}

template <typename T>
bool BSTree<T>::search(const T& value) {
	return searchInTree(root, value);	
}

template <typename T>
bool BSTree<T>::searchInTree(Item<T>* node, const T& value) {
	// TODO
	// implement searching
	 // cannot examine any further
    if(node == NULL)
        return false;
    // found
    if(value == node->val)
        return true;
    // go left
    if(value < node->val)
        return searchInTree(node->left, value);
    // go right
    else
        return searchInTree(node->right, value);
}

template <typename T>
bool BSTree<T>::empty() {
	if(root == NULL) {
		return true;
	}
	return false;
}

template <typename T>
int BSTree<T>::size() {
	return counter;
}

template <typename T>
void BSTree<T>::insert(const T& value) {
	root = insertInTree(root, value);
	counter++;
}

template <typename T>
Item<T>* BSTree<T>::insertInTree(Item<T>* node, const T& value) {
	// TODO
	// Feel free to modify any return values or parameters.
	// You can also choose to do your work in insert() instead.
	if(node == NULL){
		Item<T>* newNode = new Item<T>;
		newNode->val = value;
		newNode->right = NULL;
		newNode->left = NULL;
		return  newNode;
	}
	else if(node->val > value){
		node->left = insertInTree(node->left, value);
		
	}
	else{
		node->right = insertInTree(node->right, value);

	}
	return node;
	
}

/* In Order Traversal */
template <typename T>
std::vector<T> BSTree<T>::inOrderTraversal(){
	std::vector<T> list;
	if(!empty())
		inOrderTraversalHelper(list, root);
	return list;
}

template <typename T>
void BSTree<T>::inOrderTraversalHelper(std::vector<T>& list, Item<T>* node){
	// TODO
	// implement in order
	
	if(node->left != NULL) {
        inOrderTraversalHelper(list, node->left);
    }
    list.push_back(node->val);
    if(node->right != NULL) {
        inOrderTraversalHelper(list, node->right);
    }
    

}

/* Pre Order Traversal */
template <typename T>
std::vector<T> BSTree<T>::preOrderTraversal(){
	std::vector<T> list;
	if(!empty())
		preOrderTraversalHelper(list, root);
	return list;
}

template <typename T>
void BSTree<T>::preOrderTraversalHelper(std::vector<T>& list, Item<T>* node){
	// TODO
	// implement pre order
	list.push_back(node->val);
	if(node->left != NULL) {
        preOrderTraversalHelper(list, node->left);
    }
    if(node->right != NULL) {
        preOrderTraversalHelper(list, node->right);
    }
    
}

/* Post Order Traversal */
template <typename T>
std::vector<T> BSTree<T>::postOrderTraversal(){
	std::vector<T> list;
	if(!empty())
		postOrderTraversalHelper(list, root);
	return list;
}

template <typename T>
void BSTree<T>::postOrderTraversalHelper(std::vector<T>& list, Item<T>* node){
	// TODO
	if(node->left != NULL) {
        postOrderTraversalHelper(list, node->left);
    }
    if(node->right != NULL) {
        postOrderTraversalHelper(list, node->right);
    }
    list.push_back(node->val);
}