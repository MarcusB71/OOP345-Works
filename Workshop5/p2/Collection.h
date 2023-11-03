/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 03/11/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {
    template <typename T>
    class Collection {
    private:
        std::string m_name{};
        T* m_items{};
        size_t m_size{};
        void (*m_observer)(const Collection<T>&, const T&) {};

    public:
        Collection() = default;
        ~Collection() {
            delete[] m_items;
        };
        Collection(const std::string& name) : m_name(name) {}
        Collection(const Collection& other) = delete;
        Collection(Collection&& other) = delete;
        Collection& operator=(const Collection& other) = delete;
        Collection& operator=(Collection&& other) = delete;
        const std::string& name() const {
            return m_name;
        }
        size_t size() const {
            return m_size;
        }
        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }
        Collection<T>& operator+=(const T& item) {
            bool dup = false;
            for (size_t i = 0; i < m_size && !dup; i++) {
                //assume T has member function title()
                dup = (m_items[i].title() == item.title());
            }
            if (!dup) {
                T* temp = new T[m_size + 1];
                for (size_t i = 0; i < m_size; i++) {
                    temp[i] = m_items[i];
                }
                temp[m_size] = item;
                delete[] m_items;
                m_items = temp;
                m_size++;
                if (m_observer != nullptr) {
                    m_observer(*this, item);
                }
            }
            return *this;
        }
        T& operator[](size_t idx) const {
            if (idx >= m_size) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
            }
            else {
                return m_items[idx];
            }
        }
        T* operator[](const std::string& title) const {
            for (size_t i = 0; i < m_size; i++) {
                if (m_items[i].title() == title) {
                    return &m_items[i];
                }
            }
            return nullptr;
        }
        std::ostream& print(std::ostream& os)const {
            for (size_t i = 0; i < m_size; i++)
            {
                os << m_items[i];
            }
            return os;
        }
        friend std::ostream& operator<<(std::ostream& os, Collection& col) {
            return col.print(os);
        }
    };
}
#endif