/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Pencari Bilangan Maksimal
 * Tanggal  : 4 Maret 2020
 * Desc     : Program ini mengimplemen algoritma untuk mencari bilangan maksimal.
 */

#include <iostream>
using namespace std;

int CariMaks(int arr[], int n) {
    int maks = arr[0], i = 1;
    
    while (i < n) {
        if (arr[i] > maks)
            maks = arr[i];
        i++;
    }

    return maks;
}

int main()
{
    int n, maks;

    cout << "Banyak Bilangan : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Nilai Bilangan ke-" << i+1 << " : ";
        cin >> arr[i];
    }

    maks = CariMaks(arr, n);

    cout << "\nBilangan Terbesar adalah " << maks << endl;
}