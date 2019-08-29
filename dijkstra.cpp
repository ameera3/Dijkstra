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

	// create source and destination vertices 
	Vertex* source = (G->vertex_map)[SOURCE_IDX];
	Vertex* dest1 = (G->vertex_map)[DEST1_IDX];
	Vertex* dest2 = (G->vertex_map)[DEST2_IDX];
	Vertex* dest3 = (G->vertex_map)[DEST3_IDX];
	Vertex* dest4 = (G->vertex_map)[DEST4_IDX];
	Vertex* dest5 = (G->vertex_map)[DEST5_IDX];
	Vertex* dest6 = (G->vertex_map)[DEST6_IDX];
	Vertex* dest7 = (G->vertex_map)[DEST7_IDX];
	Vertex* dest8 = (G->vertex_map)[DEST8_IDX];
	Vertex* dest9 = (G->vertex_map)[DEST9_IDX];
	Vertex* dest10 = (G->vertex_map)[DEST10_IDX];
	
	// run Dijkstra from source to dest, reset,
	// print the distance to dest vertex
	resetVertices = G->Dijkstra(source, dest1);
	cout << *((G->vertex_map)[DEST1_IDX]) << endl;	
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest2);
	cout << *((G->vertex_map)[DEST2_IDX]) << endl;
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest3);
	cout << *((G->vertex_map)[DEST3_IDX]) << endl;
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest4);
	cout << *((G->vertex_map)[DEST4_IDX]) << endl;
	G->reset(resetVertices);
	
	resetVertices = G->Dijkstra(source, dest5);
	cout << *((G->vertex_map)[DEST5_IDX]) << endl;
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest6);
	cout << *((G->vertex_map)[DEST6_IDX]) << endl;
	G->reset(resetVertices);
	
	resetVertices = G->Dijkstra(source, dest7);
	cout << *((G->vertex_map)[DEST7_IDX]) << endl;
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest8);
	cout << *((G->vertex_map)[DEST8_IDX]) << endl;
	G->reset(resetVertices);
	
	resetVertices = G->Dijkstra(source, dest9);
	cout << *((G->vertex_map)[DEST9_IDX]) << endl;
	G->reset(resetVertices);

	resetVertices = G->Dijkstra(source, dest10);
	cout << *((G->vertex_map)[DEST10_IDX]) << endl;
	G->reset(resetVertices);

}	
