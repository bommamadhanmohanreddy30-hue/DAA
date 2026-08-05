#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Max Heap
void buildMaxHeap(vector<int> &a, int n, int i)
{
    int maxIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[maxIndex])
        maxIndex = l;

    if (r < n && a[r] > a[maxIndex])
        maxIndex = r;

    if (maxIndex != i)
    {
        swap(a[i], a[maxIndex]);
        buildMaxHeap(a, n, maxIndex);
    }
}

void maxHeapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = (n - 2) / 2; i >= 0; i--)
        buildMaxHeap(a, n, i);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        buildMaxHeap(a, i, 0);
    }
}

// Min Heap
void buildMinHeap(vector<int> &a, int n, int i)
{
    int minIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[minIndex])
        minIndex = l;

    if (r < n && a[r] < a[minIndex])
        minIndex = r;

    if (minIndex != i)
    {
        swap(a[i], a[minIndex]);
        buildMinHeap(a, n, minIndex);
    }
}

void minHeapSort(vector<int> &a)
{
    int n = a.size();

    for (int i = (n - 2) / 2; i >= 0; i--)
        buildMinHeap(a, n, i);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        buildMinHeap(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    srand((unsigned)time(0));

    for (int i = 0; i < n; i++)
        data[i] = rand() % 100000;

    vector<int> maxHeap = data;
    vector<int> minHeap = data;

    auto t1 = high_resolution_clock::now();
    maxHeapSort(maxHeap);
    auto t2 = high_resolution_clock::now();

    auto t3 = high_resolution_clock::now();
    minHeapSort(minHeap);
    auto t4 = high_resolution_clock::now();

    auto maxNano = duration_cast<nanoseconds>(t2 - t1);
    auto maxMicro = duration_cast<microseconds>(t2 - t1);

    auto minNano = duration_cast<nanoseconds>(t4 - t3);
    auto minMicro = duration_cast<microseconds>(t4 - t3);

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";

    return 0;
}
