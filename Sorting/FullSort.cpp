// seection sort decrease
#include <iostream>
#include <vector>
using namespace std;

// Selection sort
void SelectionSort(vector<int> &A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] > A[max])
                max = j;
        }
        swap(A[i], A[max]);
    }
}
// bigO = O(n^2)

// merge sort
void Merge(vector<int> &a, int Left, int Mid, int Right)
{
    int *temp = new int[Right - Left + 1];
    int i = Left, j = Mid + 1, k = 0;
    while (!(i > Mid && j > Right))
    {
        if ((i <= Mid && j <= Right && a[i] <= a[j]) || j > Right)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    for (int i = Left; i <= Right; i++)
        a[i] = temp[i - Left];
    delete[] temp;
}
void MergeSort(vector<int> &arr, int Left, int Right)
{
    if (Left < Right)
    {
        int Mid = (Left + Right) / 2;
        MergeSort(arr, Left, Mid);
        MergeSort(arr, Mid + 1, Right);
        Merge(arr, Left, Mid, Right);
    }
}
// bigO = O(nlogn)

// interchange sort

void InterchangeSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
}
// bigO = O(n^2)

// bubble sort

void BubbleSort(vector<int> &arr, int n)
{
    for (int i = n - 1; i >= 1; i--)
        for (int j = 0; j <= i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// bigO = O(n^2)

// quick sort

void QuickSort(vector<int> &arr, int Left, int Right)
{
    int i = Left, j = Right;
    int pivot = arr[(Left + Right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (Left < j)
        QuickSort(arr, Left, j);
    if (i < Right)
        QuickSort(arr, i, Right);
}
// bigO = O(nlogn)

// heap sort

void Heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
// bigO = O(nlogn)

// radix sort

void RadixSort(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int *output = new int[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
        delete[] output;
    }
}
// bigO  = O(d*(n+b)) = O(n)

// counting sort

void CountingSort(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int *count = new int[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
    delete[] count;
}
// bigO of counting sort
// bigO best case is O(n+k)
// bigO worst case is O(n+k)
// bigO average case is O(n+k)
// insertion sort

void InsertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void InsertionSortDecrease(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] < key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
// 3, 8, 4, 5, 9, 1, 2, 6 
// sort decrease
// 8, 3, 4, 5, 9, 1, 2, 6
// 8, 4, 3, 5, 9, 1, 2, 6
// 8, 5, 4, 3, 9, 1, 2, 6
// 9, 8, 5, 4, 3, 1, 2, 6
// 9, 8, 5, 4, 3, 1, 2, 6
// 9, 8, 5, 4, 3, 2, 1, 6
// 9, 8, 6, 5, 4, 3, 2, 1
// done sort decrease
// bigO of insertion sort
// bigO best case is O(n)
// bigO worst case is O(n^2)
// bigO average case is O(n^2)

int main()
{
    vector<int> A = {8, 2, 1, 9, 4, 5, 7, 6, 3};
    int type;
    cout << "Enter type of sort: ";
    cout << "1. Selection sort" << endl;
    cout << "2. Merge sort" << endl;
    cout << "3. Interchange sort" << endl;
    cout << "4. Bubble sort" << endl;
    cout << "5. Quick sort" << endl;
    cout << "6. Heap sort" << endl;
    cout << "7. Radix sort" << endl;
    cout << "8. Counting sort" << endl;
    cout << "9. Insertion sort" << endl;
    cin >> type;
    switch (type)
    {
    case 1:
        SelectionSort(A, A.size());
        break;
    case 2:
        MergeSort(A, 0, A.size() - 1);
        break;
    case 3:
        InterchangeSort(A, A.size());
        break;
    case 4:
        BubbleSort(A, A.size());
        break;
    case 5:
        QuickSort(A, 0, A.size() - 1);
        break;
    case 6:
        HeapSort(A, A.size());
        break;
    case 7:
        RadixSort(A, A.size());
        break;
    case 8:
        CountingSort(A, A.size());
        break;
    case 9:
        InsertionSortDecrease(A, A.size());
        break;
    default:
        cout << "Wrong type of sort" << endl;
        break;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    return 0;
}
