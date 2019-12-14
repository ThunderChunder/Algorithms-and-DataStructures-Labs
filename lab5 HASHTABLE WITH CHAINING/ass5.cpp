#include <iostream>
#include <fstream>

struct HashTable
{
	HashTable();
	HashTable(int value);
	int value;
	HashTable *next;	
};

HashTable::HashTable()
{
	this->value = 0;
	this->next = NULL;
}

HashTable::HashTable(int value)
{
	this->value = value;
	this->next = NULL;
}

int hashFunction(int value);
void insertNode(int key, int value);
void readFileIn();
void countLongestChain();


const int FILE_NAME_SIZE = 40;
int hashEntries = 0;
int longestHashChainLength = 0;
int emptyEntries = 0;

using namespace std;

HashTable *hashTable;

int main()
{
	hashTable = new HashTable[100]();
	readFileIn();
	countLongestChain();
	cout<<"Number of empty entries: "<<emptyEntries<<" \nlongest chain: "<<longestHashChainLength<<endl;
	delete[] hashTable;			
}

int hashFunction(int value)
{
	while(value >= 100)
	{
		value -= 100;
	}
	return value;
}

void insertNode(int key, int value)
{
	HashTable *newNode = new HashTable(value);
	if(hashTable[key].next == NULL)
	{
		hashTable[key].next = newNode;
	}
	else
	{
		HashTable *currentNode = hashTable[key].next;
		while(currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}	
		currentNode->next = new HashTable(value);
	}
}

void countLongestChain()
{
	int counter = 1;
	for(int i = 0; i < 100; i++)
	{
		HashTable *currentNode = hashTable[i].next;
		if(currentNode != NULL)
		{
			while(currentNode->next != NULL)
			{
				currentNode = currentNode->next;
				counter++;
			}
		}
		else
		{
			emptyEntries++;
		}
		if(longestHashChainLength < counter){longestHashChainLength = counter;}
		counter = 0;	
	}
}

void readFileIn()
{
	char fileName[FILE_NAME_SIZE];
	int buffer;

	cout << "Enter file name"<<endl;
	cin >> fileName;

	fstream inStream;
	inStream.open(fileName);

	if(inStream.fail())
	{
		cerr << "Unable to open "<<fileName<<endl;
	}
	inStream >> buffer;
	while(!inStream.eof())
	{
		insertNode(hashFunction(buffer), buffer);
		inStream >> buffer;
		hashEntries++;
	}
}


