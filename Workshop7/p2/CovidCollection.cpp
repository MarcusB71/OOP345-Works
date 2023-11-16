/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/16
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "CovidCollection.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
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
    void CovidCollection::display(std::ostream& out, const std::string& country) const {
        size_t worldDeaths = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](size_t total, const Covid& C) {
            return total + C.m_numDeaths;
            });
        size_t worldCases = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](size_t total, const Covid& C) {
            return total + C.m_numCases;
            });
        if (country == "ALL") {
            for_each(m_collection.begin(), m_collection.end(), [&out, country](const Covid& C) {
                out << C << endl;
                });
            out << "|" << setw(80) << right << "Total cases around the world: " << worldCases << " |" << endl;
            out << "|" << setw(80) << right << "Total deaths around the world: " << worldDeaths << " |" << endl;
        }
        else {
            for_each(m_collection.begin(), m_collection.end(), [&out, country](const Covid& C) {
                if (C.m_country == country) {
                    out << C << endl;
                }
                });
            size_t countryCases = std::accumulate(m_collection.begin(), m_collection.end(), 0, [country](size_t total, const Covid& C) {
                if (C.m_country == country) {
                    return total + C.m_numCases;
                }
                else { return total; }
                });
            size_t countryDeaths = std::accumulate(m_collection.begin(), m_collection.end(), 0, [country](size_t total, const Covid& C) {
                if (C.m_country == country) {
                    return total + C.m_numDeaths;
                }
                else { return total; }
                });
            // out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
            out << "|" << setw(79 - country.length()) << right << "Total cases in " << setw(country.length()) << country << ": " << countryCases << " |" << endl;
            out << "|" << setw(79 - country.length()) << right << "Total deaths in " << setw(country.length()) << country << ": " << countryDeaths << " |" << endl;
            size_t extraSpace{};
            if (((double)countryCases / worldCases) * 100 < 10) {
                extraSpace++;
            }
            if (((double)countryDeaths / worldDeaths) * 100 < 10) {
                extraSpace++;
            }
            out << "|" << setw(22 + extraSpace) << right << country << " has " << fixed << setprecision(6) << setw(8) << ((double)countryCases / worldCases) * 100 << "% " << "of global cases and " << setw(8) << ((double)countryDeaths / worldDeaths) * 100 << "%" << " of global deaths |" << endl;
        }
    }
    void CovidCollection::sort(const std::string& field) {
        std::sort(m_collection.begin(), m_collection.end(), [field, this](const Covid& C, const Covid& C2) {
            return compareCovid(C, C2, field);
            });
    }
    bool CovidCollection::compareCovid(const Covid& C, const Covid& C2, const std::string& field) {
        if (field == "country") {
            if (C.m_country != C2.m_country) {
                return C.m_country < C2.m_country;
            }
        }
        else if (field == "city") {
            if (C.m_city != C2.m_city) {
                return C.m_city < C2.m_city;
            }
        }
        else if (field == "variant") {
            if (C.m_variant != C2.m_variant) {
                return C.m_variant < C2.m_variant;
            }
        }
        else if (field == "year") {
            return C.m_year < C2.m_year;
        }
        else if (field == "cases") {
            return C.m_numCases < C2.m_numCases;
        }
        else if (field == "deaths") {
            if (C.m_numDeaths != C2.m_numDeaths) {
                return C.m_numDeaths < C2.m_numDeaths;
            }
        }
        return C.m_numDeaths < C2.m_numDeaths;
    }
    bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
        return any_of(m_collection.begin(), m_collection.end(), [=](const Covid& C) {
            return C.m_variant == variant && C.m_country == country && C.m_numDeaths > deaths;
            });
    }
    std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
        std::list<Covid> res{};
        copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(res), [this, deaths](const Covid& C) {
            return C.m_numDeaths >= deaths;
            });
        return res;
    }
    void CovidCollection::updateStatus() {
        transform(m_collection.begin(), m_collection.end(), m_collection.begin(), [](Covid& C) {
            if (C.m_numDeaths > 300) {
                C.m_severity = "EPIDEMIC";
            }
            else if (C.m_numDeaths < 50) {
                C.m_severity = "EARLY";
            }
            else {
                C.m_severity = "MILD";
            }
            return C;
            });
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
        os << setw(4) << C.m_numCases << " | " << setw(3) << C.m_numDeaths << " | | " << right << setw(8) << C.m_severity << " |";
        return os;
    }
}