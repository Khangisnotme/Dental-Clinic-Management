#include <iostream>
#include <cstring>
using namespace std;

class SanPham {
private:
    int masp;
    char ten[50];
    int gia;
    int sl;
    int slkho;
    SanPham* next;

public:
    // Các phương thức getter và setter cho các thuộc tính
    int getMaSP() const {
        return masp;
    }

    void setMaSP(int maSP) {
        masp = maSP;
    }

    const char* getTen() const {
        return ten;
    }

    void setTen(const char* tenSP) {
        strncpy(ten, tenSP, sizeof(ten) - 1);
        ten[sizeof(ten) - 1] = '\0';
    }

    int getGia() const {
        return gia;
    }

    void setGia(int giaSP) {
        gia = giaSP;
    }

    int getSL() const {
        return sl;
    }

    void setSL(int slSP) {
        sl = slSP;
    }

    int getSLKho() const {
        return slkho;
    }

    void setSLKho(int slKho) {
        slkho = slKho;
    }

    SanPham* getNext() const {
        return next;
    }

    void setNext(SanPham* nextSP) {
        next = nextSP;
    }

    // Các phương thức xử lý khác nếu cần


// Các hàm xử lý với lớp SanPham
    void optionkho();
    void themsp(SanPham* &sp);
    void luusp(SanPham* &sp);
    void capnhatsl();
    void xoasp();
    void timsp();
    void xuatdskho();
};