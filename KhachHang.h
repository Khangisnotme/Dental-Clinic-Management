#ifndef KHACHHANG_H
#define KHACHHANG_H

#pragma once

class KhachHang {
private:
    char ten[40];
    char sdt[12];
    char diachi[200];

public:
    KhachHang(); // Hàm khởi tạo mặc định
    KhachHang(const char ten[], const char sdt[], const char diachi[]); // Hàm khởi tạo có tham số

    // Các hàm thành viên để truy cập thông tin khách hàng
    const char* getTen() const;
    const char* getSDT() const;
    const char* getDiaChi() const;

    // Các hàm thành viên để cập nhật thông tin khách hàng
    void setTen(const char ten[]);
    void setSDT(const char sdt[]);
    void setDiaChi(const char diachi[]);
    static void optionkh();
};


#endif