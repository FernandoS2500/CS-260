#include <iostream>
#include <string>

const int maxVertices = 20; // Maximum number of vertices
const int INF = 1e9; // large number to be close to infinity

class Graph {
public:
    // start vertex count and creates the array
    Graph() : vertexCount(0) {
        // Sets all the  weights in the matrix at inf, when the array is first started. 
        //This means that they are not conneced to any edges.
        for (int i = 0; i < maxVertices; ++i) {
            for (int j = 0; j < maxVertices; ++j) {
                adjacencyMatrix[i][j] = INF;
            }
        }
    }

    // Function to add a vertex to the array
    // needs a name for the vertex
    void addVertex(const std::string& vertexName) {
        // checks that we havent gone past the array max
        if (vertexCount < maxVertices) {
            // if not it will add it to the matrix and increase the count
            vertexNames[vertexCount++] = vertexName; 
        } else {
            //let user know they cant add more edges.
            std::cout << maxVertices << " edges is the maximum." << std::endl;
        }
    }

    // Function to add an edge 
    // needs two vertices and a weight for the edge.
    void addEdge(const std::string& source, const std::string& destination, int weight) {
        // grabs in the index location for the vertex
        int srcIndex = getVertexIndex(source);
        int destIndex = getVertexIndex(destination);
        // -1 means it does not exist, return from getvertex function 
        if (srcIndex != -1 && destIndex != -1) {
            // all entres are bidirectional
            //wight added
            adjacencyMatrix[srcIndex][destIndex] = weight;
            adjacencyMatrix[destIndex][srcIndex] = weight; 
        }
    }

    // Function to find the shortest path between two vertices
    // dijkstra algorithem
    void shortestPath(const std::string& source, const std::string& destination) {
        // grabs the index 
        int srcIndex = getVertexIndex(source);
        int destIndex = getVertexIndex(destination);
        // the first thing it does is check that both vertices exist.
        if (srcIndex == -1 || destIndex == -1) {
            return;
        }

        // Array to store the shortest distance
        int distances[maxVertices]; 
        // Array to mark visited vertices false by default
        bool visited[maxVertices] = { false };
        // Array to store the previous vertex in the shortest path
        int previous[maxVertices]; 

        // sets the distances and previous arrays
        for (int i = 0; i < maxVertices; ++i) {
            // at set to inf , so no connection
            distances[i] = INF;
            // -1 will tell us that it has no path has been added
            previous[i] = -1;
        }

        // Distance is set to 0 at start
        distances[srcIndex] = 0; 

        // Main loop to find shortest paths
        while (true) {
            int smallest = -1;
            for (int i = 0; i < maxVertices; ++i) {
                //will loop loiking for an unvisited  and smallest or distance shorter
                if (!visited[i] && (smallest == -1 || distances[i] < distances[smallest])) {
                    smallest = i;
                }
            }
            // break the loop when they have all been visted
            if (smallest == -1 || distances[smallest] == INF) {
                break;
            }
            // sets the visted to true
            visited[smallest] = true;

            // Update distances to neighbors
            // loops through all the vertex possible
            for (int neighbor = 0; neighbor < maxVertices; ++neighbor) {
                //checks if has been visited first 
                if (adjacencyMatrix[smallest][neighbor] != INF && !visited[neighbor]) {
                    // gets the distance(wight)
                    int alt = distances[smallest] + adjacencyMatrix[smallest][neighbor];
                    // if its smaller it will update.
                    if (alt < distances[neighbor]) {
                        distances[neighbor] = alt;
                        previous[neighbor] = smallest;
                    }
                }
            }
        }

        //creates the shortest path liar
        int path[maxVertices];
        int pathLength = 0;
        for (int at = destIndex; at != -1; at = previous[at]) {
            path[pathLength++] = at;
        }

        // reverses the list
        for (int i = 0; i < pathLength / 2; ++i) {
            std::swap(path[i], path[pathLength - i - 1]);
        }

        // Output the list for user to see
        std::cout << "Shortest path from " << source << " to " << destination << ": ";
        for (int i = 0; i < pathLength; ++i) {
            std::cout << vertexNames[path[i]] << " ";
        }
        std::cout << std::endl;
    }

    // Function to find the minimum spanning tree using Prim's algorithm
    void minSpanTree() {
        // Array to store the parent node 
        int parent[maxVertices]; 
        // Array store if  vertex is in array, start as false
        bool inMinSpanTree[maxVertices] = { false }; 
        // Array to store the min  weight
        int key[maxVertices]; 
        // Array to store  edges
        int minSpanTreeEdges[maxVertices][2]; 
        // Number of edges in tree
        int minSpanTreeSize = 0; 

     
        //loops through each and set the key and parent values, to start
        for (int i = 0; i < maxVertices; ++i) {
            key[i] = INF;
            parent[i] = -1;
        }

        // sets value of first vertex
        key[0] = 0;

        // Main loop to create tree
        for (int count = 0; count < maxVertices - 1; ++count) {
            //grabs the location
            int keymin = minKey(key, inMinSpanTree);
            // save into array that it has been added to tree
            inMinSpanTree[keymin] = true;

            // Update key values and parent index 
            for (int i = 0; i < maxVertices; ++i) {
                //
                if (adjacencyMatrix[keymin][i] != INF && !inMinSpanTree[i] && adjacencyMatrix[keymin][i] < key[i]) {
                    parent[i] = keymin;
                    key[i] = adjacencyMatrix[keymin][i];
                }
            }
        }

        // Store the tree edges
        // looping may array size
        for (int i = 1; i < maxVertices; ++i) {
            //when its not -1, added to array
            if (parent[i] != -1) {
                minSpanTreeEdges[minSpanTreeSize][0] = parent[i];
                minSpanTreeEdges[minSpanTreeSize][1] = i;
                minSpanTreeSize++;
            }
        }

        // Output the tree edges
        std::cout << "Minimum Spanning Tree: " << std::endl;
        for (int i = 0; i < minSpanTreeSize; ++i) {
            std::cout << vertexNames[minSpanTreeEdges[i][0]] << " - " << vertexNames[minSpanTreeEdges[i][1]] << std::endl;
        }
    }

    // index locations will be the same 
    // Array to store vertex names
    std::string vertexNames[maxVertices]; 
    //  matrix to store edge weights
    int adjacencyMatrix[maxVertices][maxVertices]; 
    // vertex count
    int vertexCount; 

    //function to get the index of a vertex 
    int getVertexIndex(const std::string& vertexName) {
        //loops through the array looking for the name
        for (int i = 0; i < vertexCount; ++i) {
            if (vertexNames[i] == vertexName) {
                // returns index
                return i;
            }
        }
        // if it doent find the name it returns -1
        return -1;
    }

    // function to find the vertex with the minimum value
    int minKey(int key[], bool inMinSpanTree[]) {
        int min = INF, minIndex;

        for (int i = 0; i < maxVertices; ++i) {
            if (!inMinSpanTree[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }

        return minIndex;
    }
    
};


// Test functions
void testAddVertexOne() {
    Graph g;
    g.addVertex("A");

    if (g.getVertexIndex("A") != -1) {
        std::cout << "Test Add Vertex One Passed" << std::endl;
    } else {
        std::cout << "Test Add Vertex One Failed" << std::endl;
    }
}

void testAddVertexMultiple() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    if (g.getVertexIndex("A") != -1 && g.getVertexIndex("B") != -1 && g.getVertexIndex("C") != -1) {
        std::cout << "Test Add Vertex Multiple Passed" << std::endl;
    } else {
        std::cout << "Test Add Vertex Multiple Failed" << std::endl;
    }
}

void testAddEdgeOne() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addEdge("A", "B", 1);

    if (g.adjacencyMatrix[g.getVertexIndex("A")][g.getVertexIndex("B")] != INF) {
        std::cout << "Test Add Edge One Passed" << std::endl;
    } else {
        std::cout << "Test Add Edge One Failed" << std::endl;
    }
}

void testAddEdgeMultiple() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B", 1);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "C", 3);

    if (g.adjacencyMatrix[g.getVertexIndex("A")][g.getVertexIndex("B")] != INF &&
        g.adjacencyMatrix[g.getVertexIndex("A")][g.getVertexIndex("C")] != INF &&
        g.adjacencyMatrix[g.getVertexIndex("B")][g.getVertexIndex("C")] != INF) {
        std::cout << "Test Add Edge Multiple Passed" << std::endl;
    } else {
        std::cout << "Test Add Edge Multiple Failed" << std::endl;
    }
}

void testShortestPathSimple() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addEdge("A", "B", 1);

    g.shortestPath("A", "B");
    // Expected output: Shortest path from A to B: A B
    // You can manually verify the output.
}

void testShortestPathComplex() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addEdge("A", "B", 1);
    g.addEdge("B", "C", 2);
    g.addEdge("A", "C", 4);
    g.addEdge("C", "D", 1);

    g.shortestPath("A", "D");
    // Expected output: Shortest path from A to D: A B C D
    // You can manually verify the output.
}

void testMinSpanTreeSimple() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B", 1);
    g.addEdge("B", "C", 2);
    g.addEdge("A", "C", 3);

    g.minSpanTree();
    // Expected output: Minimum Spanning Tree:
    // A - B
    // B - C
    // You can manually verify the output.
}

void testMinSpanTreeComplex() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addEdge("A", "B", 1);
    g.addEdge("A", "C", 4);
    g.addEdge("B", "C", 2);
    g.addEdge("B", "D", 3);
    g.addEdge("C", "D", 5);

    g.minSpanTree();
    // Expected output: Minimum Spanning Tree:
    // A - B
    // B - C
    // B - D
    // You can manually verify the output.
}
int main() {
    // Add Vertex Tests
    testAddVertexOne();
    testAddVertexMultiple();

    // Add Edge Tests
    testAddEdgeOne();
    testAddEdgeMultiple();

    // Shortest Path Tests
    testShortestPathSimple();
    testShortestPathComplex();

    // Minimum Spanning Tree Tests
    testMinSpanTreeSimple();
    testMinSpanTreeComplex();

    return 0;
}
