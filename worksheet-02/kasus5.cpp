/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pengurut Bilangan Larik
 * Tanggal  : 4 Maret 2020
 * Desc     : Program ini mengurut bilangan larik menggunakan selection sort.
 */

#include <iostream>
using namespace std;

void SelectionSort(int x[], int size) {
    int i, j, imaks, temp;

    for (i = size; i > 0; i--) {
        imaks = 0;

        for (j = 1; j < size; j++) {
            if (x[j] > x[imaks])
                imaks = j;
        }

        temp = x[i];
        x[i] = x[imaks];
        x[imaks] = temp;
    }
}

int main()
{
    int x[10] = {10,9,8,7,6,5,4,3,2,1};
    SelectionSort(x, 10);
    
    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    
}