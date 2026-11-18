#include <iostream>  // For input and output
#include <vector>    // For using vectors
#include <chrono>    // For calculating execution time

using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(const vector<int> &arr, int key)
{
    // Check each element one by one
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)  // Check if element matches key
            return i;       // Return element index
    }

    return -1;  // Return -1 if element is not found
}

// Binary Search Function
int binarySearch(const vector<int> &arr, int key)
{
    int left = 0;             // Starting index
    int right = arr.size() - 1; // Ending index

    // Repeat until search range becomes empty
    while (left <= right)
    {
        int middle = (left + right) / 2;  // Find middle index

        if (arr[middle] == key)
            return middle;  // Element found

        else if (arr[middle] < key)
            left = middle + 1;  // Search right half

        else
            right = middle - 1; // Search left half
    }

    return -1;  // Return -1 if element is not found
}

int main()
{
    int n = 50000;  // Set array size to 50000
    vector<int> arr(n);  // Create vector of size n

    // Fill array with sorted elements
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;  // Store values from 1 to 50000

    int key;
    cout << "Enter number to search: ";
    cin >> key;  // Read search element

    int result;

    // -------- Linear Search --------

    auto startTime = high_resolution_clock::now(); // Start timer

    result = linearSearch(arr, key);  // Call linear search

    auto endTime = high_resolution_clock::now(); // Stop timer

    cout << "\n===== Linear Search =====\n";

    if (result >= 0)
        cout << "Found at Index : " << result << endl; // Print index
    else
        cout << "Element Not Found" << endl; // Print not found

    // Display linear search execution time
    cout << "Execution Time : "
         << duration_cast<microseconds>(endTime - startTime).count()
         << " microseconds\n";

    // -------- Binary Search --------

    startTime = high_resolution_clock::now(); // Start timer

    result = binarySearch(arr, key);  // Call binary search

    endTime = high_resolution_clock::now(); // Stop timer

    cout << "\n===== Binary Search =====\n";

    if (result >= 0)
        cout << "Found at Index : " << result << endl; // Print index
    else
        cout << "Element Not Found" << endl; // Print not found

    // Display binary search execution time
    cout << "Execution Time : "
         << duration_cast<microseconds>(endTime - startTime).count()
         << " microseconds\n";

    return 0;  // End program successfully
}
