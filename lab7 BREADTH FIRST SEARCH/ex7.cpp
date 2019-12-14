//Brian Valenzi, bv457, 4776793, lab7 Week11
#include <iostream>
#include <fstream>

const int FILE_NAME_SIZE = 20;
//const char fileName[FILE_NAME_SIZE] = "ex7.txt";
const int TOTAL_NUM_VERTICES = 25;

using namespace std;

void enqueue(int queue[], int &queueTail, int vertice)
{
	queue[queueTail] = vertice;
	queueTail++;
}

void dequeue(int queue[], int &queueHead, int &queueTail)
{
	if(queueHead > queueTail)
	{
		queue[queueHead] = -1;
	}
	else
	{
		queueHead++;
	}
}

int getQueueFront(int queue[], int queueHead)
{
	return queue[queueHead];
}

bool isQueueEmpty(int queue[], int queueHead, int queueTail)
{
	if(queue[queueHead] == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void readFile(bool adjMatrix[][TOTAL_NUM_VERTICES], int &nVertices)
{
	int v1, v2 = 0;
	char fileName[FILE_NAME_SIZE];
	cout<<"Enter File name."<<endl;
	cin >> fileName;
	fstream fileIn;

	fileIn.open(fileName);
	if(!fileIn)
	{
		cerr << "Unable to open "<<fileName<<endl;
		exit(1);
	}
	fileIn>>nVertices;

	while(!fileIn.eof())
	{
		fileIn>> v1 >> v2;
		adjMatrix[v1][v2] = true;
		adjMatrix[v2][v1] = true;

	}
	fileIn.close();
}

void BFS(bool adjMatrix[][TOTAL_NUM_VERTICES], int nVertices, int queue[], int &queueHead, int &queueTail)
{
	bool visited[nVertices]={};
	int parent[nVertices]={}; 
	//if false, havent visited
	int currentVertice = 0;
	enqueue(queue, queueTail, currentVertice);
	visited[currentVertice] = true;

	while(!isQueueEmpty(queue, queueHead, queueTail))
	{
		currentVertice = getQueueFront(queue, queueHead);
		dequeue(queue, queueHead, queueTail);
		//visited[currentVertice] = true;
		//cout<<currentVertice<<endl;
		for(int i = 0; i < nVertices; i++)
		{
			if(adjMatrix[currentVertice][i])
			{
				if(!visited[i])
				{
					enqueue(queue, queueTail, i);
					parent[i] = currentVertice;
					visited[i] = true;
					cout<<currentVertice<<" "<<i<<endl;
				}
			}
		}
	}
}

int main()
{
	int nVertices = 0;
	int queueHead = 0;
	int queueTail = 0;

	bool adjMatrix[TOTAL_NUM_VERTICES][TOTAL_NUM_VERTICES]={};

	readFile(adjMatrix, nVertices);

	int queue[100]={};

	BFS(adjMatrix, nVertices, queue, queueHead, queueTail);
}