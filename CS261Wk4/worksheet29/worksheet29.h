#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif


struct Node {
	TYPE value;
	struct Node * left;
	struct Node * right;
};

struct BinarySearchTree {
	struct Node * root;
	int size;
};

void initBST(struct BinarySearchTree*);
void addBST(struct BinarySearchTree*, TYPE);
int sizeBST(struct BinarySearchTree*);
struct Node * _nodeAddBST(struct Node*, TYPE);
int containsBST(struct BinarySearchTree*, TYPE);
void removeBST(struct BinarySearchTree*, TYPE); 
TYPE _leftMostChild(struct Node*);
struct Node * _removeLeftMostChild(struct Node*);
struct Node * _nodeRemoveBST(struct Node*, TYPE);
void destroyBST(struct BinarySearchTree*);
int _containsNode(struct Node*, TYPE);
void _destroyBST(struct Node*);