#pragma once
#include <iostream>

using namespace std;

struct DonThuc{
    float heso;
    int somu;
};

struct DaThuc{
    DonThuc A[50];
    int so_don_thuc;
    int bac;
};

// 3a. Nhap/Xuat da thuc
DonThuc NhapDonThuc(DonThuc so_hang){
    cout << "\tNhap he so: ";
    cin >> so_hang.heso;
    cout << "\tNhap so mu: ";
    cin >> so_hang.somu;
    return so_hang;
}

void XuatDonThuc(DonThuc so_hang){
    cout << so_hang.heso << "x" << so_hang.somu;
}

void NhapDaThuc(DaThuc &da_thuc){
    int so_don_thuc;
    cout << "Nhap so luong don thuc: ";
    cin >> da_thuc.so_don_thuc;
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        DonThuc temp;
        cout << "So hang thu " << i + 1 << ": " << endl;
        da_thuc.A[i] = NhapDonThuc(temp);
    }
}

void XuatDaThuc(DaThuc da_thuc){
    cout << "P(x) = ";
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        XuatDonThuc(da_thuc.A[i]);
        if (i != da_thuc.so_don_thuc - 1){
            cout << " + ";
        }
    }
}

// 3b. Tim bac da thuc, Sap xep da thuc
void SapXepDaThuc(DaThuc &da_thuc){
    DonThuc temp;
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        temp = da_thuc.A[i];
        for (int j = i; j < da_thuc.so_don_thuc; j++)
        {
            if (da_thuc.A[j].somu > da_thuc.A[i].somu){
                da_thuc.A[i] = da_thuc.A[j];
                da_thuc.A[j] = temp;
                temp = da_thuc.A[i];
            }
        }    
    }
}

// 3c. Tinh gia tri da thuc
int TinhLuyThua(int x, int so_mu){
    int ket_qua;
    ket_qua = 1;
    for (int i = 0; i < so_mu; i++){
        ket_qua *= x;
    }
    return ket_qua;
}

int TinhGiaTriDaThuc(DaThuc da_thuc, int x){
    int gia_tri;
    int he_so;
    int so_mu;
    gia_tri = 0;
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        he_so = da_thuc.A[i].heso;
        so_mu = da_thuc.A[i].somu;
        gia_tri += he_so * TinhLuyThua(x, so_mu);
    }
    return gia_tri;    
}

// 3d. Cong, tru, nhan 2 da thuc

