// hoadon.h
#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Node.h"
#include "khach.h"
#include "sanpham.h"
using namespace std;

class HoaDon {
    private:
        Node* head;
        int mahd;
        time_t tgian;
        KhachHang kh;
        SanPham sp;
        int a[100];
        int b[100];
        int tong;
        char ngay[200];
        HoaDon* next;

    public:
    // Các phương thức

        HoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, int a[], int b[], int tongtien, const string& thu);
    
        void nhapHoaDon();
    
        void luuHoaDon();
    
        static void timHoaDon();
    
        static void optionXemHoaDon();
    
        static void xoaHoaDon();
    
        static void luuKhiSauKhiXoaHoaDon();
    
        void suaHoaDonTenKhachHang();
    


    // Thêm các phương thức sửa thông tin khác nếu cần
};

#endif // HOADON_H
