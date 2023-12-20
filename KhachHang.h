#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "Person.h"
#include <string>

class KhachHang : public Person {
private:
    int makh;
    int loaikh;
    KhachHang* next;

public:
    // Các phương thức getter và setter cho các thuộc tính
    int getMaKH() const {
        return makh;
    }

    void setMaKH(int maKH) {
        makh = maKH;
    }

    int getLoaiKH() const {
        return loaikh;
    }

    void setLoaiKH(int loaiKH) {
        loaikh = loaiKH;
    }

    KhachHang* getNext() const {
        return next;
    }

    void setNext(KhachHang* nextKH) {
        next = nextKH;
    }

    // Các phương thức xử lý khác nếu cần


// Các hàm xử lý với lớp KhachHang
int optionkh();
void themkh();
void luukh();
void xemdskh();
void timkh();
void xoakh();
void optionsuakh();
void suakhTEN();
void suakhSDT();
void suakhLOAIKH();
};
#endif // KHACHHANG_H