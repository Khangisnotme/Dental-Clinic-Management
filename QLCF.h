#ifndef QLCF_H
#define QLCF_H
#include "HoaDon.h"
#include "KhachHang.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <ctime>
#include<sstream>
#include<cstring>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>  // Thêm thư viện để sử dụng các hàm API của Windows
#endif
#pragma once

class QuanLyCafe {
public:
    void optionChung();
    void optionHoaDon();
    void optionKhachHang();
    void optionNhanVien();
    void optionSanPham();


    void setColor(int color) {
        #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        #endif
}

    // Các phương thức quản lý khác...
};


#endif