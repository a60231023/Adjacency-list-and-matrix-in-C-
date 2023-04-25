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

    void deleteEdge(int src, int dest) {
        // Find the index of the destination vertex in the source vertex's adjacency list
        int destIndex = -1;
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                destIndex = i;
                break;
            }
        }
        // Remove the destination vertex from the source vertex's adjacency list
        if (destIndex != -1) {
            adjList[src].erase(adjList[src].begin() + destIndex);
        }

        // Find the index of the source vertex in the destination vertex's adjacency list
        int srcIndex = -1;
        for (int i = 0; i < adjList[dest].size(); i++) {
            if (adjList[dest][i] == src) {
                srcIndex = i;
                break;
            }
        }
        // Remove the source vertex from the destination vertex's adjacency list
        if (srcIndex != -1) {
            adjList[dest].erase(adjList[dest].begin() + srcIndex);
        }
    }

    bool isConnected(int src, int dest) {
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                return true;
            }
        }
        return false;
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
    // Output:
    // 0: 1 4 
    // 1: 0 2 3 4 
    // 2: 1 3 
    // 3: 1 2 4 
    // 4: 0 1 3 

    g.deleteEdge(1, 4);

    g.print();
    // Output:
    // 0: 1 4 
    // 1: 0 2 3 
    // 2: 1 3 
    // 3: 1 2 4 
    // 4: 0 3 

    cout << g.isConnected(0, 1) << endl; // Output: true
    cout << g.isConnected(0, 2) << endl; // Output: false
 
    return 0;

}
```

In this implementation, we define a Graph class that contains a private variable adjList which is a vector of vectors that represents the adjacency list. The Graph class also contains a constructor that takes in the number of vertices in the graph, and a function addEdge that adds an edge between two vertices. Finally, we have a function print that prints out the adjacency list for the graph.

Here is the step by step breakdown :-

<br>

> - First, we include the necessary header files and define the Graph class:

<br>

 ``` c++
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(numVertices);
    }
```

<br>

> - In the Graph constructor, it initializes the number of vertices and resizes the adjacency list vector accordingly.

<br>

 ``` c++
public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(numVertices);
    }
```

<br>

> - The class also has a public function called "addEdge" that takes in two integers, "src" and "dest", representing the source and destination vertices of an edge, respectively. The function adds the destination vertex to the adjacency list of the source vertex, and vice versa. Here we are doing both ways because we are assuming its an undirected graph( we have a edge from a to b, and also from b to a).

<br>

 ``` c++
 void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
```

<br>

> - The deleteEdge method takes in the source and destination vertices of the edge to be deleted. It first finds the index of the destination vertex in the source vertex's adjacency list, and removes it if found. Then it finds the index of the source vertex in the destination vertex's adjacency list, and removes it if found.

<br>

 ``` c++
void deleteEdge(int src, int dest) {
        // Find the index of the destination vertex in the source vertex's adjacency list
        int destIndex = -1;
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                destIndex = i;
                break;
            }
        }
        // Remove the destination vertex from the source vertex's adjacency list
        if (destIndex != -1) {
            adjList[src].erase(adjList[src].begin() + destIndex);
        }

        // Find the index of the source vertex in the destination vertex's adjacency list
        int srcIndex = -1;
        for (int i = 0; i < adjList[dest].size(); i++) {
            if (adjList[dest][i] == src) {
                srcIndex = i;
                break;
            }
        }
        // Remove the source vertex from the destination vertex's adjacency list
        if (srcIndex != -1) {
            adjList[dest].erase(adjList[dest].begin() + srcIndex);
        }
    }
```

<br>

> - The isConnected function takes two arguments, the source vertex and the destination vertex, and returns true if they are directly connected and false otherwise.

<br>

 ``` c++
bool isConnected(int src, int dest) {
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                return true;
            }
        }
        return false;
    }
```

<br>

 > - The output shows the initial graph after adding edges, then the graph after deleting an edge. Finally, it tests the isConnected function by checking if vertices 0 and 1 are connected (which they are) and if vertices 0 and 2 are connected (which they are not).

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

    // Add edge between two vertices with unit weight
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
    }

    // Delete edge between two vertices
    void deleteEdge(int src, int dest) {
        adjMatrix[src][dest] = 0;
    }

    // Check if two vertices are directly connected
    bool areConnected(int src, int dest) {
        return (adjMatrix[src][dest] == 1);
    }

    // Print out adjacency matrix
    void print() {
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

    g.print();  // 0 1 1 0 0 
                // 0 0 0 1 0 
                // 0 0 0 1 0 
                // 0 0 0 0 1 
                // 0 0 0 0 0

    g.deleteEdge(2, 3);

    g.print();  // 0 1 1 0 0 
                // 0 0 0 1 0 
                // 0 0 0 0 0 
                // 0 0 0 0 1 
                // 0 0 0 0 0

    cout << g.areConnected(0, 2) << endl;  // true
    cout << g.areConnected(0, 3) << endl;  // false

    return 0;
}

```

In this implementation, we use a 2D vector to represent the adjacency matrix. We initialize the matrix to all zeros in the constructor and use the addEdge function to add edges by setting the corresponding entry in the matrix to 1. We use the deleteEdge function to delete edges by setting the corresponding entry in the matrix back to 0. We use the areConnected function to check if two vertices are directly connected by checking the corresponding entry in the matrix. Finally, we use the print function to display the matrix for debugging purposes.

Here is the step by step breakdown :-

<br>

> - First, we include the necessary header files and define the Graph class:

<br>

 ``` c++
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
    
};
```

<br>

> - In the Graph constructor, we initialize the numVertices member variable and create a 2D vector to represent the adjacency matrix. We use a nested for loop to fill the matrix with all zeros:

<br>

 ``` c++
Graph(int numVertices) {
    this->numVertices = numVertices;

    // Initialize adjacency matrix to all zeros
    for (int i = 0; i < numVertices; i++) {
        vector<int> row(numVertices, 0);
        adjMatrix.push_back(row);
    }
}
```

<br>

> - To add an edge between two vertices, we simply set the corresponding entry in the adjacency matrix to 1:

<br>

 ``` c++
 void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
}
```

<br>

> - To check if two vertices are directly connected, we simply check the corresponding entry in the adjacency matrix. If it is 1, the vertices are directly connected. If it is 0, they are not directly connected:

<br>

 ``` c++
bool areConnected(int src, int dest) {
    return (adjMatrix[src][dest] == 1);
}
```

<br>

> - Finally, we add a print function to print out the adjacency matrix for debugging purposes:

<br>

 ``` c++
void print() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
```

<br>

> - In the main function, we create a Graph object with 5 vertices and add some edges. We then call the print function to display the adjacency matrix, delete an edge, call the areConnected function to check if two vertices are directly connected, and print the adjacency matrix again:


<br>

# Conclusion

Both the adjacency list and adjacency matrix representations have their advantages and disadvantages depending on the specific use case. The adjacency list is generally more space-efficient and faster for sparse graphs (i.e., graphs with fewer edges), while the adjacency matrix is generally more space-efficient and faster for dense graphs (i.e., graphs with many edges).



