#pragma once
#include "Sinhvien.h"
#include <iostream>

using namespace std;

// NODE
struct NODE {
    Sinhvien info;
    NODE* pNext;
};

// LIST
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

// Create an empty list
void Init(LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// Create a node, then return its address
NODE* CreateNode(Sinhvien data) {
    NODE* p;
    p = new NODE;
    if (p == NULL)
        cout << "Het bo nho.";
        return NULL;
    p->info = data;
    p->pNext = NULL;
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

// Count member of a list
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
bool RemoveHead(LIST &L, Sinhvien &data){
    NODE* p;
    if (L.pHead != NULL)
    {
        data = L.pHead->info;
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
        return 1; // Remove head successfully
    }
    return 0; // Empty list
}

// Delete a node after Q node
bool RemoveAfterQ(LIST &L, NODE *Q, Sinhvien &data)
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
            data = p->info;
            delete p;
        }
        return 1;
    }
    return 0;
}

// Delete last node
bool RemoveTail(LIST &L, Sinhvien &data)
{
    NODE* p;
    p = L.pHead;
    while (p->pNext->pNext != NULL){
        p = p->pNext;
    }
    if (RemoveAfterQ(L, p, data))
    {
        return 1;
    }
    return 0;
}

// Search node
NODE* SearchNode(LIST L, Sinhvien x) // NULL = NOT FOUND;
{
    NODE* p = L.pHead;
    while (p != NULL && p->info.mssv != x.mssv)
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
