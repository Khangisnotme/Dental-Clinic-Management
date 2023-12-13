#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void xemLichHen() {
    ifstream file("lich_hen.txt"); // Mở file để đọc dữ liệu

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close(); // Đóng file sau khi đọc xong
    }
    else {
        cout << "Khong the mo file doc du lieu" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Dat lich hen" << endl;
        cout << "2. Xem lai lich hen" << endl;
        cout << "3. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // Bỏ qua kí tự '\n' còn lại trong bộ đệm
            string appointment;
            string email;
            string name;
            string dob;

            cout << "Hay nhap ngay hen ban muon: ";
            getline(cin, appointment);

            cout << "Nhap email: ";
            getline(cin, email);

            cout << "Nhap Ten: ";
            getline(cin, name);

            cout << "Nhap ngay thang nam sinh: ";
            getline(cin, dob);

            ofstream file("lich_hen.txt"); // Mở file để ghi dữ liệu

            if (file.is_open()) {
                file << " LICH HEN PHONG KHAM NHA KHOA" << endl;
                file << " =============================" << endl;
                file << "Lich hen da duoc dat vao ngay " << appointment << endl;
                file << "Email: " << email << endl;
                file << "Ten: " << name << endl;
                file << "Ngay thang nam sinh: " << dob << endl;

                file.close(); // Đóng file sau khi ghi xong
                cout << "Thong tin lich hen da duoc ghi vao file lich_hen.txt" << endl;
            }
            else {
                cout << "Khong the mo file ghi du lieu" << endl;
            }

            break;
        }
        case 2:
            xemLichHen();
            break;
        case 3:
            cout << "Ket thuc chuong trinh" << endl;
            break;
        default:
            cout << "Khong co lua chon hop le" << endl;
            break;
        }
        cout << endl;
    } while (choice != 3);
    

    return 0;
}