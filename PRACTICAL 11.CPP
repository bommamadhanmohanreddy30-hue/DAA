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
    cout << "Enter 0 for no edge (except diagonal):\n";

    // Read adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];  // Read edge weight

            // Replace 0 with infinity if no edge exists
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)  // Select intermediate vertex
    {
        for (int i = 0; i < n; i++)  // Select source vertex
        {
            for (int j = 0; j < n; j++)  // Select destination vertex
            {
                // Check whether a path exists through k
                if (graph[i][k] != INT_MAX &&
                    graph[k][j] != INT_MAX &&
                    graph[i][k] + graph[k][j] < graph[i][j])
                {
                    // Update shortest distance
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Display shortest distance matrix
    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INT_MAX)
                cout << "INF\t";  // Print infinity if no path exists
            else
                cout << graph[i][j] << "\t";  // Print shortest distance
        }
        cout << endl;
    }

    return 0;  // End program
}
