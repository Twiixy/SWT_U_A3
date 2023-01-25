// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::thread;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void start_and_wait_for_thread() {
    thread([]() -> void {                           // (A)
        printf("- starte worker-thread, warte 2s\n");
        sleep_for(milliseconds(2000));
        printf("- worker-thread fertig...\n");
    }).join();
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01| starte thread" << endl;
    start_and_wait_for_thread();

    cout << "02| thread gestartet, warte 3s" << endl;
    sleep_for(milliseconds(3000));

    cout << "03| main-thread fertig\n" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
/* Kommentierung
 *
 * (A)  thread mit Lambda-Ausdruck starten und auf das Ende warten
 *      => join blockiert den Aufruf! Ist noch nicht so die Idee von
 *      paralleler Verarbeitung...
 *
 */
