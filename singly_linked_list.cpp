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

struct sll{
	node_t* head;
	sll(){
		head = NULL;
	}
	void insertBeginning(int f){
		node_t* temp = head;
		head = new node_t(f, temp);
	}

	// The node pointed by ptr_to_new_node is the successor of the 
	// node pointed by ptr_to_node
	void insertAfter(node_t* ptr_to_node, node_t* ptr_to_new_node){
		if(ptr_to_node && ptr_to_new_node){
			ptr_to_new_node->next = ptr_to_node->next;
			ptr_to_node->next = ptr_to_new_node;
		}
	}

	void removeBeginning(){
		if(head){
			//(According to Wikipedia)
			//node_t* obsolete = head;
			//head = head->next;
			//delete obsolete;
			// My way
			node_t* next = head->next;
			delete head;
			head = next;
		}		
	}

	// Remove the node after the node pointed to 
	// by ptr_to_node
	void removeAfter(node_t* ptr_to_node){
		if(ptr_to_node){
			node_t* obsolete = ptr_to_node->next;
			node_t* obsolete_succ = obsolete->next;
			delete obsolete;
			ptr_to_node->next = obsolete_succ;
		}
	}

	// The contents of the list printed to stdio.
	void peek(){
		node_t* p = head;
		while(p){
			cout << p->key << endl;
			p = p->next;
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
	sll l = sll();
	l.insertBeginning(1);
	l.insertAfter(l.head, new node_t(2,NULL));
	l.insertAfter(l.head, new node_t(3,NULL));
	l.peek();
	l.removeBeginning();
	l.peek();
	l.removeAfter(l.head);
	l.peek();
	l.removeBeginning();
	l.peek();


}