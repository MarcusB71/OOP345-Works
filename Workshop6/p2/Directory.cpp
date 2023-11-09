/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Directory.h"
#include <iomanip>
#include <iostream>
using namespace std;
namespace sdds {
    Directory::Directory(std::string dirName) {
        m_name = dirName;
    }
    Directory::~Directory() {
        for (auto content : m_contents) {
            delete content;
        }
    }
    void Directory::update_parent_path(const std::string& dirPath) {
        m_parent_path = dirPath;
        for (auto content : m_contents)
        {
            content->update_parent_path(m_parent_path + m_name);
        }
    }
    NodeType Directory::type() const {
        return NodeType::DIR;
    }
    std::string Directory::path() const {
        return m_parent_path + m_name;
    }
    std::string Directory::name() const {
        return m_name;
    }
    int Directory::count() const {
        return m_contents.size();
    }
    size_t Directory::size() const {
        size_t size{};
        for (auto content : m_contents) {
            size += content->size();
        }
        return size;
    }
    Directory& Directory::operator+=(Resource* toAdd) {
        bool dup = false;
        for (auto content : m_contents) {
            if (toAdd->name() == content->name()) {
                dup = true;
            }
        }
        if (dup) {
            throw "File name already exists!";
        }
        else {
            toAdd->update_parent_path(m_parent_path + m_name);
            m_contents.push_back(toAdd);
        }
        return *this;
    }
    Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
        Resource* temp = nullptr;
        bool recursive = false;
        for (auto flag : flags) {
            if (flag == OpFlags::RECURSIVE) {
                recursive = true;
            }
        }
        for (size_t i = 0; i < m_contents.size() && temp == nullptr; i++)
        {
            if (m_contents[i]->name() == name) {
                temp = m_contents[i];
            }
            else if (m_contents[i]->type() == NodeType::DIR && recursive) {
                //downcast to check if content is of the derived Directory type, if not dyncast will return nullptr
                temp = dynamic_cast<Directory*>(m_contents[i])->find(name, flags);
            }
        }
        return temp;
    }
    void Directory::remove(const std::string& resToDel, const std::vector<OpFlags>& flags) {
        Resource* res = find(resToDel, flags);
        bool recursive = false;
        for (auto flag : flags) {
            if (flag == OpFlags::RECURSIVE) {
                recursive = true;
            }
        }

        if (res) {
            int index{};
            for (size_t i = 0; i < m_contents.size(); i++) {
                if (m_contents[i] == res) {
                    index = i;
                }
            }
            if (res->type() == NodeType::FILE) {
                delete res;
                res = nullptr;
                m_contents.erase(m_contents.begin() + index);
            }
            else if (res->type() == NodeType::DIR) {
                if (recursive) {
                    delete res;
                    res = nullptr;
                    m_contents.erase(m_contents.begin() + index);
                }
                else {
                    throw std::invalid_argument(m_name + " is a directory. Pass the recursive flag to delete directories.");
                }
            }
            else {
                throw  resToDel + " does not exist in " + m_parent_path;
            }
        }
        else {
            throw std::invalid_argument(resToDel + " does not exist");
        }
    }
    void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const {
        bool longMode = false;
        for (auto flag : flags) {
            if (flag == FormatFlags::LONG) {
                longMode = true;
            }
        }
        os << "Total size: " << size() << " bytes" << endl;
        for (auto content : m_contents) {
            if (content->type() == NodeType::DIR) {
                os << "D | " << left << setw(15) << content->name() << " |";
                if (longMode) {
                    os << setw(3) << right << content->count() << " | " << setw(4) << right << content->size() << " bytes |";
                }
            }
            if (content->type() == NodeType::FILE) {
                os << "F | " << left << setw(15) << content->name() << " |";
                if (longMode) {
                    os << setw(4) << right << "" << "|" << setw(5) << right << content->size() << " bytes |";
                }
            }
            os << endl;
        }

    }
}

