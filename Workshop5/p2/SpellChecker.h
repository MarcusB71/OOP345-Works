#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
#define SIZE_WORDS 6
namespace sdds {
    class SpellChecker
    {
    private:
        std::string m_badWords[SIZE_WORDS]{};
        std::string m_goodWords[SIZE_WORDS]{};
        size_t m_countFixed[SIZE_WORDS]{};
    public:
        SpellChecker();
        SpellChecker(const char* filename);
        ~SpellChecker();
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif