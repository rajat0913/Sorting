#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *b = *a;
    *a = temp;
}

void heapify(int *a, int n, int i)
{
    int big = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && a[big] > a[l])
    {
        big = l;
    }
    if (r < n && a[big] > a[r])
    {
        big = r;
    }

    if (big != i)
    {
        swap(&a[i], &a[big]);
        heapify(a, n, big);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[i], &a[0]);
        heapify(a, i, 0);
    }
}
int main()
{
    int arr[] = {101, 22, 65, 65, 25};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}