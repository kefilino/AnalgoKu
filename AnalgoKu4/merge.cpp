/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pengurut bilangan dalam array integer.
 * Tanggal  : 18 Maret 2020
 * Desc     : Program ini berfungsi mengurutkan bilangan dalam sebuah array dengan menggunakan algoritma merge sort.
 */

#include <iostream>
#include <chrono>
using namespace std;

void merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1];
    int R[n2+1];

    for (int i = 0; i < n1; i++)
        L[i] = arr[(p - 1) + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[q + j];

    L[n1] = 2147483647;
    R[n2] = 2147483647;
    int i = 0;
    int j = 0;

    for (int k = (p-1); k < r; k++){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int r){
    int q;
    if (p < r) {
        q = (p + r)/2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
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

    auto start = chrono::steady_clock::now();
    mergeSort(arr, 1, 10);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    printArray(arr, 10);

    cout << endl << "waktu yang dibutuhkan komputer : "
         << chrono::duration <double, nano> (diff).count()
         << " nanosekon." << endl;
}