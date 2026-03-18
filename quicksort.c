#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];   // choosing first element as pivot
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }

    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
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

    srand(time(NULL));

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    st = clock();
    quicksort(a, 0, n - 1);
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
