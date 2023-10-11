/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include <string>
namespace sdds {
    class Cheese
    {
    private:
        std::string m_name;
        size_t m_weight;
        double m_pricePerGram;
        std::string m_desc;
    public:
        Cheese();
        Cheese(const std::string& str);
        Cheese& operator=(const Cheese& other);
        Cheese(const Cheese& other);
        ~Cheese();
        Cheese slice(size_t weight);
        static std::string trim(const std::string& str);
        std::ostream& print(std::ostream& os)const;
        size_t getWeight()const;
    };
    std::ostream& operator<<(std::ostream& os, const Cheese& obj);
}
#endif