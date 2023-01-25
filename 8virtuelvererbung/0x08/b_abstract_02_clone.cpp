// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

class object
{
public:
    [[nodiscard]] virtual string to_string() const {        // (H)
        return "object::to_string"; 
    }

    // ~object() { ... }
    virtual ~object() {                                     // (A)
        cout << "-a|      dtor object" << endl;
    }
};

class cloneable {
public:
    virtual object* clone() = 0;
};

class address : public object, cloneable                    // (B)
{
public:
    [[nodiscard]] string to_string() const override {       // (G),(H)
        return "address::to_string"; 
    }
    
    ~address() override {
        cout << "-b|      dtor address" << endl;
    }
    
    object* clone() override { return new address(); }
};

class buffer : public object, cloneable
{
public:
    [[nodiscard]] string to_string() const override {
        return "buffer::to_string"; 
    }

    buffer() : p(new int) { }                               // (C)

    ~buffer() override {
        cout << "-c|      dtor buffer" << endl;
        delete p;
    }
    
    object* clone() override { return new buffer(); }
    
private:
    int* p;
};


int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    address a;
    buffer b;

    cout << "01|    a:" << a.to_string() << endl;
    cout << "02|    b:" << b.to_string() << endl;

    cout << "-----" << endl;
    
    vector<object*> v;                                      // (D)
    v.push_back(a.clone());
    v.push_back(b.clone());
    v.push_back(a.clone());
    v.push_back(b.clone());

    for (object* o : v) {
        cout << "03|    v:" << o->to_string() << endl;      // (E)
    }

    for (object* o : v)
        delete o;                                           // (F)
    v.clear();

    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Der virtuelle dtor ist wichtig, siehe (F).
 * 
 * (B)  'multiple inheritance', d.h. man erbt von mehreren Klassen.
 *      Hier ist die Klasse object mehr eine Basisklasse, wobei cloneable
 *      eher einem Interface vergleichbar ist.
 * 
 * (C)  buffer enthält dynamischen Speicher, d.h. wenn der dtor nicht
 *      ordentlich aufgerufen wird, entsteht ein Speicherleck. 
 * 
 * (D)  Der vector v enthält lauter (raw)Zeiger, die wir selber wegräumen
 *      müssen. Insbesondere sind es nur address- und buffer-Objekte,
 *      aber object-Zeiger. 
 * 
 * (E)  Der Aufruf der 'richtigen' Memberfunktion ist korrekt.
 * 
 * (F)  Wenn der dtor von object nicht virtuell ist, entsteht hier ein
 *      Speicherleck. Test mit valgrind.
 *
 * (G)  'override' unterstreicht den Wunsch, dass hier die Funktion überschrieben
 *      wird und erzeugt anderenfalls einen Fehler ('express your intentions to the compiler.').
 *      Es gibt auch noch 'final', was selten gebraucht wird. Damit kann man
 *      das Überschreiben einer Funktion oder das Ableiten von einer Klasse
 *      verhindern.
 *
 * (H)  '[[nodiscard]]', zur Erinnerung, erzeugt ein Warning, wenn der Rückgabewert
 *      nicht verwendet wird.
 *
 */
 
