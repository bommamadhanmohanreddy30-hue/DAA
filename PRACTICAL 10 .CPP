#include <iostream>    // For input and output
#include <algorithm>   // For sorting edges
using namespace std;

// Structure to store edge details
struct Edge
{
    int u, v, weight;  // Source, destination and weight
};

// Compare edges based on weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;  // Sort in ascending order
}

int parent[10];  // Array to store parent vertices

// Find the root of a vertex
int find(int x)
{
    if (parent[x] == x)  // Check whether vertex is root
        return x;

    return find(parent[x]);  // Recursively find root
}

// Combine two sets
void unionSet(int u, int v)
{
    int rootU = find(u);  // Find root of first vertex
    int rootV = find(v);  // Find root of second vertex

    parent[rootV] = rootU;  // Join both sets
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;  // Read number of vertices

    cout << "Enter number of edges: ";
    cin >> e;  // Read number of edges

    Edge edges[20];  // Array to store edges

    cout << "Enter edges (u v weight):\n";

    // Read edge details
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Initialize parent array
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;  // Each vertex is its own parent
    }

    // Sort edges by weight
    sort(edges, edges + e, compare);

    int totalCost = 0;  // Store total MST cost
    int count = 0;      // Count selected edges

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    // Select minimum weight edges
    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;  // Get source vertex
        int v = edges[i].v;  // Get destination vertex

        // Check whether adding edge creates a cycle
        if (find(u) != find(v))
        {
            // Print selected edge and weight
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            totalCost += edges[i].weight;  // Add edge weight

            unionSet(u, v);  // Combine two sets

            count++;  // Increase selected edge count
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;  // End program
}
