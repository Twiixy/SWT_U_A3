// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::numeric_limits;

int x{};

// template<typename T>
// [...]
// T::Z * x;                                        // (A)

template<typename T>
void f() {
    // T::Z * x;                                    // (B)
    typename T::Z * x;
}

template<typename T>
void g() {
    T::Z * x;
    // typename T::Z * x;                           // (C)
}

struct F { typedef int       Z;      };
struct G { static  int const Z = 23; };

template <typename T>
struct collection {
    typedef typename T::value_type value_type;      // (D)
};

template <typename T>
struct A {
    typedef T value_type;
};

template <template <typename> typename T, typename S>   // (F)
struct meta_collection {
    typename T<S>::value_type v;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    f<F>();                                         // (B)
    // f<F>();
    // g<G>();
    g<G>();                                         // (C)

    collection<vector<int>>::value_type w{};        // (D)

    vector<int>::value_type * v{};                  // (E)
    numeric_limits<int>::is_signed * 1;

    meta_collection<A,double> mc_d{};               // (F)
    meta_collection<A,int> mc_i{};

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Was bedeutet dieser Ausdruck im Kontext eines Templates?
 *      Wenn T eine Klasse mit einem Typ Z ist, dann definiert der Ausdruck
 *      einen Zeiger. -> (B)
 *      Ist T jedoch eine Klasse mit einem statischen Element Z, dann ist
 *      es eine einfache Multiplikation (bzw. das, was der Op.* macht). -> (C)
 *      Zusammengefasst gibt es Situationen, wo man dem Compiler sagen muss,
 *      dass es sich um einen Datentyp handelt - und das macht 'typename' als
 *      zusätzliche Angabe vor einem Datentyp aus einem Template.
 *
 * (B),(C) Beachte den jeweils zugehörigen Aufruf in main.
 *
 * (D)  Gleiche Situation. Der Compiler kennt T in collection nicht und wir
 *      sagen explizit, dass T::value_type ein Datentyp ist.
 *      Bei den Beispielen in main ist das nicht notwendig, da hat der Compiler
 *      alle Informationen und weiß, was es ist.
 *
 * (E)  Nochmal ein Beispiel für gleiche Syntax, aber unterschiedliche Semantik.
 *
 * (F)  Das entscheidende hier ist die Verwendung eines Template-Parameters, der
 *      selbst wieder ein Template ist... beachte hier, dass in main A ohne
 *      eigenen Parameter in meta_collection verwendet wird.
 *
 */
