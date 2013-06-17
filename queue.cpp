#include <iostream>
using namespace std;

// A stack of positive ints.
class Stack{
private:
	struct Node_t{
		int key;
		Node_t* next;
		Node_t(int key_){
			key = key_;
		}
	};
public:
	Node_t* head;
	Stack(){
		head = NULL;
	}
	void push(int k){
		Node_t* new_node = new Node_t(k);
		if(head != NULL){
			new_node->next = head;
			head = new_node;
		} else{
			head = new_node;
		}
	}
	int top(){
		if(head != NULL){
			return head->key;
		} else{
			return -1;
		}
	}
	void pop(){
		if(head != NULL){
			Node_t* obsolete = head;
			head = head->next; 
			delete obsolete;
		} else{
			cout << "Nothing to pop!" << endl;
		}
	}
};

int main(){
	Stack s = Stack();
	s.push(NULL);
	for(int i=0;i<100;i++){
		S.push(i);
	}
	cout << S.top() << endl;
	for(int i=0;i<100;i++){
		S.pop();
	}
	cout << S.top() << endl;
	S.pop();
	return 0;
}