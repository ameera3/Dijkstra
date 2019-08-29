/*
 * Filename: dijkstra.cpp
 * Description: The command line program djikstra.cpp
 *	        takes in one parameter, an input file
 *		name. The input file specified by the
 *		input file name should contain the adjacency
 *		list representation of a weighted undirected
 *		graph. The program outputs the distances
 *		from a selected source vertex to selected
 *		destination vertices.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <string>
#include "graph.hpp"

using namespace std;

// argv index of input file
#define IN_IDX 1

// expected number of arguments
#define EXPECTED_ARGS 2

// source vertex index
#define SOURCE_IDX 1

// destination vertex 1 index
#define DEST1_IDX 7

// destination vertex 1 index
#define DEST2_IDX 37

// destination vertex 1 index
#define DEST3_IDX 59

// destination vertex 1 index
#define DEST4_IDX 82

// destination vertex 1 index
#define DEST5_IDX 99

// destination vertex 1 index
#define DEST6_IDX 115

// destination vertex 1 index
#define DEST7_IDX 133

// destination vertex 1 index
#define DEST8_IDX 165

// destination vertex 1 index
#define DEST9_IDX 188

// destination vertex 1 index
#define DEST10_IDX 197

using namespace std;

void printPath(Vertex* source, Vertex* dest) {

	// stores all the previous actors and movie starting from dest
	vector<Vertex*> vectorPrevious;

	// the current actor in the path
	Vertex* current = dest;

	// store all the previous actors and movies in path from
	// dest to source until you hit source
	while( current != source ){
		vectorPrevious.push_back(current->previous);
		current = current->previous;
	}

	// iterate backwards through the vector to print the path
	// from source to dest
	for( int i = vectorPrevious.size()-1; i >= 0; --i){
		cout << vectorPrevious[i]->label << " --> ";
	}
	cout << dest->label << endl;
}    


// Main Driver
int main(int argc, char** argv) 
{

	//Check for Arguments
	if (argc != EXPECTED_ARGS){
		cout << "This program requires 2 arguments!" << endl;
		return -1;
	}

	// create a new instance of graph
	Graph* G = new Graph();

	// vector returned by Djikstra of vertices whose
	// parameters need to be reset to default
	vector<Vertex*> resetVertices;

	// load graph from text file
	G->loadFromFile(argv[IN_IDX]);

	// create source vertex 
	Vertex* source = (G->vertex_map)[SOURCE_IDX];
	
	// indices of destination ints
	vector<unsigned int> destinations; 

	// fill vector
	destinations.push_back(DEST1_IDX);
	destinations.push_back(DEST2_IDX);
	destinations.push_back(DEST3_IDX);
	destinations.push_back(DEST4_IDX);
	destinations.push_back(DEST5_IDX);
	destinations.push_back(DEST6_IDX);
	destinations.push_back(DEST7_IDX);
	destinations.push_back(DEST8_IDX);
	destinations.push_back(DEST9_IDX);
	destinations.push_back(DEST10_IDX);

	// run Dijkstra from source to dest, reset,
	// print the distance to dest vertex
	for(unsigned int i = 0; i < destinations.size(); ++i){
		Vertex* dest = (G->vertex_map)[destinations[i]];
		resetVertices = G->Dijkstra(source, dest);
		cout << *dest << endl;	
		G->reset(resetVertices);
		printPath(source, dest);
	}	

}	
