#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <iostream>
#include "UndirectedWeightedGraph.h"

using namespace std;

int main() {

	UndirectedWeightedGraph graph(10);
	int source, destination, weight;
	string input;

	ifstream edges("Board.txt");
	

	while (getline(edges, input)) {

		stringstream s(input);

		s >> source >> destination >> weight;
		graph.addEdge(source, destination, weight);


	}

	cout << "The new graph: " << endl;
	
	for (int i = 0; i < graph.getVertices(); i++) {

		cout << i << ": ";
		for (Edge edge : graph.getEdge(i)) {

			cout << edge.destination << " ";

		}

		cout << endl;

	}

	cout << "Breadth-First Searcg: " << endl;
	graph.BFS(0);

	cout << "Depth-First Search: " << endl;
	graph.DFS(0);

	return 0;
}