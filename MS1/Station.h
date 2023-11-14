// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/11/11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include "Utilities.h"
#include <string>
namespace sdds {
    class Station {
    private:
        size_t m_id{};
        std::string m_name{};
        std::string m_desc{};
        size_t m_nextSN{}; //next serial number to be assigned
        size_t m_inventory{};
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station() = default;
        Station(const std::string& record); //a one line record string ref
        ~Station() = default;
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

    };
}
#endif