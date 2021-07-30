#pragma once
#include <iostream>

using namespace std;


// NODE structure
struct NODE {
    int info;
    NODE* pNext;
};

// Singly Linked List structure
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

// Create an empty list
// Khoi tao List
void Init(LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// Create a node, then return its address
// Chuyen du lieu x -> Node
NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    if (p == NULL)
        cout << "Het bo nho.";
        return NULL;
    p->info = x;
    p->pNext = NULL;
    cout << p->info;
    return p;
}

// Insert a node into the beginning of list
void AddHead(LIST &L, NODE* p){
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}


// Create a node & Insert it into the beginning of list
void AddHead(LIST &L, int x){
    NODE* p = CreateNode(x);
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

// Insert a node into the end of list
void AddTail(LIST &L, NODE* p){
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

// Insert a node after another node
void AddAfterQ(LIST &L, NODE* Q, NODE* p){
    if (Q != NULL)
    {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q)
        {
            L.pTail = p;
        }
    }
    else
    {
        AddHead(L, p); // Add p into the beginning of list since Q is NULL 
    }
}

// Print List
// Duyet list
void Travel(LIST &L){
    NODE* p;
    p = L.pHead;
    while (p != NULL){
        cout << p->info << "\t";
        p = p->pNext;
    }
}

// Dem phan tu trong list
int CountMember(LIST &L)
{
    NODE* p;
    int count;
    p = L.pHead;
    count = 0;
    while (p != NULL){
        count++;
        p = p->pNext;
    }
    return count;
}

// Delete a node at beginning of list
bool RemoveHead(LIST &L, int &x){
    NODE* p;
    if (L.pHead != NULL)
    {
        x = L.pHead->info;
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
        return 1; // Remove head successfully
    }
    return 0; // Empty list
}

// Delete a node after Q node
bool RemoveAfterQ(LIST &L, NODE *Q, int &x)
{
    NODE *p;
    if (Q != NULL)
    {
        p = Q->pNext; // p is targeted node
        if (p != NULL) // q is NOT last node
        {
            if (p == L.pTail) // targeted node is last node
            {
                L.pTail = Q; // pTail points to Q since Q now is last node
            }
            Q->pNext = Q->pNext->pNext;
            x = p->info;
            delete p;
        }
        return 1;
    }
    return 0;
}

// Delete last node
bool RemoveTail(LIST &L, int &x)
{
    NODE* p;
    p = L.pHead;
    while (p->pNext->pNext != NULL){
        p = p->pNext;
    }
    if (RemoveAfterQ(L, p, x))
    {
        return 1;
    }
    return 0;
}

// Search node
NODE* SearchNode(LIST L, int x) // NULL = NOT FOUND;
{
    NODE* p = L.pHead;
    while (p != NULL && p->info != x)
    {
        p = p->pNext;
    }
    return p;
}


// Remove list
void RemoveList(LIST &L)
{
    NODE* p;
    while (L.pHead != NULL)
    {
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
    }
    L.pTail = NULL;
}
