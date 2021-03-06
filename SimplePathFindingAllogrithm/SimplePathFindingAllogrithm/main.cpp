//
//  main.cpp
//  SimplePathFindingAllogrithm
//
//  Created by GEORGE QUENTIN on 25/04/2017.
//  Copyright © 2017 GeoDev. All rights reserved.
//

#include <iostream>
// An implementation of Dijkstra's algorithm

#include <cassert>
#include <cstdlib>
#include <cfloat>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <vector>

using namespace std;


// Like operator[] on a map, but returns a const reference
// requires: m.count(k) == 1
template <typename K, typename V>
const V & search(const map<K, V> &m, const K &k) {
    assert(m.count(k) == 1);
    return m.find(k)->second;
}

// Graph class, parameterized by the type of label on each node.
template <typename Label>
class Graph {
public:
    // internal representation of nodes
    typedef unsigned int node_type;
    
    // cost of an edge between two nodes
    typedef double cost_type;
    
private:
    // correspondence between labels and 0, ..., size()-1
    map<Label, node_type> index;
    vector<Label> label;
    
    // adjacency lists
    vector<map<node_type, cost_type> >edges;
    
public:
    // The number of nodes in the graph
    unsigned int size() const { return int(edges.size()); }
    
    // Is this node label present in the graph?
    bool present(const Label &n) const { return index.count(n) != 0; }
    
    // Convert a label to a node number.
    // requires: present(n)
    node_type get_index(const Label &n) const { return search(index, n); }
    
    // Convert a node number to a label.
    // requires: i < size()
    const Label & get_label(unsigned int i) const { return label[i]; }
    
    // Return the cost between two nodes.
    cost_type edge_cost(node_type from, node_type to) const;
    
    // Convert a label to a node number, adding the node if new.
    node_type add_label(const Label &n);
    
    // Add an edge between two nodes, identified by labels,
    // adding the nodes if new.
    void add_edge(const Label &start, const Label &finish, cost_type cost);
    
    // If there is a path from start to finish, set path to
    // a shortest one and return true.  otherwise return false.
    // requires start < size && finish < size
    bool find_path(node_type start, node_type finish, deque<node_type> &path) const;
};

// The largest possible cost
const double infinity = DBL_MAX;

// Return the cost between two nodes.
template <typename Label>
typename Graph<Label>::cost_type Graph<Label>::edge_cost(node_type from, node_type to) const {
    const map<node_type, cost_type> &out_edges = edges[from];
    if (out_edges.count(to))
        return search(out_edges, to);
    return infinity;
}

// Convert a label to a node number, adding the node if new.
template <typename Label>
typename Graph<Label>::node_type Graph<Label>::add_label(const Label &n) {
    if (present(n))
        return index[n];
    int new_index = size();
    index[n] = new_index;
    label.push_back(n);
    edges.resize(new_index+1);
    return new_index;
}

// Add an edge between two nodes, identified by labels,
// adding the nodes if new.
template <typename Label>
void Graph<Label>::add_edge(const Label &start, const Label &finish, cost_type cost) {
    edges[add_label(start)][add_label(finish)] = cost;
}

// If there is a path from start to finish, set path to
// a shortest one and return true.  otherwise return false.
// requires start < size && finish < size
template <typename Label>
bool Graph<Label>::find_path(node_type start, node_type finish,
                             deque<node_type> &path) const {
    // nodes for which the shortest path is not yet known
    set<node_type> unvisited;
    
    // length of the shortest known path from start to each node
    vector<cost_type> best_cost;
    
    // Initially the only known shortest path is to the start (length 0)
    for (unsigned int i = 0; i < size(); i++) {
        cost_type cost;
        if (i == start)
            cost = 0;
        else {
            cost = infinity;
            unvisited.insert(i);
        }
        best_cost.push_back(cost);
    }
    
    // previous node on the shortest known path to a node
    map<node_type, node_type> previous;
    
    node_type current = start;
    cost_type current_cost = 0;
    while (current != finish) {
        assert(unvisited.count(current) == 0);
        
        // update costs of the neighbours of current
        const map<node_type, cost_type> &edge = edges[current];
        typedef map<node_type, cost_type>::const_iterator edge_iter;
        for (edge_iter p = edge.begin(); p != edge.end(); p++)
            if (best_cost[p->first] - p->second > current_cost) {
                assert(unvisited.count(p->first) == 1);
                best_cost[p->first] = current_cost + p->second;
                previous[p->first] = current;
            }
        
        // set current to the closest unvisited node
        typedef set<node_type>::iterator unv_iter;
        current_cost = infinity;
        for (unv_iter p = unvisited.begin(); p != unvisited.end(); p++)
            if (best_cost[*p] < current_cost) {
                current = *p;
                current_cost = best_cost[*p];
            }
        if (current_cost == infinity)
            return false;
        unvisited.erase(current);
    }
    
    // extract the path by going backwards from the finish
    path.clear();
    for (node_type n = finish; n != start; n = previous[n]) {
        path.push_front(n);
        assert(previous.count(n) == 1);
    }
    path.push_front(start);
    
    return true;
}

// Read a graph from the named file.
// Each line of this file should consist of 3 words describing an edge:
// the start and end nodes and a number for the cost.
void read_graph(const string &filename, Graph<string> &g) {
    ifstream in(filename.c_str());
    string start, finish;
    Graph<string>::cost_type cost;
    while (in >> start >> finish >> cost)
        g.add_edge(start, finish, cost);
}

const string graph_file = "graph.txt";
const string resourcePath =  "/Users/GeorgeQuentin/Dev/Cpp/CityUniversity/SimplePathFindingAllogrithm/SimplePathFindingAllogrithm/";

// Main program: takes two node labels as arguements and tries to find
// a shortest path between them in the graph from graph_file.
int main(int argc, const char *const argv[]) {

    Graph<string> g;
    read_graph(graph_file, g);
    
    cout << g.size() << endl;
    
    deque<Graph<string>::node_type> path;
    string start, finish;
    cout << "Start station: ";
    getline(cin, start);
    if (! g.present(start)) {
        cerr << argv[0] << ": unknown node '" << start << '\'' << endl;
        return 1;
    }
    cout << "End station: ";
    getline(cin, finish);
    if (! g.present(finish)) {
        cerr << argv[0] << ": unknown node '" << finish << '\'' << endl;
        return 1;
    }
    double distance = 0;
    if (g.find_path(g.get_index(start), g.get_index(finish), path))
        for (unsigned int i = 0; i < path.size(); i++) {
            cout << distance << ' ' << g.get_label(path[i]) << endl;
            if (i+1 < path.size())
                distance += g.edge_cost(path[i], path[i+1]);
        }
    else
        cerr << "no path found" << endl;
    
    
    /*
    const string fileName = resourcePath+graph_file;
    ifstream inFile;
    inFile.open(fileName);
    
    if (inFile.is_open()){
        
        string line;
        while(inFile)
        {
            getline(inFile, line);
            cout << line << endl;
        }
        
        inFile.close();
    }else{
        cout << "Cannot open file: " << fileName << endl;
    }
    */
    
    
    
    return 0;
}
