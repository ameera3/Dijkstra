/*
 * Filename: graph.cpp
 * Description: Implements an undirected graph
 *		on which we will apply Djiksta.
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include "graph.hpp"

using namespace std;

/*
 * Constructor of the graph
 */ 
Graph::Graph(void) {}

/*
 * Load the graph from a tab-delimited file of actor->movie relationships.
 *
 * in_filename - input filename
 *
 * return true if file was loaded sucessfully, false otherwise
 */
bool Graph::loadFromFile(const char* filename) {

	// used to get each line from input file
	string line;

	// input file stream
	ifstream * in = new ifstream(filename);

	// Raise an error if file can't be read and return false
	if (in->eof()) {
		cerr << "Failed to read " << filename << "!\n";
		return false;
	}
	while (getline(*in, line)) {

		// replace the tabs and commas in the line with spaces
		replace(begin(line), end(line), '\t', ' ');
		replace(begin(line), end(line), ',', ' ');

		// used for parsing the line
		stringstream ss;

		// Storing the line into stringstream
		ss << line;

		// used for parsing the line
		string temp;

		// current tail vertex
		unsigned int currentTail;

		// current head vertex
		unsigned int currentHead;

		// current weight
		unsigned int currentWeight;

		// extracting current tail;
		ss >> temp;

		// check current tail is unsigned int
		if( stringstream(temp) >> currentTail ){

			/*  search for vertex in current list of
			 *  vertices. If it's not there, create
			 *  a new vertex and add it to the current
			 *  list of vertices
			 */  
			Vertex* currTail = vertex_map[currentTail];
			if(currTail == nullptr){
				currTail = new Vertex(currentTail);
				vertex_map[currentTail] = currTail;
			}

			while (!ss.eof()) {

				// extracting current head
				ss >> temp;

				// check current head is unsigned int
				if ( stringstream(temp) >> currentHead ){

					/* search for vertex in current list
					 * of vertices. If it's not there, 
					 * create a new vertex and add it to
					 * the current list of vertices.
					 */
					Vertex* currHead = vertex_map[currentHead];
					if(currHead == nullptr){
						currHead = new Vertex(currentHead);
						vertex_map[currentHead] = currHead;
					}

					ss >> temp;

					// check currentWeight is unsigned int
					if( stringstream(temp) >> currentWeight ){
						(currTail->edges).push_back
							(make_pair(currentWeight, currHead));
					}

				}

			}
		}

		// reset the string stream to be empty
		ss.str("");
	}

	// no memory leaks here
	delete in;
	return true;
}	

/*
 * Implements Dijkstra's algorithm to find a shortest weighted
 * path from source to all other vertices in the graph.
 *                
 * source - pointer to source actor
 *                               
 */

vector<Vertex*> Graph::Dijkstra(Vertex* source, Vertex* dest) {

	// priority queue containing pairs of vertices and their
	// tentative distance to the source
	priority_queue< pair<unsigned int, Vertex*>, 
		vector< pair<unsigned int, Vertex*> >, 
		greater< pair<unsigned int, Vertex*> > > toExplore;

	// stores all actors whose parameters were changed and
	// need to be reset to default
	vector<Vertex*> reset;

	// set the cost of the source to be zero and push the 
	// source to both reset and toExplore
	source->cost = 0;
	reset.push_back(source);
	toExplore.push(make_pair(source->cost, source));

	// while the priority queue is not empty, pop the next 
	// node to explore. If this node is the destination, stop
	// because we are done. If the node is not visited, mark it 
	// as visited and consider all of its unvisited neighbors. 
	// Calculate the tentative distance of the unvisited 
	// neightbors through the current node. If this newly 
	// assigned tentative value is less than the currently 
	// stored cost, then reset the cost and push this node 
	// to the queue.
	while ( !toExplore.empty() ) {
		pair<unsigned int, Vertex*> next = toExplore.top();
		toExplore.pop();
		if( next.second == dest ) {
			break;
		}
		if( next.second->visited == false ) {
			next.second->visited = true;
			vector< pair<unsigned int, Vertex*> >::iterator adjIt 
				= next.second->edges.begin(); 
			for ( ; adjIt != next.second->edges.end(); ++adjIt ) {
				if ( ((*adjIt).second)->visited == false ) {
					unsigned int tentative = next.second->cost + (*adjIt).first;
					if( tentative < ((*adjIt).second)->cost ){
						((*adjIt).second)->cost = tentative;
						reset.push_back((*adjIt).second);
						toExplore.push(make_pair(((*adjIt).second)->cost, 
									(*adjIt).second));
					}    
				}    
			}
		}    
	}

	return reset;
}

/*
 * For each actor in resetVec, resets all actor's parameters to their
 * default values
 *
 * resetVec -- a vector of actor pointers whose parameters were
 *             changed and need to be reset to default values
 * no return value
 */

void Graph::reset(vector<Vertex*> resetVec) {

	for( unsigned int i = 0; i < resetVec.size(); ++i ){

		resetVec[i]->cost = std::numeric_limits<int>::max();
		resetVec[i]->visited = false;
	}
}    

/*
 * Destructor: Iterate through the vertex map and delete
 *             all vertices.
 */            

Graph::~Graph() {

	for ( auto it = vertex_map.begin(); it != vertex_map.end(); ++it ){
		delete it->second;
	}

}

