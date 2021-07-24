#include "List.h"

using namespace std;

int main()
{
    LIST L;
    Init(L);
    AddTail(L, CreateNode(5));
    AddTail(L, CreateNode(6));
    Travel(L);
    return 1;
}
