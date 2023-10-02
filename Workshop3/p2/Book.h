/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 1/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
namespace sdds {
    class Book
    {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        bool operator<(const Book& other)const;
        bool operator>(const Book& other)const;
        operator bool()const;
        double avgPagesPerCh()const;
        std::ostream& print(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif