/*Marcus Brown
mbrown106@myseneca.ca
127900223
16/09/2023*/
#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
	double g_taxrate = 0.0;
	double g_discount = 0.0;

	RideRequest::RideRequest() : m_price(0.0), m_discount(false) {
		m_name[0] = '\0';
		m_rideDetails = nullptr;
	}
	RideRequest::RideRequest(const RideRequest& R) {
		m_rideDetails = nullptr;
		if (this != &R)
		{
			m_rideDetails = new char[strlen(R.m_rideDetails) + 1];
			strcpy(m_rideDetails, R.m_rideDetails);
			strcpy(m_name, R.m_name);
			m_price = R.m_price;
			m_discount = R.m_discount;
		}
	}
	RideRequest& RideRequest::operator=(const RideRequest& R) {
		if (this != &R)
		{
			delete[] m_rideDetails;
			m_rideDetails = nullptr;
			strcpy(m_name, R.m_name);
			if (R.m_rideDetails)
			{
				m_rideDetails = new char[strlen(R.m_rideDetails) + 1];
				strcpy(m_rideDetails, R.m_rideDetails);
			}
			m_price = R.m_price;
			m_discount = R.m_discount;
		}
		return *this;
	}
	RideRequest::~RideRequest() {
		delete[] m_rideDetails;
	}
	void RideRequest::read(std::istream& istr)
	{
		if (istr)
		{
			char rideDetails[500];
			char discount{};
			if (m_rideDetails)
			{
				delete[] m_rideDetails;
				m_rideDetails = nullptr;
			}
			istr.getline(m_name, 11, ',');
			istr.getline(rideDetails, 500, ',');
			m_rideDetails = new char[strlen(rideDetails) + 1];
			strcpy(m_rideDetails, rideDetails);

			istr >> m_price;
			istr.ignore();
			istr >> discount;
			if (discount == 'Y')
			{
				m_discount = true;
			}
			else {
				m_discount = false;
			}
		}
	}
	void RideRequest::display()const
	{
		static int counter{};
		if (m_name[0] != '\0') {
			cout.width(2);
			cout.setf(ios::left);
			cout << " " << ++counter << ". ";
			cout.width(10);
			cout << m_name << "|";
			cout.width(25);
			cout << m_rideDetails << "|";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(12);
			double taxedPrice = m_price * (1 + g_taxrate);
			cout << taxedPrice << "|";
			if (m_discount)
			{
				double discountPrice = taxedPrice - g_discount;
				cout.width(13);
				cout.setf(ios::right);
				cout << discountPrice;
				cout.unsetf(ios::right);
			}
			cout << endl;
		}
		else {
			cout << " " << ++counter << ". " << "No Ride Request" << endl;
		}
	}
}
