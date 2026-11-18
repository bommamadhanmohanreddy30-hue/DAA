#include <iostream>   // For input and output
#include <vector>     // For using vectors
#include <algorithm>  // For swap() and reverse()
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
#include <chrono>     // For calculating execution time

using namespace std;
using namespace chrono;

// ---------------- MAX HEAP ----------------

// Function to create Max Heap
void buildMaxHeap(vector<int> &a, int n, int i)
{
    int maxIndex = i;       // Assume current node is maximum
    int l = 2 * i + 1;      // Find left child
    int r = 2 * i + 2;      // Find right child

    // Check whether left child is greater
    if (l < n && a[l] > a[maxIndex])
        maxIndex = l;

    // Check whether right child is greater
    if (r < n && a[r] > a[maxIndex])
        maxIndex = r;

    // If maximum is not the current node
    if (maxIndex != i)
    {
        swap(a[i], a[maxIndex]);       // Swap elements
        buildMaxHeap(a, n, maxIndex);  // Recursively heapify
    }
}

// Function to perform Max Heap Sort
void maxHeapSort(vector<int> &a)
{
    int n = a.size();  // Get array size

    // Build Max Heap
    for (int i = (n - 2) / 2; i >= 0; i--)
        buildMaxHeap(a, n, i);

    // Extract maximum element one by one
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);       // Move maximum to the end
        buildMaxHeap(a, i, 0);  // Restore Max Heap
    }
}

// ---------------- MIN HEAP ----------------

// Function to create Min Heap
void buildMinHeap(vector<int> &a, int n, int i)
{
    int minIndex = i;       // Assume current node is minimum
    int l = 2 * i + 1;      // Find left child
    int r = 2 * i + 2;      // Find right child

    // Check whether left child is smaller
    if (l < n && a[l] < a[minIndex])
        minIndex = l;

    // Check whether right child is smaller
    if (r < n && a[r] < a[minIndex])
        minIndex = r;

    // If minimum is not the current node
    if (minIndex != i)
    {
        swap(a[i], a[minIndex]);       // Swap elements
        buildMinHeap(a, n, minIndex);  // Recursively heapify
    }
}

// Function to perform Min Heap Sort
void minHeapSort(vector<int> &a)
{
    int n = a.size();  // Get array size

    // Build Min Heap
    for (int i = (n - 2) / 2; i >= 0; i--)
        buildMinHeap(a, n, i);

    // Extract minimum element one by one
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);       // Move minimum to the end
        buildMinHeap(a, i, 0);  // Restore Min Heap
    }

    reverse(a.begin(), a.end()); // Reverse to get ascending order
}

// ---------------- MAIN FUNCTION ----------------

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;  // Read number of elements

    vector<int> data(n);  // Create vector

    srand((unsigned)time(0));  // Initialize random number generator

    // Generate random numbers
    for (int i = 0; i < n; i++)
        data[i] = rand() % 100000;

    vector<int> maxHeap = data; // Copy data for Max Heap
    vector<int> minHeap = data; // Copy data for Min Heap

    // Measure Max Heap Sort execution time
    auto t1 = high_resolution_clock::now();
    maxHeapSort(maxHeap);
    auto t2 = high_resolution_clock::now();

    // Measure Min Heap Sort execution time
    auto t3 = high_resolution_clock::now();
    minHeapSort(minHeap);
    auto t4 = high_resolution_clock::now();

    // Calculate Max Heap execution time
    auto maxNano = duration_cast<nanoseconds>(t2 - t1);
    auto maxMicro = duration_cast<microseconds>(t2 - t1);

    // Calculate Min Heap execution time
    auto minNano = duration_cast<nanoseconds>(t4 - t3);
    auto minMicro = duration_cast<microseconds>(t4 - t3);

    // Display Max Heap Sort time
    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";

    // Display Min Heap Sort time
    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";

    return 0;  // End program
}
