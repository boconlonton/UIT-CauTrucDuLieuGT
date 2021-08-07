#include <iostream>

using namespace std;

void BInsertionSort(int [], int);

int main()
{
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    BInsertionSort(a, 15);
    for (int i=0; i<15; i++)
    {
        cout << a[i] << ",";
    }
    return 1;
} 

void BInsertionSort(int a[], int n)
{
    int left, right, mid;
    // Luu gia tri a[i], tranh bi ghi de khi doi cho cac phan tu
    int x;
    for (int i=1; i<n; i++)
    {
        x = a[i];
        left = 1;
        right = n-1;
        // Tim vi tri chen x (dung BinarySearch)
        while (i<=right)
        {
            // Tim vi tri thich hop mid
            mid = (left+right)/2;
            if (x < a[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (int j=i-1; j>=left; j--)
        {
            // Doi cac phan tu se dung sau x
            a[j+1] = a[j];
        }
        // Chen x vao vi tri nay
        a[left] = x;
    }    
}