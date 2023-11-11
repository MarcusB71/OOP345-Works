#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <iostream>
namespace sdds {
    class Utilities {
    private:
        size_t m_widthField{ 1 };
        static char m_delimiter;
    public:
        Utilities();
        ~Utilities() = default;
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
        static std::string trim(const std::string& str);
    };
}
#endif