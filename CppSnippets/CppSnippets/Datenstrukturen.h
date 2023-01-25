#include<iostream>
#include<array>
#include<vector>

using namespace std;

class ArrayS {
	array<string, 5> namen = { "a","b","c","d","e"};


public:
	void getnames() {
		for (int i = 0; i < namen.size(); i++) {
			cout << namen[i];
		}
		cout << endl;
	}

};





class VectorS { //find etc in main
public:
	vector<int> v{1,2,3,4,5};



	void ausgeben() {
		for (auto x : v) {
			cout << x << " ";
		}
	}

};