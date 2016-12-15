#pragma once
class Genetics
{
public:
	Genetics(); 
	~Genetics();
	void reproduce(int* survivors);
	int* getFittest();
	void printGeneration();
	std::string combine(int binary1, int binary2, int splitpoint);
private:
	int binaries[1000];
};

