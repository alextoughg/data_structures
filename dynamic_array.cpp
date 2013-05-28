using namespace std;

struct dynarray{
	// Content of dynamic array.
	void * content;
	// Logical size: number of elements 
	// used by array.
	int size;
	// Physical size: maximum possible size 
	// without relocating data.
	int capacity; 
	dynarray(){
		;
	}
}