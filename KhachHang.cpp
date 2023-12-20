#include "KhachHang.h"
#include <cstring>

KhachHang::KhachHang() {
    // Hàm khởi tạo mặc định, có thể không cần thực hiện gì đặc biệt nếu không có logic cụ thể
}

KhachHang::KhachHang(const char ten[], const char sdt[], const char diachi[]) {
    // Hàm khởi tạo có tham số
    strcpy(this->ten, ten);
    strcpy(this->sdt, sdt);
    strcpy(this->diachi, diachi);
}

const char* KhachHang::getTen() const {
    return ten;
}

const char* KhachHang::getSDT() const {
    return sdt;
}

const char* KhachHang::getDiaChi() const {
    return diachi;
}

void KhachHang::setTen(const char ten[]) {
    strcpy(this->ten, ten);
}

void KhachHang::setSDT(const char sdt[]) {
    strcpy(this->sdt, sdt);
}

void KhachHang::setDiaChi(const char diachi[]) {
    strcpy(this->diachi, diachi);
}
