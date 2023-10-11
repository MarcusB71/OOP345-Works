#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include <string>
namespace sdds {
    class Cheese
    {
    private:
        std::string m_name;
        size_t m_weight;
        double m_pricePerGram;
        std::string m_desc;
    public:
        Cheese();
        Cheese(const std::string& str);
        Cheese& operator=(const Cheese& other);
        Cheese(const Cheese& other);
        ~Cheese();
        Cheese slice(size_t weight);
        static std::string trim(const std::string& str);
        std::ostream& print(std::ostream& os)const;

    };
    std::ostream& operator<<(std::ostream& os, const Cheese& obj);

}
#endif