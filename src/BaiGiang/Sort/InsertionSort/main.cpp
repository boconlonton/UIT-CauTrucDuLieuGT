#include <iostream>

using namespace std;

void InsertionSort(int [], int);

int main()
{
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    InsertionSort(a, 15);
    for (int i=0; i<15; i++)
    {
        cout << a[i] << ",";
    }
    return 1;
} 

void InsertionSort(int a[], int n)
{
    // Luu gia tri a[i], tranh bi ghi de khi doi cho cac phan tu
    int x;
    int pos;
    // Doan a[0] da sap thu tu
    for (int i=1; i<n; i++)
    {
        x = a[i];
        pos = i-1;
        // Tim vi tri chen x
        while ((pos >= 0) && (a[pos] > x))
        {
            // Ket hop doi cho cac phan tu se dung sau x trong day moi
            a[pos+1] = a[pos];
            pos--;
        }
        // Chen x vao day
        a[pos+1] = x;
    }
}