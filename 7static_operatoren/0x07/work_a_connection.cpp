// author: a.voss@fh-aachen.de

#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

#include "work_a_connection.hpp"

/*
 * Trennung Header und Implementierung.
 *
 * Hier nur die Implementierung. Man beachte die vollständige Qualifizierung des Namens,
 * also connection::xxx
 */

connection::connection(const std::string& url) : url{url} {
    cout << "[ + connection ctor " << *this << " ]" << std::endl;
}

connection::~connection() {
    cout << "[ - connection dtor " << *this << " ]" << std::endl;
}

bool connection::is_connected() const {
    return true;
}

std::ostream& operator<<(std::ostream& os, const connection& c) {
    os << "('" << c.url
       << "'," << (c.is_connected()?"connected":"disconnected")
       << ",this=" << &c
       << ")";
    return os;
}
