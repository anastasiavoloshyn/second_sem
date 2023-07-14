#include <iostream>
#include <vector>

void Heap(std::vector<int>& arr, int n, int i) {
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[max])
        max = leftChild;

    if (rightChild < n && arr[rightChild] > arr[max])
        max = rightChild;

    if (max != i)
    {
        std::swap(arr[i], arr[max]);
        Heap(arr, n, max);
    }
}

void pyramidalSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        Heap(arr, i, 0);
    }
}

void bucketSort(std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<std::vector<int>>buckets(n);
    int max = arr[0], min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    int Range = max - min;

    for (int i = 0; i < n; i++)
    {
        int bucketIdx = (arr[i] - min) / (Range) * (n - 1);
        buckets[bucketIdx].push_back(arr[i]);
    }


    for (int i = 0; i < n; i++)
    {
        pyramidalSort(buckets[i]);
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }


}
void printArray(std::vector<int> arr) {

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


void isEqueal(std::vector<int>arr, std::vector<int>arr1)
{
    if (arr != arr1) {
        std::cout << "Test failed\n";

    }
    else {
        std::cout << "Test passed\n";
    }

}
void TestBucketSort()
{
    //тест з непосортованим масивом
    std::vector<int>arr = { 3,7,6,6,44,987,9 };
    int n = arr.size();
    bucketSort(arr);
    std::vector<int>sortedArr = { 3,6,6,7,9,44,987 };
    isEqueal(arr, sortedArr);
    //тест з від'ємними числами
    arr = { -3,-6,-9,-6,-7,-44,-987 };
    bucketSort(arr);
    sortedArr = { -987,-44,-9,-7,-6,-6,-3 };
    isEqueal(arr, sortedArr);
    //тест з вже посортованим масивом
    arr = { 1,2,3,4,5,6,7,8 };
    bucketSort(arr);
    sortedArr = { 1,2,3,4,5,6,7,8 };
    isEqueal(arr, sortedArr);
    //тест з від'ємними і з нулем
    arr = { -93,5,0,-2,4,59,14,88 };
    bucketSort(arr);
    sortedArr = { -93,-2,0,4,5,14,59,88 };
    isEqueal(arr, sortedArr);
}

void TestPyramidalSort()
{
    //тест з непосортованим масивом
    std::vector<int>arr = { 3,7,6,6,44,987,9 };
    int n = arr.size();
    pyramidalSort(arr);
    std::vector<int>sortedArr = { 3,6,6,7,9,44,987 };
    isEqueal(arr, sortedArr);
    //тест з від'ємними числами
    arr = { -3,-6,-9,-6,-7,-44,-987 };
    pyramidalSort(arr);
    sortedArr = { -987,-44,-9,-7,-6,-6,-3 };
    isEqueal(arr, sortedArr);
    //тест з вже посортованим масивом
    arr = { 1,2,3,4,5,6,7,8 };
    pyramidalSort(arr);
    sortedArr = { 1,2,3,4,5,6,7,8 };
    isEqueal(arr, sortedArr);
    //тест з від'ємними і з нулем
    arr = { -93,5,0,-2,4,59,14,88 };
    pyramidalSort(arr);
    sortedArr = { -93,-2,0,4,5,14,59,88 };
    isEqueal(arr, sortedArr);
}

int main()
{
    std::vector<int> arr = { -15, -77, 92, 44,0, 31,45 };
    std::cout << "Unsorted array:\n";
    printArray(arr);
    bucketSort(arr);
    std::cout << "Sorted array: \n";
    printArray(arr);
    std::cout << "Pyramidal Sort:\n";
    TestPyramidalSort();
    std::cout << "Bucket Sort: \n";
    TestBucketSort();




    return 0;
}
