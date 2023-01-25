// author: a.voss@fh-aachen.de

#include <iostream>

using std::cout;
using std::endl;

int f(int n) { return n+n; }
[[nodiscard]] int g(int n) { return n+n; }          // (A)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
        
    cout << "01|    f(1) = " << f(1) << endl;

    f(2);
    g(3);                                           // (A)

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Das Attribut [[nodiscard]] führt dazu, dass der Aufruf einer Funktion
 *      mit Rückgabewert, bei dem die Rückgabe aber nicht verwendet wird,
 *      ein Warning generiert -> hier nur bei g(3).
 */
