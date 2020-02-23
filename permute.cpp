#include <iostream>
#include "permute.h"

// Methods begin
Permute::Permute()
{
}

Permute::~Permute()
{
}

/* Perform  nPn permutation on input string.
   results should be n! combinations.

  Takes an arbitrary string, including null.
*/

void Permute::permute(char string[])
{
	int len = strlen(string);
	if(len<=1)
	{
		print(string, ' ', ' ');
		return;
	}

	// Recursively generate all the permutations
	intPermute((char *) "",0,string,len);

}


/* Resursively generate all the permutations

   Takes following Prams:
   fixStr: string that is fixed and not permuted
   fixSz : size of the fixed string
   varStr: string that is variable and is permuted
   varSz : size of the variable string 
*/

void Permute::intPermute(char * fixStr, int fixSz, char varStr[], int varSz)
{
	// Terminating condition.
	if(varSz ==2)
	{
		print(fixStr, varStr[0], varStr[1]);
		print(fixStr, varStr[1], varStr[0]);
		return;
	}
	else
	{
		char * firstStr, *lastStr;
		int i=0;
		for(i=0; i< varSz; i++)
		{
			// Split the var str at index i, such that the index i chr is added to fixstr and returned
			// in firstStr. Remaining are copied in laststr minus index i char in order
			split(fixStr,fixSz, varStr,varSz, i,firstStr,lastStr);
			intPermute(firstStr,fixSz+1, lastStr,varSz-1);
			// cleanup allocated memory, ensures fixed heap space for input string size
			delete [] firstStr;
			delete [] lastStr;
		}		
	} 
}

void Permute::print(char* fixStr, char varStr1, char varStr2)
{   
	static int count=1;
	// print each permutation per line with a counter
	std::cout << fixStr << varStr1 << varStr2 <<  " " << count++ << std::endl; 
}

/* Split a given string based on a given pivot splitPt and recaclutae fixed and variable string
   Allocates memory for out params firstSplit & secondSplit

   Takes in following Prams:
   fixStr: string that is fixed and not permuted
   fixSz : size of the fixed string
   varStr: string that is variable and is permuted
   varSz : size of the variable string 
   splitPt: index in varStr where to split

   Out params:
   firstSplit: returns new fixed string
   firstSplit: returns new var string

*/
void Permute::split(char fixStr[], int fixSz, char varStr[], int varSz, int splitPt, 
	                char *&firstSplit, char *&secondSplit)
{
	// Allocate 2 strs
	firstSplit= new char[fixSz+1+1];
	firstSplit[0] = '\0';
	// recalculate fixed string
	strcpy(firstSplit,fixStr);
	strncat(firstSplit,varStr+splitPt,1);

	secondSplit = new char[varSz];
	secondSplit[0] = '\0';
	// recalculate variable string
	if((splitPt-0) >= 1)
	{
		strncat(secondSplit,varStr,splitPt-0);
	}

	if((varSz-1)- splitPt >= 1)
	{
		strncat(secondSplit,varStr+splitPt+1, varSz- splitPt -1);
	}
}



int main(int argc, char* argv[])
{
	
	//Permute::permute("ABCD");

	char string[5000];
	std::cin >> string;
	Permute::permute(string);
	return 0;
}
