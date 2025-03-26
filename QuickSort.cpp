#include "QuickSort.h"
#include "Planet.h"
void QuickSort(Planet arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2].GetDiameter();
    int i = left, j = right;

    while (i <= j) {
        while (arr[i].GetDiameter() < pivot) i++;
        while (arr[j].GetDiameter() > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(arr, left, j);
    if (i < right) QuickSort(arr, i, right);
}
