#include <iostream>//cin,cout
#include <string>//stoi, string
#include <algorithm>
#include <set>//pair,make_pair
#include <cstdlib> // Thư viện cstdlib để sử dụng hàm rand() và srand()
#include <ctime> // Thư viện ctime để sử dụng hàm time()
#include <vector>
#include <cctype>//toupper
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>//setw
#include <limits>//ignore(numeric_limits<streamsize>::max(), '\n'), INT_MAX, INT_MIN
#include <sstream>

using namespace std;
using namespace this_thread;
using namespace chrono;

// Các khai báo cấu trúc dữ liệu và hàm đã cho
struct Product {
    string name;
    int price = 0;
};

Product products[5] = {
    {"Ao khoac", 10000},
    {"Non", 20000},
    {"Quan tay", 30000},
    {"Ao somi", 40000},
    {"Quan the thao", 50000}
};

struct Address {
    string city;
    string district;
    string street;
};

struct Customer {
    string id;
    string firstName;
    string lastName;
    string phoneNumber = "0";
    Address address;
    vector<pair<Product, int>> products;
};

struct Node {
    Customer data;
    Node* next = nullptr;
    Node* pre = nullptr;
};


struct DouList {
    Node* head = nullptr;
    Node* tail = nullptr;
    set<int> usedIds;
};

DouList* createList(Customer x) {
    DouList* l = new DouList;
    l->head = new Node;
    l->head->data = x;
    l->head->pre = l->head; // trỏ về chính nó
    l->head->next = l->head; // trỏ về chính nó
    l->tail = l->head;
    return l;
}

//KHỞI TẠO CÁC HÀM
string ones[] = { "", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin" };
string thousands[] = { "", "nghin", "trieu", "ty" };
string capitalize(string str);
string convertThreeDigits(int num);
string convertNumberToWords(long long num);
void nhapDiaChi(Address& address);
void inDiaChi(const Address& address);
void nhapDanhSach(DouList* l);
void inDanhSach(DouList* l);
void timKiemTheoHoTen(DouList* l);
void chenKhachHang(DouList* l, string maSoChiDinh);
bool xoaKhachHang(DouList* l, string maSoChiDinh);
void xoaTatCaKhachHang(DouList* l);
void quickSort(DouList* l, Node* leftNode, Node* rightNode);
void sapXepTheoMaSo(DouList* l);
void sapXepTheoTen(DouList* l);
void chinhSuaDonHang(DouList* l, string maSo);
void xuatDanhSachRaFILE(DouList* l, const string& fileName);
void thongKeSanPham(DouList* l);
void thongKeSanPhamFILE(DouList* l, ostream& os);
void docDanhSachTuFILE(DouList* l, const string& fileName);
void inThongBao();

//HÀM MAIN 
int main() {
    DouList* danhSachKhachHang = createList(Customer());

    char choice;
    do {
        inThongBao();

        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 'a': {
            char subChoice;
            do {
                system("cls");
                cout << "Ban co muon tiep tuc nhap danh sach (y) hoac quay lai menu chinh (m)? ";
                cin >> subChoice;
                if (subChoice == 'y' || subChoice == 'Y') {
                    nhapDanhSach(danhSachKhachHang);
                }
            } while (subChoice == 'y' || subChoice == 'Y');
            if (subChoice == 'm' || subChoice == 'M') {
                system("cls");
            }
            break;
        }

        case 'b':
            system("cls");
            inDanhSach(danhSachKhachHang);
            break;
        case 'c': {
            system("cls");
            if (danhSachKhachHang->head->next == danhSachKhachHang->head) {
                cout << "Danh sach khach hang rong." << endl;
            }
            else {
                timKiemTheoHoTen(danhSachKhachHang);
            }
            break;
        }
        case 'd': {
            system("cls");
            if (danhSachKhachHang->head->next == danhSachKhachHang->head) {
                cout << "Danh sach khach hang rong." << endl;
            }
            else {
                inDanhSach(danhSachKhachHang);
                string maSoChiDinh;
                cout << "Nhap vi tri can chen sau ma so (hoac nhap 'q' de quay lai menu chinh): ";
                cin >> maSoChiDinh;
                if (maSoChiDinh == "q" || maSoChiDinh == "Q") {
                    break;
                }
                chenKhachHang(danhSachKhachHang, maSoChiDinh);
            }
            break;
        }

        case 'e': {
            system("cls");
            if (danhSachKhachHang->head->next == danhSachKhachHang->head) {
                cout << "Danh sach khach hang rong." << endl;
            }
            else {
                inDanhSach(danhSachKhachHang);
                string maSoChiDinh;
                cout << "Nhap ma so cua khach hang can xoa (hoac nhap 'q' de quay lai menu chinh): ";
                cin >> maSoChiDinh;
                if (maSoChiDinh == "q" || maSoChiDinh == "Q") {
                    break;
                }
                if (xoaKhachHang(danhSachKhachHang, maSoChiDinh)) {
                    cout << "Da xoa thanh cong khach hang co ma so: " << maSoChiDinh << endl;
                }
                else {
                    cout << "Khong tim thay khach hang co ma so: " << maSoChiDinh << endl;
                }
            }
            break;
        }
        case 'f':
            system("cls");
            sapXepTheoMaSo(danhSachKhachHang);
            break;
        case 'g':
            system("cls");
            sapXepTheoTen(danhSachKhachHang);
            break;

        case 'h': {
            system("cls");
            if (danhSachKhachHang->head->next == danhSachKhachHang->head) {
                cout << "Danh sach khach hang rong." << endl;
            }
            else {
                inDanhSach(danhSachKhachHang);
                string maSoChiDinh;
                cout << "Nhap ma so cua khach hang can chinh sua (hoac nhap 'q' de quay lai menu chinh): ";
                cin >> maSoChiDinh;
                if (maSoChiDinh == "q" || maSoChiDinh == "Q") {
                    break;
                }
                chinhSuaDonHang(danhSachKhachHang, maSoChiDinh);
            }
            break;
        }
        case 'i':
            system("cls");
            thongKeSanPham(danhSachKhachHang);
            char exportChoice;  
            cout << "BAN CO MUON XUAT DANH SACH KHACH HANG RA FILE KHONG ? (y/n) (bam q de quay ve lai menu): ";
            cin >> exportChoice;

            if (exportChoice == 'q' || exportChoice == 'Q') {
                break;
            }

            if (exportChoice == 'y' || exportChoice == 'Y') {
                string fileName;
                cout << "Nhap ten file: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, fileName);

                while (true) {
                    xuatDanhSachRaFILE(danhSachKhachHang, fileName);
                    char anotherChoice;
                    cout << "Ban co muon nhap ten file khac khong? (y/n): ";
                    cin >> anotherChoice;
                    if (anotherChoice != 'y' && anotherChoice != 'Y') {
                        break;
                    }

                    cout << "Nhap ten file: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, fileName);
                }
            }
            xoaTatCaKhachHang(danhSachKhachHang);
            cout << endl;
            break;
        case 'j':
            system("cls");
            for (int i = 0; i < 5; i++) {
                cout << "\033[33m                          TAM BIET!\033[0m" << endl;
                sleep_for(milliseconds(500));
                system("CLS");
                cout << endl;
                cout << "\033[32m                          TAM BIET!\033[0m" << endl;
                sleep_for(milliseconds(500));
                system("CLS");
            }
            break;
        case 'k': {
            system("cls");
            char subChoice;
            cout << "1. Gop nhieu hoa don." << endl;
            cout << "2. Sua lai 1 hoa don duy nhat." << endl;
            cout << "Lua chon cua ban (nhap 'q' de quay ve menu): ";
            cin >> subChoice;

            if (subChoice == 'q' || subChoice == 'Q') {
                break; // Quay về menu chính nếu người dùng nhập 'q'
            }
            else if (subChoice == '1') { // Không xóa khách hàng
                string fileName;
                cout << "Nhap ten file: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, fileName);
                docDanhSachTuFILE(danhSachKhachHang, fileName); 
            }
            else if (subChoice == '2') { // Xóa khách hàng
                xoaTatCaKhachHang(danhSachKhachHang);
                string fileName;
                cout << "Nhap ten file: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, fileName);
                docDanhSachTuFILE(danhSachKhachHang, fileName); 
            }
            else {
                cout << "Lua chon khong hop le." << endl;
            }
            break;
        }



        default:
            system("cls");
            cout << "Lua chon khong hop le. Moi ban chon lai." << endl;
            break;
        }
    } while (choice != 'j');

    return 0;
}

// HÀM NHẬP THÔNG TIN ĐỊA CHỈ
void nhapDiaChi(Address& address) {
    cout << "Dia chi:" << endl;
    cout << "TP: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, address.city);
    transform(address.city.begin(), address.city.end(), address.city.begin(), ::toupper);
    cout << "Quan/huyen: ";
    getline(cin, address.district);
    transform(address.district.begin(), address.district.end(), address.district.begin(), ::toupper);
    cout << "Duong/Phuong: ";
    getline(cin, address.street);
    transform(address.street.begin(), address.street.end(), address.street.begin(), ::toupper);
}

// HÀM IN THÔNG TIN ĐỊA CHỈ
void inDiaChi(const Address& address) {
    cout << "Dia chi: " << address.street << ", " << address.district << ", " << address.city << endl;
}

// HÀM NHẬP DANH SÁCH KHÁCH HÀNG TỪ NGƯỜI DÙNG
void nhapDanhSach(DouList* l) {
    Customer khachHang;
    cout << "Nhap thong tin khach hang:" << endl;

    // Tạo mã ID ngẫu nhiên
    srand(time(0));
    int id;
    do {
        id = rand() % 1000;
    } while (l->usedIds.count(id) > 0);
    l->usedIds.insert(id);

    khachHang.id = to_string(id);
    cout << "ID: " << khachHang.id << endl;
    cout << "Ho va ten dem: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, khachHang.firstName);
    cout << "Ten: ";
    getline(cin, khachHang.lastName);
    cout << "SDT: ";
    cin >> khachHang.phoneNumber;
    nhapDiaChi(khachHang.address);

    // In bảng sản phẩm
    cout << "Danh sach san pham:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") " << products[i].name << ", Gia: " << products[i].price << endl;
    }

    char input;
    cout << "(nhap q de hoan thanh viec nhap)" << endl;
    do {
        int productCode;
        cout << "Ma san pham (1-5): ";
        while (true) {
            cin >> input;
            if (input == 'q') break;
            productCode = input - '0';
            if (productCode >= 1 && productCode <= 5) {
                break;
            }
            else {
                cout << "Ma san pham khong hop le. Xin moi nhap lai." << endl;
                cout << "Ma san pham (1-5): ";
            }
        }

        if (input == 'q') break;

        if (productCode >= 1 && productCode <= 5) {
            Product selectedProduct = products[productCode - 1];

            // Kiểm tra xem sản phẩm đã được chọn trước đó hay chưa
            bool productExists = false;
            for (auto& product : khachHang.products) {
                if (product.first.name == selectedProduct.name) {
                    productExists = true;
                    cout << "So luong: ";
                    int quantity;
                    while (!(cin >> quantity)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Khong hop le. Xin moi nhap lai." << endl;
                        cout << "So luong: ";
                    }
                    product.second += quantity; // Cập nhật số lượng sản phẩm
                    break;
                }
            }

            if (!productExists) {
                cout << "So luong: ";
                int quantity;
                while (!(cin >> quantity)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Khong hop le. Xin moi nhap lai." << endl;
                    cout << "So luong: ";
                }

                khachHang.products.push_back(make_pair(selectedProduct, quantity));
            }
        }

    } while (input != 'q');

    Node* newNode = new Node;
    newNode->data = khachHang;
    newNode->next = l->head;
    newNode->pre = l->tail;

    l->tail->next = newNode;
    l->head->pre = newNode;
    l->tail = newNode;
}

//HÀM VIẾT HOA CHỮ CÁI ĐẦU TRONG CHUỖI
string capitalize(string str) {
    string result = str;
    bool newWord = true;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == ' ') {
            newWord = true;
        }
        else if (newWord) {
            result[i] = toupper(result[i]);
            newWord = false;
        }
    }
    return result;
}

//HÀM CHUYỂN SỐ SANG CHỮ
string convertThreeDigits(int num) {
    string result;

    int hundreds = num / 100;
    int remainder = num % 100;

    if (hundreds > 0) {
        result += ones[hundreds] + " tram ";
    }

    if (remainder >= 10 && remainder <= 19) {
        result += "muoi " + ones[remainder % 10];
    }
    else {
        int tens = remainder / 10;
        int onesDigit = remainder % 10;

        if (tens > 0) {
            result += ones[tens] + " muoi ";
        }

        if (onesDigit > 0) {
            result += ones[onesDigit];
        }
    }

    return result;
}
string convertNumberToWords(long long num) {
    if (num == 0) {
        return "dong";
    }

    string words;
    int thousandsIndex = 0;

    while (num > 0) {
        int threeDigits = num % 1000;
        if (threeDigits > 0) {
            words = convertThreeDigits(threeDigits) + " " + thousands[thousandsIndex] + " " + words;
        }

        num /= 1000;
        thousandsIndex++;
    }

    return words;
}

// HÀM IN DANH SÁCH KHÁCH HÀNG
void inDanhSach(DouList* l) {
    Node* currentNode = l->head->next;
    set<string> usedIds;

    while (currentNode != l->head) {
        Customer khachHang = currentNode->data;

        string currentId = khachHang.id;

        // Kiểm tra xem mã id đã sử dụng trước đó chưa
        if (usedIds.count(currentId) > 0) {
            // Trường hợp mã id trùng nhau
            bool isDuplicate = false;
            string newId = currentId;

            // Kiểm tra thông tin khách hàng có trùng nhau không
            Node* tempNode = l->head->next;
            while (tempNode != l->head) {
                if (tempNode != currentNode && tempNode->data.id == currentId) {
                    if (tempNode->data.firstName == khachHang.firstName &&
                        tempNode->data.lastName == khachHang.lastName &&
                        tempNode->data.phoneNumber == khachHang.phoneNumber &&
                        tempNode->data.address.street == khachHang.address.street &&
                        tempNode->data.address.district == khachHang.address.district &&
                        tempNode->data.address.city == khachHang.address.city) {
                        // Trùng thông tin khách hàng
                        isDuplicate = true;
                        break;
                    }
                }
                tempNode = tempNode->next;
            }

            if (isDuplicate) {
                // Xóa khách hàng có thông tin trùng nhau
                Node* temp = currentNode->next;
                xoaKhachHang(l, khachHang.id);
                currentNode = temp;
                continue;
            }
            else {
                // Không trùng thông tin khách hàng, tạo mã id mới
                do {
                    int newIdInt = stoi(newId) + 1;
                    newId = to_string(newIdInt);
                } while (usedIds.count(newId) > 0);

                khachHang.id = newId;
                currentNode->data.id = newId;
            }
        }

        // Đánh dấu mã id đã sử dụng
        usedIds.insert(currentId);

        // In thông tin khách hàng và sản phẩm
        string firstName = capitalize(khachHang.firstName);
        string lastName = capitalize(khachHang.lastName);
        cout << "\033[1;31mID: " << khachHang.id << "\033[0m"
            << ", Ho va ten: " << firstName + ' ' + lastName
            << ", SDT: " << khachHang.phoneNumber << endl;
        inDiaChi(khachHang.address);

        cout << "San pham da chon: " << endl;
        int totalPrice = 0;
        for (const auto& product : khachHang.products) {
            cout << product.first.name << "(" << product.first.price << "). So luong: " << product.second << endl;
            totalPrice += product.first.price * product.second;
        }
        cout << "Tong gia tien san pham (bang so): " << totalPrice << endl;

        string priceInWords = convertNumberToWords(totalPrice);
        cout << "Tong gia tien san pham (bang chu): " << priceInWords << " dong" << endl;
        cout << endl;

        currentNode = currentNode->next;
    }
}

// HÀM TÌM KIẾM KHÁCH HÀNG THEO HỌ TÊN
void timKiemTheoHoTen(DouList* l) {
    string hoTen;
    cout << "Nhap ho ten can tim kiem (hoac nhap 'q' de quay lai menu chinh): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, hoTen);
    if (hoTen == "q" || hoTen == "Q") {
        return;
    }

    // Chuyển đổi chuỗi tìm kiếm thành chữ thường
    transform(hoTen.begin(), hoTen.end(), hoTen.begin(), ::tolower);

    Node* currentNode = l->head->next;
    int count = 0;
    while (currentNode != l->head) {
        Customer khachHang = currentNode->data;
        string fullName = khachHang.firstName + " " + khachHang.lastName;

        // Chuyển đổi tên đầy đủ của khách hàng thành chữ thường
        transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);

        if (fullName.find(hoTen) != string::npos) {
            count++;
            cout << "\nTim thay khach hang co \033[1;31mID: " << khachHang.id << "\033[0m"
                << ", Ho va ten: " << khachHang.firstName + " " + khachHang.lastName
                << ", SDT: " << khachHang.phoneNumber << endl;
            inDiaChi(khachHang.address);
            cout << "San pham da chon : ";

            for (const auto& product : khachHang.products) {
                cout << product.first.name << "(" << product.second << "), ";
            }
            cout << endl;
        }
        currentNode = currentNode->next;
    }

    if (count == 0) {
        cout << "Khong tim thay khach hang nao co ho ten: " << hoTen << endl;
    }
}


// HÀM CHÈN THÊM KHÁCH HÀNG VÀO SAU MỘT KHÁCH HÀNG CÓ MÃ SỐ CHỈ ĐỊNH
void chenKhachHang(DouList* l, string maSoChiDinh) {
    Node* currentNode = l->head->next;
    while (currentNode != l->head) {
        Customer khachHang = currentNode->data;
        if (khachHang.id == maSoChiDinh) {
            Customer khachHangMoi;
            cout << "Nhap thong tin khach hang moi can chen:" << endl;
            system("cls");
            // Tạo mã ID ngẫu nhiên
            srand(time(0));
            int id;
            do {
                id = rand() % 1000;
            } while (l->usedIds.count(id) > 0);
            l->usedIds.insert(id);

            khachHangMoi.id = to_string(id);
            cout << "ID: " << khachHangMoi.id << endl;
            cout << "Ho va ten dem: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, khachHangMoi.firstName);
            cout << "Ten:";
            getline(cin, khachHangMoi.lastName);
            cout << "SDT: ";
            cin >> khachHangMoi.phoneNumber;

            nhapDiaChi(khachHangMoi.address);

            // In bảng sản phẩm
            cout << "Danh sach san pham:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ") " << products[i].name << ", Gia: " << products[i].price << endl;
            }

            char input;
            cout << "(nhap q de hoan thanh viec nhap)" << endl;
            do {
                int productCode;
                cout << "Ma san pham (1-5): ";
                while (true) {
                    cin >> input;
                    if (input == 'q') break;
                    productCode = input - '0';
                    if (productCode >= 1 && productCode <= 5) {
                        break;
                    }
                    else {
                        cout << "Ma san pham khong hop le. Xin moi nhap lai." << endl;
                        cout << "Ma san pham (1-5): ";
                    }
                }

                if (input == 'q') break;

                if (productCode >= 1 && productCode <= 5) {
                    Product selectedProduct = products[productCode - 1];

                    // Kiểm tra xem sản phẩm đã được chọn trước đó hay chưa
                    bool productExists = false;
                    for (auto& product : khachHangMoi.products) {
                        if (product.first.name == selectedProduct.name) {
                            productExists = true;
                            cout << "So luong: ";
                            int quantity;
                            while (!(cin >> quantity)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Khong hop le. Xin moi nhap lai." << endl;
                                cout << "So luong: ";
                            }
                            product.second += quantity; // Cập nhật số lượng sản phẩm
                            break;
                        }
                    }

                    if (!productExists) {
                        cout << "So luong: ";
                        int quantity;
                        while (!(cin >> quantity)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Khong hop le. Xin moi nhap lai." << endl;
                            cout << "So luong: ";
                        }

                        khachHangMoi.products.push_back(make_pair(selectedProduct, quantity));
                    }
                }

            } while (input != 'q');

            Node* newNode = new Node;
            newNode->data = khachHangMoi;
            newNode->next = currentNode->next;
            newNode->pre = currentNode;

            currentNode->next->pre = newNode;
            currentNode->next = newNode;

            if (currentNode == l->tail) {
                l->tail = newNode;
            }

            cout << "Da chen thanh cong khach hang moi." << endl;

            return;
        }
        currentNode = currentNode->next;
    }

    cout << "Khong tim thay khach hang co ma so: " << maSoChiDinh << endl;
}

// HÀM XÓA KHÁCH HÀNG CÓ MÃ SỐ CHỈ ĐỊNH
bool xoaKhachHang(DouList* l, string maSoChiDinh) {
    Node* currentNode = l->head->next;
    while (currentNode != l->head) {
        Customer khachHang = currentNode->data;
        if (khachHang.id == maSoChiDinh) {
            currentNode->pre->next = currentNode->next;
            currentNode->next->pre = currentNode->pre;
            l->usedIds.erase(stoi(maSoChiDinh)); // Xóa ID khỏi danh sách IDs đã sử dụng
            if (currentNode == l->tail) {
                l->tail = currentNode->pre; // Cập nhật con trỏ đuôi nếu xóa khách hàng cuối cùng
            }
            delete currentNode;
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}

// HÀM XÓA TẤT CẢ CÁC KHÁCH HÀNG TRONG DANH SÁCH
void xoaTatCaKhachHang(DouList* l) {
    Node* currentNode = l->head->next;
    while (currentNode != l->head) {
        Node* nextNode = currentNode->next;
        currentNode->pre->next = currentNode->next;
        currentNode->next->pre = currentNode->pre;
        if (currentNode == l->tail) {
            l->tail = currentNode->pre; 
        }
        delete currentNode;
        currentNode = nextNode;
    }
    l->usedIds.clear(); 
}


void quickSort(DouList* l, Node* leftNode, Node* rightNode) {
    if (leftNode == rightNode || leftNode->pre == rightNode) {
        return;
    }

    Node* i = leftNode;
    Node* j = rightNode;
    int p = stoi(leftNode->data.id);

    while (i != j) {
        while (stoi(i->data.id) < p && i != j) {
            i = i->next;
        }
        while (stoi(j->data.id) > p && i != j) {
            j = j->pre;
        }
        if (i != j) {
            Customer tempData = i->data;
            i->data = j->data;
            j->data = tempData;
        }
    }

    quickSort(l, leftNode, j);
    quickSort(l, j->next, rightNode);
}

// HÀM SẮP XẾP DANH SÁCH THEO MÃ SỐ TĂNG DẦN
void sapXepTheoMaSo(DouList* l) {
    quickSort(l, l->head->next, l->head->pre);
    cout << "Da sap xep danh sach theo ma so tang dan." << endl;
}

// HÀM SẮP XẾP DANH SÁCH THEO TÊN TĂNG DẦN
void sapXepTheoTen(DouList* l) {
    int n = 0;
    Node* currentNode = l->head->next;
    while (currentNode != l->head) {
        n++;
        currentNode = currentNode->next;
    }

    currentNode = l->head->next;
    for (int i = 0; i < n - 1; i++) {
        Node* minNode = currentNode;
        Node* tempNode = currentNode->next;
        while (tempNode != l->head) {
            string minFullName = minNode->data.firstName + " " + minNode->data.lastName;
            string tempFullName = tempNode->data.firstName + " " + tempNode->data.lastName;

            string minLastName = minFullName.substr(minFullName.rfind(' ') + 1);
            string tempLastName = tempFullName.substr(tempFullName.rfind(' ') + 1);

            if (tempLastName < minLastName || (tempLastName == minLastName && tempFullName < minFullName)) {
                minNode = tempNode;
            }
            tempNode = tempNode->next;
        }

        if (currentNode != minNode) {
            Customer tempData = currentNode->data;
            currentNode->data = minNode->data;
            minNode->data = tempData;
        }

        currentNode = currentNode->next;
    }

    cout << "Da sap xep danh sach theo ten tang dan." << endl;
}

//HÀM CHỈNH SỬA ĐƠN HÀNG
void chinhSuaDonHang(DouList* l, string maSo) {
    Node* currentNode = l->head->next;
    while (currentNode != l->head) {
        Customer& khachHang = currentNode->data;
        if (khachHang.id == maSo) {
            while (true) {
                system("cls");
                // Hiển thị thông tin đầy đủ của khách hàng có mã số chỉ định
                cout << "Thong tin khach hang:" << endl;
                cout << "\033[1;31mID: " << khachHang.id << "\033[0m" << endl;
                cout << "Ho va ten: " << khachHang.firstName + ' ' + khachHang.lastName << endl;
                cout << "SDT: " << khachHang.phoneNumber << endl;
                inDiaChi(khachHang.address);
                cout << "Danh sach san pham da chon:" << endl;

                int totalPrice = 0;
                for (const auto& product : khachHang.products) {
                    cout << product.first.name << "(" << product.first.price << "). So luong: " << product.second << endl;
                    totalPrice += product.first.price * product.second;
                }
                cout << "Tong gia tien san pham (bang so): " << totalPrice << endl;

                string priceInWords = convertNumberToWords(totalPrice);
                cout << "Tong gia tien san pham (bang chu): " << priceInWords << " dong" << endl;
                cout << endl;

                // Lựa chọn loại chỉnh sửa
                cout << "Chon loai thong tin can chinh sua:" << endl;
                cout << "1) Xoa san pham" << endl;
                cout << "2) Thay doi so luong san pham" << endl;
                cout << "3) Sua thong tin khach hang" << endl;
                cout << "4) Mua them san pham" << endl;
                cout << "5) Quay lai menu chon loai thong tin" << endl;
                int choice;
                cin >> choice;

                switch (choice) {
                case 1: {
                    // Xóa sản phẩm không muốn mua nữa
                    cout << "Danh sach san pham da chon:" << endl;
                    for (int i = 0; i < khachHang.products.size(); i++) {
                        cout << i + 1 << ") " << khachHang.products[i].first.name
                            << ", So luong: " << khachHang.products[i].second << endl;
                    }
                    cout << "Nhap so thu tu san pham can xoa: ";
                    int indexToDelete;
                    cin >> indexToDelete;
                    if (indexToDelete >= 1 && indexToDelete <= khachHang.products.size()) {
                        cout << "Ban co chac chan muon xoa san pham nay khong? (y/n): ";
                        char confirm;
                        cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            khachHang.products.erase(khachHang.products.begin() + indexToDelete - 1);
                            cout << "Da xoa san pham thanh cong." << endl;
                        }
                        else {
                            cout << "Huy viec xoa san pham." << endl;
                        }
                    }
                    else {
                        cout << "So thu tu khong hop le." << endl;
                    }
                    break;
                }
                case 2: {
                    // Thay đổi số lượng sản phẩm
                    cout << "Danh sach san pham da chon:" << endl;
                    for (int i = 0; i < khachHang.products.size(); i++) {
                        cout << i + 1 << ") " << khachHang.products[i].first.name
                            << ", So luong: " << khachHang.products[i].second << endl;
                    }
                    cout << "Nhap so thu tu san pham can thay doi so luong: ";
                    int indexToChange;
                    while (!(cin >> indexToChange)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Khong hop le. Xin moi nhap lai." << endl;
                        cout << "Nhap so thu tu san pham can thay doi so luong: ";
                    }
                    if (indexToChange >= 1 && indexToChange <= khachHang.products.size()) {
                        cout << "Nhap so luong moi: ";
                        int newQuantity;
                        while (!(cin >> newQuantity)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Khong hop le. Xin moi nhap lai." << endl;
                            cout << "Nhap so luong moi: ";
                        }
                        cout << "Ban co chac chan muon thay doi so luong san pham nay khong? (y/n): ";
                        char confirm;
                        cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            khachHang.products[indexToChange - 1].second = newQuantity;
                            cout << "Da thay doi so luong san pham thanh cong." << endl;
                        }
                        else {
                            cout << "Huy viec thay doi so luong san pham." << endl;
                        }
                    }
                    else {
                        cout << "So thu tu khong hop le." << endl;
                    }
                    break;
                }
                case 3: {
                    //sửa thông tin
                    cout << "Chon loai thong tin can chinh sua:" << endl;
                    cout << "1) Sua thong tin ca nhan" << endl;
                    cout << "2) Sua dia chi" << endl;
                    int choice;
                    cin >> choice;

                    switch (choice) {
                    case 1: {
                        // Sửa thông tin cá nhân
                        cout << "Nhap thong tin moi:" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ho va ten dem: ";
                        string newFirstName;
                        getline(cin, newFirstName);
                        newFirstName = capitalize(newFirstName);
                        cout << "Ten: ";
                        string newLastName;
                        getline(cin, newLastName);
                        newLastName = capitalize(newLastName);
                        cout << "SDT: ";
                        string newPhoneNumber;
                        cin >> newPhoneNumber;
                        cout << "Ban co chac chan muon thay doi thong tin khach hang nay khong? (y/n): ";
                        char confirm;
                        cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            khachHang.firstName = capitalize(newFirstName);
                            khachHang.lastName = capitalize(newLastName);
                            khachHang.phoneNumber = newPhoneNumber;
                            cout << "Da sua thong tin khach hang thanh cong." << endl;
                        }
                        else {
                            cout << "Huy viec sua thong tin khach hang." << endl;
                        }
                        break;
                    }
                    case 2: {
                        // Sửa địa chỉ
                        cout << "Ban co muon sua dia chi cua khach hang nay khong? (y/n): ";
                        char confirmAddress;
                        cin >> confirmAddress;
                        if (confirmAddress == 'y' || confirmAddress == 'Y') {
                            nhapDiaChi(khachHang.address);
                            cout << "Da sua dia chi cua khach hang thanh cong." << endl;
                        }
                        else {
                            cout << "Huy viec sua dia chi cua khach hang." << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Lua chon khong hop le." << endl;
                        break;
                    }
                    break;
                }

                case 4: {
                    // Mua thêm sản phẩm
                    cout << "Danh sach san pham da chon:" << endl;
                    for (int i = 0; i < khachHang.products.size(); i++) {
                        cout << i + 1 << ") " << khachHang.products[i].first.name
                            << ", So luong: " << khachHang.products[i].second << endl;
                    }

                    cout << "Danh sach san pham:" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ") " << products[i].name << ", Gia: " << products[i].price << " dong" << endl;
                    }

                    int productCode;
                    do {
                        cout << "Nhap so thu tu san pham can them (1-5): ";
                        while (!(cin >> productCode)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Khong hop le. Xin moi nhap lai." << endl;
                            cout << "Nhap so thu tu san pham can them (1-5): ";
                        }
                        if (productCode < 1 || productCode > 5) {
                            cout << "Ma san pham khong hop le. Xin moi nhap lai." << endl;
                        }
                    } while (productCode < 1 || productCode > 5);

                    Product selectedProduct = products[productCode - 1];

                    // Kiểm tra xem sản phẩm đã được chọn trước đó hay chưa
                    bool productExists = false;
                    for (auto& product : khachHang.products) {
                        if (product.first.name == selectedProduct.name) {
                            productExists = true;
                            cout << "So luong: ";
                            int quantity;
                            while (!(cin >> quantity)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Khong hop le. Xin moi nhap lai." << endl;
                                cout << "So luong: ";
                            }
                            product.second += quantity; // Cập nhật số lượng sản phẩm
                            break;
                        }
                    }

                    if (!productExists) {
                        cout << "So luong: ";
                        int quantity;
                        while (!(cin >> quantity)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Khong hop le. Xin moi nhap lai." << endl;
                            cout << "So luong: ";
                        }

                        khachHang.products.push_back(make_pair(selectedProduct, quantity));
                    }
                    cout << "Da them san pham moi thanh cong." << endl;
                    break;
                }



                case 5: {
                    // Quay lại menu chọn loại chỉnh sửa ban đầu
                    return;
                }
                default:
                    cout << "Lua chon khong hop le." << endl;
                    break;
                }
            }
            return;
        }
        currentNode = currentNode->next;
    }
    cout << "Khong tim thay khach hang co ma so: " << maSo << endl;
}

//HÀM XUẤT RA FILE 
void xuatDanhSachRaFILE(DouList* l, const string& fileName) {
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cout << "KHONG THE MO TEP DE GHI." << endl;
        return;
    }
    Node* currentNode = l->head->next;
    outFile << "Danh sach khach hang:" << endl;
    while (currentNode != l->head) {
        Customer khachHang = currentNode->data;
        string firstName = capitalize(khachHang.firstName);
        string lastName = capitalize(khachHang.lastName);
        outFile << "ID: " << khachHang.id
            << ", Ho va ten: " << firstName + ' ' + lastName
            << ", SDT: " << khachHang.phoneNumber << endl;
        outFile << "Dia chi: " << khachHang.address.street << ", " << khachHang.address.district << ", " << khachHang.address.city << endl;

        outFile << "San pham da chon: " << endl;
        int totalPrice = 0;
        for (const auto& product : khachHang.products) {
            outFile << product.first.name << "(" << product.first.price << "). So luong: " << product.second << endl;
            totalPrice += product.first.price * product.second;
        }
        outFile << "Tong gia tien san pham (bang so): " << totalPrice << endl;

        string priceInWords = convertNumberToWords(totalPrice);
        outFile << "Tong gia tien san pham (bang chu): " << priceInWords << " dong" << endl;
        outFile << endl;

        currentNode = currentNode->next;
    }
    thongKeSanPhamFILE(l, outFile);
    outFile.close();
}

//HÀM THỐNG KÊ
void thongKeSanPham(DouList* l) {
    cout << "BANG THONG KE SAN PHAM" << endl;
    cout << left << setw(15) << "Ten san pham"
        << setw(15) << "Gia san pham"
        << setw(20) << "So luong san pham"
        << setw(10) << "Tong tien"
        << setw(30) << "Tong tien (chu)" << endl;
    cout << string(90, '-') << endl;
    int tongThu = 0;
    int maxSoLuong = 0;
    vector<string> bestSeller;
    int minSoLuong = INT_MAX;
    vector<string> itNguoiMuaNhat;
    int maxTien = 0;
    vector<string> nhieuTienNhat;
    int minTien = INT_MAX;
    vector<string> itTienNhat;
    for (int i = 0; i < 5; i++) {
        Product product = products[i];
        int soLuong = 0;
        Node* currentNode = l->head->next;
        while (currentNode != l->head) {
            Customer khachHang = currentNode->data;
            for (const auto& p : khachHang.products) {
                if (p.first.name == product.name) {
                    soLuong += p.second;
                }
            }
            currentNode = currentNode->next;
        }
        int tongTien = soLuong * product.price;
        string tongTienChu = convertNumberToWords(tongTien);
        tongThu += tongTien;
        cout << left << setw(15) << product.name
            << setw(15) << product.price
            << setw(20) << soLuong
            << setw(10) << tongTien
            << setw(30) << tongTienChu << endl;

        if (soLuong > maxSoLuong) {
            maxSoLuong = soLuong;
            bestSeller.clear();
            bestSeller.push_back(product.name);
        }
        else if (soLuong == maxSoLuong) {
            bestSeller.push_back(product.name);
        }
        if (soLuong < minSoLuong) {
            minSoLuong = soLuong;
            itNguoiMuaNhat.clear();
            itNguoiMuaNhat.push_back(product.name);
        }
        else if (soLuong == minSoLuong) {
            itNguoiMuaNhat.push_back(product.name);
        }
        if (tongTien > maxTien) {
            maxTien = tongTien;
            nhieuTienNhat.clear();
            nhieuTienNhat.push_back(product.name);
        }
        else if (tongTien == maxTien) {
            nhieuTienNhat.push_back(product.name);
        }
        if (tongTien < minTien && tongTien >= 0) {
            minTien = tongTien;
            itTienNhat.clear();
            itTienNhat.push_back(product.name);
        }
        else if (tongTien == minTien && tongTien >= 0) {
            itTienNhat.push_back(product.name);
        }
    }
    cout << "Best seller: ";
    for (int i = 0; i < bestSeller.size(); i++) {
        cout << bestSeller[i];
        if (i != bestSeller.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "It nguoi mua nhat: ";
    for (int i = 0; i < itNguoiMuaNhat.size(); i++) {
        cout << itNguoiMuaNhat[i];
        if (i != itNguoiMuaNhat.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "San pham mang lai nhieu tien nhat: ";
    for (int i = 0; i < nhieuTienNhat.size(); i++) {
        cout << nhieuTienNhat[i];
        if (i != nhieuTienNhat.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "San pham mang lai it tien nhat: ";
    for (int i = 0; i < itTienNhat.size(); i++) {
        cout << itTienNhat[i];
        if (i != itTienNhat.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Tong thu tat ca quan ao: " << tongThu << endl;
}

//HÀM ĐƯA BẢNG THỐNG KÊ VÀO FILE
void thongKeSanPhamFILE(DouList* l, ostream& os) {
    os << "BANG THONG KE SAN PHAM" << endl;
    os << left << setw(15) << "Ten san pham"
        << setw(15) << "Gia san pham"
        << setw(20) << "So luong san pham"
        << setw(10) << "Tong tien"
        << setw(30) << "Tong tien (chu)" << endl;
    os << string(90, '-') << endl;
    int tongThu = 0;
    int maxSoLuong = 0;
    vector<string> bestSeller;
    int minSoLuong = INT_MAX;
    vector<string> itNguoiMuaNhat;
    int maxTien = 0;
    vector<string> nhieuTienNhat;
    int minTien = INT_MAX;
    vector<string> itTienNhat;
    for (int i = 0; i < 5; i++) {
        Product product = products[i];
        int soLuong = 0;
        Node* currentNode = l->head->next;
        while (currentNode != l->head) {
            Customer khachHang = currentNode->data;
            for (const auto& p : khachHang.products) {
                if (p.first.name == product.name) {
                    soLuong += p.second;
                }
            }
            currentNode = currentNode->next;
        }
        int tongTien = soLuong * product.price;
        string tongTienChu = convertNumberToWords(tongTien);
        tongThu += tongTien;
        os << left << setw(15) << product.name
            << setw(15) << product.price
            << setw(20) << soLuong
            << setw(10) << tongTien
            << setw(30) << tongTienChu << endl;

        if (soLuong > maxSoLuong) {
            maxSoLuong = soLuong;
            bestSeller.clear();
            bestSeller.push_back(product.name);
        }
        else if (soLuong == maxSoLuong) {
            bestSeller.push_back(product.name);
        }
        if (soLuong < minSoLuong) {
            minSoLuong = soLuong;
            itNguoiMuaNhat.clear();
            itNguoiMuaNhat.push_back(product.name);
        }
        else if (soLuong == minSoLuong) {
            itNguoiMuaNhat.push_back(product.name);
        }
        if (tongTien > maxTien) {
            maxTien = tongTien;
            nhieuTienNhat.clear();
            nhieuTienNhat.push_back(product.name);
        }
        else if (tongTien == maxTien) {
            nhieuTienNhat.push_back(product.name);
        }
        if (tongTien < minTien && tongTien >= 0) {
            minTien = tongTien;
            itTienNhat.clear();
            itTienNhat.push_back(product.name);
        }
        else if (tongTien == minTien && tongTien >= 0) {
            itTienNhat.push_back(product.name);
        }
    }
    os << "Best seller: ";
    for (int i = 0; i < bestSeller.size(); i++) {
        os << bestSeller[i];
        if (i != bestSeller.size() - 1) {
            os << ", ";
        }
    }
    os << endl;

    os << "It nguoi mua nhat: ";
    for (int i = 0; i < itNguoiMuaNhat.size(); i++) {
        os << itNguoiMuaNhat[i];
        if (i != itNguoiMuaNhat.size() - 1) {
            os << ", ";
        }
    }
    os << endl;

    os << "San pham mang lai nhieu tien nhat: ";
    for (int i = 0; i < nhieuTienNhat.size(); i++) {
        os << nhieuTienNhat[i];
        if (i != nhieuTienNhat.size() - 1) {
            os << ", ";
        }
    }
    os << endl;

    os << "San pham mang lai it tien nhat: ";
    for (int i = 0; i < itTienNhat.size(); i++) {
        os << itTienNhat[i];
        if (i != itTienNhat.size() - 1) {
            os << ", ";
        }
    }
    os << endl;

    os << "Tong thu tat ca quan ao: " << tongThu << endl;
}

void docDanhSachTuFILE(DouList* l, const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cout << "KHONG THE MO TEP DE DOC." << endl;
        return;
    }
    string line;
    getline(inFile, line); // Đọc dòng "Danh sach khach hang:"
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        if (line == "BANG THONG KE SAN PHAM") break; // Thêm dòng này để chỉ đọc phần "Danh sach khach hang"

        Customer khachHang;
        // Đọc thông tin khách hàng
        stringstream ss(line);
        string temp;
        getline(ss, temp, ':'); // Đọc "ID"
        getline(ss, temp, ','); // Đọc ID
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.id = temp;
        getline(ss, temp, ':'); // Đọc ", Ho va ten"
        getline(ss, temp, ','); // Đọc họ và tên đệm
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.firstName = temp;
        getline(ss, temp, ':'); // Đọc ", SDT"
        getline(ss, temp); // Đọc số điện thoại
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.phoneNumber = temp;

        getline(inFile, line); // Đọc dòng "Dia chi: ..."
        ss.clear();
        ss.str(line);
        getline(ss, temp, ':'); // Đọc "Dia chi"
        getline(ss, temp, ','); // Đọc đường phố
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.address.street = temp;
        getline(ss, temp, ','); // Đọc quận/huyện
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.address.district = temp;
        getline(ss, temp); // Đọc thành phố
        temp.erase(0, temp.find_first_not_of(' ')); temp.erase(temp.find_last_not_of(' ') + 1);
        khachHang.address.city = temp;


        getline(inFile, line); // Đọc dòng "San pham da chon:"
        while (getline(inFile, line)) {
            if (line.empty()) break;

            if (line.rfind("Tong gia tien san pham", 0) == 0) {
                getline(inFile, line); // Bỏ qua dòng "Bang chu:"
                break;
            }

            Product product;
            int quantity;
            ss.clear();
            ss.str(line);
            getline(ss, product.name, '('); // Đọc tên sản phẩm
            product.name.erase(0, product.name.find_first_not_of(' ')); product.name.erase(product.name.find_last_not_of(' ') + 1);
            ss >> product.price; // Đọc giá sản phẩm
            getline(ss, temp, ':'); // Đọc "). So luong"
            ss >> quantity; // Đọc số lượng

            khachHang.products.push_back(make_pair(product, quantity));
        }

        Node* newNode = new Node;
        newNode->data = khachHang;
        newNode->next = l->head;
        newNode->pre = l->tail;

        l->tail->next = newNode;
        l->head->pre = newNode;
        l->tail = newNode;
    }

    inFile.close();
}

//HÀM IN THÔNG BÁO
void inThongBao() {
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                HỆ THỐNG QUẢN LÝ PHÒNG KHÁM NHA KHOA KHANG PS" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    cout << "Menu:" << endl;
    cout << "a) Đặt lịch hẹn cho khách hàng" << endl;
    cout << "b) In lịch hẹn" << endl;
    cout << "c) Tìm kiếm một khách hàng theo họ tên" << endl;
    cout << "d) Chèn thêm một khách hàng mới vào sau một khách hàng có mã số chỉ định" << endl;
    cout << "e) Xóa một khách hàng có mã số chỉ định" << endl;
    cout << "f) Sắp xếp danh sách theo mã số tăng dần" << endl;
    cout << "g) Sắp xếp danh sách theo tên tăng dần " << endl;
    cout << "h) Sửa lịch hẹn" << endl;
    cout << "i) In hóa đơn" << endl;
    cout << "j) Thoát" << endl;
    cout << "k) Đọc danh sách từ file" << endl;

}