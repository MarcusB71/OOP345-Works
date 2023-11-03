/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 03/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

namespace sdds {
    class Movie
    {
    private:
        std::string m_title{};
        size_t m_year{};
        std::string m_desc{};
    public:
        Movie();
        Movie(const std::string& strMovie);
        ~Movie();
        const std::string& title() const;
        static std::string trim(const std::string& str);
        std::ostream& print(std::ostream& os)const;
        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_desc);
            spellChecker(m_title);
        }
        friend std::ostream& operator<<(std::ostream& os, const Movie& M);
    };
}
#endif