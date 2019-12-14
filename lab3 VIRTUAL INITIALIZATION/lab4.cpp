//Brian valenzi, bv457, lab4

#include <iostream>
#include <fstream>

const int dataLength =100;

int validCount = 0;
int data[dataLength];
int forwardArr[dataLength];
int backward[dataLength];

void storeData(int, int, bool&);
void checkProbe(int);

using namespace std;

int main()
{
	char fileName[30];
	int what;
	int where;
	int probe;
	bool flag = false;

	cout<<"Enter file name."<<endl;
	cin >> fileName;

	fstream fileIn;
	fileIn.open(fileName);
	if(fileIn.fail())
	{
		cerr<<"Error opening "<<fileName<<endl;
	}
	while(!fileIn.eof())
	{
		if(!flag)
		{
			fileIn >> what >> where;
			if(fileIn.fail())
			{
				break;
			}
			storeData(what, where, flag);
		}
		else
		{
			fileIn >> probe;
			if(fileIn.fail() || probe == -1)
			{
				break;
			}
			else
			{
				checkProbe(probe);
			}
		}
	}
} 

void storeData(int what, int where, bool &flag)
{
	if(what == -1 && where == -1)
	{
		flag = true;
		return;
	}
	validCount++;
	data[where] = what;
	forwardArr[validCount] = where;
	backward[where] = validCount;
}

void checkProbe(int probe)
{
	if(backward[probe] > 0 && backward[probe] <= validCount && forwardArr[backward[probe]] == probe)
	{
		cout<< "Position "<<probe<<" has been initialized to value "<<data[probe]<<endl;
	}
	else
	{
		cout<< "Position "<<probe<<" has not been initailized"<<endl;
	}
}
