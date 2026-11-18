#include <iostream>   // For input and output
#include <vector>     // For adjacency list
#include <queue>      // For BFS
#include <stack>      // For DFS
#include <chrono>     // For calculating execution time

using namespace std;
using namespace chrono;

int main() {
    int vertices, edges;

    cout << "Number of vertices: ";
    cin >> vertices;  // Read number of vertices

    vector<vector<int>> graph(vertices); // Create adjacency list

    cout << "Number of edges: ";
    cin >> edges;  // Read number of edges

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;  // Read edge between two vertices

        graph[a].push_back(b); // Add edge from a to b
        graph[b].push_back(a); // Add edge from b to a (undirected graph)
    }

    int source;
    cout << "Starting vertex: ";
    cin >> source;  // Read starting vertex

    // ---------------- DFS ----------------

    auto dfsStart = high_resolution_clock::now(); // Start DFS timer

    vector<bool> visitedDFS(vertices, false); // Track visited vertices
    stack<int> st; // Create stack for DFS
    st.push(source); // Push starting vertex

    cout << "\nDFS Traversal: ";

    while (!st.empty()) { // Repeat until stack becomes empty
        int current = st.top(); // Get top element
        st.pop(); // Remove top element

        if (!visitedDFS[current]) { // Check if vertex is not visited
            visitedDFS[current] = true; // Mark vertex as visited
            cout << current << " "; // Print current vertex

            // Visit adjacent vertices in reverse order
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int next = graph[current][i];

                if (!visitedDFS[next]) // Check whether neighbor is visited
                    st.push(next); // Push neighbor into stack
            }
        }
    }

    auto dfsEnd = high_resolution_clock::now(); // End DFS timer

    // ---------------- BFS ----------------

    auto bfsStart = high_resolution_clock::now(); // Start BFS timer

    vector<bool> visitedBFS(vertices, false); // Track visited vertices
    queue<int> q; // Create queue for BFS
    q.push(source); // Insert starting vertex
    visitedBFS[source] = true; // Mark source as visited

    cout << "\nBFS Traversal: ";

    while (!q.empty()) { // Repeat until queue becomes empty
        int current = q.front(); // Get front element
        q.pop(); // Remove front element

        cout << current << " "; // Print current vertex

        for (int next : graph[current]) { // Visit adjacent vertices
            if (!visitedBFS[next]) { // Check if neighbor is not visited
                visitedBFS[next] = true; // Mark neighbor as visited
                q.push(next); // Insert neighbor into queue
            }
        }
    }

    auto bfsEnd = high_resolution_clock::now(); // End BFS timer

    // ---------------- Execution Time ----------------

    cout << "\n\nDFS Time: "
         << duration_cast<nanoseconds>(dfsEnd - dfsStart).count()
         << " ns"; // Display DFS execution time

    cout << "\nBFS Time: "
         << duration_cast<nanoseconds>(bfsEnd - bfsStart).count()
         << " ns"; // Display BFS execution time

    return 0; // End program successfully
}
