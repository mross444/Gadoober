#ifndef __TYPE
#define __TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

// AVLNode structure definition
struct AVLnode {
	TYPE value;
	struct AVLnode *left;
	struct AVLnode *right;
	int height;
};

// AVLTree structure definition
struct AVLTree {
	struct AVLnode * root;
	int size;
};

// AVLTree helper functions prototypes (provided)
int _h(struct AVLnode*);
void _setHeight(struct AVLnode*);
struct AVLnode * _AVLnodeAdd(struct AVLnode*, TYPE);
int _bf(struct AVLnode*);
struct AVLnode * _balance(struct AVLnode*);
struct AVLnode * _rotateLeft(struct AVLnode*);
struct AVLnode * _rotateRight(struct AVLnode*);
TYPE _leftMost(struct AVLnode*);
struct AVLnode * _removeLeftmost(struct AVLnode*);
struct AVLnode * _removeNode(struct AVLnode*, TYPE);

// AVLTree helper functions prototypes (added)
void _destroyAVLTree(struct AVLnode*);
int _containsAVLnode(struct AVLnode*, TYPE);

// AVLTree public functions prototypes (provided)
void removeAVLTree(struct AVLTree*, TYPE);

// AVLTree public functions prototypes (added)
void initAVLTree(struct AVLTree*);
struct AVLTree* createAVLTree();
int sizeAVLTree(struct AVLTree*);
void destroyAVLTree(struct AVLTree*);
void addAVLTree(struct AVLTree*, TYPE);
int containsAVLTree(struct AVLTree*, TYPE);