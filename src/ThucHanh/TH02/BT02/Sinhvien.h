#pragma once
#include <iostream>
#include <string>

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
NODE* CreateNode(Sinhvien data) {
    NODE* p;
    p = new NODE;
    // if (p == NULL)
    //     cout << "Het bo nho.";
    //     return NULL;
    p->info = data;
    p->pNext = NULL;
    return p;
}

// Add NODE vao dau LIST
void AddHead(LIST &L, NODE* p){
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

// 2.2 Nhap danh sach sinh vien
void NhapDS(LIST &L)
{
    Init(L);
    while (true)
    {
        Sinhvien data;
        cout << "Ho ten: ";
        getline(cin, data.ten);
        if (data.ten.length() == 0)
            break;
        cout << "MSSV: ";
        getline(cin, data.mssv);
        cout << "Diem TB: ";
        cin >> data.dtb;
        cin.ignore();
        NODE* p; 
        p = CreateNode(data);
        AddHead(L,p);
    }
}

// 2.3. Tim sinh vien
bool TimSinhVienByMSSV(LIST &L, string mssv){
    NODE* p;
    p = L.pHead;
    while (p != NULL){
        if (p->info.mssv == mssv)
            return true;
        p = p->pNext;
    }
    return false;
}
