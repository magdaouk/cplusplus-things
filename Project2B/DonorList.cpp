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

#include "DonorList.h"

// Definition default constructor
DonorList::DonorList()
{
	donors = new list<DonorType>;
}

// Definition copy constructor
DonorList::DonorList(const DonorList& oldDonorList)
{
	donors = new list<DonorType>;
	donors->assign(oldDonorList.donors->begin(), oldDonorList.donors->end());
}

// Definition overloaded assignment operator
DonorList& DonorList::operator=(const DonorList& oldDonorList)
{
	if (&oldDonorList != this)
	{
		donors->assign(oldDonorList.donors->begin(),
					   oldDonorList.donors->end());
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

// Definition member function addDonor 
void DonorList::addDonor(const string& newFirstName,
		const string& newLastName, int newMembershipNo,
		double newDonationAmount) const
{
	list<DonorType>::iterator iter = donors->begin();
	list<DonorType>::iterator iterEnd = donors->end();

	while (iter != iterEnd && iter->getMembershipNo() < newMembershipNo)
	{
		++iter;
	}
	if (iter == iterEnd) 
	{ 
		donors->push_back(DonorType(newFirstName, newLastName, 
					      newMembershipNo, newDonationAmount));
	}
	else
	{
		donors->insert(iter, DonorType(newFirstName, newLastName,
					   newMembershipNo, newDonationAmount));
	}
}

// Definition member function getNumberOfDonors
int DonorList::getNumberOfDonors() const
{
	return static_cast<int>(donors->size());
}

// Definition member function getTotalDonations
double DonorList::getTotalDonations() const
{
	list<DonorType>::iterator iter = donors->begin();
	list<DonorType>::iterator iterEnd = donors->end();

	double totalDonation = 0.0;
	while (iter != iterEnd)
	{
		totalDonation += iter->getAmountDonated();
		++iter;
	}
	return totalDonation;
}

// Definition member function getHighestDonation
double DonorList::getHighestDonation() const
{
	if (donors->size() == 1)
	{
		return donors->front().getAmountDonated();
	}
	else
	{
		list<DonorType>::iterator iter = donors->begin();
		list<DonorType>::iterator iterEnd = donors->end();

		double highestDonation = donors->front().getAmountDonated();
		++iter;
		while (iter != iterEnd)
		{
			if (iter->getAmountDonated() > highestDonation)
				highestDonation = iter->getAmountDonated();
			++iter;
		}
		return highestDonation;
	}
}

// Definition member function isEmpty
bool DonorList::isEmpty() const
{
	return (donors->size() == 0);
}

// Definition member function searchID
bool DonorList::searchID(int membershipNo) const
{
	return (find(donors->begin(), donors->end(), 
			     DonorType("", "", membershipNo, 0.0)) != donors->end());
}

// Definition member function deleteDonor
void DonorList::deleteDonor(int membershipNo)
{
	list<DonorType>::iterator iter = find(donors->begin(), donors->end(),
		                                  DonorType("", "", membershipNo, 0.0));
	donors->erase(iter);
}

// Definition member function emptyList
void DonorList::emptyList()
{
	donors->clear();
}

// Definition member function printAllDonors
void DonorList::printAllDonors() const
{
	list<DonorType>::iterator iter = donors->begin();
	list<DonorType>::iterator iterEnd = donors->end();

	while (iter != iterEnd)
	{
		iter->printDonor();
		++iter;
	}
}

// Definition member function printDonorByName
void DonorList::printDonorByName(const string& lastName) const
{
	list<DonorType>::iterator iter = donors->begin();
	list<DonorType>::iterator iterEnd = donors->end();

	bool found = false;
	while (iter != iterEnd)
	{
		if (iter->getLastName() == lastName)
		{
			found = true;
			iter->printDonor();
		}
		++iter;
	}
	if (!found) cout << "There are no donors with this last name.";
}

// Definition member function printDonor
void DonorList::printDonor(int membershipNo) const
{
	list<DonorType>::iterator iter = find(donors->begin(), donors->end(), 
										  DonorType("", "", membershipNo, 0.0));
	iter->printDonor();
}

// Definition member function printDonation
void DonorList::printDonation(int membershipNo) const
{
	list<DonorType>::iterator iter = find(donors->begin(), donors->end(), 
										  DonorType("", "", membershipNo, 0.0));
	cout << "    ";
	iter->printDonation();
	cout << endl;
}

// Definition member function printTotalDonations
void DonorList::printTotalDonations() const
{
	cout << "    Total donations: $" << getTotalDonations() << endl;
}

// Definition member function printHighestDonation
void DonorList::printHighestDonation() const
{
	cout << "    Highest donation: $" << getHighestDonation() << endl; 
}

// Definition destructor
DonorList::~DonorList()
{
	donors->clear();
	delete donors;
	donors = nullptr;
}