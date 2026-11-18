#include <iostream>  // For input and output
#include <climits>   // For INT_MAX
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;  // Read number of vertices

    int graph[10][10];  // Declare adjacency matrix

    cout << "Enter the adjacency matrix:\n";

    // Read adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];  // Read edge weight
        }
    }

    int parent[10];   // Store parent of each vertex
    int key[10];      // Store minimum edge weight
    bool visited[10]; // Track visited vertices

    // Initialize all vertices
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;    // Set key to infinity
        visited[i] = false;  // Mark as not visited
    }

    // Start from vertex 0
    key[0] = 0;      // Set starting vertex key to 0
    parent[0] = -1;  // Starting vertex has no parent

    // Find Minimum Spanning Tree (MST)
    for (int count = 0; count < n - 1; count++)
    {
        int min = INT_MAX;
        int u = -1;

        // Find vertex with minimum key value
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];  // Update minimum weight
                u = i;         // Store selected vertex
            }
        }

        // Mark selected vertex as visited
        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&  // Check edge exists
                !visited[v] &&       // Check not visited
                graph[u][v] < key[v]) // Check minimum weight
            {
                parent[v] = u;           // Update parent
                key[v] = graph[u][v];    // Update minimum key
            }
        }
    }

    // Print Minimum Spanning Tree
    int totalCost = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    // Display MST edges and calculate total cost
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]]; // Add edge weight
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;  // End program
}
