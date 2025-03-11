#include <iostream>

void QuickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int key = arr[(left + right) / 2]; 
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < key) i++;  
        while (arr[j] > key) j--;  
        
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}

int main() {
    int arr[10] = {7, 4, 5, 2, 1, 8, 3, 6, 9, 0};
    int left {0};
    int right {9}; 

    QuickSort(arr, left, right);

    for (int i = 0; i < 10; i++) { 
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
