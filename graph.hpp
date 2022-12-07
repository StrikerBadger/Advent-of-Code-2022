#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <functional>

// Vertex class that holds vertex values and id
template <typename T> class Vertex {
    private:
        int id;
        T value;
    
    public:
        Vertex(T value, int id = 0); // Construct a vertex with given id and value

        void setValue(T newVal);
        T getValue();
        int getId(); // Gets the ID, no setter here, becaue ID should never be changed
};

// Graph class using Vertex Class
template <typename T> class Graph {
    private:
        std::list<std::list<Vertex<T>>> adjList;
        bool bidirectional;
    
    public:
        Graph(bool bidirectional = false); // Constructs an empty Graph
        Graph(std::list<std::list<Vertex<T>>> adjList); // Constructs a Graph given an adjacency list of Vertices
        Graph(std::list<std::list<int>> adjList, bool bidirectional = false); // Constructs a Graph given an adjacency list of unique ID's

        void setBidirectional(bool bidirectional);
        bool isBidirectional();


        std::list<std::list<Vertex<T>>> getAdjList(); // Returns the adjacency list

        void insertEdge(Vertex<T> from, Vertex<T> to); // Inserts an edge
        void deleteEdge(Vertex<T> from, Vertex<T> to); // Deletes an edge
        void applyRecursiveFunction(Vertex<T> from, T aggr, std::function<T(T, T)); // Applies a recursive function to each Vertex
};
#endif