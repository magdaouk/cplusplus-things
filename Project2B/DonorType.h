/*
	offTheGrid
	Dang, Daniel
	Daouk, Marwa
	Le, Emily
	Messick, Matthew
	Smith, Wes

	CS A250
	November 30, 2018

	Project 2
*/

#ifndef DONORTYPE_H
#define DONORTYPE_H

#include "MemberType.h"

#include <iostream>
#include <string>

using namespace std;

class DonorType : public MemberType
{
public:
	DonorType();
	DonorType(const string& newFirstName, const string& newLastName, 
		      int newMembershipNo, double newDonationAmount);

	void setDonorInfo(const string& newFirstName, const string& newLastName, 
		              int newMembershipNo, double newDonationAmount);
	void setAmountDonated(double newDonationAmount);

	double getAmountDonated() const;

	void printDonor() const;
	void printDonation() const;

	~DonorType();

	bool operator==(const DonorType& otherDonorType) const;

private:
	double donationAmount;
};

#endif