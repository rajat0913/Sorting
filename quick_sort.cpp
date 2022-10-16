#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int quickPartition(int *a, int beg, int end)
{
    int pivot = a[end];
    int i = beg - 1;

    for (int j = beg; j <= end - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[end]);
    return (i + 1);
}

void quickSort(int *a, int beg, int end)
{
    if (beg < end)
    {
        int pi = quickPartition(a, beg, end);
        quickSort(a, beg, pi - 1);
        quickSort(a, pi + 1, end);
    }
}

int main()
{
    int arr[] = {45, 101, 22, 65, 87, 87, 65, 25};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);

    cout << "After sorting the array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}