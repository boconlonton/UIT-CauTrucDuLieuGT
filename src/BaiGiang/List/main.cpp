#include "List.h"

using namespace std;

NODE* CreateNode1(int x) {
    NODE* p;
    p = new NODE;
    // if (p == NULL)
    //     cout << "Het bo nho.";
    //     return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

int main()
{
    LIST L;
    NODE* p1; 
    p1 = CreateNode1(5);
    NODE* p2; 
    p2 = CreateNode1(6);
    AddHead(L, p1);
    AddHead(L, p2);
    int kq = CountMember(L);
    cout << kq;
    return 1;
}


