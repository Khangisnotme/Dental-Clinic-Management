// nhanvien.h
#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <fstream>

using namespace std;



class NhanVien {
private:
    int manv;
    char ten[30];
    char chucvu[20];
    char sdt[12];
    time_t chamcong;
    bool lamviec;
    NhanVien* next;

public:
    // Các phương thức getter và setter cho các thuộc tính
    int getMaNV() const {
        return manv;
    }

    void setMaNV(int maNV) {
        manv = maNV;
    }

    const char* getTen() const {
        return ten;
    }

    void setTen(const char* tenNV) {
        strncpy(ten, tenNV, sizeof(ten) - 1);
        ten[sizeof(ten) - 1] = '\0';
    }

    const char* getChucVu() const {
        return chucvu;
    }

    void setChucVu(const char* chucVuNV) {
        strncpy(chucvu, chucVuNV, sizeof(chucvu) - 1);
        chucvu[sizeof(chucvu) - 1] = '\0';
    }

    const char* getSDT() const {
        return sdt;
    }

    void setSDT(const char* sdtNV) {
        strncpy(sdt, sdtNV, sizeof(sdt) - 1);
        sdt[sizeof(sdt) - 1] = '\0';
    }

    time_t getChamCong() const {
        return chamcong;
    }

    void setChamCong(time_t chamCong) {
        chamcong = chamCong;
    }

    bool getLamViec() const {
        return lamviec;
    }

    void setLamViec(bool lamViec) {
        lamviec = lamViec;
    }

    NhanVien* getNext() const {
        return next;
    }

    void setNext(NhanVien* nextNV) {
        next = nextNV;
    }

    // Các phương thức xử lý khác nếu cần
};

// Các hàm xử lý với lớp NhanVien
int optionnv();
void themnv();
void luunv();
void xemdsnv();
void capnhatlamviec();
void chamcongvatinhluong();
void xembangluong();
void xemluong1nv();
void xemluong1thang();
void timnv();
void xoanv();
void optionsuanv();
void suanvTEN();
void suanvSDT();
void suanvCHUCVU();

#endif // NHANVIEN_H
