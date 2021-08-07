#include <iostream>

using namespace std;

void BubbleSort(int [], int);
void Swap(int &, int &);

int main()
{
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    BubbleSort(a, 15);
    for (int i=0; i<15; i++)
    {
        cout << a[i] << ",";
    }
    return 1;
} 

void BubbleSort(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=n-1; j>i; j--)
        {
            if (a[j] < a[i])
            {
                Swap(a[i], a[j]);
            }
        }
    }
}

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}