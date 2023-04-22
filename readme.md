### In this article, we will take a look at Adjacency list and matrix in C++

<br>

In this example, I'll show you how to implement these two graph data structures in C++.


### Table of contents:


- [Introduction](#introduction)
- [Adjacency List](#adjacency-list)
- [Adjacency Matrix](#adjacency-matrix)
- [Conclusion](#conclusion)
  
<br>

# Introduction

**Graphs** are one of the most important data structures in computer science, and they can be implemented in many different ways. Two popular ways of representing graphs are the adjacency list and the adjacency matrix.

<br>

# Adjacency List

<br>

An adjacency list is a collection of linked lists or vectors that represent the connections between vertices in a graph. Each linked list or vector corresponds to a vertex in the graph, and contains a list of the other vertices that are connected to it.

Here's an example of how to implement an adjacency list in C++:

```c++
#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void print() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();

    return 0;
}

/**
Output- 
0: 1 4     
1: 0 2 3 4 
2: 1 3     
3: 1 2 4
4: 0 1 3
**/
```

In this implementation, we define a Graph class that contains a private variable adjList which is a vector of vectors that represents the adjacency list. The Graph class also contains a constructor that takes in the number of vertices in the graph, and a function addEdge that adds an edge between two vertices. Finally, we have a function print that prints out the adjacency list for the graph.

<br>

# Adjacency Matrix

<br>

An adjacency matrix is a two-dimensional matrix that represents the connections between vertices in a graph. Each row and column in the matrix corresponds to a vertex in the graph, and the value in the matrix represents the weight or distance between the two vertices.

Here's an example of how to implement an adjacency matrix in C++:

```c++
#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;

        // Initialize adjacency matrix to all zeros
        for (int i = 0; i < numVertices; i++) {
            vector<int> row(numVertices, 0);
            adjMatrix.push_back(row);
        }
    }

    void addEdge(int src, int dest) {
        // Set matrix entry to 1 to represent edge
        adjMatrix[src][dest] = 1;
    }

    void print() {
        // Print out adjacency matrix
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();

    return 0;
}

/**
Output- 
0 1 1 0 0 
0 0 0 1 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
**/

```

In this implementation, we define a Graph class that contains a private variable adjMatrix which is a two-dimensional vector that represents the adjacency matrix. The Graph class also contains a constructor that takes in the number of vertices in the graph, and a function addEdge that adds an edge between two vertices with unit weight (by setting the corresponding entry in the adjacency matrix to 1). Finally, we have a function print that prints out the adjacency matrix for the graph.

<br>

# Conclusion

Both the adjacency list and adjacency matrix representations have their advantages and disadvantages depending on the specific use case. The adjacency list is generally more space-efficient and faster for sparse graphs (i.e., graphs with fewer edges), while the adjacency matrix is generally more space-efficient and faster for dense graphs (i.e., graphs with many edges).



