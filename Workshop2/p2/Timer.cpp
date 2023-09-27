/*Marcus Brown
mbrown106@myseneca.ca
127900223
27/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "Timer.h"
#include <iostream>
namespace sdds {

    Timer::Timer() {};
    Timer::~Timer() {};
    void Timer::start() {
        m_startTime = std::chrono::steady_clock::now();
    };
    long long Timer::stop() {

        const auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_startTime);
        return diff.count();
    };
}
