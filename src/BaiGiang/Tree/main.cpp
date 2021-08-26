#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
    Tree T;
    CreateTree(T);
    Insert(T, 2);
    Insert(T, 3);
    Insert(T, 5);
    Insert(T, 6);
    Insert(T, 1);
    Insert(T, -1);
    // preOrder(T);
    inOrder(T);
    // postOrder(T);
    DeleteNodeX(T, 2);
    cout << endl;
    inOrder(T);
    return 1;
}
