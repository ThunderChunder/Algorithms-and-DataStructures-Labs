//Lab 4, Week 6, Brian Valenzi, bv457, 4776793.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int BST_LENGTH = 10000;
const int ROOT_NODE = 1;
const int FILE_NAME_SIZE = 30;
int wordCount = 1;
int printCount = 0;
int bst[BST_LENGTH];

void readFileIn();
void insertFirst(int);
void insertNode(int, int);
void inOrderTraversal(int);

int main()
{
	readFileIn();
	inOrderTraversal(ROOT_NODE);
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
	insertFirst(buffer);

	while(!inStream.eof())
	{
		inStream >> buffer;
		//check from root down
		insertNode(buffer, 1);
		
		if(inStream.fail())
		{
			break;
		}
		wordCount++;
	}
}

void insertFirst(int root)
{
	bst[ROOT_NODE] = root;
}

void insertNode(int node, int index)
{
	if(node == bst[index])
	{
		return;
	}
	else if(node < bst[index])
	{
		index *= 2;
	}
	else
	{
		index = (index*2)+1;
	}
	if(bst[index] != 0)
	{
		insertNode(node, index);
	}
	else
	{
		bst[index] = node;
	}
}

void inOrderTraversal(int index)
{
	if(bst[index] == 0)
	{
		return;
	}
	//recursively search left nodes
	inOrderTraversal(index*2);

	cout<<setw(5)<<bst[index]<<" ";
	printCount++;

	if(printCount % 10 == 0)
	{
		cout<<endl;		
	}

	//recursively search right nodes
	inOrderTraversal((index*2)+1);
}