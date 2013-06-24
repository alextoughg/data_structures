// An implementation of the StringBuffer class of Java,
// allowing a maximum of SIZE characters in the buffer.

#include <string>
#include <iostream>
#include <string.h> //for memset
#include <assert.h>
#define SIZE 1024

using namespace std;

class StringBuffer{
private:
	char buffer[SIZE];
	int current_size;
public:
	StringBuffer(){
		current_size = 0;
		buffer[0] = '\0';
	}
	void append(string s){
		int l = s.length();
		if( l + current_size > SIZE-1){
			cout << "No more space to add string" << endl;
		} else{
			for(int i=current_size;i<current_size+l;i++){
				buffer[i] = s[i-current_size];
			}
			current_size += l;
			buffer[current_size] = '\0';
		}
	}
	string toString(){
		string res(buffer);
		return res;
	}
	void clear(){
		memset(buffer, SIZE, 0);
		current_size = 0;
	}
	void test(){

		// Normal case
		string k = "Krypton";
		string h = "Earth";
		string kh = "KryptonEarth";
		append(k);
		append(h);
		assert(!kh.compare(toString()));
		clear();
		cout << "Normal case OK" << endl;

		// Extreme case
		string e;
		e.append(SIZE-1, 'f');
		append(e);
		assert(!e.compare(toString()));
		clear();
		cout << "Extreme case OK" << endl;		

		// Nulls and illegal input
		string ee;
		ee.append(SIZE, 'f');
		append(ee);
		clear();

		string emp = "";
		append(emp);
		assert(!emp.compare(toString()));
		clear();
		cout << "Nulls and illegal cases OK" << endl;				
	}
};

int main(){
	StringBuffer b = StringBuffer();
	b.test();
	return 0;
}