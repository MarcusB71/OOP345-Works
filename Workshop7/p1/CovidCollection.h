#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
namespace sdds {
    struct Covid
    {
        std::string m_country{};
        std::string m_city{};
        std::string m_variant{};
        int m_year{};
        size_t m_numCases{};
        size_t m_numDeaths{};
    };
    class CovidCollection
    {
    private:
        std::vector<Covid>m_collection{};
    public:
        CovidCollection() = default;
        CovidCollection(std::string fileName);
        ~CovidCollection() = default;
        void display(std::ostream& out) const;
        static std::string trim(const std::string& str);
    };
    std::ostream& operator<<(std::ostream& os, const Covid& C);

}
#endif