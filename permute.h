#ifndef MY_PERMUTE_H
#define MY_PERMUTE_H

#include <iostream>

class Permute
{
	Permute();
	~Permute();
public:
	static void permute(char string[]);
private:
	static void intPermute(char fixStr[], int fixSz, char varStr[], int varSz);
	static void print(char fixStr[], char varStr1, char varStr2);
	static void split(char fixStr[], int fixSz, char varStr[], int varSz, int splitPt, char *&firstSplit, char *&secondSplit);
};

#endif
