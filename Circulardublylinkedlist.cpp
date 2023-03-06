#include <iostream>
#include<stdio.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class LinkedList {
public:
    node* head;
    int i;
    int index;

    LinkedList() {
        head = NULL;
        i=0;
        index=0;
    }
    void insert(int val) {
    // Create a new node with the given value
    node* new_node = new node;
    new_node->data = val;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = new_node;
        head->next = head;
        head->prev = head;
        return;
    }
    else{
    	// Find the last node in the list
    node* last_node = head->prev;

    // Insert the new node at the end of the list
    last_node->next = new_node;
    new_node->prev = last_node;
    new_node->next = head;
    head->prev = new_node;
    	
	}
    
   }
   void adds(int val, int pos) {
    // Create a new node
    node *newnode = new node;
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;

    // Case 1: List is empty
    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    }

    // Traverse the list to the insertion position
    int i = 0;
    node *current = head;
    while (i < pos && current->next != head) {
        current = current->next;
        i++;
    }

    // Case 2: Inserting at the beginning of the list
    if (current == head && pos == 1) {
        newnode->prev = head->prev;
        newnode->next = head;
        head->prev->next = newnode;
        head->prev = newnode;
        head = newnode;
        return;
    }

    // Case 3: Inserting at the end of the list
    if (current->next == head && pos == i + 1) {
        newnode->prev = current;
        newnode->next = head;
        current->next = newnode;
        head->prev = newnode;
        return;
    }

    // Case 4: Inserting in the middle of the list
    newnode->prev = current->prev;
current->prev = newnode;
newnode->next = current;
newnode->prev->next = newnode;

}
bool search(int key){
		node *tptr=head;
	    
    	
    	while(tptr!=NULL){
    		
    		if(tptr->data==key){
    			
    			cout<<endl<<"Your number :"<<key<<"  Is present at index :"<<index<<endl;
    			return true;
    			
			}
    		tptr=tptr->next;
    		index++;
		}
		
		return false;
	}
void printList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    cout << "NULL" << endl;
}
void deleteNode(int val) {
    node* tptr = head;
    

    while ( tptr->data != val) {
       
        tptr = tptr->next;
    }

    if (tptr == head) {
        head = head->next;
        head->prev = tptr->prev;
        tptr->prev->next = head;
        return;
    }

   
 else {
 	tptr->prev->next=tptr->next;
 	tptr->next->prev=tptr->prev;
 	
        
    }

    delete tptr;
}

   
};
int main() {
    LinkedList list;
    list.insert(9);
    list.insert(7);
    list.insert(11);
    list.insert(43);
    list.printList();
    list.adds(5,2);
    list.printList();
    list.deleteNode(9);
    list.printList();
    list.search(7);
    list.printList();

   
    return 0;
}