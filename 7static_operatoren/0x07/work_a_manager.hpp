// author: a.voss@fh-aachen.de

#pragma once

#include <string>
#include <memory>

#include "work_a_connection.hpp"

/*
 * Trennung Header und Implementierung.
 *
 * Hier nur die Klasse ohne Implementierung.
 *
 * Bitte Anmerkung in *.cpp und main beachten, denn diese statische Variable
 * würde man _so_ nicht verwenden.
 */

class database_manager {
    database_manager();
    static std::shared_ptr<database_manager> the_manager;   // "Singleton"

public:
    ~database_manager();

    connection make_connection(const std::string& url);

    static std::shared_ptr<database_manager> instance();
    friend std::ostream& operator<<(std::ostream& os, const database_manager& c);
};
