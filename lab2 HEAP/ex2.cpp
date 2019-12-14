#include <iostream>
#include <fstream>
#include <cstring>

const int heapSize = 100000;
const int fileNameSize = 40;

int Heap[heapSize];
int heapEnd = 1;

void insertIntoHeap(int[], int);
void siftUp(int[], int);
void makeHeap(int [], int);
void siftDown(int [], int);
void swap(int&, int&);
void printTop();

using namespace std;

int main()
{
	char fileName[fileNameSize];
	int buffer = 0;

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

		insertIntoHeap(Heap, buffer);
		siftUp(Heap, heapEnd-1);
	}

	inStream.close();
	printTop();
	makeHeap(Heap, heapEnd-1);
	cout<<endl;
	printTop();
}
void insertIntoHeap(int heap[], int newData)
{
	if(heapEnd <= heapSize)
	{
		heap[heapEnd] = newData;
		heapEnd++;
	}
}

void siftUp(int heap[], int element)
{
	if(element == 1){ return; }

	int p = element / 2;

	if(heap[p]<heap[element]){ return; }
	else
	{
		swap(heap[element], heap[p]);
		siftUp(heap, p);
	}
}

void siftDown(int heap[], int element)
{
	int c = element*2;

	if(heap[c] < heap[c+1]){c+=1;}

	if(heap[element] < heap[c])
	{
		swap(heap[element], heap[c]);
		siftDown(heap, c);
	}
}

void makeHeap(int heap[], int element)
{
	for(int i = element/2; i >= 1; i--)
	{
		siftDown(heap, i);
	}
}

void swap(int &x, int &y)
{
	int z = y;
	y = x;
	x = z;
}

void printTop()
{
	for(int i = 1; i <= 5; i++)
	{
		cout<<Heap[i]<<endl;
	}
}
