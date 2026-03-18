#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int size = high - low + 1;
    int b[size];

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    // Copy back to original array
    for (int l = 0; l < size; l++)
        a[low + l] = b[l];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n, i;
    clock_t st, end;
    float d;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    // Seed random numbers
    srand(time(NULL));

    // Generate random array
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    st = clock();
    mergesort(a, 0, n - 1);
    end = clock();

    d = (float)(end - st) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n", d);

    // Optional: print sorted array
    /*
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    */

    return 0;
}
