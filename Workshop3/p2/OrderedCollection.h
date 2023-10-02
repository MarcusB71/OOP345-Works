/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 1/10/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include "Collection.h"
namespace sdds {
    template <typename T>
    class OrderedCollection : public Collection<T, 72>
    {
    private:

    public:
        OrderedCollection() = default;
        bool operator+=(const T& obj) {
            if (this->size() < this->capacity())
            {
                size_t index = 0;
                //find index where item belongs
                while (index < this->size() && obj > this->operator[](index))
                {
                    index++;
                }
                //shift everything bigger to the right
                for (size_t i = this->size(); i > index; i--)
                {
                    this->operator[](i) = this->operator[](i - 1);
                }
                this->operator[](index) = obj;
                this->incrSize();
                this->setSmallestItem(obj);
                this->setLargestItem(obj);
                return true;

                // T temp;
                // for (size_t i = 0; i < this->size() - 1; i++) {
                //     for (size_t j = 0; j < this->size() - i - 1; j++) {
                //         if (this->operator[](j) > this->operator[](j + 1)) {
                //             temp = this->operator[](j);
                //             this->operator[](j) = this->operator[](j + 1);
                //             this->operator[](j + 1) = temp;
                //         }
                //     }
                // }
            }
            else {
                return false;
            }
        }
    };
}
#endif