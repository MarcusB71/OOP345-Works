// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/12/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds {
    size_t CustomerOrder::m_widthField{};
    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities localUtil{};
        size_t next_pos = 0;
        bool more = true;
        m_name = localUtil.extractToken(str, next_pos, more);
        m_product = localUtil.extractToken(str, next_pos, more);
        while (more) {
            std::string itemName = localUtil.extractToken(str, next_pos, more);
            auto temp = new Item * [m_cntItem + 1];
            for (size_t i = 0; i < m_cntItem; i++) {
                temp[i] = m_lstItem[i];
            }
            temp[m_cntItem++] = new Item(itemName);
            delete[] m_lstItem;
            m_lstItem = temp;
        }
        if (localUtil.getFieldWidth() > m_widthField) {
            m_widthField = localUtil.getFieldWidth();
        }
    }
    CustomerOrder::CustomerOrder(const CustomerOrder&) {
        throw "copy not allowed!";
    }
    CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
        *this = move(other);
    }
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
        if (this != &other) {
            clearList();
            m_name = other.m_name;
            m_product = other.m_product;
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;
            other.m_name.clear();
            other.m_product.clear();
            other.m_cntItem = 0;
            other.m_lstItem = nullptr;
        }
        return *this;
    }
    CustomerOrder::~CustomerOrder() {
        clearList();
    }
    bool CustomerOrder::isOrderFilled() const {
        bool filled{ true };
        for (size_t i = 0; i < m_cntItem && filled; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                filled = false;
            }
        }
        return filled;
    }
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool filled{ true };
        for (size_t i = 0; i < m_cntItem && filled; i++) {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
                filled = false;
            }
        }
        return filled;
    }
    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0; i < m_cntItem; i++) {
            Item* curItem = m_lstItem[i];
            if (station.getItemName() == curItem->m_itemName && !curItem->m_isFilled) {
                if (station.getQuantity() > 0) {
                    curItem->m_serialNumber = station.getNextSerialNumber();
                    curItem->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", " << m_product << " [" << curItem->m_itemName << "]" << endl;
                    break;
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << curItem->m_itemName << "]" << endl;
                }
            }
        }
    }
    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << setfill(' ') << left << "] " << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
            m_lstItem[i]->m_isFilled ? os << "FILLED" << std::endl : os << "TO BE FILLED" << std::endl;
        }
    }
    void sdds::CustomerOrder::clearList() {
        for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }
}