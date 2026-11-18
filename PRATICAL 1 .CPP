
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// BUBBLE SORT
// Repeatedly compares adjacent elements and swaps them if needed
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    // Repeat passes through the array
    for (int i = 0; i < n - 1; i++)
    {
        // Compare adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in the wrong order
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// SELECTION SORT
// Finds the smallest element and places it in the correct position
void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current element is the minimum
        int min = i;

        // Find the smallest element in the remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // Place the minimum element in the correct position
        swap(arr[i], arr[min]);
    }
}

// INSERTION SORT
// Inserts each element into its correct position
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // Start from the second element
    for (int i = 1; i < n; i++)
    {
        // Store the current element
        int key = arr[i];
        int j = i - 1;

        // Shift larger elements one position to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key into its correct position
        arr[j + 1] = key;
    }
}

// MERGE FUNCTION
// Combines two sorted parts into one sorted array
void merge(vector<int> &arr, int left, int mid, int right)
{
    // Find the sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy elements into the left subarray
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Copy elements into the right subarray
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Initialize indexes for both arrays and original array
    int i = 0, j = 0, k = left;

    // Compare and merge elements in sorted order
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements from right subarray
    while (j < n2)
        arr[k++] = R[j++];
}

// MERGE SORT
// Divides the array into smaller parts and sorts them
void mergeSort(vector<int> &arr, int left, int right)
{
    // Continue until only one element remains
    if (left < right)
    {
        // Find the middle position
        int mid = (left + right) / 2;

        // Sort the left half
        mergeSort(arr, left, mid);

        // Sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge both sorted halves
        merge(arr, left, mid, right);
    }
}

// PARTITION FUNCTION FOR QUICK SORT
// Uses the first element as the pivot
int partition(vector<int> &arr, int low, int high)
{
    // Select the first element as pivot
    int pivot = arr[low];

    // Initialize left and right pointers
    int i = low + 1;
    int j = high;

    while (true)
    {
        // Move left pointer while elements are <= pivot
        while (i <= high && arr[i] <= pivot)
            i++;

        // Move right pointer while elements are > pivot
        while (arr[j] > pivot)
            j--;

        // Swap elements if pointers have not crossed
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            break;
        }
    }

    // Place pivot in its correct position
    swap(arr[low], arr[j]);

    // Return the pivot position
    return j;
}

// QUICK SORT
// Sorts the array using divide and conquer
void quickSort(vector<int> &arr, int low, int high)
{
    // Check whether the subarray has more than one element
    if (low < high)
    {
        // Partition the array and get pivot position
        int p = partition(arr, low, high);

        // Sort elements before the pivot
        quickSort(arr, low, p - 1);

        // Sort elements after the pivot
        quickSort(arr, p + 1, high);
    }
}

// MAIN FUNCTION
int main()
{
    // Number of elements
    int n = 12345;

    // Create original and temporary arrays
    vector<int> arr(n), temp;

    // Initialize random number generator
    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 9998;

    // Display number of elements
    cout << "Number of Elements : " << n << endl << endl;

    // BUBBLE SORT EXECUTION
    auto start = high_resolution_clock::now();

    // Copy original array
    temp = arr;

    // Apply Bubble Sort
    bubbleSort(temp);

    // Record ending time
    auto stop = high_resolution_clock::now();

    // Display execution time
    cout << "Bubble Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // SELECTION SORT EXECUTION
    start = high_resolution_clock::now();
    temp = arr;

    // Apply Selection Sort
    selectionSort(temp);

    stop = high_resolution_clock::now();

    cout << "Selection Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // INSERTION SORT EXECUTION
    start = high_resolution_clock::now();
    temp = arr;

    // Apply Insertion Sort
    insertionSort(temp);

    stop = high_resolution_clock::now();

    cout << "Insertion Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // MERGE SORT EXECUTION
    start = high_resolution_clock::now();
    temp = arr;

    // Apply Merge Sort
    mergeSort(temp, 0, n - 1);

    stop = high_resolution_clock::now();

    cout << "Merge Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // QUICK SORT EXECUTION
    start = high_resolution_clock::now();
    temp = arr;

    // Apply Quick Sort
    quickSort(temp, 0, n - 1);

    stop = high_resolution_clock::now();

    cout << "Quick Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    return 0;
}
