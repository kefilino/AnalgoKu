/*
 * Kefilino Khalifa Filardi
 * 140810180028
 * Tugas 5
 */

#include <iostream>
using namespace std;

void input(string &X, string &Y)
{
    cout << "String pertama\t: ";
    getline(cin, X);
    cout << "String kedua\t: ";
    getline(cin, Y);
}

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string addBitStrings(string first, string second)
{
    string result;

    int length = makeEqualLength(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        int sum = (firstBit ^ secondBit ^ carry) + '0';

        result = (char)sum + result;

        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry)
        result = '1' + result;

    return result;
}

int multiplyBit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

long int multiplyBits(string X, string Y)
{
    for (int i = 0; i < X.length(); i++) 
        if (X[i] != '0' && X[i] != '1') {
            cout << "String pertama bukan kode biner!" << endl;
            return 0;
        }
    for (int i = 0; i < Y.length(); i++) 
        if (Y[i] != '0' && Y[i] != '1') {
            cout << "String pertama bukan kode biner!" << endl;
            return 0;
        }
    
    int n = makeEqualLength(X, Y);

    if (n == 0)
        return 0;
    else if (n == 1)
        return multiplyBit(X, Y);

    int fh = n / 2;
    int sh = (n - fh);

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    long int P1 = multiplyBits(Xl, Yl);
    long int P2 = multiplyBits(Xr, Yr);
    long int P3 = multiplyBits(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main()
{
    string X = "\0", Y = "\0";
    input(X, Y);

    cout << "\nHasil perkalian kedua bit adalah " << multiplyBits(X, Y);
}