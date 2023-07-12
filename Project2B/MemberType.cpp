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

#include "MemberType.h"

MemberType::MemberType()
{
	membershipNo = 0;
}

MemberType::MemberType(const string& newFirstName,
		const string& newLastName, int newMembershipNo)
{
	firstName = newFirstName;
	lastName = newLastName;
	membershipNo = newMembershipNo;
}

void MemberType::setMemberInfo(const string& newFirstName,
		const string& newLastName, int newMembershipNo)
{
	firstName = newFirstName;
	lastName = newLastName;
	membershipNo = newMembershipNo;
}

string MemberType::getFirstName() const
{
	return firstName;
}

string MemberType::getLastName() const
{
	return lastName;
}

int MemberType::getMembershipNo() const
{
	return membershipNo;
}

void MemberType::printName() const
{
	cout << lastName << ", " << firstName;
}

void MemberType::printMemberInfo() const
{
	cout << "     " << membershipNo << " - " << firstName
		<< " " << lastName << endl;
}

MemberType::~MemberType(){}