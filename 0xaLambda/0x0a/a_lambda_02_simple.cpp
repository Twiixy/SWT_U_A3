// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    auto less = [](int a, int b) -> bool { return a < b; }; // (A)
    cout << "01|    2<3? " << less(2,3) << endl;            // (B)
    cout << "02|    3<2? " << less(3,2) << endl;

    auto plus2 = [](int n) -> int { return n+2; };          // (C)
    auto plus3 = [](int n) -> auto { return n+3; };         // (D)
    auto plus4 = [](int n) { return n+4; };                 // (E)

    int n{7};
    cout << "03|    n=" << n 
         << ", n+2=" << plus2(n)                            // (F)
         << ", n+3=" << plus3(n) 
         << ", n+4=" << plus4(n) << endl;

    cout << "-----" << endl;

    int m{3};
    auto plusm = [=](int n) { return n+m; };                // (G)

    cout << "04|    n=" << n << ", m=" << m
         << ", n+m=" << plusm(n) << endl;

    m = 100;                                                // (H)
    cout << "05|    n=" << n << ", m=" << m
         << ", n+m=" << plusm(n) << endl;

    m = 3;
    auto plusrefm = [&m](int n) { return n+m; };            // (I)

    cout << "06|    n=" << n << ", m=" << m
         << ", n+m=" << plusrefm(n) << endl;

    m = 100;                                                // (J)
    cout << "07|    n=" << n << ", m=" << m
         << ", n+m=" << plusrefm(n) << endl;

    cout << "-----" << endl;

    string A{"<"}, B{">"};
    auto compose = [&](const string& s) { return A+s+B; };  // (K)

    cout << "08|    compose:'" << compose("line") << "'" << endl;

    cout << "-----" << endl;

    struct S {
        int n{0};
        void f() {
            [&]() -> void { n = 1;} ();                     // (L)
            cout << "09|    n=" << n << endl;
        }
        void g() {
            [*this]() mutable -> void { n = 2;} ();         // (M)
            cout << "10|    n=" << n << endl;
        }
        void h() {
            [this]()mutable -> void { n = 3;} ();           // (N)
            cout << "11|    n=" << n << endl;
        }
    };
    S().f();
    S().g();
    S().h();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Das ist ein lambda-Ausdruck (lambda-Expression). Er besteht im
 *      Kern aus drei Teilen:
 *      - die [] Klammern zu Beginn, Erklaerung folgt.
 *      - die Parameter
 *      - der Anweisungsblock {} selbst.
 *      Je nach Syntax (zwei Varianten) benoetigen wir noch "->" und 
 *      den Rueckgabetyp.
 *      Dieser Ausdruck berechnet "a<b", der Rueckgabetyp (bool) ist
 *      extra angegeben und der Ausdruck insgesamt ist mit einem "auto"
 *      dem Compiler ueberlassen.
 *      Die Syntax mit dem "->" orientiert sich an der mathematischen 
 *      Schreibweise x->x^2.
 * 
 * (B)  Man verwendet die Lambda-Ausdruecke wie eine Funktion.
 *      
 * (C)  Weiterer lambda-Ausdruck, er berechnet "n+2".
 * 
 * (D)  Wie (C), nur dass der Rueckgabetyp automatisch ermittelt wird.
 * 
 * (E)  Andere Syntax ohne "->".
 * 
 * (F)  Wie (B).
 * 
 * (G)  In der Funktion des lambda-Ausdrucks wird auf "m" zugegriffen.
 *      Welches "m" wird verwendet? Der Ausdruck "=" in den [] gibt an,
 *      wie und welche "externen" Variablen verwendet werden koennen.
 *      Hier sagt "=", dass "m" kopiert wird und diese Kopie innerhalb
 *      bekannt ist.
 * 
 * (H)  Achtung: das "m" aus (G) ist nicht immer der aktuelle Wert sondern
 *      die zu Beginn erstellte Kopie!
 * 
 * (I)  Wie (I), nur dass "m" jetzt als Referenz verwendet wird...
 * 
 * (J)  ... und daher auch in der Berechnung beruecksichtigt wird.
 * 
 * (K)  Man kann auch generell alle externen Groessen per Referenz 
 *      durch "&" in den [] verwenden, hier etwa die Strings.
 *
 * (L)  Lambda mit direktem Aufruf... aber es geht hier um die capture clause:
 *      capture & -> Alles per Referenz, auch this.
 * (M)  capture *this -> Das ist eine Kopie von *this, allerdings const,
 *      daher das zusätzliche 'mutable', damit die Kopie verändert werden kann.
 *      Das Original-n bleibt natürlich erhalten.
 * (N)  capture this -> this per Referenz, genauer *this
 *
 *      Insgesamt hat sich capture this über die Standards verändert, siehe
 *      https://en.cppreference.com/w/cpp/language/lambda
 *      https://www.nextptr.com/tutorial/ta1430524603/capture-this-in-lambda-expression-timeline-of-change
 *
 */
 
