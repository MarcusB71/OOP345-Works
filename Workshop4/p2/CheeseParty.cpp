/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "CheeseParty.h"
#include <iostream>
using namespace std;
namespace sdds {
    CheeseParty::CheeseParty(string name) :m_name(name) {    }
    CheeseParty::CheeseParty(const CheeseParty& CPCopy) {
        *this = CPCopy;
    }
    CheeseParty& CheeseParty::operator=(const CheeseParty& CPCopy) {
        if (this != &CPCopy) {
            clearCP();
            m_numCheeses = CPCopy.m_numCheeses;
            m_name = CPCopy.m_name;
            m_pCheeses = new const Cheese * [m_numCheeses];
            for (size_t i = 0; i < m_numCheeses; i++) {
                m_pCheeses[i] = CPCopy.m_pCheeses[i];
            }
        }
        return *this;
    }
    CheeseParty::CheeseParty(CheeseParty&& CPMove) noexcept {
        *this = move(CPMove);
    }
    CheeseParty& CheeseParty::operator=(CheeseParty&& CPMove) noexcept {
        if (this != &CPMove) {
            clearCP();
            m_name = CPMove.m_name;
            m_numCheeses = CPMove.m_numCheeses;
            m_pCheeses = CPMove.m_pCheeses;
            CPMove.m_name = "";
            CPMove.m_numCheeses = 0;
            CPMove.m_pCheeses = nullptr;
        }
        return *this;
    }
    sdds::CheeseParty::~CheeseParty() {
        clearCP();
    }
    CheeseParty& CheeseParty::addCheese(const Cheese& cheese) {
        bool exists = false;
        for (size_t i = 0; i < m_numCheeses; i++) {
            if (m_pCheeses[i] == &cheese) {
                exists = true;
            }
        }
        if (!exists) {
            const Cheese** temp = new const Cheese * [m_numCheeses + 1];
            for (size_t i = 0; i < m_numCheeses; i++) {
                temp[i] = m_pCheeses[i];
            }
            temp[m_numCheeses++] = &cheese;
            delete[] m_pCheeses;
            m_pCheeses = temp;
        }
        return *this;
    }
    CheeseParty& CheeseParty::removeCheese() {
        unsigned index = 0;
        for (size_t i = 0; i < m_numCheeses; i++) {
            if (!m_pCheeses[i]->getWeight()) {
                index = i;
                shrink(index);
            }
        }
        return *this;
    }
    void CheeseParty::shrink(unsigned index) {
        if (index < m_numCheeses)
        {
            const Cheese** temp = new const Cheese * [m_numCheeses - 1];
            for (size_t i = 0, j = 0; i < m_numCheeses - 1; i++, j++) {
                if (i == index) { j++; }
                temp[i] = m_pCheeses[j];
            }
            delete[] m_pCheeses;
            m_pCheeses = temp;
            m_numCheeses--;
        }
    }
    void sdds::CheeseParty::clearCP() {
        for (size_t i = 0; i < m_numCheeses; i++) {
            m_pCheeses[i] = nullptr;
        }
        delete[] m_pCheeses;
        m_pCheeses = nullptr;
        m_numCheeses = 0;
        m_name = "";
    }
    ostream& CheeseParty::print(ostream& os)const {
        os << "--------------------------" << std::endl;
        os << "Cheese Party" << std::endl;
        os << "--------------------------" << std::endl;
        if (m_numCheeses) {
            for (size_t i = 0; i < m_numCheeses; i++) {
                // m_pCheeses[i]->print(os);
                os << *m_pCheeses[i];
            }
            os << "--------------------------" << std::endl;
        }
        else {
            os << "This party is just getting started!" << std::endl;
            os << "--------------------------" << std::endl;
        }
        return os;
    }
    ostream& operator<<(ostream& os, const CheeseParty& CSParty) {
        return CSParty.print(os);
    }

}