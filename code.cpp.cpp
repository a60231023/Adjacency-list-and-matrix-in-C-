// #include <iostream>
// #include <vector>

// using namespace std;

// class Graph {
// private:
//     int numVertices;
//     vector<vector<int>> adjList;

// public:
//     Graph(int n) {
//         numVertices = n;
//         adjList.resize(numVertices);
//     }

//     void addEdge(int src, int dest) {
//         adjList[src].push_back(dest);
//         adjList[dest].push_back(src);
//     }

//     void print() {
//         for (int i = 0; i < numVertices; i++) {
//             cout << i << ": ";
//             for (int j = 0; j < adjList[i].size(); j++) {
//                 cout << adjList[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graph g(5);

//     g.addEdge(0, 1);
//     g.addEdge(0, 4);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);
//     g.addEdge(2, 3);
//     g.addEdge(3, 4);

//     g.print();

//     return 0;
// }

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
