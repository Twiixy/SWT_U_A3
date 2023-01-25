// author: a.voss@fh-aachen.de

#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;
using std::ostream;
using std::is_integral_v;
using std::is_class;
                                                            // (A)

template <typename T>                                       // (B)
struct is_T_pointer {
    static const bool value = false;
};

template <typename T>                                       // (C)
struct is_T_pointer<T*> {
    static const bool value = true;
};

template <typename T, bool isptr>                           // (D)
struct the_collection {
    friend ostream& operator<<(ostream& os, const the_collection& /*c*/) {
        os << "collection-non-pointer";
        return os;
    }
};

template <typename T>                                       // (E)
struct the_collection<T,true> {
    friend ostream& operator<<(ostream& os, const the_collection& /*c*/) {
        os << "collection-pointer";
        return os;
    }
};

template<typename T>                                        // (F)
using collection = the_collection<T,is_T_pointer<T>::value>;

template <typename T>                                       // (G)
struct only_integral {
    static_assert((is_integral_v<T> && std::is_unsigned_v<T>) || std::is_class<T>::value);
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

 	cout << "01|    int=ptr ? " << is_T_pointer<int>::value << endl;
	cout << "02|    int*=ptr ? " << is_T_pointer<int*>::value << endl;

    cout << "-----" << endl;

    collection<double> c1;
    collection<double*> c2;
	cout << "03|    type c1 ? " << c1 << endl;
	cout << "04|    type c2 ? " << c2 << endl;

    cout << "---" << endl;

    only_integral<unsigned int> i1;                         // (G)
    only_integral<unsigned long> i2;
    // only_integral<float> i3;
    // only_integral<int> i4;
    only_integral<ostream> i5;
     
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Ziel ist es, die Spezialisierung zu nutzen, um z.B. für
 *      Zeiger oder Nicht-Zeiger unterschiedliche Collections zu
 *      verwenden.
 *      Diese Art von Verwendung ist typisch für C++ Traits. Zitat
 *      Bjarne Stroustrup:
 *      "Think of a trait as a small object whose main purpose is to
 *       carry information used by another object or algorithm to 
 *       determine 'policy' or 'implementation details'."
 * 
 * (B)  Hilfstemplate, welches es in einer spezialisierten Variante gibt
 *      und das über die Konstante value angibt, ob der Datentyp ein
 *      Zeiger ist oder nicht.
 * 
 * (C)  Spezialisierung nur für Zeiger -> value = true.
 * 
 * (D)  Platzhalter für eine Collection oder Klasse, die für Zeiger
 *      oder Nicht-Zeiger unterschiedliche Implementationen besitzt.
 * 
 * (E)  Hier die Variante für Zeiger.
 * 
 * (F)  Eine (!) bequeme Variante, sich um die interne unterschiedliche 
 *      Behandlung nicht zu kümmern.
 *
 * (G)  Ein Template, bei dem nur einige bestimmte Typen zugelassen sind:
 *      - integrale Typen ohne Vorzeichen, oder
 *      - Klassen.
 *      Der Check läuft zur Compilezeit und das zugehörige Stichwort lautet
 *      'type-traits' (siehe auch (A)).
 *      Entweder man nutzt die Variante 'is_whatever<T>::value' oder die
 *      Kurzform 'is_whatever_v<T>'.
 * 
 */
 
