#include <iostream>
using namespace std;

void merge(int *a, int l, int m, int r)
{

    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int Larr[n1], Rarr[n2];
    // Copying thw array elements in two arrays.
    k = l;
    for (int i = 0; i < n1; i++)
    {
        Larr[i] = a[k++];
    }

    k = m + 1;
    for (int j = 0; j < n2; j++)
    {
        Rarr[j] = a[k++];
    }

    // Merging two arrays

    int index1 = 0;
    int index2 = 0;
    int index_mergedArray = l;

    while (index1 < n1 && index2 < n2)
    {
        if (Larr[index1] <= Rarr[index2])
        {
            a[index_mergedArray] = Larr[index1];
            index1++;
        }
        else
        {
            a[index_mergedArray] = Rarr[index2];
            index2++;
        }
        index_mergedArray++;
    }

    while (index1 < n1)
    {
        a[index_mergedArray] = Larr[index1];
        index1++;
        index_mergedArray++;
    }

    while (index2 < n2)
    {
        a[index_mergedArray] = Rarr[index2];
        index2++;
        index_mergedArray++;
    }
}

void mergesort(int *a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int m = (l + r) / 2;

        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {12, 7, 22, 1, 11, 34};
    int n = sizeof(a) / sizeof(int);
    mergesort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}