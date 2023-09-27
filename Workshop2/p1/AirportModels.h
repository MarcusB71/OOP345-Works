/*Marcus Brown
mbrown106@myseneca.ca
127900223
25/09/2023*/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
#include <iostream>
#include <string>
namespace sdds {
    struct Airport
    {
    private:
        std::string m_code{};
        std::string m_name{};
        std::string m_city{};
        std::string m_state{};
        std::string m_country{};
        double m_latitude{};
        double m_longitude{};
    public:
        Airport();
        Airport(std::string code, std::string name, std::string city, std::string state, std::string country, double latitude, double longitude);
        Airport(Airport& A);
        Airport& operator=(const Airport& A);
        std::ostream& print(std::ostream& os)const;
        std::istream& read(std::istream& is);
        std::string getState()const;
        std::string getCountry()const;
        operator bool() const;
    };
    std::ostream& operator<<(std::ostream& os, const Airport& A);
    std::istream& operator>>(std::istream& is, Airport& A);

    class AirportLog
    {
    private:
        Airport* m_airports{};
        size_t m_countAirports{};

    public:
        AirportLog();
        AirportLog(const char* fileName);
        AirportLog(const AirportLog& A);
        AirportLog& operator=(const AirportLog& A);
        ~AirportLog();
        void addAirport(const Airport& airportToAdd);
        AirportLog findAirport(const char* stateName, const char* countryName);
        Airport operator[](size_t index)const;
        operator size_t()const;
    };
}
#endif