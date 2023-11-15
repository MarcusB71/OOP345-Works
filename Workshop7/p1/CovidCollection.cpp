#include "CovidCollection.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
namespace sdds {
    CovidCollection::CovidCollection(std::string fileName) {
        ifstream file(fileName);
        if (file) {
            while (file.peek() != EOF) {
                Covid C;
                char buffer[26];
                file.read(buffer, 25);
                C.m_country = trim(buffer);
                file.read(buffer, 25);
                C.m_city = trim(buffer);
                file.read(buffer, 25);
                C.m_variant = trim(buffer);
                file >> C.m_year >> C.m_numCases >> C.m_numDeaths;
                m_collection.push_back(C);
            }
            file.close();
        }
        else {
            throw "Invalid file!";
        }
    }
    void CovidCollection::display(std::ostream& out) const {
        for_each(m_collection.begin(), m_collection.end(), [&out](Covid C) {out << C;});
    }
    std::string CovidCollection::trim(const std::string& str) {
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

    std::ostream& operator<<(std::ostream& os, const Covid& C) {
        os << "| " << left << setw(21) << C.m_country << " | " << setw(15) << C.m_city << " | " << setw(20) << C.m_variant << " | ";
        if (C.m_year > 0) {
            os << setw(6) << C.m_year << " | ";
        }
        else {
            os << setw(6) << "" << " | ";
        }
        os << setw(4) << C.m_numCases << " | " << setw(3) << C.m_numDeaths << " |" << endl;
        return os;
    }
}