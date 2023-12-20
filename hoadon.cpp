// hoadon.cpp
#include "hoadon.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

HoaDon::HoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, int a[], int b[], int tongtien, const string& thu)
    : mahd(mahd), slsp(slsp), tongtien(tongtien), thu(thu) {
    strcpy(this->tenkh, tenkh);
    strcpy(this->sdtkh, sdtkh);
    strcpy(this->dckh, dckh);
    for (int i = 0; i < slsp; i++) {
        this->a[i] = a[i];
        this->b[i] = b[i];
    }
}
HoaDon() : next(nullptr) {}
void HoaDon::nhapHoaDon(){
        cout << "Nhap ma hoa don: ";
        cin >> mahd;

        cout << "Nhap ten khach hang: ";
        cin.ignore();
        cin.getline(kh.ten, 40);

        cout << "Nhap so dien thoai khach hang: ";
        cin.getline(kh.sdt, 12);

        cout << "Nhap dia chi khach hang: ";
        cin.getline(kh.diachi, 100);

        cout << "Nhap so luong san pham: ";
        int slsp;
        cin >> slsp;

        for (int i = 0; i < slsp; i++) {
            cout << "Nhap ma san pham " << i + 1 << ": ";
            cin >> a[i];

            cout << "Nhap so luong san pham " << i + 1 << ": ";
            cin >> b[i];
        }

        // Thực hiện các thao tác khác tại đây nếu cần

        // Sau khi nhập, bạn có thể gọi các phương thức khác của lớp HoaDon hoặc lưu thông tin vào file, database, v.v.
    }

    // Các phương thức khác của lớp HoaDon có thể được định nghĩa ở đây


void HoaDon::luuHoaDon() {
    // Bạn có thể chuyển đoạn mã lưu hoá đơn vào đây
}

void HoaDon::xemHoaDonTheoGiaTang() {
    // Bạn có thể chuyển đoạn mã xem hoá đơn theo giá tăng vào đây
}

void HoaDon::xemHoaDonTheoGiaGiam() {
    // Bạn có thể chuyển đoạn mã xem hoá đơn theo giá giảm vào đây
}

void HoaDon::timHoaDon() {
    // Bạn có thể chuyển đoạn mã tìm hoá đơn vào đây
}

void HoaDon::optionXemHoaDon() {
    // Bạn có thể chuyển đoạn mã menu xem hoá đơn vào đây
}

void HoaDon::xoaHoaDon() {
    // Bạn có thể chuyển đoạn mã xóa hoá đơn vào đây
}

void HoaDon::luuKhiSauKhiXoaHoaDon() {
    // Bạn có thể chuyển đoạn mã lưu khi sau khi xóa hoá đơn vào đây
}

void HoaDon::suaHoaDonTenKhachHang() {
    // Bạn có thể chuyển đoạn mã sửa hoá đơn (tên khách hàng) vào đây
}
 void HoaDon::menu(){
    cout << "                                            CA PHE MA CHE                                    " << endl;
    cout << endl;
    cout << " ----------------------------------------------  MENU  ----------------------------------------------" << endl;
    cout << setw(20) << left << "MA SP" << setw(60) << left << "            TEN SAN PHAM          " << setw(20) << left << "GIA TIEN (VND)" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                           1. COFFEE PHIN                                               /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "11" << setw(60) << left << "Phin sua da " << setw(20) << left << "39000" << endl;
    cout << setw(20) << left << "12" << setw(60) << left << "Phin den da " << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "13" << setw(60) << left << "Bac xiu " << setw(20) << left << "39000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        2. PHINDI                                      /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "14" << setw(60) << left << "Phindi hanh nhan" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "15" << setw(60) << left << "Phindi kem sua" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "16" << setw(60) << left << "Phindi choco" << setw(20) << left << "49000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        3. ESPRESSO                                     /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "21" << setw(60) << left << "Espresso" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "31" << setw(60) << left << "Cappuchino " << setw(20) << left << "75000" << endl;
    cout << setw(20) << left << "32" << setw(60) << left << "Mocha " << setw(20) << left << "79000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        4. BANH MI QUE                                       /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "33" << setw(60) << left << "Que Pate " << setw(20) << left << "19000" << endl;
    cout << setw(20) << left << "41" << setw(60) << left << "Que Ga Pho Mai" << setw(20) << left << "19000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        5. TRA                                         /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "42" << setw(60) << left << "Tra Sen Vang" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "43" << setw(60) << left << "Tra thach dao" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "51" << setw(60) << left << "Tra thanh dao" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "52" << setw(60) << left << "Tra thach vai" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "53" << setw(60) << left << "Tra xanh dau do" << setw(20) << left << "55000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                          6. BANH                                  /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "61" << setw(60) << left << "Banh pho mai chanh day" << setw(20) << left << "29000" << endl;
    cout << setw(20) << left << "62" << setw(60) << left << "Banh pho mai caphe" << setw(20) << left << "29000" << endl;
    cout << setw(20) << left << "63" << setw(60) << left << "Tiramisu" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "64" << setw(60) << left << "Mousse dao" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "65" << setw(60) << left << "Mousse cacao" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "66" << setw(60) << left << "Banh chuoi" << setw(20) << left << "29000" << endl;

}

