#include <iostream>
using namespace std;

class DoublyLinkedList{
private:
	struct Node_t{
		int key;
		Node_t* prev;
		Node_t* next;
		Node_t(int key_){key = key_;}
	};
public:
	Node_t* first;
	DoublyLinkedList(){first = NULL;}
	void insertAfter(Node_t* node, Node_t* newNode){
		if(node != NULL){
			newNode->prev = node;
			node->next = newNode;
		}
		else{
			first = newNode;
		}
	}
	void insertBefore(Node_t* node, Node_t* newNode){
		if(newNode != NULL){
			if(node == NULL || node == first){
				first = newNode;
			}
			newNode->next = node;
			node->prev = newNode;
		}
	}
	void deleteNode(Node_t* node){
		if(node != NULL){
			if(node == first){
				Node_t* tail = node->next;
				first = tail;
			}
			else if(node->next == NULL){
				Node_t* p = node->prev;
				p->next = NULL;
			}
			else{
				Node_t* n = node->next;
				Node_t* p = node->prev;
				p->next = n;
				n->prev = p;
			}
			delete node;
		}
	}
	void iterate(Node_t* node){
		if(first == NULL || node == NULL){
			cout << "List is empty" << endl;
		}
		else{
			Node_t* current = node;
			do{
				cout << current->key << endl;
				current = current->next;
			} while(current != NULL);
		}
	}
	void test(){
		insertAfter(first, new Node_t(1));
		insertBefore(first, new Node_t(0));
		iterate(first);
		deleteNode(first->next);
		deleteNode(first);
		iterate(first);
	}
};

int main(){
	DoublyLinkedList l = DoublyLinkedList();
	l.test();
	return 0;
}