#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    Station::Station(const std::string& record) {
        Utilities localUtil;
        size_t next_pos = 0;
        bool more = true;
        m_id = ++id_generator;
        m_name = localUtil.extractToken(record, next_pos, more);
        m_nextSN = stoul(localUtil.extractToken(record, next_pos, more));
        m_inventory = stoul(localUtil.extractToken(record, next_pos, more));
        if (m_name.length() > m_widthField) {
            m_widthField = m_name.length();
        }
        if (localUtil.getFieldWidth() > m_widthField) {
            m_widthField = localUtil.getFieldWidth();
        }
        m_desc = localUtil.extractToken(record, next_pos, more);
    }
    const std::string& Station::getItemName() const {
        return m_name;
    }
    size_t Station::getNextSerialNumber() {
        return m_nextSN++;
    }
    size_t Station::getQuantity() const {
        return m_inventory;
    }
    void Station::updateQuantity() {
        if (m_inventory > 0) {
            m_inventory--;
        }
    }
    void Station::display(std::ostream& os, bool full) const {
        if (!full) {
            os << right << setfill('0') << setw(3) << m_id << setfill(' ') << " | " << left << setw(m_widthField) << m_name << " | " << setw(6) << right << setfill('0') << m_nextSN << setfill(' ') << " | " << endl;
        }
        else if (full) {
            os << right << setfill('0') << setw(3) << m_id << setfill(' ') << " | " << left << setw(m_widthField) << m_name << " | " << setw(6) << right << setfill('0') << m_nextSN << setfill(' ') << " | " << setw(4) << m_inventory << " | " << m_desc << endl;
        }
    }
}