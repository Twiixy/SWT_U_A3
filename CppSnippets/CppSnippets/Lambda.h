#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;


array<int, 5>a = { 1,5,7,6,8 };

auto less = [](int a, int b)->auto {return a; };  //[] bedeutet dass man variablen die man dort nutzt nicht nur nur kopiert (( [=] kopiert es nur))  
//[&variable] nimmt immer den aktuellen wert

//sort(a.begin(), a.end(), less);

