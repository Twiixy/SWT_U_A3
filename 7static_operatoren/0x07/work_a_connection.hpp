// author: a.voss@fh-aachen.de

#pragma once

#include <string>
#include <ostream>

/*
 * Trennung Header und Implementierung.
 *
 * Hier nur die Klasse ohne Implementierung.
 */

class connection {
    std::string url;
    connection(const std::string& url);     // private

public:
    ~connection();

    [[nodiscard]] bool is_connected() const;

    friend std::ostream& operator<<(std::ostream& os, const connection& c);
    friend class database_manager;          // darf Instanzen erzeugen
};
