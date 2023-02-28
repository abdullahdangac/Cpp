#include<iostream>
#include<stdlib.h>

using namespace std;


class ListNode {
  public:
    char data;
    ListNode *nextPtr;
};


typedef class ListNode ListNode;
typedef ListNode* ListNodePtr;


void insert(ListNodePtr* sPtr, char value) {
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	
	newPtr = new ListNode;
	
	if (newPtr) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		
	    while (currentPtr!=NULL && value>currentPtr->data) {
		     previousPtr = currentPtr;
		     currentPtr = currentPtr->nextPtr;
	    }
	    
	    if (previousPtr == NULL) {
    		newPtr->nextPtr = *sPtr;
    		*sPtr = newPtr;
    	}
    	else {
    		previousPtr->nextPtr = newPtr;
    		newPtr->nextPtr = currentPtr;
    	}
	}
	else {
		cout<<"BAD MEMORY ALLOC"<<endl;
	}	
}


void printList(ListNodePtr currentPtr) {
	if (!currentPtr) {
		cout << "NULL";
	}
	else {
		ListNodePtr currPtr = currentPtr; 
		
		while (currPtr) {
			cout << currPtr->data << " ";
			currPtr = currPtr->nextPtr;
		}
	}
}


int main() {
	ListNodePtr list1ptr = NULL;
	char ch;
	
	for (ch = 'Z'; ch >= 'A'; --ch){
		insert(&list1ptr, ch);
	}

	printList(list1ptr);
	
	return 0;
}
