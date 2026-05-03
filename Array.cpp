#include <iostream>
using namespace std;

int LinearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int A[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    while (h >= l)
    {
        int mid = l + (h - l) / 2;
        if (A[mid] == key)
            return mid;
        if (A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int BinarySearch(int A[], int l, int h, int key)
{
    if (h < l)
        return -1;
    int mid = l + (h - l) / 2;
    if (A[mid] == key)
        return mid;
    else if (A[mid] > key)
        return BinarySearch(A, l, mid - 1, key);
    else
        return BinarySearch(A, mid + 1, h, key);
}
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[min_index] > A[j])
            {

                min_index = j;
            }
        }
        if (min_index != i)
        {

            Swap(&A[i], &A[min_index]);
        }
    }
}

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {

                Swap(&A[j], &A[j + 1]);
            }
        }
    }
}
void merge(int A[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];

    int i = 0,
        j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < n1)
    {
        A[k++] = L[i++];
    }
    while (j < n2)
        A[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void Merge_Sort(int A[], int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    ;
    Merge_Sort(A, low, mid);
    Merge_Sort(A, mid + 1, high);
    merge(A, low, mid, high);
}

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[i + 1], &A[high]);
    return (i + 1);
}
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        QuickSort(A, low, pi - 1);
        QuickSort(A, pi + 1, high);
    }
}
int main()
{
    int arr[] = {10, -20, -30, -40, 50};
    BubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}