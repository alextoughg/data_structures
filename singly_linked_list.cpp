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
	void cons(int f){
		node_t* temp = head;
		head = new node_t(f, temp);
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