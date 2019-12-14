//Brian Valenzi, bv457, 4776793, Lab6

#include <iostream>
#include <fstream>
#include <cstring>

const int STRING_LENGTH = 5000;
const int SUBSTRING_LENGTH = 10;
const int MODULUS = 257;

const int FILE_NAME_SIZE = 40;

using namespace std;

int pow(int base, int exp)
{
	int result = 1;
	for(int i = 0; i < exp; i++)
	{
		result = (result*base) % MODULUS;
	}
	return result;
}

int returnHash(char *input, int inputLength)
{
	int digest = 0;

	for(int i = 0; i < inputLength; i++)
	{
		digest = ((STRING_LENGTH * digest) + input[i]) % MODULUS;
	}
	return digest;	
}

int roll(int &hash, int c1, int c2, int h)
{
	hash = (STRING_LENGTH*(hash - c1*h)+c2)%MODULUS;

	while(hash < 0)
	{
		hash += MODULUS;
	}
	return hash;
}

void readFileIn(char *stringPool, char *subString)
{
	char fileName[FILE_NAME_SIZE];

	cout << "Enter file name"<<endl;
	cin >> fileName;

	fstream inStream;
	inStream.open(fileName);

	if(inStream.fail())
	{
		cerr << "Unable to open "<<fileName<<endl;
	}
	inStream >> stringPool >>subString;
}

bool compareStrings(char *subString, char *stringPool, int index, int m)
{
	for(int i = 0; i < m; i++)
	{
		if(subString[i] == stringPool[index])
		{
			index++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char stringPool[STRING_LENGTH];
	char subString[SUBSTRING_LENGTH];

	readFileIn(stringPool, subString);

	int n = strlen(stringPool);
	int m = strlen(subString);
	int h = pow(STRING_LENGTH, m-1);

	int hash_s = returnHash(subString, m);
	int hash_t = returnHash(stringPool, m);

	for(int i = 0; i < n-m; i++)
	{
		if(hash_s == hash_t)
		{
			if(compareStrings(subString, stringPool, i, m))
			{
				cout<<"String match found at: "<<i<<endl;
			}
		}
		hash_t = roll(hash_t, stringPool[i], stringPool[i+m], h);
	}
}
	

