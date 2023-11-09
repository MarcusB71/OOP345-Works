/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <iostream>
#include <string>
#include "Resource.h"
#include "Flags.h"
namespace sdds {
    class File : public Resource
    {
    private:
        std::string m_contents{};
    public:
        File() = default;
        File(std::string fileName, std::string content = "");
        ~File() = default;
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };


}

#endif