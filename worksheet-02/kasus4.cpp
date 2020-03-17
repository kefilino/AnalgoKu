/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pengurut Bilangan Larik
 * Tanggal  : 4 Maret 2020
 * Desc     : Program ini mengurut bilangan larik menggunakan insertion sort.
 */

#include <iostream>
using namespace std;

void InsertionSort(int x[], int size) {
    int i, j, insert;

    for (i = 1; i < size; i++) {
        insert = x[i];
        j = i;

        do {
            x[j] = x[j-1];
            j--;
        } while (j < i && x[j-i] > insert);

        x[j] = insert;
    }
}

int main()
{
    int x[10] = {10,9,8,7,6,5,4,3,2,1};
    InsertionSort(x, 10);
    
    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    
}