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

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void createDonorList(ifstream& infile, DonorList& donorList)
{
	string  fName, lName;
	int memberID = 0;
	double donation = 0.0;

	while (!infile.eof())
	{
		infile >> fName >> lName >> memberID >> donation;

		donorList.addDonor(fName, lName, memberID, donation);
	}
}

void readDonorData(DonorList& donorList)
{
	ifstream infile;

	infile.open("donors_data.txt");

	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1); // terminates program
	}

	createDonorList(infile, donorList);

	infile.close();
}