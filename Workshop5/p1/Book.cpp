#include "Book.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
    Book::Book() {};

    Book::Book(const std::string& strBook) {
        stringstream s(strBook);
        string token;
        getline(s, token, ',');
        if (!token.empty()) { m_author = trim(token); }
        getline(s, token, ',');
        if (!token.empty()) { m_title = trim(token); }
        getline(s, token, ',');
        if (!token.empty()) { m_COFP = trim(token); }
        getline(s, token, ',');
        if (!token.empty()) { m_price = stod(trim(token)); }
        getline(s, token, ',');
        if (!token.empty()) { m_year = stoi(trim(token)); }
        while (getline(s, token, ',')) {
            if (!token.empty()) {
                m_desc += " ";
            }
            m_desc += trim(token);
        }
    }
    Book::~Book() {}
    Book::Book(const Book& other) {
        *this = other;
    }
    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            m_author = other.m_author;
            m_title = other.m_title;
            m_COFP = other.m_COFP;
            m_year = other.m_year;
            m_price = other.m_price;
            m_desc = other.m_desc;
        }
        return *this;
    }
    const std::string& Book::title() const
    {
        return m_title;
    }
    const std::string& Book::country() const
    {
        return m_COFP;
    }
    const size_t& Book::year() const
    {
        return m_year;
    }
    double& Book::price()
    {
        return m_price;
    }
    std::string Book::trim(const std::string& str) {
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
    std::ostream& Book::print(std::ostream& os)const
    {
        return os << setw(20) << m_author << " | " << setw(22) << m_title << " | " << setw(5) << m_COFP << " | " << setw(4) << m_year << " | " << setw(6) << fixed << setprecision(2) << m_price << " | " << m_desc << std::endl;
    }
    std::ostream& operator<<(std::ostream& os, const Book& b)
    {
        return b.print(os);
    }
}