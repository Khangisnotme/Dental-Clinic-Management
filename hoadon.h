#ifndef HOADON_H
#define HOADON_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "KhachHang.h"
#include "SanPham.h"
using namespace std;
class HoaDon {
private:
    int masp;
    int sl;
    int slsp;
    
    int tongtien;

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
    HoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a,vector<int>& b, int tongtien, const string& thu);
    void menu();
    void optionhd();
    void nhapHD();
    void luuhd();
    void themHoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a, vector<int>& b, int tongtien, const string& thu);
};


#endif