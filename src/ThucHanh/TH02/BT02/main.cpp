#include "Sinhvien.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    LIST danhSachSV;
    LIST danhSachSV_copied;
    NODE* p; 
    Sinhvien data;
    string mssv_search;
    string control_program;
    int control_function;
    NhapDS(danhSachSV);
    XuatDS(danhSachSV);
    while (true)
    {
        cout << "(3) Tim sinh vien (theo MSSV)." << endl;
        cout << "(4) Xoa 1 sinh vien (theo mssv)." << endl;
        cout << "(5) Liet ke sinh vien co DTB >= 5." << endl;
        cout << "(6) Xep loai va in ra thong tin sinh vien." << endl;
        cout << "(7) Sap xep va in ra danh sach theo DTB." << endl;
        cout << "(8) Chen 1 SV vao danh sach." << endl;
        cout << "Chon tu 3 -> 8: ";
        cin >> control_function;
        switch (control_function)
        {
        case 3:
            // 2.3. Tim Sinh vien
            cout << "Nhap MSSV: ";
            cin.ignore();
            getline(cin, mssv_search);
            p = TimSinhVienByMSSV(danhSachSV, mssv_search);
            if (p != NULL)
            {
                cout << "(" << p->info.ten << ", "; 
                cout << p->info.mssv << ", ";
                cout << p->info.dtb << ")" << endl;
            }
            else
            {
                cout << "Khong ton tai." << endl;
            }
            break;
        
        case 4:
            // 2.4. Xoa sinh vien dua tren mssv
            danhSachSV_copied = danhSachSV;
            cout << "Nhap MSSV: ";
            cin.ignore();
            getline(cin, mssv_search);
            if (XoaMSSV(danhSachSV_copied, mssv_search))
            {
                XuatDS(danhSachSV_copied);
            }
            else
            {
                cout << "Khong ton tai." << endl;
            }
            break;
        
        case 5:
            ListSVgreaterThan5(danhSachSV);
            break;
        
        case 6:
            danhSachSV_copied = danhSachSV;
            XepLoaiVaList(danhSachSV_copied);
            break;
        
        case 7:
            danhSachSV_copied = danhSachSV;
            SapXepTheoDTB(danhSachSV_copied);
            XuatDS(danhSachSV_copied);
            break;
        
        case 8:
            cin.ignore();
            danhSachSV_copied = danhSachSV;
            SapXepTheoDTB(danhSachSV_copied);
            cout << "Ho ten: ";
            getline(cin, data.ten);
            cout << "MSSV: ";
            cin.ignore();
            getline(cin, data.mssv);
            cout << "Diem TB: ";
            cin >> data.dtb;
            p = CreateNode(data);
            ChenGiuNguyenThuTu(danhSachSV_copied, p);
            XuatDS(danhSachSV_copied);
            break;
        
        default:
            break;
        
        }
        cout << "Tiep tuc (y/n) ? ";
        cin >> control_program;
        if (control_program == "n")
        {
            cout << "Cam on ban da su dung chuong trinh.";
            break;
        }
    }
    return 1;
}
