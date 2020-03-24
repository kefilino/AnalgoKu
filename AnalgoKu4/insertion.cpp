/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pengurut bilangan dalam array integer.
 * Tanggal  : 18 Maret 2020
 * Desc     : Program ini berfungsi mengurutkan bilangan dalam sebuah array dengan menggunakan algoritma insertion sort.
 */

#include <iostream>
using namespace std;

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void insertionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + 1;

        if (arr[i] > arr[j]) {
            swap(arr[i], arr[j]);

            for (i; i > 0; i--) {
                if (arr[i-1] > arr[i])
                    swap(arr[i-1], arr[i]);
                else
                    break;
            }
        }
    }
}

void printArray(int arr[], int size) { 
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << endl << "array sebelum disort : ";
    printArray(arr, 10);

    cout << endl << "array setelah disort : ";
    insertionSort(arr, 10);
    printArray(arr, 10);
}