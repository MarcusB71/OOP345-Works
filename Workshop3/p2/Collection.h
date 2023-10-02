/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 1/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
namespace sdds {
    template <typename T, const unsigned C>
    class Collection
    {
    private:
        T m_items[C]{};
        unsigned m_size{};
        static T m_smallestItem;
        static T m_largestItem;
    protected:
        void setSmallestItem(const T& obj) {
            if (m_smallestItem > obj)
            {
                m_smallestItem = obj;
            }
        }
        void setLargestItem(const T& obj) {
            if (m_largestItem < obj) {
                m_largestItem = obj;
            }
        }
    public:
        T& operator[](size_t index) {
            return m_items[index];
        }
        void incrSize() {
            m_size++;
        }
        Collection() = default;
        Collection(const Collection&) = delete;
        static T getSmallestItem() { return m_smallestItem; }
        static T getLargestItem() { return m_largestItem; }
        unsigned size()const { return m_size; }
        unsigned capacity()const { return C; }
        bool operator+=(const T& obj) {
            if (m_size == C)
            {
                return false;
            }
            else {
                setSmallestItem(obj);
                setLargestItem(obj);
                m_items[m_size++] = obj;
                return true;
            }
        }
        std::ostream& print(std::ostream& os)const {
            os << "[";
            for (size_t i = 0; i < m_size; i++)
            {
                os << m_items[i];
                if (i < m_size - 1)
                {
                    os << ",";
                }
                else {
                    os << "]";
                }
            }
            os << std::endl;
            return os;
        }
    };
    template<typename T, const unsigned C>
    T Collection<T, C>::m_smallestItem(9999);
    template<typename T, const unsigned C>
    T Collection<T, C>::m_largestItem(-9999);
    template<>
    Book Collection<Book, 10>::m_smallestItem("", 1, 10000);
    template<>
    Book Collection<Book, 10>::m_largestItem("", 10000, 1);
    template<>
    Book Collection<Book, 72>::m_smallestItem("", 1, 10000);
    template<>
    Book Collection<Book, 72>::m_largestItem("", 10000, 1);
    template<>
    std::ostream& Collection<Book, 10>::print(std::ostream& os)const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (size_t i = 0; i < m_size; i++)
        {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        return os;
    }
    template<>
    std::ostream& Collection<Book, 72>::print(std::ostream& os)const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (size_t i = 0; i < m_size; i++)
        {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        return os;
    }
}
#endif