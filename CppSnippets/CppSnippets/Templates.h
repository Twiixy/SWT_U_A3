#include<iostream>

template<typename T1, typename T2>
class Templates {
private:
	T1 key;
	T2 value;

public:

	//virtual    quasi override

	//virtual .... :=0; abstracte klasse

	//konstruktor
	Templates(T1 a, T2, b) :key{ a }, value{ b } {

	}

	//copykonstruktor
	Templates(const Templates& t) :key{ t.key }, value{ t.value } {

	}

	//destruktor
	~Templates(){}


	//getter:
	T1 getKey() const { return key; }

	friend ostream& operator<<(ostream& os, const Templates& t) {
		os << "(key = " << t.key << " value = " << t.value << ")" << endl;
		
	}


};


template<typename T2>
class Templates<int, T2>
{
	long key;
	T2 value;
};