#include<iostream>
#include<stdlib.h>

using namespace std;


typedef class TreeNode {
  public:
	int data;
	TreeNode *leftPtr;
	TreeNode *rightPtr;
}TreeNode, *TreeNodePtr;


void insertNode(TreeNodePtr *treePtr, int value) {
	if (*treePtr == NULL) {
		*treePtr = new TreeNode;
		
		if(*treePtr != NULL){
		  	(*treePtr)->data = value;
		  	(*treePtr)->leftPtr = NULL;
		  	(*treePtr)->rightPtr = NULL;
	  	}
	  	else { cout << "BAD MEMORY ALLOC"; }
    }
	else {
		if (value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else { 
			if (value > (*treePtr)->data) {
				insertNode(&((*treePtr)->rightPtr), value);
			}
		}
	}	
}


int main() {
	int array[7] = {49, 28, 82, 18, 40, 71, 97};
	
	TreeNodePtr rootPtr = NULL;
	
	int i;
	for (i=0; i<7; ++i) {
		int item = array[i];
		insertNode(&rootPtr, item);
	}
	
	cout << rootPtr->data << endl;
	cout << rootPtr->leftPtr->data << " " << rootPtr->rightPtr->data << endl;
	cout << rootPtr->leftPtr->leftPtr->data << " " << rootPtr->leftPtr->rightPtr->data << " " 
		 << rootPtr->rightPtr->leftPtr->data << " " << rootPtr->rightPtr->rightPtr->data << endl;
	
	return 0;
}
