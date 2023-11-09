/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H
#include "Resource.h"
#include <iostream>
#include <string>
#include <vector>
namespace sdds {

    class Directory : public Resource {
    private:
        std::vector <Resource*> m_contents{};

    public:
        Directory() = default;
        Directory(std::string dirName);
        ~Directory();
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory& operator+=(Resource*);
        Resource* find(const std::string&, const std::vector<OpFlags> & = {});
        void remove(const std::string&, const std::vector<OpFlags> & = {});
        void display(std::ostream&, const std::vector<FormatFlags> & = {}) const;
    };
}


#endif