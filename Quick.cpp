#include "QuickSort.h"

void QuickSort(Patient arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2].GetVisitsCount();
    int i = left, j = right;

    while (i <= j) {
        while (arr[i].GetVisitsCount() < pivot) i++;
        while (arr[j].GetVisitsCount() > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(arr, left, j);
    if (i < right) QuickSort(arr, i, right);
}
