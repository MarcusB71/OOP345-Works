/*
Name: Marcus Brown
Email: mbrown106@myseneca.ca
StNo: 127900223
Date: 2023/11/16
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
namespace sdds {
    struct Covid
    {
        std::string m_country{};
        std::string m_city{};
        std::string m_variant{};
        int m_year{};
        size_t m_numCases{};
        size_t m_numDeaths{};
        std::string m_severity{ "General" };
    };
    class CovidCollection
    {
    private:
        std::vector<Covid>m_collection{};
    public:
        CovidCollection() = default;
        CovidCollection(std::string fileName);
        ~CovidCollection() = default;
        void display(std::ostream& out, const std::string& country = "ALL") const;
        void sort(const std::string& field = "country");
        bool compareCovid(const Covid& C, const Covid& C2, const std::string& field);
        bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
        std::list<Covid> getListForDeaths(unsigned int deaths) const;
        void updateStatus();
        static std::string trim(const std::string& str);
    };
    std::ostream& operator<<(std::ostream& os, const Covid& C);

}
#endif