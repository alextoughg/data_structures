#include <list>
#include <assert.h>
#include <limits>
#include <string>
#include <iostream>
#define SIZE 1000

using namespace std;

const long long long_long_max = numeric_limits<long long>::max();
const long long long_long_min = numeric_limits<long long>::min();

/* A hashtable that contains 1000 slots and maps strings to long long ints.*/
class HashTable{
private:
	struct Pair{
		string key;
		long long value;
		Pair(string key_, long long value_)
		    : key(key_), value(value_) {}
		/*Pair(string key_, long long value_){
			// Is this the right way to copy a string?
			key(key_);
			value = value_;
		}*/
		/*Pair & operator=(const Pair &rhs){
			cout << "Here" << endl;
			if (this == &rhs)      // Same object?
				return *this;        // Yes, so skip assignment, and just return *this.
			key = rhs.key;
			value = rhs.value;
			return *this;
		}*/
		/*
		bool operator==(const Pair &x, const Pair &y){
			;
		}*/
	};

	list<Pair> table[SIZE];
public:
	int hash_function(string s){
		int acc = 0;
		for(int i=0;i<s.length();i++){
			acc += s[i];
		}
		return acc % SIZE;
	}
	void insert(string key, long long value){
		//assert(key.compare(NULL));
		table[hash_function(key)].push_back(Pair(key, value));
	}
	list<Pair>::iterator find(string key){
		// Null isn't a valid value for string, since it is an object!
		// http://www.gamedev.net/topic/421554-c-how-do-i-check-if-a-stdstring-is-null/
		list<Pair> l = table[hash_function(key)];
		list<Pair>::iterator it;
		for(it = l.begin();it!=l.end();it++){
			if(!key.compare(it->key)){
				break;
			}
		}
		return it;
	}
	void erase(string key){
		
		
		list<Pair> l = table[hash_function(key)];
		list<Pair>::iterator it = find(key);
		if(it != l.end()){
			// The trouble is that the erase operator doesn't 
			// know how to treat your data structures.
			l.erase(it);
		}
		
		// Alternative version:
		//list<Pair> l = table[hash_function(key)];
		// With remove you have to define the == operator!
		//l.remove(Pair(key, find(key)->value));
	}
	void test(){
		
		// For insert
		// - Normal case
		string key1 = "Hello"; string key2 = "I"; string key3 = "am"; string key4 = "Alex";
		insert(key1, 0);
		insert(key2, 0);insert(key3, 0);insert(key4, 0);
		// - The extremes
		insert("", 4);
		insert("Large positive", long_long_max);
		insert("Large negative", long_long_min);

		
		// - Nulls & illegal input
		// Not valid call (notifies at run time)
		//insert(NULL, 5);
		insert("Small", 0.0000000000000001);
		// You can't really check for overflow inside the function!
		// The only way you can do it is by checking it outside!
		//insert("X-Large-Pos", long_long_max+1);
		//insert("X-Large-Neg", long_long_min-1);

		
		
		// For find
		// - Normal case
		assert(!key1.compare(find(key1)->key));
		assert(!key2.compare(find(key2)->key));
		assert(!key3.compare(find(key3)->key));
		assert(!key4.compare(find(key4)->key));

		// - The extremes
		string large = "Large";
		string large_pos = "Large positive";
		string emp = "";
		// Fails, as expected! :)
		//assert(!large.compare(find(large)->key));
		assert(!emp.compare(find(emp)->key));
		assert(!large_pos.compare(find(large_pos)->key));
		// Nulls & illegal input
		// Illegal at runtime!
		//find(NULL);
		// Doesn't compile! :)
		//find(5);

		
		// For erase
		// - Normal case
		erase(key2);
		/*erase(key1);
		// - The extremes
		erase(emp);
		// - Nulls & illegal input
		//erase(NULL);
		// Doesn't compile! :)
		//erase(3);
		// - Strange input
		erase(key1);*/
	}
};

int main(){
	HashTable h = HashTable();
	h.test();
	return 0;
}