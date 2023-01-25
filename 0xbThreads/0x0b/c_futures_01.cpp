// author: a.voss@fh-aachen.de

#include <iostream>
#include <future>
#include <thread>
#include "ts.h"
using namespace std;

void process_data(future<int>& fut);
void load_data(promise<int>&& prom);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01) " << ts() << " | start main" << endl;
    promise<int> promise1;                          // (A)
    future<int> future1{promise1.get_future()};     // (B)

    cout << "02) " << ts() << " | start thread, work for 2s" << endl;
    thread paul1{process_data, std::ref(future1)};  // (C)
    this_thread::sleep_for(2000ms);

    cout << "03) " << ts() << " | done, set value" << endl;
    promise1.set_value (10);                        // (D)

    cout << "04) " << ts() << " | wait for join" << endl;
    paul1.join();

    cout << "05) " << ts() << " | done part I" << endl << endl;

    promise<int> promise2;                          // (F)
    future<int> future2{promise2.get_future()};

    std::thread paul2{load_data, std::move(promise2)};  // (G)
    cout << "06) " << ts() << " | start thread, wait for value" << endl;
    int x = future2.get();
    cout << "07) " << ts() << " | got value: " << x << ", wait for join" << endl;
    paul2.join();

    cout << "08) " << ts() << " | done part II" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void process_data(future<int>& fut) {
    cout << "-a) " << ts() << " | process_data, wait for value" << endl;
    int x = fut.get();                              // (E)
    cout << "-b) " << ts() << " | got value: " << x << ", work with it for 2s" << endl;
    this_thread::sleep_for(2000ms);
    cout << "-c) " << ts() << " | done, end process_data" << endl;
}

void load_data(promise<int>&& prom) {               // (G)
    cout << "-a) " << ts() << " | load_data, load for 2s" << endl;
    this_thread::sleep_for(2000ms);
    cout << "-b) " << ts() << " | done, set value" << endl;
    prom.set_value(20);
    cout << "-c) " << ts() << " | done, end load_data" << endl;
}

/* Kommentierung
 * 
 * (A)  Ein promise<T>-Objekt kann einen Wert vom Typ T speichern, der später
 *      von einem future-Objekt (ggf. in einem anderen Thread) geholt werden kann.
 *      In der promise-future-Kommunikation ist das der push-Teil (provider).
 *      https://www.cplusplus.com/reference/future/promise/
 *      https://en.cppreference.com/w/cpp/thread/promise
 *
 *      Genauer ist ein promise-Objekt mit einem sog. shared-state assoziiert,
 *      ebenso das zugehörige future-Objekt z.B. nach get_future, d.h. sie teilen
 *      sich diesen Status.
 *
 * (B)  Das ist das zugehörige future-Objekt, welches später dem Thread
 *      übergeben wird, damit dieser den Wert dort empfangen kann.
 *      Der shared-state lebt so lange, bis das letzte assoziierte Objekt
 *      'releases' oder zerstört ist. Daher kann das future-Objekt länger
 *      leben als das initiale promise-Objekt.
 *
 *      Future-Objekte können durch
 *          async
 *          promise::get_future
 *          packaged_task::get_future
 *      erzeugt bzw. assoziiert werden.
 *
 * (C)  Start des threads, der auf das Ergebnis wartet. Achtung, das future-Obj.
 *      kann nicht kopiert werden.
 *
 * (D)  Setzen des Werts. Das bewirkt das Aufwachen des blockierenden Threads.
 *
 * (E)  Warten auf den Wert blockiert den Thread. bis entweder ein Wert oder
 *      eine exception gesetzt wurde.
 *
 * (F)  Dies ist der umgekehrte Fall, d.h. main wartet auf die Daten und der
 *      Thread schickt sie.
 *
 * (G)  Deswegen benötigt der Thread auch das promise-Objekt und main nur
 *      den future. Ob die Übergabe per ref oder move erfolgt, ist hier egal.
 *      Die Nutzung von move signalisiert, dass der Thread sich nun darum kümmert.
 */
