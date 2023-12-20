#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>
#include "KhachHang.h"
#include "SanPham.h"

using namespace std;

class HoaDon {
private:
    int mahd;
    time_t tgian;
    KhachHang kh;
    SanPham sp;
    vector<int> a;
    vector<int> b;
    int tong;
    string ngay;
    HoaDon* next;

public:
    HoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a, vector<int>& b, int tongtien, const string& thu);
    void menu();
    void optionhd();
    void nhapHD();
    void xemHD();
    void luuHoaDon();
    void themHoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a, vector<int>& b, int tongtien, const string& thu);
};

#endif
