// HoaDon.cpp
#include "HoaDon.h"
#include <iostream>
#include <fstream>
using namespace std;


// Định nghĩa phương thức khởi tạo
HoaDon::HoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a, int b[], int tongtien, const std::string& thu)
    : mahd(mahd), slsp(slsp), tongtien(tongtien), thu(thu) {
    strcpy(this->kh.ten, tenkh);
    strcpy(this->kh.sdt, sdtkh);
    strcpy(this->kh.diachi, dckh);
    for (int i = 0; i < slsp; i++) {
        this->a[i] = a[i];
        this->b[i] = b[i];
    }
}


void HoaDon::menu() {
    cout << "                                            CA PHE MA CHE                                    " << endl;
    cout << endl;
    cout << " ----------------------------------------------  MENU  ----------------------------------------------" << endl;
    cout << setw(20) << left << "MA SP" << setw(60) << left << "            TEN SAN PHAM          " << setw(20) << left << "GIA TIEN (VND)" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                           1. COFFEE PHIN                                               /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "11" << setw(60) << left << "Phin sua da " << setw(20) << left << "39000" << endl;
    cout << setw(20) << left << "12" << setw(60) << left << "Phin den da " << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "13" << setw(60) << left << "Bac xiu " << setw(20) << left << "39000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        2. PHINDI                                      /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "14" << setw(60) << left << "Phindi hanh nhan" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "15" << setw(60) << left << "Phindi kem sua" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "16" << setw(60) << left << "Phindi choco" << setw(20) << left << "49000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        3. ESPRESSO                                     /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "21" << setw(60) << left << "Espresso" << setw(20) << left << "49000" << endl;
    cout << setw(20) << left << "31" << setw(60) << left << "Cappuchino " << setw(20) << left << "75000" << endl;
    cout << setw(20) << left << "32" << setw(60) << left << "Mocha " << setw(20) << left << "79000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        4. BANH MI QUE                                       /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "33" << setw(60) << left << "Que Pate " << setw(20) << left << "19000" << endl;
    cout << setw(20) << left << "41" << setw(60) << left << "Que Ga Pho Mai" << setw(20) << left << "19000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                        5. TRA                                         /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "42" << setw(60) << left << "Tra Sen Vang" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "43" << setw(60) << left << "Tra thach dao" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "51" << setw(60) << left << "Tra thanh dao" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "52" << setw(60) << left << "Tra thach vai" << setw(20) << left << "55000" << endl;
    cout << setw(20) << left << "53" << setw(60) << left << "Tra xanh dau do" << setw(20) << left << "55000" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "/                                          6. BANH                                  /" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "61" << setw(60) << left << "Banh pho mai chanh day" << setw(20) << left << "29000" << endl;
    cout << setw(20) << left << "62" << setw(60) << left << "Banh pho mai caphe" << setw(20) << left << "29000" << endl;
    cout << setw(20) << left << "63" << setw(60) << left << "Tiramisu" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "64" << setw(60) << left << "Mousse dao" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "65" << setw(60) << left << "Mousse cacao" << setw(20) << left << "35000" << endl;
    cout << setw(20) << left << "66" << setw(60) << left << "Banh chuoi" << setw(20) << left << "29000" << endl;

}


void HoaDon::nhapHD(HoaDon* dshd, int& slsp, vector<int> a, vector<int> b) {
    int x;
    int slsp;
    int mahd;
    char tenkh[40];
    char dckh[100];
    char sdtkh[12];
    int masp;
    int sl;
    int tongtien = 0;
    int slkho;
    
    cout << "Nhap ma hoa don: ";
    cin >> mahd;
    cout << "Nhap ten khach hang: ";
    cin.ignore();
    cin.getline(tenkh, 40);
    cout << "Nhap sdt khach hang: ";
    cin.getline(sdtkh, 12);
    cout << "Nhap dia chi cua khach hang: ";
    cin.getline(dckh, 100);
    cout << "So luong loai san pham ma ban muon chon la: ";
    cin >> slsp;
    
    for (int i = 0; i < slsp; i++) {
        cout << "Nhap loai san pham thu " << i + 1 << ": ";
        cin >> masp;
        a[i] = masp;
        // Thêm yêu cầu nhập số lượng sau khi nhập mã sản phẩm
        cout << "Nhap so luong cua loai san pham nay: ";
        cin >> sl;


        ifstream file;
        file.open("kho.txt");
        ofstream ghi;
        ghi.open("temp.txt", ios::app);
        string line;
        bool tim = false;
        while (getline(file, line)) {
            if (line == "Ma so: " + to_string(masp)) {
                tim = true;
            }
            if (line.find("So luong: ") != string::npos && tim) {
                string sl_kho = line.substr(10, 2);
                slkho = stoi(sl_kho);
                cout << "So luong co trong kho: " << slkho << endl;
                cin.clear();
                cout << "Nhap so luong: ";
                cin >> sl;
                while (sl > slkho) {
                    cout << "So luong trong kho khong du! Vui long nhap lai: ";
                    cin >> sl;
                }
                b[i] = sl;
                ghi << "So luong: " << sl << endl;

            }
            else
            {
                ghi << line << endl;
            }
            if (line.find("--------------------------------------------------------") != string::npos && tim)
            {
                tim = false;
            }
        }
        file.close();
        ghi.close();
        remove("kho.txt");
        rename("temp.txt","kho.txt");

        switch (masp) {
        case 11:
            tongtien += 39000 * sl;
            break;
        case 12:
            tongtien += 35000 * sl;
            break;
        case 13:
            tongtien += 39000 * sl;
            break;
        case 14:
            tongtien += 49000 * sl;
            break;
        case 15:
            tongtien += 49000 * sl;
            break;
        case 16:
            tongtien += 49000 * sl;
            break;
        case 21:
            tongtien += 49000 * sl;
            break;
        case 31:
            tongtien += 79000 * sl;
            break;
        case 32:
            tongtien += 79000 * sl;
            break;
        case 33:
            tongtien += 19000 * sl;
            break;
        case 41:
            tongtien += 19000 * sl;
            break;
        case 42:
            tongtien += 55000 * sl;
            break;
        case 43:
            tongtien += 55000 * sl;
            break;
        case 51:
            tongtien += 55000 * sl;
            break;
        case 52:
            tongtien += 55000 * sl;
            break;
        case 53:
            tongtien += 55000 * sl;
            break;
        case 61:
            tongtien += 29000 * sl;
            break;
        case 62:
            tongtien += 29000 * sl;
            break;
        case 63:
            tongtien += 35000 * sl;
            break;
        case 64:
            tongtien += 35000 * sl;
            break;
        case 65:
            tongtien += 35000 * sl;
            break;
        case 66:
            tongtien += 29000 * sl;
            break;
        default:
            cout << "Lua chon khong hop le!";
            break;
        }
    }
    
    cout << "---------------------- Tong hoa don: " << tongtien << "---------------------------" << endl;

    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    string thu = ss.str();

    themHoaDon(mahd, tenkh, sdtkh, dckh, slsp, a, b, tongtien, thu);
    
    
}
void HoaDon::themHoaDon(int mahd, const char tenkh[], const char sdtkh[], const char dckh[], int slsp, vector<int>& a, vector<int>& b, int tongtien, const string& thu); {
    HoaDon* p = new HoaDon;
    p->mahd = mahd;
    // Copy thông tin khách hàng vào hóa đơn
    strcpy(p->kh.ten, tenkh);
    strcpy(p->kh.sdt, sdtkh);
    strcpy(p->kh.diachi, dckh);
    p->tong = tongtien;
    strcpy(p->ngay, thu.c_str());
    p->sp.sl = slsp;
    for (int i = 0; i < slsp; i++) {
        p->sp.masp = a[i];
        p->a[i] = p->sp.masp;
        p->sp.sl = b[i];
        p->b[i] = p->sp.sl;
    }
    p->next = NULL;

    if (next == NULL) {
        next = p; // Cập nhật con trỏ next để trỏ tới nút đầu tiên
    }
    else {
        HoaDon* q = this;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }

    luuHoaDon();
}

void HoaDon::optionxemhd() {
    // Triển khai phương thức optionxemhd ở đây
}

void HoaDon::timhd() {
    // Triển khai phương thức timhd ở đây
}

void HoaDon::xoahd() {
    // Triển khai phương thức xoahd ở đây
}

void HoaDon::optionsuahd(HoaDon* dshd, int mssua, int slsp) {
    // Triển khai phương thức optionsuahd ở đây
}

void HoaDon::optionhd() {
    // Triển khai phương thức optionhd ở đây
}