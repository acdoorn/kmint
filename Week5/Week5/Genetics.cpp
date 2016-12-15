#include "stdafx.h"
#include "Genetics.h"
#include <iostream>
#include <bitset>


Genetics::Genetics()
{
	std::string s;
	for (int i = 0; i < 1000; i++) {
		s = std::bitset<8>(rand() % 128 + 1).to_string();
		binaries[i] = std::stoi(s);
	}
}

int* Genetics::getFittest() {
	long minimum_number = 100;
	int survivors[1000] = { 0 };
	int counter = 0;
	for each (int i in binaries)
	{
		if (std::bitset<8>(i).to_ulong() >= minimum_number) {
			survivors[counter] = i;
			counter++;
		}
	}
	return survivors;
}

void Genetics::reproduce(int* survivors) {
	int newPopulation[1000] = { 0 };
	for (int i = 0; i < 1000; i++) {
		std::string s = combine(survivors[i], survivors[i + 1], rand() % 5 + 1);
	}
}

void Genetics::printGeneration() {
	for each (int i in binaries)
	{
		std::cout << i << ",";
	}
	std::cout << "\n";
}

char* Genetics::combine(int binary1, int binary2, int splitpoint) {
	std::string firstbinary = std::to_string(binary1);
	std::string firstsplit = "";
	std::string secondbinary = std::to_string(binary2);
	std::string secondsplit = "";
	for (int i = 0; i<splitpoint; i++)
	{
		firstsplit.push_back(firstbinary[i]);
	}
	for (int i = splitpoint+1; i<secondbinary.length(); i++)
	{
		secondsplit.push_back(secondbinary[i]);
	}
	return static_cast<char*>(firstsplit& + secondsplit&);
}


Genetics::~Genetics()
{
	delete binaries;
}
