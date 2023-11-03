/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 03/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
    class Book {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_COFP{}; // country of publciation
        size_t m_year{};
        double m_price{};
        std::string m_desc{};
    public:
        Book() = default;
        Book(const std::string& strBook);
        ~Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        static std::string trim(const std::string& str);
        std::ostream& print(std::ostream& os)const;
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_desc);
        }
        friend std::ostream& operator<<(std::ostream& os, const Book& b);
    };
}
#endif
