#include<iostream>
using namespace std;

template <typename T>
void merge(T arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    T* L = new T[n1];
    T* R = new T[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    cout << endl;
    cout << "---------------------- Merge Sorting --------------------------------";
    cout << endl << endl;

    int array[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, n - 1);

    cout << "Sorted array of Integers: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl << endl;

    double secondArray[] = {12.0, 11.9, 13.6, 5.7, 6.2, 7.1,19.0, 99.0, 107.7};
    int  y = sizeof(array) / sizeof(secondArray[0]);

    mergeSort(secondArray, 0, n - 1);

    cout << "Sorted array of Doubles: ";
    for (int i = 0; i < n; i++) {
        cout << secondArray[i] << " ";
    }
    cout << endl << endl;


    return 0;
}

