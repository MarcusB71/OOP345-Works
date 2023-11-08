/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/08
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Directory.h"
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
        int size{};
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
        for (auto content : m_contents) {
            if (content->type() == NodeType::FILE && content->name() == name) {
                temp = content;
            }
            if (content->type() == NodeType::DIR && recursive) {
                //downcast to check if content is of the derived Directory type, if not dyncast will return nullptr
                temp = dynamic_cast<Directory*>(content);
            }
        }
        return temp;
    }
}