#include "QLCF.h"
#include <iostream>
using namespace std;

void QuanLyCafe::optionHoaDon(){
        HoaDon hoaDon;
        hoaDon.optionhd();
}
void QuanLyCafe::optionKhachHang(){
    KhachHang khachhang2;
    khachhang2.optionkh();
}
void QuanLyCafe::optionChung() {
    int x = 0;

    while (x != 6) {
        cout << "--------------------------- CA PHE MA CHE ---------------------------" << endl;
        cout << "1. Hoa don" << endl;
        cout << "2. Khach hang" << endl;
        cout << "3. Nhan vien" << endl;
        cout << "4. Kho" << endl;
        cout << "5. Doanh thu" << endl;
        cout << "6. Thoat chuong trinh" << endl;

        cout << "Nhap lua chon cua ban: ";
        cin >> x;

        switch (x) {
            case 1:
                system("cls");
                optionHoaDon();
                break;
            case 2:
                system("cls");
                optionKhachHang();
                break;
            case 3:
                system("cls");
                optionNhanVien();
                break;
            case 4:
                system("cls");
                optionSanPham();
                break;
            case 5:
                system("cls");
                // optionDoanhThu();
                break;
            case 6:
                system("cls");
                setColor(10);  // Màu xanh lá cây
                cout<<endl;
                cout << "                           HE THONG XIN CHAO TAM BIET!!" << endl;
                setColor(7);  // Trả lại màu mặc định
                cout<< endl;
                cout<< endl;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }
}
