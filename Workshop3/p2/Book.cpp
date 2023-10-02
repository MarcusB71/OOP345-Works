/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 1/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Book.h"
#include <iomanip>
using namespace std;
namespace sdds {
    Book::Book() {}

    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

    Book::operator bool() const
    {
        return(m_title.length() > 0 && m_numChapters > 0 && m_numPages > 0);
    }
    double Book::avgPagesPerCh() const
    {
        return (static_cast<double>(m_numPages) / static_cast<double>(m_numChapters));
    }
    bool Book::operator<(const Book& other) const
    {
        return avgPagesPerCh() < other.avgPagesPerCh();
    }
    bool Book::operator>(const Book& other) const
    {
        return avgPagesPerCh() > other.avgPagesPerCh();
    }
    ostream& Book::print(ostream& os) const
    {
        if (*this)
        {
            os << right << (m_numChapters > 9 ? setw(49) : setw(50)) << m_title << "," << m_numChapters << "," << m_numPages << " | (" << left << fixed << setprecision(6) << avgPagesPerCh() << ")    " << setprecision(1);
        }
        else {
            os << "| Invalid book data";
        }
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Book& bk)
    {
        return bk.print(os);
    }
}