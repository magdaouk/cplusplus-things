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

#ifndef DONORLIST_H
#define DONORLIST_H

#include "DonorType.h"

#include <iostream>
#include <string>
#include <list>
#include <algorithm> 

using namespace std;

class DonorList
{
public:
	// Declarations public member functions
	DonorList();
	DonorList(const DonorList& oldDonorList);
	DonorList& operator=(const DonorList& oldDonorList);
	
	void addDonor(const string& newFirstName, const string& newLastName, 
		          int newMembershipNo, double newAmountDonated) const;
	
	int getNumberOfDonors() const;
	double getTotalDonations() const;
	double getHighestDonation() const;

	bool isEmpty() const;
	bool searchID(int membershipNo) const;

	void deleteDonor(int membershipNo);
	void emptyList();

	void printAllDonors() const;
	void printDonorByName(const string& lastName) const;
	void printDonor(int membershipNo) const;
	void printDonation(int membershipNo) const;
	void printTotalDonations() const;
	void printHighestDonation() const;

	~DonorList();

private:
	// Declaration private member function
	list<DonorType> * donors;
};

#endif