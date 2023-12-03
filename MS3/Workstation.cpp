// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/12/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Station.h"
#include <deque>
#include <iostream>
using namespace std;
namespace sdds {
    deque<CustomerOrder>
        g_pending, g_completed, g_incomplete;

    Workstation::Workstation(const string& record) : Station(record) {
        m_pNextStation = nullptr;
    }
    void Workstation::fill(ostream& os) {
        if (m_orders.size()) {
            m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::attemptToMoveOrder() {
        bool valid{ true };
        bool moved{};
        if (!m_orders.size()) {
            valid = false;
        }
        if (valid && (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() == 0)) {
            if (m_pNextStation) {
                *m_pNextStation += std::move(m_orders.front());
            }
            else {
                if (m_orders.front().isOrderFilled())
                {
                    g_completed.push_back(std::move(m_orders.front()));
                }
                else {
                    g_incomplete.push_back(std::move(m_orders.front()));
                }
            }
            m_orders.pop_front();
            moved = true;
        }
        return moved;
    }
    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }
    Workstation* Workstation::getNextStation()const {
        return m_pNextStation;
    }
    void Workstation::display(ostream& os) const {
        if (m_pNextStation == nullptr) {
            os << getItemName() << " --> End of Line" << std::endl;
        }
        else {
            os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
        }
    }
    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}