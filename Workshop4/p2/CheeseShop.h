/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include <string>
#include "Cheese.h"

namespace sdds {
    class CheeseShop {
    private:
        std::string m_name{};
        size_t m_numCheese{};
        const Cheese** m_arrOfPtrCheese{};
    public:
        CheeseShop();
        CheeseShop(const std::string& name = "No Name");
        CheeseShop(const CheeseShop& CSCopy);
        CheeseShop& operator=(const CheeseShop& CSCopy);
        CheeseShop(CheeseShop&& CSMove)noexcept;
        CheeseShop& operator=(CheeseShop&& CSMove)noexcept;
        ~CheeseShop();
        void clearCS();
        operator bool()const;
        CheeseShop& addCheese(const Cheese& cheese);
        std::ostream& print(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& os, const CheeseShop& CS);
}
#endif