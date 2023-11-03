#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
namespace sdds {
    SpellChecker::SpellChecker() {}
    SpellChecker::SpellChecker(const char* filename) {
        ifstream file(filename);
        if (file) {
            size_t count = 0;
            while (file && count < SIZE_WORDS) {
                string wordsLine{};
                getline(file, wordsLine);
                stringstream s(wordsLine);
                s >> m_badWords[count] >> m_goodWords[count];
                count++;
            }
        }
        else {
            throw "Bad file name!";
        }
    }
    SpellChecker::~SpellChecker() {}
    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < SIZE_WORDS; i++) {
            size_t index = 0;
            while ((index = text.find(m_badWords[i], index)) != std::string::npos) {
                text.replace(index, m_badWords[i].length(), m_goodWords[i]);
                m_countFixed[i]++;
                index += m_goodWords[i].length(); // move past the replaced word
            }
        }
    }
    void SpellChecker::showStatistics(ostream& out) const {
        out << "Spellchecker Statistics" << endl;
        for (size_t i = 0; i < SIZE_WORDS; i++) {
            out << setw(15) << right << m_badWords[i] << ": " << m_countFixed[i] << " replacements" << endl;
        }
    }
}