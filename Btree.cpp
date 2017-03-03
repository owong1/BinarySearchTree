#include <iostream>
#include "Btree.h"


btree::btree(){		//ctor default
  root = NULL;
}

btree::~btree(){	//dtor
	deleteTree();
}

void btree::deleteTree(node *leaf){			//private member: recursively delete nodes
  if(leaf != NULL){							//search while there is a non-NULL nodes
    deleteTree(leaf->left);					//leftmost leaf node
    deleteTree(leaf->right);				//right child leaf node from leftmost's parent node
    delete leaf;
  }
}

void btree::deleteTree(){					//public: delete
	deleteTree(root);						//call private delete function for the root(s)
}

void btree::insert(int key, node *leaf){	//private: insert a value into the tree
	if (key < leaf->key_value){				//left if lower value
		if (leaf->left != NULL){			//search: if left leaf is not empty
			insert(key, leaf->left);		//recursively move down left of the tree
		}
		else{								//until empty node
			leaf-> left = new node;			//create the node to left of parent
			leaf-> left-> key_value = key;	//insert the key value into the new child leaf
			leaf-> left-> left = NULL;		//sets the left child of the child node to null
			leaf-> left-> right = NULL;		//sets the right child of the child node to null
		}
	}
	else if (key >= leaf -> key_value){		//right if greater or equal value
		if (leaf->right != NULL){			//if right leaf is not empty
			insert(key, leaf->right);		//recursively move down right of tree
		}
		else{
			leaf-> right = new node;
			leaf-> right-> key_value = key;	//create node to right of parent
			leaf-> right-> left = NULL;		//sets the left child of the child node to null
			leaf-> right-> right = NULL;	//sets the right child of the child node to null
		}
	}
}

void btree::insert(int key){				//public: insert
	if (root != NULL){						//if root node is not empty
		insert(key, root);					//call private insert function
	}
	else{
		root = new node;					//create new root node
		root->key_value = key;				//root's value becomes input key
		root->left = NULL;					//root's left child is empty
		root->right = NULL;					//root's right child is empty
	}
}

bool btree::search(int key, node *leaf){	//private: search the tree for a value
	if (leaf != NULL){						//if leaf has a value
		if (key == leaf->key_value){		//search key is equal to the leaf value: true
			return true;
		}
		if (key < leaf->key_value){			//if the search key is less, go to the left
			return search(key, leaf->left);
		}
		else{
			return search(key, leaf->right); //if the search key is more, go to the right
		}
	}
	else{
		return false;						//else return false, key was not found in tree
	}
}

void btree::search(int key){				//public: search

	if (search(key, root)){
		std::cout << "Key found: " << key << std::endl;
	}
	else{
		std::cout << "Key not found." << std::endl;
	}
}

// Left root Right
void btree::inOrder(node* leaf, int indent){				//private: print values in order
	if (root != NULL){
		if (leaf->left != NULL){
			inOrder(leaf->left, indent + 1);
		}
		for (int i = 0; i < 3 * indent; i++){
			std::cout << ' ';
		}
		std::cout << leaf->key_value << std::endl;
		if (leaf->right != NULL){
			inOrder(leaf->right, indent + 1);
		}
	}
	else{
		std::cout << "Tree is empty" << std::endl;
	}
}

void btree::inOrder(){							//public: in order
	inOrder(root, 0);
}

// root Left Right
void btree::preOrder(node* leaf){				//private: print values pre order
	if (root != NULL){
		std::cout << leaf->key_value << " ";
		if (leaf->left != NULL){
			preOrder(leaf->left);
		}
		if (leaf->right != NULL){
			preOrder(leaf->right);
		}
	}
	else{
		std::cout << "Tree is empty" << std::endl;
	}
}

void btree::preOrder(){							//public: pre order
	preOrder(root);
}

// Left Right root
void btree::postOrder(node* leaf){				//private: print values post order
	if (root != NULL){
		if (leaf->left != NULL){
			postOrder(leaf->left);
		}
		if (leaf->right != NULL){
			postOrder(leaf->right);
		}
		std::cout << leaf->key_value << " ";
	}
	else{
		std::cout << "Tree is empty" << std::endl;
	}
}

void btree::postOrder(){							//public: post order
	postOrder(root);
}
