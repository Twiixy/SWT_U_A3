// author: a.voss@fh-aachen.de

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout;
using std::endl;
using std::string;

// bindet externe Deklarationen ein
#include "d_link_01_extern.hpp"

// Achtung !!!
// Das würde man hier nicht so inkludieren, sondern in einem Build-Tool,
// z.B. make, diese Datei einzeln compilieren (genau wie main) und dann
// in einem zweiten Schritt, '01_main' und '01_extern' "linken".
// Der Einfachheit halber kompilieren und linken wir hier zusammen.
// Achtung !!! Beachten Sie auch das Video dazu.
#include "d_link_01_extern.cpp"

// ab C++20 gibt es auch Module...
// https://en.cppreference.com/w/cpp/language/modules
// oder im Detail z.B. ab hier (3-Serie)
// https://vector-of-bool.github.io/2019/03/10/modules-1.html
// da der Compiler- und CMake-Support aber bislang mäßig ist,
// lassen wir das Thema bis auf Weiteres außen vor

int main()
{
    // externe Funktion
    write_something("hello");

    // externe Klasse
    C c;
    cout << "2*12=" << c.mal2(12) << ", C::m=" << C::m << endl;

    // Template, als einziges vollständig in header-File
    D<int> d;
    return EXIT_SUCCESS;
}

