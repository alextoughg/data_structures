#include <iostream>

using namespace std;

struct node_t{
	int key;
	struct node_t* next;
	node_t(int k_, node_t* rest){
		key = k_;
		next = rest;
	}
	~node_t(){cout << "node_t destroyed" << endl;}
};

// Circular singly linked list.
struct csll{
	node_t* head;
	node_t* last;
	csll(){
		head = NULL;
		last = NULL;
	}
	void insertBeginning(int f){
		node_t* temp = head;
		head = new node_t(f, temp);
		if(!last){
			head->next = head;
			last = head;
		}
		else{
			last->next = head;	
		}
		
	}

	// The node pointed by ptr_to_new_node is the successor of the 
	// node pointed by ptr_to_node
	void insertAfter(node_t* ptr_to_node, node_t* ptr_to_new_node){
		// If we are going to insert after last node, we have to update 
		// the pointer to the last node!
		if(ptr_to_node == last){
			last = ptr_to_new_node;
		}
		ptr_to_new_node->next = ptr_to_node->next;
		ptr_to_node->next = ptr_to_new_node;
	}

	void removeBeginning(){
		if(head){
			// i.e. one element in list
			if(head == last){
				delete head;
				head = NULL;
				last = NULL;
			}
			else{
				//(According to Wikipedia)
				//node_t* obsolete = head;
				//head = head->next;
				//delete obsolete;
				// My way
				node_t* obsolete = head;
				head = head->next;
				delete obsolete;
				last->next = head;
			}
		}		

	}

	// Remove the node after the node pointed to 
	// by ptr_to_node
	void removeAfter(node_t* ptr_to_node){
		if(ptr_to_node){
			node_t* obsolete = ptr_to_node->next;
			node_t* obsolete_succ = obsolete->next;
			// Make sure the head and last pointers are 
			// up to date.
			if(obsolete == head){
				head = obsolete_succ;
			}
			if(obsolete == last){
				last = ptr_to_node;
			}
			delete obsolete;
			ptr_to_node->next = obsolete_succ;
		}
	}

	// The contents of the list printed to stdio.
	void peek(node_t* ptr_to_some_node){
		if(ptr_to_some_node){
			node_t* p = ptr_to_some_node;
			do 
			{
				cout << p->key << endl;
				p = p->next;
			} while (p != ptr_to_some_node);
		}
	}

	// NOTE: Given that we don't have back pointers, 
	// the operations insertBefore and deleteBefore 
	// are not possible to implement.

	// NOTE: If we had a dummy element at the beginning 
	// of the list, the operations insertBeginning and 
	// removeBeginning would not be necessary.

	// SOURCE: Wikipedia.
};

int main(){

	// Normal cases
	csll l = csll();
	l.insertBeginning(1);
	l.insertAfter(l.head, new node_t(2,NULL));
	l.insertAfter(l.head, new node_t(3,NULL));
	//l.peek(l.head);
	l.removeBeginning();
	l.removeAfter(l.head);
	l.peek(l.head);
	l.removeBeginning();
	l.peek(l.head);
	return 0;
}