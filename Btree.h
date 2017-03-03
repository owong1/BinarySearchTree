#ifndef BTREE_H
#define BTREE_H
#include "Node.h"

//binary search tree where insert left child if less
//insert right child if greater or equal than parent
class btree{		
private:
	void insert(int key, node* leaf);	//recursively moves down tree
	bool search(int key, node* leaf);
	void deleteTree(node* leaf);		//deletion of each node
	node* root;

	void inOrder(node* leaf, int indent);
	void preOrder(node* leaf);
	void postOrder(node* leaf);
public:
	btree();		//ctor
	~btree();		//dtor
	
	void insert(int key);
	void search(int key);
	void deleteTree();					//deletion to conserve memory
	//print functions
	void inOrder();		
	void preOrder();
	void postOrder();

};

#endif