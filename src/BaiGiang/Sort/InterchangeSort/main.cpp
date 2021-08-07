#include <iostream>

using namespace std;

void InterchangeSort(int [], int);
void Swap(int &, int &);

int main()
{
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    InterchangeSort(a, 15);
    for (int i=0; i<15; i++)
    {
        cout << a[i] << ",";
    }
    return 1;
} 

void InterchangeSort(int a[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
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