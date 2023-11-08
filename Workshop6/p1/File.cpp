/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "File.h"
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
    File::File(std::string fileName, std::string content) : m_contents(content) {
        m_name = fileName;
    }
    void File::update_parent_path(const std::string& parPath) {
        m_parent_path = parPath;
    }
    NodeType File::type() const {
        return NodeType::FILE;
    }
    std::string File::path() const {
        return m_parent_path + m_name;
    }
    std::string File::name() const {
        return m_name;
    }
    int File::count() const {
        return -1;
    }
    size_t File::size() const {
        return m_contents.length();
    }
}