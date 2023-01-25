// author: a.voss@fh-aachen.de

#include <iostream>
#include <array>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::array;

// Part I: struct vs. class

//------------------------------------

struct S1 {
    int n,m;
};

class C1 {
    int n,m;
};

//------------------------------------

struct S2 {
private:
    int n,m;
};

class C2 {
public:
    int n,m;
};

//------------------------------------

// Part II: Named parameter or Designated initializers

//------------------------------------

int add(int arg_n, int arg_m) {
    return arg_n+arg_m;
}

struct Add_Params { int arg_n, arg_m; };

int add(const Add_Params& p) {
    return add(p.arg_n,p.arg_m);
}

//------------------------------------

// Part III: raw array vs. std::array

//------------------------------------

struct Vector {
    static const int dim = 3;

    int coeffs1[dim]{1,2,3};            // sum=6

    array<int,dim> coeffs2{4,5,6};      // sum=15
};

int eval_sum(const int coeffs[], int dim) {     // int eval_sum(int coeffs[dim]) ; coeffs[0]=11;
    int sum{0};
    for (size_t i=0; i<dim; sum+=coeffs[i++]) ;
    return sum;
}

int eval_sum(const array<int,Vector::dim>& coeffs) {    // //int eval_sum(const decltype(Vector::coeffs2)& coeffs)
    int sum{0};
    for (auto c : coeffs) sum+=c;
    return sum;
}

//------------------------------------

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    // Part I: struct vs. class

    {   // S1 vs. C1
        S1 s1{101,201};
        cout << "01|    s1: (" << s1.n << "," << s1.m << ")" << endl;

        // C1 c1{501,601};  // error: no matching constructor for initialization of 'C1'
    }

    {   // S2 vs. C2
        // S2 s2{102,202};  // error: no matching constructor for initialization of 'S2'

        C2 c2a{502,602};
        cout << "02|    c2a: (" << c2a.n << "," << c2a.m << ")" << endl;

        C2 c2b{.n=34,.m=12,};
        cout << "02|    c2b: (" << c2b.n << "," << c2b.m << ")" << endl;
    }

    // for "Default constructors" see https://en.cppreference.com/w/cpp/language/default_constructor
    // for "List-initialization" see https://en.cppreference.com/w/cpp/language/list_initialization
    // for "Aggregate initialization" see https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers

    // Part II: Named parameter or Designated initializers

    {
        auto k12 = add(1,2);
        auto k34 = add({.arg_n=3,.arg_m=4});

        cout << "03|    k12: " << k12 << ", k34: " << k34 << endl;
    }

    // Part III: raw array vs. std::array

    {
        Vector v;
        cout << "04|    v: " << eval_sum(v.coeffs1,v.dim) << endl;
        cout << "04|    v: " << eval_sum(v.coeffs2) << endl;
    }

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
