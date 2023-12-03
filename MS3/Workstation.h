// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/12/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include "Station.h"
#include "CustomerOrder.h"
#include <iostream>
#include <deque>
#include <string>
namespace sdds {
    extern std::deque<CustomerOrder>
        g_pending, g_completed, g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation;
    public:
        Workstation() = default;
        Workstation(const std::string& record);

        Workstation(const Workstation&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(Workstation&&) = delete;

        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation()const;
        void display(std::ostream& os)const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}
#endif