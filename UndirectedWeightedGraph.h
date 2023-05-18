#pragma once
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
	int source;
	int destination;
	int weight;
};

class UndirectedWeightedGraph
{
private:
	int numberOfVertices;
	vector<vector<Edge>> adjacencyList;
	
public:
	UndirectedWeightedGraph(int count);
	int getVertices();
	vector<Edge> getEdge(int vertex);
	void addEdge(int s, int d ,int w);
	void BFS(int source); // Breadth First Search
	void DFSRec(int vertex, vector<bool>& visited);
	void DFS(int source); // Depth First Search
};
