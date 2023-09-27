/*Marcus Brown
mbrown106@myseneca.ca
127900223
27/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "AirportModels.h"
#include <fstream>
#include <iomanip>
using namespace std;
namespace sdds {
    Airport::Airport() {}

    Airport::Airport(string code, string name, string city, string state, string country, double latitude, double longitude) : m_code(code), m_name(name), m_city(city), m_state(state), m_country(country), m_latitude(latitude), m_longitude(longitude) {}

    Airport::Airport(Airport& A)
    {
        *this = A;
    }
    Airport& Airport::operator=(const Airport& A)
    {
        if (this != &A)
        {
            m_code = A.m_code;
            m_name = A.m_name;
            m_city = A.m_city;
            m_state = A.m_state;
            m_country = A.m_country;
            m_latitude = A.m_latitude;
            m_longitude = A.m_longitude;
        }
        return *this;
    }
    ostream& Airport::print(ostream& os) const
    {
        if (*this) {
            os.fill('.');
            os << setw(20) << right << "Airport Code" << " : " << left << setw(30) << m_code << endl;
            os << setw(20) << right << "Airport Name" << " : " << left << setw(30) << m_name << endl;
            os << setw(20) << right << "City" << " : " << left << setw(30) << m_city << endl;
            os << setw(20) << right << "State" << " : " << left << setw(30) << m_state << endl;
            os << setw(20) << right << "Country" << " : " << left << setw(30) << m_country << endl;
            os << setw(20) << right << "Latitude" << " : " << left << setw(30) << m_latitude << endl;
            os << setw(20) << right << "Longitude" << " : " << left << setw(30) << m_longitude << endl;
        }
        else {
            os << "Empty Airport";
        }
        return os;
    }
    std::istream& Airport::read(std::istream& is)
    {
        if (is)
        {
            getline(is, m_code, ',');
            getline(is, m_name, ',');
            getline(is, m_city, ',');
            getline(is, m_state, ',');
            getline(is, m_country, ',');
            is >> m_latitude;
            is.ignore();
            is >> m_longitude;
            is.ignore();
        }
        return is;
    }
    std::string Airport::getState() const
    {
        return m_state;
    }
    std::string Airport::getCountry() const
    {
        return m_country;
    }
    ostream& operator<<(ostream& os, const Airport& A)
    {
        return A.print(os);
    }
    istream& operator>>(istream& is, Airport& A)
    {
        return A.read(is);
    }
    AirportLog::AirportLog() {}

    AirportLog::AirportLog(const char* fileName)
    {
        ifstream file(fileName);
        string temp;
        if (file.is_open())
        {
            while (getline(file, temp))
            {
                m_countAirports++;
            }
            m_countAirports--;
            file.close();
        }
        if (m_countAirports > 0)
        {
            file.open(fileName);
            getline(file, temp, '\n');
            m_airports = new Airport[m_countAirports];
            for (size_t i = 0; i < m_countAirports; i++)
            {
                m_airports[i].read(file);
            }
            file.close();
        }
    }
    AirportLog::AirportLog(const AirportLog& A)
    {
        *this = A;
    }
    AirportLog& AirportLog::operator=(const AirportLog& A)
    {
        if (this != &A)
        {
            m_countAirports = A.m_countAirports;
            delete[] m_airports;
            m_airports = new Airport[m_countAirports];
            for (size_t i = 0; i < m_countAirports; i++)
            {
                m_airports[i] = A.m_airports[i];
            }
        }
        return *this;
    }
    AirportLog::AirportLog(AirportLog&& rh) noexcept
    {
        // *this = rh; // should be the same as below
        m_countAirports = rh.m_countAirports;
        m_airports = rh.m_airports;
        rh.m_countAirports = 0;
        rh.m_airports = nullptr;
    }
    AirportLog& AirportLog::operator=(AirportLog&& rh) noexcept
    {
        if (this != &rh)
        {
            delete[] m_airports;
            m_airports = rh.m_airports;
            m_countAirports = rh.m_countAirports;
            rh.m_airports = nullptr;
            rh.m_countAirports = 0;
        }
        return *this;
    }
    AirportLog::~AirportLog()
    {
        delete[] m_airports;
        m_airports = nullptr;
    }
    void AirportLog::addAirport(const Airport& airportToAdd)
    {

        Airport* temp = new Airport[m_countAirports + 1];
        for (size_t i = 0; i < m_countAirports; i++)
        {
            temp[i] = m_airports[i];
        }
        temp[m_countAirports] = airportToAdd;
        m_countAirports++;
        delete[] m_airports;
        m_airports = temp;

    }
    AirportLog AirportLog::findAirport(const char* stateName, const char* countryName)
    {
        AirportLog matchedAiports;
        for (size_t i = 0; i < m_countAirports; i++)
        {
            if ((m_airports[i].getState() == stateName) && (m_airports[i].getCountry() == countryName))
            {
                matchedAiports.addAirport(m_airports[i]);
            }
        }
        return matchedAiports;
    }
    Airport AirportLog::operator[](size_t index) const
    {
        Airport temp{};
        if (index < m_countAirports)
        {
            temp = m_airports[index];
        }
        return temp;
    }
    AirportLog::operator size_t() const
    {
        return m_countAirports;
    }

    Airport::operator bool() const
    {
        return m_code[0] != '\0';
    }

}
