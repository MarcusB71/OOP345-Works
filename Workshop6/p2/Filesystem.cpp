/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Filesystem.h"
#include "File.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
namespace sdds {
    Filesystem::Filesystem(std::string fileName, std::string root) {
        m_root = new Directory(root);
        m_current = m_root;
        ifstream file(fileName);
        if (file) {
            std::string line{};
            while (getline(file, line)) {
                //npos is a not found result of find function 
                bool found = (line.find('|') != std::string::npos);
                if (found) {
                    string filePath = trim(line.substr(0, line.find('|')));
                    string fileContent = trim(line.substr(line.find('|') + 1));
                    addRes(filePath, fileContent);
                }
                else {
                    line = trim(line);
                    addRes(line);
                }
            }
        }
        else {
            delete m_root;
            throw "Failed to open file!";
        }
    }
    void Filesystem::addRes(std::string filePath, std::string fileContent) {
        Directory* curDir = m_root;
        bool finished = false;

        while (!finished) {
            finished = filePath.find("/") == std::string::npos;
            if (!finished) {
                size_t pos = filePath.find('/');
                std::string dirName = filePath.substr(0, pos + 1);
                filePath = (pos != std::string::npos) ? filePath.substr(pos + 1) : "";

                Directory* newDir = dynamic_cast<Directory*>(curDir->find(dirName));
                if (!newDir) {
                    newDir = new Directory(dirName);
                    *curDir += newDir;
                }
                curDir = newDir;
            }
            else if (fileContent.length() && !curDir->find(filePath)) {
                if (!curDir->find(filePath)) {
                    *curDir += new File(filePath, fileContent);
                }
            }
        }
    }
    Filesystem::~Filesystem() {
        delete m_current;
        m_current = nullptr;
    }
    Filesystem::Filesystem(Filesystem&& other) noexcept {
        *this = std::move(other);
    }
    Filesystem& Filesystem::operator=(Filesystem&& other) noexcept {
        if (this != &other) {
            delete m_current;
            m_current = other.m_current;
            other.m_current = nullptr;
            delete m_root;
            m_root = other.m_root;
            other.m_root = nullptr;
        }
        return *this;
    }
    Filesystem& Filesystem::operator+=(Resource* resource) {
        *m_current += resource;
        return *this;
    }
    Directory* Filesystem::change_directory(const std::string& newDir) {
        if (newDir.length()) {
            Resource* target = m_root->find(newDir, vector<OpFlags>{OpFlags::RECURSIVE});
            if (target && target->type() == NodeType::DIR) {
                m_current = dynamic_cast<Directory*>(target);
            }
            else {
                throw std::invalid_argument("Cannot change directory! " + newDir + " not found!");
            }
        }
        else {
            m_current = m_root;
        }
        return m_current;
    }
    Directory* Filesystem::get_current_directory() const {
        return m_current;
    }
    std::string Filesystem::trim(const std::string& str) {
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