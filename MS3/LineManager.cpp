// Name: Marcus Brown
// Seneca Student ID: 127900223
// Seneca email: mbrown106@myseneca.ca
// Date of completion: 2023/12/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "LineManager.h"
#include "CustomerOrder.h"
#include "Workstation.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        Utilities util;
        string curStation{};
        string nextStation{};
        ifstream f(file);
        if (!f) {
            throw "Unable to open: " + file;
        }
        while (!f.eof()) {
            string line{};
            size_t pos{};
            bool more = true;
            getline(f, line);
            curStation = util.extractToken(line, pos, more);
            auto curIterator = find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getItemName() == curStation;
                });
            if (curIterator == stations.end()) {
                throw "Invalid WS name";
            }
            Workstation* curWS = *curIterator;
            if (more) {
                nextStation = util.extractToken(line, pos, more);
                auto nextIterator = find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                    return ws->getItemName() == nextStation;
                    });
                if (nextIterator != stations.end())
                {
                    curWS->setNextStation(*nextIterator);
                }
            }
            if (none_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
                return ws->getItemName() == curStation;
                })) {
                m_activeLine.push_back(curWS);
            }
            else {
                throw "station is not unique";
            }
        }
        f.close();
        m_cntCustomerOrder = g_pending.size();
        auto firstIterator = find_if(stations.begin(), stations.end(), [&](Workstation* curWS) {
            return none_of(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getNextStation() == curWS;
                });
            });
        if (firstIterator == stations.end()) {
            throw "first station not found";
        }
        m_firstStation = *firstIterator;
    }
    void LineManager::reorderStations() {
        vector<Workstation*> orderedStations;
        Workstation* curStation = m_firstStation;
        while (curStation != nullptr) {
            orderedStations.push_back(curStation);
            curStation = curStation->getNextStation();
        }
        m_activeLine = orderedStations;
    }
    bool LineManager::run(std::ostream& os) {
        static size_t curIteration{};
        bool res{};
        curIteration++;
        os << "Line Manager Iteration: " << curIteration << std::endl;
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }
        for (auto& station : m_activeLine) {
            station->fill(os);
        }
        for (auto& station : m_activeLine) {
            station->attemptToMoveOrder();
        }
        if (g_completed.size() + g_incomplete.size() == m_cntCustomerOrder) {
            res = true;
        }
        return res;
    }
    void LineManager::display(std::ostream& os) const {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->display(os);
            });
    }
}