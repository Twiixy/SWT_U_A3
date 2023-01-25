// author: a.voss@fh-aachen.de
// remarks: P.Blaneck

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_all_lines(const std::string &fin);
void write_all_lines(const std::string &fout,
                     const std::vector<std::string> &lines);

// file IO
int main() {
    std::vector<std::string> lines;
    lines = read_all_lines("../sixlines.txt");

    for (const auto &line : lines) {
        std::cout << line << std::endl;
    }

    write_all_lines("../sixlines_out.txt", lines);
}

// Implementieren Sie eine "read_all_lines" Funktion, die eine Textdatei
// komplett einliest und die Zeilen in einem Vektor von Strings zurückgibt.
std::vector<std::string> read_all_lines(const std::string &fin) {
    std::vector<std::string> lines;

    std::ifstream ifs_fin(fin);

    if (ifs_fin) {
        std::string temp;
        while (std::getline(ifs_fin, temp)) {
            lines.push_back(temp);
        }
        ifs_fin.close();
    } else {
        std::cout << "Fehler in read_all_lines!" << std::endl;
    }

    return lines;
}

// Implementieren Sie analog eine "write_all_lines" Funktion, die einen
// übergebenen Vektor von Strings in eine Textdatei schreibt.
void write_all_lines(const std::string &fout,
                     const std::vector<std::string> &lines) {
    std::ofstream ofs_fout(fout);

    if (ofs_fout) {
        for (const auto &line : lines) {
            ofs_fout << line << std::endl;
        }
        ofs_fout.close();
    }
}
