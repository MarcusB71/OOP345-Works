// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/12/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include <iostream>
#include <sstream>
using namespace std;
namespace sdds {
    char Utilities::m_delimiter = '\0';
    Utilities::Utilities() {
    }
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string token;
        size_t delimPos = str.find(m_delimiter, next_pos);
        if (next_pos >= str.length()) {
            more = false;
            throw "Invalid position for token extraction";
        }
        else if (str[next_pos] == m_delimiter) {
            more = false;
            throw "Delim at first position";
        }
        else if (delimPos != std::string::npos) {
            token = trim(str.substr(next_pos, delimPos - next_pos));
            next_pos = str.find(m_delimiter, next_pos) + 1;
            more = true;
        }
        else {
            token = trim(str.substr(next_pos));
            more = false;
        }
        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }
        return token;
    }
    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
    std::string Utilities::trim(const std::string& str) {
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
}