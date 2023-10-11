/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define CRT_SECURE_NO_WARNINGS
#include "CheeseShop.h"
#include <iostream>
using namespace std;
namespace sdds {
    sdds::CheeseShop::CheeseShop() :m_name(""), m_numCheese(0), m_arrOfPtrCheese(nullptr) {}

    sdds::CheeseShop::CheeseShop(const std::string& name) : m_name(name), m_numCheese(0), m_arrOfPtrCheese(nullptr) {}

    CheeseShop::CheeseShop(const CheeseShop& CSCopy) {
        *this = CSCopy;
    }
    CheeseShop& CheeseShop::operator=(const CheeseShop& CSCopy) {
        if (this != &CSCopy) {
            clearCS();
            m_name = CSCopy.m_name;
            for (size_t i = 0; i < CSCopy.m_numCheese; i++) {
                addCheese(*CSCopy.m_arrOfPtrCheese[i]);
            }
        }
        return *this;
    }
    CheeseShop::CheeseShop(CheeseShop&& CSMove) noexcept {
        *this = move(CSMove);
    }

    CheeseShop& CheeseShop::operator=(CheeseShop&& CSMove) noexcept {
        if (this != &CSMove) {
            clearCS();
            m_arrOfPtrCheese = CSMove.m_arrOfPtrCheese;
            m_name = CSMove.m_name;
            m_numCheese = CSMove.m_numCheese;
            CSMove.m_arrOfPtrCheese = nullptr;
            CSMove.m_name = "";
            CSMove.m_numCheese = 0;
        }
        return *this;
    }

    sdds::CheeseShop::~CheeseShop() { clearCS(); }

    void CheeseShop::clearCS() {
        if (*this) {
            for (size_t i = 0; i < m_numCheese; i++) {
                delete m_arrOfPtrCheese[i];
                m_arrOfPtrCheese[i] = nullptr;
            }
        }
        delete[] m_arrOfPtrCheese;
        m_arrOfPtrCheese = nullptr;
        m_numCheese = 0;
        m_name = "";
    }

    CheeseShop::operator bool()const {
        return m_numCheese;
    }

    CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
        const Cheese** temp = new const Cheese * [m_numCheese + 1];
        for (size_t i = 0; i < m_numCheese; i++) {
            temp[i] = m_arrOfPtrCheese[i];
        }
        temp[m_numCheese] = new Cheese(cheese);
        delete[] m_arrOfPtrCheese;
        m_arrOfPtrCheese = temp;
        m_numCheese++;
        return *this;
    }
    ostream& CheeseShop::print(ostream& os)const {
        os << "--------------------------" << std::endl;
        os << m_name << std::endl;
        os << "--------------------------" << std::endl;
        if (*this) {
            for (size_t i = 0; i < m_numCheese; i++) {
                // os << m_arrOfPtrCheese[i]; 
                os << *m_arrOfPtrCheese[i];
            }
            os << "--------------------------" << std::endl;
        }
        else {
            os << "This shop is out of cheese!" << std::endl;
            os << "--------------------------" << std::endl;
        }
        return os;
    }
    ostream& operator<<(ostream& os, const CheeseShop& CS) {
        return CS.print(os);
    }
}