#include <vector>
#include <queue>
#include <iostream>
#include "UndirectedWeightedGraph.h"
using namespace std;

UndirectedWeightedGraph::UndirectedWeightedGraph(int count):numberOfVertices(count) {

	adjacencyList.resize(numberOfVertices);

}

void UndirectedWeightedGraph::addEdge(int s, int d, int w) {

	Edge edge;

	edge.source = s;
	edge.destination = d;
	edge.weight = w;

}

void UndirectedWeightedGraph::BFS(int source) {

	queue<int> q;
	vector<bool> visited(numberOfVertices, false);
	
	q.push(source);
	visited[source] = true;

	while (!q.empty()) {

		int currentVertex = q.front();
		q.pop();

		cout << currentVertex << " ";

		for (Edge edge : adjacencyList[currentVertex]) {

			if (!visited[edge.destination]) {

				q.push(edge.destination);
				visited[edge.destination] = true;

			}
		}
	}
	cout << endl;
}

void UndirectedWeightedGraph::DFSRec(int vertex, vector<bool>& visited) {

	visited[vertex] = true;

	cout << vertex << " ";

	for (Edge edge : adjacencyList[vertex]) {

		if (!visited[edge.destination]) {

			DFSRec(edge.destination, visited);

		}
	}
}

void UndirectedWeightedGraph::DFS(int source) {

	vector<bool> visited(numberOfVertices, false);

	DFSRec(source, visited);

}

int UndirectedWeightedGraph::getVertices() {

	return numberOfVertices;

}

vector<Edge> UndirectedWeightedGraph::getEdge(int vertex) {

	return adjacencyList[vertex];

}