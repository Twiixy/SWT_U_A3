// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

#include "work_a_manager.hpp"
#include "work_a_connection.hpp"

/*
 * Hintergrund:
 *
 *  Wir sprachen über sog. Klassenvariablen bzw. statische Variablen einer Klasse
 *  (es gibt weitere statische Variablen) in C++ und Beispiele dafür.
 *  Das Problem dabei ist, dass statische Variablen durchaus Nachteile haben,
 *  etwa Testbarkeit, und deswegen gar nicht so häufig verwendet werden bzw.
 *  man das Design hinterfragen sollte.
 *
 *  Darum habe ich auch kein gutes Beispiel gefunden, wo ich sagen würde, dass
 *  unbedingt eine statische Variable zum Einsatz kommen müsste.
 *  Um dennoch ein weiteres halbwegs reales Beispiel zu nennen, habe ich hier eine
 *  Art Singleton zur Verwaltung von Database-Connections (z.B. für Pooling) gebaut,
 *  der in so einer Art durchaus in Frameworks oder als Library vorkommt,
 *  z.B. in Android:
 *      BluetoothAdapter adapter = BluetoothAdapter.getDefaultAdapter();
 *      ConnectivityManager manager = (ConnectivityManager)getSystemService(Context.CONNECTIVITY_SERVICE);
 *  oder bzgl. Connection Pooling hier in der Lib.
 *      https://devcenter.heroku.com/articles/connecting-to-relational-databases-on-heroku-with-java
 *
 *  Dieses Beispiel hier demonstriert ein paar Aspekte, über die wir diskutiert haben:
 *      - Trennung hpp zu cpp (hier auch CMakeList beachten)
 *      - statische Klassenvariable
 *      - friend class
 *  benutzt aber auch Konzepte, die wir noch diskutieren werden:
 *      - Trennung hpp zu cpp
 *      - #pragma once
 *      - shared_ptr
 *      - [[nodiscard]]
 *
 *  Daher also bitte nur als Ideensammlung betrachten und bei Bedarf gerne nachfragen.
 */

void mail_to_class() {
    auto manager = database_manager::instance();
    auto connection = manager->make_connection("Driver={MySql};Server=localhost;Database=School");
    // ... sql-command auf connection
    cout << "      mail to class" << endl;
}

void read_customers() {
    int n;
    auto manager = database_manager::instance();
    auto connection = manager->make_connection("Driver={MySql};Server=localhost;Database=Business");
    // ... sql-command auf connection
    cout << "      read customers" << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    mail_to_class();

    cout << endl;

    read_customers();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/*
 * Anmerkungen:
 *
 *  Wie üblich ist das Thema "Initialisierung statischer Variablen" nicht so einfach,
 *  wie es vielleicht aussieht. Infos bzw. nette Kommentare findet man hier
 *      https://en.cppreference.com/w/cpp/language/initialization
 *      https://pabloariasal.github.io/2020/01/02/static-variable-initialization/
 *
 *  Wichtig ist hier das "The Static Initialization Order Fiasco" zu erwähnen,
 *  für alle die, die eine feste Reihenfolge der Initialisierung, z.B. entsprechend
 *  der Abhängigkeit, erwarten. Der entsprechende Teil zum Aufräumen findet sich
 *  hier erläutert
 *      https://en.cppreference.com/w/cpp/utility/program/exit
 */
