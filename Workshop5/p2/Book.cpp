/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 03/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Book.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
    // Book::Book() {};

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
    ostream& Book::print(ostream& os)const
    {
        return os << setw(20) << m_author << " | " << setw(22) << m_title << " | " << setw(5) << m_COFP << " | " << setw(4) << m_year << " | " << setw(6) << fixed << setprecision(2) << m_price << " |" << m_desc << std::endl;
    }
    ostream& operator<<(ostream& os, const Book& b)
    {
        return b.print(os);
    }
}