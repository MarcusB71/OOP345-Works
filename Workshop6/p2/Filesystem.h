/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H
#include "Directory.h"
#include <iostream>
#include <string>
namespace sdds {

    class Filesystem
    {
    private:
        Directory* m_root{};
        Directory* m_current{};
    public:
        Filesystem();
        Filesystem(std::string fileName, std::string root = "");
        void addRes(std::string path, std::string content = "");
        ~Filesystem();
        Filesystem(const Filesystem&) = delete;
        Filesystem& operator=(const Filesystem&) = delete;
        Filesystem(Filesystem&&) noexcept;
        Filesystem& operator=(Filesystem&&) noexcept;
        Filesystem& operator+=(Resource*);
        Directory* change_directory(const std::string & = "");
        Directory* get_current_directory() const;
        static std::string trim(const std::string& str);
    };
}
#endif