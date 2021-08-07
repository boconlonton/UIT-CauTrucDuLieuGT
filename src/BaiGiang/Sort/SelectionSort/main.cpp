#include <iostream>

using namespace std;

void SelectionSort(int [], int);
void Swap(int &, int &);

int main()
{
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    SelectionSort(a, 15);
    for (int i=0; i<15; i++)
    {
        cout << a[i] << ",";
    }
    return 1;
} 

void SelectionSort(int a[], int n)
{
    int min;
    int k;
    int temp;
    for (int i=0; i<n; i++)
    {
        min = a[i];
        k = i;
        for (int j=i+1; j<n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                k = j;
            }
        }
        if (k != i)
            Swap(a[i], a[k]);
    }
}

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}