#include <list>
#include <functional>

// Vertex class that holds vertex values and id
template <typename T> class Vertex {
    private:
        int id;
        T value;
    
    public:
        // Construct a vertex with given id and value
        Vertex(T value, int id = 0) {
            this->value = value;
            this->id = id;
        }

        void setValue(T newVal) {
            this->value = newVal;
        }
        T getValue() {
            return this->value;
        }
        // Gets the ID, no setter here, becaue ID should never be changed
        int getId() {
            return this->id;
        }
};

// Graph class using Vertex Class
template <typename T> class Graph {
    private:
        std::list<std::list<Vertex<T>>> adjList;
        bool bidirectional;
    
    public:
        // Constructs an empty Graph
        Graph(bool bidirectional = false) {
            this->bidirectional = bidirectional;
        }
        // Constructs a Graph given an adjacency list of Vertices
        Graph(std::list<std::list<Vertex<T>>> adjList) {

        }
        Graph(std::list<std::list<int>> adjList, bool bidirectional = false); // Constructs a Graph given an adjacency list of unique ID's

        std::list<std::list<Vertex<T>>> getAdjList(); // Returns the adjacency list
        
        void setBidirectional(bool bidirectional) {
            this->bidirectional = bidirectional;
        }
        bool isBidirectional() {
            return this->bidirectional;
        }

        void insertEdge(Vertex<T> from, Vertex<T> to); // Inserts an edge
        void deleteEdge(Vertex<T> from, Vertex<T> to); // Deletes an edge
        void applyRecursiveFunction(Vertex<T> from, T aggr, std::function<T(T, T)); // Applies a recursive function to each Vertex
};