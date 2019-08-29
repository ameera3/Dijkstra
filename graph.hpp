/*
 * Filename: graph.hpp
 * Description: Implements an undirected graph on which
 *	 	we will apply Djikstra's algorithm
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <unordered_map>
#include "vertex.hpp"

using namespace std;

/* 
 * Class name: Graph
 * Instance Variables: vertex_map (unordered map of vertex labels
 *                                and corresponding vertex pointers)
 * Description: Implements an undirected graph class on which we
 *		will apply Djikstra's algorithm.
 * Public Methods: constructor, destructor, loadfromFile, Djikstra.
 * Private Methods: None                    
 */

class Graph {

public:

    // Unordered map of movie names+years and corresponding movie pointers
    unordered_map<unsigned int,Vertex*> vertex_map;

    /*
     * Constructor of the graph
     */
    Graph(void);

    /*
     * Load the graph from its adjacency list representation. Each row consists 
     * of the node tuples that are adjacent to that particular vertex along 
     * with the weight of that edge. For example, the 6th row has 6 as the 
     * first entry indicating that this row corresponds to the vertex labeled 
     * 6. The next entry of this row "141,8200" indicates that there is an 
     * edge between vertex 6 and vertex 141 that has length 8200. The rest of 
     * the pairs of this row indicate the other vertices adjacent to vertex 6 
     * and the weights of the corresponding edges. 
     *
     * in_filename - input filename
     *
     * return true if file was loaded sucessfully, false otherwise
     */
    bool loadFromFile(const char* filename);

    /* Destructor */
    ~Graph();

    /*
     * Implements Dijkstra's algorithm from source to find
     * shortest weighted paths to all other vertices in the graph
     *
     * source - pointer to source actor
     *
     */ 
    vector<Vertex*> Dijkstra(Vertex* source, Vertex* dest);

    void reset(vector<Vertex*> resetVec);


};


#endif // GRAPH_HPP
