#include"Datenstrukturen.h"
#include<iostream>
#include"Lambda.h"
#include<algorithm>

using namespace std;



int main() {

	ArrayS aBsp;
	aBsp.getnames();

	VectorS vBsp;
	vBsp.ausgeben();

	vector<int>v= vBsp.v;

	auto it5 = find(v.begin(), v.end(), 2);
	if (it5 != v.end()) {
		v.insert(it5, 23);
		v.erase(it5);
	}
	vBsp.ausgeben();

	array<int, 11> arr = { 5,7,4,2,8,6,1,9,0,3,5 };


	//algorithmen/lambda
	all_of(arr.begin(), arr.end(), [](int i) {return i >= 0; });

	struct sum_op {
		int sum;
		sum_op():sum{0}{}
		void operator ()(int n) { sum += n; }
	};

	//sum_op s = for_each(arr.begin(), arr.end(); sum_op());



	count(arr.begin(), arr.end(), 5);//zählen wieoft 5 in arr



	auto find_even = find_if(arr.begin(), arr.end(), [](int i) {return (i % 2) == 0; });

	fill(arr.begin(), arr.end(), 11);//füllen

	//copy(arr.begin(), n, arr2.begin()) kopiert von arr.begin die nächsten n elemente in arr2


	return 0;
}