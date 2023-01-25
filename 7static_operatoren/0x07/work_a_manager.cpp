// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
#include <memory>

#include "work_a_connection.hpp"
#include "work_a_manager.hpp"

/*
 * Trennung Header und Implementierung.
 *
 * Hier nur die Implementierung.
 *
 * Bitte Anmerkung in main beachten, denn diese statische Variable würde man _so_
 * nicht verwenden.
 *
 * Einen Singleton, wenn man denn einen verwenden möchte, wird man als sog.
 * Meyers-Singleton implementieren - der Verwendung einer lokalen statischen Variablen
 *      https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 *      https://laristra.github.io/flecsi/src/developer-guide/patterns/meyers_singleton.html
 *      https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 * bzw.
 *      Modern C++ Design: Generic Programming and Design Patterns Applied, Andrei Alexandrescu.
 *
 *  static singleton_t & instance() {
 *      static singleton_t s;       // wird nur einmal angelegt - und faktisch lazy
 *      return s;
 *  }
 */

// Wg. private ctr in make_shared siehe
//      https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared#Notes
std::shared_ptr<database_manager> database_manager::the_manager = //std::make_shared<database_manager>();
        std::shared_ptr<database_manager>(new database_manager());

connection database_manager::make_connection(const std::string& url) {
    return connection(url);
}

std::shared_ptr<database_manager> database_manager::instance() {
    std::cout << "[ . database_manager instance " << (*the_manager) << " ]" << std::endl;
    return the_manager;
}

database_manager::database_manager() {
    std::cout << "[ + database_manager ctor " << (*this) << " ]" << std::endl;
}

database_manager::~database_manager() {
    std::cout << "[ - database_manager dtor " << (*this) << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const database_manager& dm) {
    os << "(this=" << &dm
       << ")";
    return os;
}
