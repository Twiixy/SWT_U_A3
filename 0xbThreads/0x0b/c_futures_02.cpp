// author: a.voss@fh-aachen.de

#include <iostream>
#include <future>
#include <thread>
#include "ts.h"
using namespace std;

int process_data(double x);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01) " << ts() << " | start main" << endl;

    packaged_task<int(double)> task1(process_data); // (A)
    auto future1 = task1.get_future();

    cout << "02) " << ts() << " | start thread, wait for return value" << endl;
    std::thread paul1{std::move(task1), 23.5};      // (B)
    auto x1 = future1.get();

    cout << "03) " << ts() << " | got value: " << x1 << ", wait for join" << endl;
    paul1.join();

    cout << "04) " << ts() << " | done part I" << endl << endl;

    cout << "05) " << ts() << " | start async, wait for return value" << endl;
    auto future2 = async(process_data, 123.5); // (C)
    cout << "06) " << ts() << " | do something in between" << endl;
    auto x2 = future2.get();
    cout << "07) " << ts() << " | got value: " << x2 << ", done part II" << endl << endl;

    {                                               // (C)
        auto future3 = async(process_data, 49.5);
        cout << "08) " << ts() << " | future3 is running" << endl;
    }
    cout << "09) " << ts() << " | future3 scope ended, done part III" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

int process_data(double x) {
    cout << "-a) " << ts() << " | process_data, process for 2s" << endl;
    this_thread::sleep_for(2000ms);
    cout << "-b) " << ts() << " | done, return value" << endl;
    return (int)x;
}

/* Kommentierung
 * 
 * (A)  Ein packaged_task ist ähnlich einer std::function, nur dass das Ergebnis
 *      asynchron, via future, erhältlich ist. Der Task enthält ein sog.
 *      callable Element und intern einen shared state, siehe promise.
 *
 * (B)  Der Task wird analog einem callable im Thread gestartet. Wichtig/Üblich ist
 *      hier, den Task per move zu übergeben.
 *
 * (C)  async started die Funktion direkt und gibt den future zurück. Entweder
 *      man wartet mit get auf das Ergebnis, ansonsten wartet der dtor.
 *
 */
