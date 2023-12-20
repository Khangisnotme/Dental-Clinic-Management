#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <ctime>
#include<sstream>
#include<cstring>
#include <cstdlib>

// Khai báo các file để thực hiện các tác vụ liên quan tới phần mềm
#include "Node.h"
#include "hoadon.h"
#include "hoadon.cpp"
#ifdef _WIN32
#include <windows.h>  // Thêm thư viện để sử dụng các hàm API của Windows
#endif
void optionchung();
using namespace std;

void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}
int main()
{

	optionchung();
    return 0;
}

void optionchung()
{
	int x=0;
	int chon;

	while (x!= 6)
	{
		cout<<"--------------------------- CA PHE MA CHE ---------------------------"<<endl;
		cout<<"1. Hoa don"<<endl;
		cout<<"2. Khach hang"<<endl;
		cout<<"3. Nhan vien"<<endl;
		cout<<"4. Kho"<<endl;
		cout<<"5. Doanh thu"<<endl;
		cout<<"6. Thoat chuong trinh"<<endl;

		cout<<"Nhap lua chon cua ban: ";
		cin>>x;
		switch(x)
		{
			case 1:
            system("cls");
			//optionhd();
            quanLyHoaDon();
			break;
			case 2:
            system("cls");
			//optionkh();
			break;
			case 3:
            system("cls");
			//optionnv();
			break;
			case 4:
            system("cls");
			//optionkho();
            break;
            case 5:
            system("cls");
            //optiondoanhthu();
            break;
			case 6:
            system("cls");
            setColor(10);  // Màu xanh lá cây
            cout<<endl;
            cout << "                           HE THONG XIN CHAO TAM BIET!!" << endl;
            setColor(7);  // Trả lại màu mặc định
            cout<< endl;
            cout<< endl;
			break;
			default:
			cout<<"Lua chon khong hop le!";
		}
	}
}

void quanLyHoaDon() {
    int slsp;
    int a[100];
    int b[100];
    HoaDon hoaDon;

    int chon;
    while (chon != 7) {
        cout << "-----------------------------------------QUAN LY HOA DON------------------------------------" << endl;
        cout << "1. Xem MENU." << endl;
        cout << "2. Them hoa don." << endl;
        cout << "3. Xem danh sach hoa don." << endl;
        cout << "4. Tim hoa don." << endl;
        cout << "5. Xoa hoa don." << endl;
        cout << "6. Sua hoa don." << endl;
        cout << "7. Quay lai man hinh chinh." << endl;

        cout << "Nhap lua chon : ";
        cin >> chon;

        switch (chon) {
        case 1:
            system("cls");
            hoaDon.menu();
            break;
        case 2:
            hoaDon.nhapHoaDon(slsp, a, b);
            break;
        case 3:
            hoaDon.xemDanhSachHoaDon();
            break;
        case 4:
            hoaDon.timHoaDon();
            break;
        case 5:
            hoaDon.xoaHoaDon();
            break;
        case 6:
            hoaDon.suaHoaDon();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Lua chon khong hop le!";
        }
    }
}
