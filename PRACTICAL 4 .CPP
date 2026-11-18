#include <iostream>  // For input and output
#include <chrono>    // For calculating execution time

using namespace std;
using namespace std::chrono;

// -------- Iterative Factorial --------
long long iterativeFactorial(int n)
{
    long long fact = 1;  // Initialize factorial value

    // Multiply numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;  // Calculate factorial
    }

    return fact;  // Return factorial result
}

// -------- Recursive Factorial --------
long long recursiveFactorial(int n)
{
    // Base condition to stop recursion
    if (n == 0 || n == 1)
        return 1;

    // Recursive function call
    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;  // Read input number

    cout << " ....Result for " << n << "!...." << endl;

    // -------- Iterative Execution Time --------

    auto start1 = high_resolution_clock::now(); // Start timer

    long long ans1 = iterativeFactorial(n);  // Call iterative function

    auto end1 = high_resolution_clock::now(); // Stop timer

    // -------- Recursive Execution Time --------

    auto start2 = high_resolution_clock::now(); // Start timer

    long long ans2 = recursiveFactorial(n);  // Call recursive function

    auto end2 = high_resolution_clock::now(); // Stop timer

    // Calculate execution time in nanoseconds
    auto time1 = duration_cast<nanoseconds>(end1 - start1);
    auto time2 = duration_cast<nanoseconds>(end2 - start2);

    // Display iterative factorial result
    cout << "\nFactorial using Iterative Method = " << ans1 << endl;
    cout << "Execution Time = " << time1.count() << " ns" << endl;

    // Display recursive factorial result
    cout << "\nFactorial using Recursive Method = " << ans2 << endl;
    cout << "Execution Time = " << time2.count() << " ns" << endl;

    return 0;  // End program
}
