/*
 * Filename: vertex.hpp
 * Description: Implements a vertex class for an undirected graph
 *	  	on which we will apply Dijkstra's algorithm. 
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <limits>
using namespace std;

/* 
 * Class name: Vertex
 * Instance Variables: label (unsigned int vertex label)
 *                     edges (a vector of pairs of edge weights and vertex pointers
                              that given vertex is adjacent to)
 *                     cost (cost to reach vertex from source)
 *                     visited (true if we have discovered all of its 
 *                              neighbors during Djikstra)        
 * Description: Implements a vertex class for an undirected graph on 
 *              which we will apply Djikstra's algorithm.
 * Public Methods: constructor
 * Private Methods: None                    
*/

class Vertex {

    public:

        // Vertex Label
        unsigned int label;

        // unordered set of all movies in which actor has acted
        vector< pair<unsigned int, Vertex*> > edges;

        // cost to reach node from source node
        unsigned int cost;

        // whether node has been visited or not
        bool visited;

	// node that comes before this one in a path from source node
	Vertex* previous;

        // Constructor that constructs a node with the given label.
        Vertex(const unsigned int& name) :
                label(name), cost(std::numeric_limits<int>::max()), 
                visited(false), previous(nullptr) {} 

};

/* Overload operator<< to print a Node's fields to an ostream. */
inline ostream & operator <<(ostream& stm, const Vertex& v) {
    stm << '[';
    stm << setw(10) << &v;                   // Vertex address
    stm << "; l:" << v.label;                // Vertex label
    stm << "; d:" << v.edges.size();         // Vertex degree
    stm << "; c:" << v.cost;                 // Vertex Cost
    stm << "; v:" << v.visited;              // Vertex Visited?
    stm << ']';
    return stm;
}

#endif // VERTEX_HPP
