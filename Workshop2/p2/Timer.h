/*Marcus Brown
mbrown106@myseneca.ca
127900223
27/09/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
#include <chrono>
namespace sdds {
    class Timer
    {
    private:
        std::chrono::steady_clock::time_point m_startTime{};
    public:
        Timer();
        ~Timer();
        void start();
        long long stop();
    };
}
#endif


