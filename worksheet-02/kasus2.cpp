/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pencari Index dari Bilangan
 * Tanggal  : 4 Maret 2020
 * Desc     : Program ini mencari index dari bilangan yang dicari dengan Menggunakan Sequential Search.
 */

#include <iostream>
using namespace std;

int SequentialSearch(int x[], int y, int size) {
    int i = 0;
    bool found = false;

    while (i < size && !found) {
        if (x[i] == y)
            found = true;
        else
            i++;
    }

    if (found)
        return i;
    else
        return 0;
}

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "Index dari 5 = " << SequentialSearch(x, 5, 10) << endl;
}