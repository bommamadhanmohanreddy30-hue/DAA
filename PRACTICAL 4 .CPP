 #include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
long long iterativeFactorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
long long recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout << " ....Result for "  << n << "!...." << endl;


    // Iterative Time
    auto start1 = high_resolution_clock::now();
    long long ans1 = iterativeFactorial(n);
    auto end1 = high_resolution_clock::now();

    // Recursive Time
    auto start2 = high_resolution_clock::now();
    long long ans2 = recursiveFactorial(n);
    auto end2 = high_resolution_clock::now();

    // Calculate Time
    auto time1 = duration_cast<nanoseconds>(end1 - start1);
    auto time2 = duration_cast<nanoseconds>(end2 - start2);

    cout << "\nFactorial using Iterative Method = " << ans1 << endl;
    cout << "Execution Time = " << time1.count() << " ns" << endl;

    cout << "\nFactorial using Recursive Method = " << ans2 << endl;
    cout << "Execution Time = " << time2.count() << " ns" << endl;

    return 0;
}
