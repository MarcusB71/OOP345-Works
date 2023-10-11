/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/10/11
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define CRT_SECURE_NO_WARNINGS
#include "Cheese.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
namespace sdds {
    Cheese::Cheese() :m_name("NaC"), m_weight(0), m_pricePerGram(0), m_desc("") {}

    Cheese::Cheese(const std::string& str) :m_name("NaC"), m_weight(0), m_pricePerGram(0), m_desc("") {
        stringstream s(str);
        string token;
        getline(s, token, ',');
        if (!token.empty()) { m_name = trim(token); }
        getline(s, token, ',');
        if (!token.empty()) { m_weight = stoi(trim(token)); }
        getline(s, token, ',');
        if (!token.empty()) { m_pricePerGram = stod(trim(token)); }
        while (getline(s, token, ',')) {
            if (!token.empty()) {
                m_desc += " ";
            }
            m_desc += trim(token);
        }
    }
    Cheese& Cheese::operator=(const Cheese& other) {
        if (this != &other)
        {
            m_name = other.m_name;
            m_weight = other.m_weight;
            m_pricePerGram = other.m_pricePerGram;
            m_desc = other.m_desc;
        }
        return *this;
    }
    Cheese::Cheese(const Cheese& other) {
        *this = other;
    }
    Cheese::~Cheese() {}
    Cheese Cheese::slice(size_t weight) {
        Cheese temp{};
        if (m_weight >= weight) {
            temp = *this;
            temp.m_weight = weight;
            m_weight -= weight;
            return temp;
        }
        else {
            return temp;
        }
    }
    std::string Cheese::trim(const std::string& str) {
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
    ostream& Cheese::print(ostream& os)const {
        os << "|" << left << setw(21) << m_name << "|" << setw(5) << m_weight << "|" << fixed << setprecision(2) << setw(5) << m_pricePerGram << "|" << setw(33) << right << m_desc << " |" << std::endl;
        return os;
    }
    size_t Cheese::getWeight()const {
        return m_weight;
    }
    ostream& operator<<(ostream& os, const Cheese& obj) {
        return obj.print(os);
    }
}