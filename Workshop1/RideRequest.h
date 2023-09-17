/*Marcus Brown
mbrown106@myseneca.ca
127900223
16/09/2023*/
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>

namespace sdds {
	extern double g_taxrate;
	extern double g_discount;

	class RideRequest
	{
	private:
		char m_name[11];
		char* m_rideDetails;
		double m_price;
		bool m_discount;
	public:
		RideRequest();
		RideRequest(const RideRequest& R);
		RideRequest& operator=(const RideRequest& R);
		~RideRequest();
		void read(std::istream& istr);
		void display()const;
	};
}
#endif // !SDDS_RIDEREQUEST
