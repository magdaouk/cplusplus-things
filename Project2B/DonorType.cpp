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

#include "DonorType.h"

DonorType::DonorType()
{
	donationAmount = 0.0;
}

DonorType::DonorType(const string& newFirstName,
		const string& newLastName, int newMembershipNo,
		double newDonationAmount)
		: MemberType(newFirstName, newLastName, newMembershipNo)
{
	donationAmount = newDonationAmount;
}

void DonorType::setDonorInfo(const string& newFirstName,
		const string& newLastName, int newMembershipNo,
		double newDonationAmount)
{
	setMemberInfo(newFirstName, newLastName, newMembershipNo);
	donationAmount = newDonationAmount;
}

void DonorType::setAmountDonated(double newDonationAmount)
{
	donationAmount = newDonationAmount;
}

double DonorType::getAmountDonated() const
{
	return donationAmount;
}

void DonorType::printDonor() const
{
	printMemberInfo();
}

void DonorType::printDonation() const
{
	printName();
	cout << endl << "    Donation amount: $" << donationAmount;
}

DonorType::~DonorType(){}

bool DonorType::operator==(const DonorType& otherDonorType) const
{
	return (getMembershipNo() == otherDonorType.getMembershipNo());
}