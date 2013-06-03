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
		ptr_to_new_node->next = new_node->next;
		ptr_to_node->next = new_node->next;
	}
	void deleteHead(){
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
	void peek(){
		node_t* p = head;
		while(p){
			cout << p->key << endl;
			p = p->next;
		}
	}

};

int main(){
	sll l = sll();
	l.cons(1);
	l.cons(2);
	l.cons(3);
	l.peek();
	l.deleteHead();
	l.peek();
}