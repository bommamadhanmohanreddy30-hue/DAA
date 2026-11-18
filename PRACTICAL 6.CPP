#include <iostream>  // For input and output
#include <climits>   // For INT_MAX
using namespace std;

// Function to calculate minimum multiplication cost
int matrixChainMultiplication(int p[], int n) {

    // Create DP table to store minimum multiplication cost
    int dp[n][n];

    // Cost is 0 when multiplying a single matrix
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Check different chain lengths
    for (int len = 2; len < n; len++) {

        // Select starting position of matrix chain
        for (int i = 1; i < n - len + 1; i++) {

            int j = i + len - 1;  // Calculate ending position

            dp[i][j] = INT_MAX;  // Initialize minimum cost

            // Try all possible splitting positions
            for (int k = i; k < j; k++) {

                // Calculate multiplication cost
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                // Update minimum multiplication cost
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    // Return minimum cost of multiplying all matrices
    return dp[1][n - 1];
}

int main() {

    // Define matrix dimensions
    // A1 = 10 x 20
    // A2 = 20 x 30
    // A3 = 30 x 40
    // A4 = 40 x 30

    int p[] = {10, 20, 30, 40, 30};

    // Calculate number of dimensions
    int n = sizeof(p) / sizeof(p[0]);

    // Display minimum multiplication cost
    cout << "Minimum number of scalar multiplications = "
         << matrixChainMultiplication(p, n);

    return 0;  // End program
}
