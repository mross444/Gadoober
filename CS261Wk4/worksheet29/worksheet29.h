#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

struct Node {
	TYPE value;
	struct Node * left;
	struct Node * right;
};

struct BinarySearchTree {
	struct Node * root;
	int size;
};

// PriorityQueue structure
struct PriorityQueue {
	struct BinarySearchTree * data;
};

// Public BST functions
void initBST(struct BinarySearchTree*);
struct BinarySearchTree* createBST();
void addBST(struct BinarySearchTree*, TYPE);
int sizeBST(struct BinarySearchTree*);
int containsBST(struct BinarySearchTree*, TYPE);
void removeBST(struct BinarySearchTree*, TYPE);
void destroyBST(struct BinarySearchTree*);
TYPE getFirst(struct BinarySearchTree*);
void removeFirst(struct BinarySearchTree*);

// Helper BST functions
struct Node * _nodeAddBST(struct Node*, TYPE);
TYPE _leftMostChild(struct Node*);
struct Node * _removeLeftMostChild(struct Node*);
struct Node * _nodeRemoveBST(struct Node*, TYPE);
int _containsNode(struct Node*, TYPE);
void _destroyBST(struct Node*);

// PriorityQueue functions
void initPQ(struct PriorityQueue*);
struct PriorityQueue* createPQ();
void addPQ(struct PriorityQueue*, TYPE);
TYPE frontPQ(struct PriorityQueue*);
void removeFrontPQ(struct PriorityQueue*);
int isEmptyPQ(struct PriorityQueue*);
void destroyPQ(struct PriorityQueue*);