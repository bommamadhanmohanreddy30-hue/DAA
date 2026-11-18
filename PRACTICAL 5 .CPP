#include <iostream>  // For input and output
#include <vector>    // For using vectors
#include <algorithm> // For max() function
using namespace std;

int main()
{
    int n, W;

    // Read number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Create arrays for weights and profits
    vector<int> weight(n + 1);
    vector<int> profit(n + 1);

    // Read weights of items
    cout << "Enter weights:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    // Read profits of items
    cout << "Enter profits:\n";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    // Read knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Create DP table and initialize with 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Check each item
    for (int i = 1; i <= n; i++)
    {
        // Check each knapsack capacity
        for (int w = 1; w <= W; w++)
        {
            // Check whether item fits in knapsack
            if (weight[i] <= w)
            {
                // Find maximum profit by taking or not taking item
                dp[i][w] = max(
                    dp[i - 1][w],  // Do not take the item
                    profit[i] + dp[i - 1][w - weight[i]] // Take the item
                );
            }
            else
            {
                // If item does not fit, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display maximum profit
    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    return 0;  // End program
}
