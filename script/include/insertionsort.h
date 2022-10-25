#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

unsigned t4, t5;

double insertionSort(int arr[], int n)
{
    clock_t tStart3 = clock();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    t5 = clock();
       double time = ((double)(clock() - tStart3)*1000)/CLOCKS_PER_SEC;
    return 555.0102;
}

#endif // INSERTIONSORT_H
