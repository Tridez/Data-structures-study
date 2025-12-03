#include <iostream>
using namespace std;

typedef int DataType;

typedef struct Node{		
	DataType	data;    
	Node     	*left,*right; 
}BTNode;


void TreeInit(BTNode* &root);


BTNode *BSTSearch(BTNode *root,DataType item);

int BSTInsert(BTNode *&root,DataType item);
int   recursionBSInsert(BTNode*& root, DataType item);

BTNode *BSTMaxNode(BTNode *&root);


int BSTDelete(BTNode *&root,DataType item);


void InOrder(BTNode *root);


void ClearBTree(BTNode* &root);
