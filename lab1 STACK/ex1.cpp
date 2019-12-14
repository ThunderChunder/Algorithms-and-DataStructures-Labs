// Brian Valenzi, bv457, lab1


#include <iostream>
#include <fstream>
#include <cstring>

const int stackSize = 20;
const int wordSize = 20;
const int fileNameSize = 40;

char stack[stackSize][wordSize];
int stackIndex = 0;

void push(char [][wordSize], char *, int&);
char* top(char stack[][wordSize], int&);
void pop(int&);
bool isEmpty(int&);

using namespace std;

int main()
{
	char fileName[fileNameSize];
	char buffer[wordSize];

	cout << "Enter file name"<<endl;
	cin >> fileName;

	fstream inStream;
	inStream.open(fileName);

	if(inStream.fail())
	{
		cerr << "Unable to open "<<fileName<<endl;
	}

	while(!inStream.eof())
	{
		inStream >> buffer;
		if(inStream.fail())
		{
			break;
		}
		push(stack, buffer, stackIndex);
	}

	inStream.close();
	while (!isEmpty(stackIndex))
	{
		cout<<top(stack, stackIndex)<<endl;
		pop(stackIndex);
	}
}

void push(char stack[][wordSize], char *buffer, int &pos)
{
	//length +1 because i pass as pointer not array, '\0' not included in pointer length.
	strncpy(stack[pos], buffer, strlen(buffer)+1);
	stackIndex++;
}

char* top(char stack[][wordSize], int &pos)
{
	return stack[pos];
}

void pop(int &pos)
{
	if(isEmpty(pos))
	{
		return;
	}
	else
	{
		pos--;
	}
}

bool isEmpty(int &pos)
{
	return(pos < 0);
}
