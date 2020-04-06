/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Program Undirected Graph
 * Tanggal  : 5 April 2020
 * Desc     : Program ini mengimplemen undirected graph dengan menggunakan adjacency matrix.
 */

#include <iostream>
using namespace std;

void input(int &n)
{
    cout << "Banyak simpul dalam graph : ";
    cin >> n;
}

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "Nilai simpul ke-" << i+1 << " : ";
        cin >> arr[i];
    }
}

void input(int &num, int value)
{
    num = value;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
}

bool check(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return true;
    }

    return false;
}

int main()
{
    int n, val;
    input(n);
    
    int simpul[n];
    input(simpul, n);

    int garis[n][n];
    for (int i = 0; i < n; i++) {
        int edge;
        cout << "\nBanyak garis simpul ke-" << i+1
             << " (" << simpul[i] << ") : ";
        cin >> edge;

        for (int j = 0; j < edge; j++) {
            bool found = false;

            do {
                cout << "Simpul garis ke-" << i+1 << " : ";
                cin >> val;

                found = check(simpul, n, val);
                if (!found)
                    cout << endl << "Simpul tidak ditemukan!" << endl;
            } while (!found);

            input(garis[i][j], val);
        }
    }

    cout << endl << "Adjacency matrix dari undirected graph : \n\t";
    print(simpul, n);

    for (int i = 0; i < n; i++) {
        cout << endl << simpul[i] << "\t";
        
        for (int j = 0; j < n; j++) {
            bool found = false;

            for (int k = 0; k < n; k++) {
                if (garis[i][k] == simpul[j])
                    found = true;
            }

            if(found)
                cout << "1\t";
            else
                cout << "0\t";
        }
        
    }
}