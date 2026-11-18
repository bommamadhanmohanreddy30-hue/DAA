
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>

using namespace std;
using namespace std::chrono;

// GREEDY APPROACH
// Select the largest coin first
vector<int> coinExchangeGreedy(vector<int> coins, int amount)
{
    // Sort coins in descending order
    sort(coins.rbegin(), coins.rend());

    vector<int> usedCoins;
    int remaining = amount;

    // Check each coin
    for (int c : coins)
    {
        // Use the coin while it fits the remaining amount
        while (remaining >= c)
        {
            usedCoins.push_back(c);
            remaining -= c;
        }
    }

    // Return selected coins
    return usedCoins;
}

// DYNAMIC PROGRAMMING APPROACH
// dp[i] = minimum coins required to make amount i
void coinExchangeDP(vector<int> &coins, int amount)
{
    // Initialize DP array with infinity
    vector<int> dp(amount + 1, INT_MAX);

    // Store the last coin used for each amount
    vector<int> lastCoinUsed(amount + 1, -1);

    // Base case: zero coins are needed for amount 0
    dp[0] = 0;

    // Create DP table for displaying results
    vector<vector<int>> table(
        coins.size(), vector<int>(amount + 1, -1));

    // Process each coin
    for (size_t row = 0; row < coins.size(); row++)
    {
        int coin = coins[row];

        // Calculate minimum coins for each amount
        for (int i = 0; i <= amount; i++)
        {
            if (i == 0)
            {
                dp[i] = 0;
            }
            // Check whether the current coin can be used
            else if (coin <= i && dp[i - coin] != INT_MAX)
            {
                // Calculate the number of coins if this coin is used
                if (dp[i - coin] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin] + 1;
                    lastCoinUsed[i] = coin;
                }
            }

            // Store the current DP result in the table
            table[row][i] = (dp[i] == INT_MAX ? -1 : dp[i]);
        }
    }

    // Display DP table
    cout << "\nDP Table:\n";
    cout << "Coin\\Amt";

    for (int i = 0; i <= amount; i++)
        cout << "\t" << i;

    cout << "\n";

    for (size_t row = 0; row < coins.size(); row++)
    {
        cout << coins[row];

        for (int i = 0; i <= amount; i++)
        {
            if (table[row][i] == -1)
                cout << "\t-";
            else
                cout << "\t" << table[row][i];
        }

        cout << "\n";
    }

    // Display minimum number of coins
    cout << "\nMinimum coins needed: ";

    if (dp[amount] == INT_MAX)
    {
        cout << "Not possible\n";
        return;
    }

    cout << dp[amount] << "\n";

    // Find the actual coins used
    vector<int> usedCoins;
    int remaining = amount;

    while (remaining > 0)
    {
        int c = lastCoinUsed[remaining];
        usedCoins.push_back(c);
        remaining -= c;
    }

    // Display selected coins
    cout << "Coins used: { ";

    for (int c : usedCoins)
        cout << c << " ";

    cout << "}\n";
}

int main()
{
    // Available coins and target amount
    vector<int> coins = {1, 5, 6, 9};
    int amount = 11;

    cout << "Coins available: { 1 5 6 9 }\n";
    cout << "Amount to make: " << amount << "\n";

    // GREEDY APPROACH
    auto greedyStart = high_resolution_clock::now();

    vector<int> greedyResult =
        coinExchangeGreedy(coins, amount);

    auto greedyEnd = high_resolution_clock::now();

    // Calculate execution time
    auto greedyTime =
        duration_cast<nanoseconds>(greedyEnd - greedyStart);

    cout << "\n========== GREEDY APPROACH ==========\n";

    cout << "Coins used: { ";
    for (int c : greedyResult)
        cout << c << " ";

    cout << "}\n";

    cout << "Total coins: " << greedyResult.size() << "\n";
    cout << "Time Taken: " << greedyTime.count() << " ns\n";

    // DYNAMIC PROGRAMMING APPROACH
    cout << "\n========== DYNAMIC PROGRAMMING ==========\n";

    auto dpStart = high_resolution_clock::now();

    coinExchangeDP(coins, amount);

    auto dpEnd = high_resolution_clock::now();

    // Calculate execution time
    auto dpTime =
        duration_cast<nanoseconds>(dpEnd - dpStart);

    cout << "Time Taken: " << dpTime.count() << " ns\n";

    return 0;
}
