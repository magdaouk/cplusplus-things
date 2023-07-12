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

#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <iostream>
#include <string>

using namespace std;

class MemberType
{
public:
	MemberType();
	MemberType(const string& newFirstName, const string& newLastName, 
		       int newMembershipNo);
	
	void setMemberInfo(const string& newFirstName, const string& newLastName, 
		               int newMembershipNo);
	
	string getFirstName() const;
	string getLastName() const;
	int getMembershipNo() const;

	void printName() const;
	void printMemberInfo() const;

	~MemberType();

private:
	string firstName;
	string lastName;
	int membershipNo;
};

#endif