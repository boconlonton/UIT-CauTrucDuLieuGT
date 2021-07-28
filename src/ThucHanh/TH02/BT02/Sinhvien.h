#pragma once
#include <iostream>

using namespace std;

// Sinhvien
struct Sinhvien {
    string ten;
    string mssv;
    float dtb;
};

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

// Khoi tao LIST
void Init(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

// Tao NODE
NODE* CreateNode() {
    NODE* p;
    Sinhvien data;
    p = new NODE;
    if (p == NULL)
        cout << "Het bo nho.";
        return NULL;
    p->info = data;
    p->pNext = NULL;
    return p;
}

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
// Nhap danh sach sinh vien
void NhapDS(LIST &L)
{
    Init(L);
    do
    {
        NODE* p = CreateNode();
        cout << "Ho ten: ";
        cin >> p->info.ten;
        cin.ignore();
        cout << "MSSV: ";
        cin.ignore();
        cin >> p->info.mssv;
        cout << "Diem TB: ";
        cin >> p->info.dtb;
        AddHead(L, p);
    } while (L.pHead->info.ten != "");
}
