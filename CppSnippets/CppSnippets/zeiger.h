#include<memory>
#include<iostream>

using namespace std;

class test {
public:
	int as;
	test(int a):as{a}{ }
};
//unique_ptr
unique_ptr<test>p = make_unique<test>(5);
//2 können nicht auf den gleichen speicherbereich zeigen
//mit p2=move(p) möglich
//p.reset()//löscht







//funktionszeiger:
typedef double (*function_t)(double);


//sharedpointer
shared_ptr<test> sp = make_shared<test>(7);
shared_ptr<test> sp2 = sp;

 void ausgeben() {
	 sp2.use_count();//anzahl der elemente die auf den speicher zeigen
	 sp2.reset();//gibt frei -> letzter löst destruktor auf
}


 //weakptr
 weak_ptr
