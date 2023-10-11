/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include "Cheese.h"
#include <string>
namespace sdds {
    class CheeseParty
    {
    private:
        const Cheese** m_pCheeses{};
        size_t m_numCheeses{};
        std::string m_name{};
    public:
        CheeseParty(std::string name = "Cheese Party");
        CheeseParty(const CheeseParty& CPCopy);
        CheeseParty& operator=(const CheeseParty& CPCopy);
        CheeseParty(CheeseParty&& CPMove)noexcept;
        CheeseParty& operator=(CheeseParty&& CPMove)noexcept;
        ~CheeseParty();
        CheeseParty& addCheese(const Cheese& cheese);
        CheeseParty& removeCheese();
        void shrink(size_t index);
        void clearCP();
        std::ostream& print(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& os, const CheeseParty& CSParty);
}
#endif