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

// 2.2. In danh sach sinh vien
bool XuatDS(LIST &L){
    NODE* p;
    p = L.pHead;
    cout << "-----DANH SACH SINH VIEN-----" << endl;
    cout << "(Ho ten, MSSV, DTB)" << endl;
    while (p != NULL){
        cout << "(" << p->info.ten << ", "; 
        cout << p->info.mssv << ", ";
        cout << p->info.dtb << ")" << endl;
        p = p->pNext;
    }
    cout << "-----------------" << endl;
    return false;
}

// 2.3. Tim sinh vien
NODE* TimSinhVienByMSSV(LIST &L, string mssv){
    NODE* p;
    p = L.pHead;
    while (p != NULL){
        if (p->info.mssv == mssv)
            return p;
        p = p->pNext;
    }
    return NULL;
}

// 2.4. Xoa sinh vien
NODE* TimNODEBeforeMSSV(LIST &L, string mssv){
    NODE* p;
    p = L.pHead;
    while (p != NULL){
        if (p->pNext->info.mssv == mssv)
            return p;
        p = p->pNext;
    }
    return NULL;
}


bool RemoveAfterQ(LIST &L, NODE *Q)
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
            delete p;
        }
        return 1;
    }
    return 0;
}

// 2.5. Liet ke thong tin sinh vien co dtb >= 5
void ListSVgreaterThan5(LIST &L){
    NODE *p;
    p = L.pHead;
    while (p != NULL){
        if (p->info.dtb >= 5)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ")" << endl;
        }
        p = p->pNext;
    }
}

// 2.6. Xep loai va in ra thong tin sinh vien
void XepLoaiVaList(LIST &L){
    NODE *p;
    p = L.pHead;
    cout << "-----DANH SACH SINH VIEN-----" << endl;
    cout << "(Ho ten, MSSV, DTB, Xep loai)" << endl;
    while (p != NULL){
        if (p->info.dtb < 5)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Yeu" << ")" << endl;
        }
        else if (p->info.dtb >= 5 && p->info.dtb < 6.5)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Trung binh" << ")" << endl;
        }
        else if (p->info.dtb >= 6.5 && p->info.dtb < 7.0)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Trung binh Kha" << ")" << endl;
        }
        else if (p->info.dtb >= 7.0 && p->info.dtb < 8.0)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Kha" << ")" << endl;
        }
        else if (p->info.dtb >= 8.0 && p->info.dtb < 9.0)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Gioi" << ")" << endl;
        }
        else if (p->info.dtb >= 9.0 && p->info.dtb <= 10.0)
        {
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ", ";
            cout << "Xuat sac" << ")" << endl;
        }

        p = p->pNext;
    }
}

// 2.7. Sap xep theo diem trung binh
void SapXepTheoDTB(LIST &L){
    NODE* p;
    NODE* q;
    NODE* temp;
    p = L.pHead;
    while (p != NULL){
        q = p->pNext;
        while (q != NULL)
        {
            if (q->info.dtb > p->info.dtb)
            {
                temp = p;
                p = q;
                q = temp;
            }
            q = p->pNext;    
        }

        p = p->pNext;
    }
}
