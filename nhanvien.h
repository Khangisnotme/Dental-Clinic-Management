// nhanvien.h
#ifndef NHANVIEN_H
#define NHANVIEN_H
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class NhanVien : public Person {
private:
    int manv;
    string chucvu;
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

    const string& getChucVu() const {
        return chucvu;
    }

    void setChucVu(const string& chucVuNV) {
        chucvu = chucVuNV;
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

int optionnv();
void themnv();
void luunv();
void xemdsnv();
void capnhatlamviec();
void chamcongvatinhluong();
void xemluong1nv();
void xemluong1thang();
void timnv();
void xoanv();
void optionsuanv();
void suanvTEN();
void suanvSDT();
void suanvCHUCVU();
};
#endif // NHANVIEN_H