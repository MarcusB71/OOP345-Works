#include "Movie.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
namespace sdds {
    Movie::Movie() {}
    Movie::Movie(const std::string& strMovie) {
        stringstream s(strMovie);
        string movieLine;
        getline(s, movieLine, ',');
        if (!movieLine.empty()) { m_title = trim(movieLine); }
        getline(s, movieLine, ',');
        if (!movieLine.empty()) { m_year = stoi(trim(movieLine)); }
        while (getline(s, movieLine, ',')) {
            if (!movieLine.empty()) {
                m_desc += " ";
            }
            m_desc += trim(movieLine);
        }
    }
    Movie::~Movie() {}
    const string& Movie::title() const {
        return m_title;
    }
    std::string Movie::trim(const std::string& str) {
        //left trim
        std::string lTrim = str;
        size_t start = lTrim.find_first_not_of(" \n\r\t");
        if (start != std::string::npos) {
            lTrim.erase(0, start);
        }
        //right trim
        std::string rTrim = lTrim;
        size_t end = rTrim.find_last_not_of(" \n\r\t");
        if (end != std::string::npos) {
            rTrim.erase(end + 1);
        }
        return rTrim;
    }

    ostream& Movie::print(ostream& os)const {
        os << setw(40) << m_title << " | " << setw(4) << m_year << " | " << m_desc << endl;
        return os;
    }
    ostream& operator<<(ostream& os, const Movie& M) {
        return M.print(os);
    }
}