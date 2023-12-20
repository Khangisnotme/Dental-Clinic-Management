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

using namespace std;
struct nhanvien
{
	int manv;
	char ten[30];
	char chucvu [20];
	char sdt[12];
	time_t chamcong;
	bool lamviec;
	nhanvien* next;
};
struct sanpham
{
	int masp;
	char ten[50];
	int gia;
	int sl;
	int slkho;
	sanpham* next;
};

struct khach
{
	char ten [40];
	char sdt [12];
	char diachi [200];
};

struct hoadon
{
	int mahd;
	time_t tgian;
	khach kh;
	sanpham sp;
	int a[100];
	int b[100];
	int tong;
	char ngay[200];
	hoadon* next;
};

void optionchung();
void optionhd();
void menu();
hoadon* newhd(hoadon* &dshd, int& slsp, int a[],int b[], int mahd, char tenkh[], long long sdtkh, char dckh[], int sl, int tongtien, char thu);
void nhaphd(hoadon* &dshd, int& slsp, int a[],int b[]);
void luuhd(hoadon* &dshd, int&slsp, int a[],int b[]);
void optionxemhd();
void xemhdtg();
void xemhdthapcao();
void xemhdcaothap();
void timhd();
void xoahd();
void optionsuahd(hoadon* &dshd,int&masua,int&slsp);
void suahdTEN(int&masua) ;
void suahdSDT(int&masua);
void suahdDC(int&masua) ;
void xoadssp(int&masua) ;
void suahdSP(int&masua);
void optionkh ();
void luukh(hoadon*& dshd);
void luukhsaukhixoahd();
void xemdskh();
void timhdcuakh();
void timkh();
void suakhSDT();
void suakhDC();
void suakhTEN();
int optionnv();
void themnv() ;
void luunv();
void xemdsnv();
void capnhatlamviec();
void chamcongvatinhluong();
void xembangluong();
void xemluong1nv();
void xemluong1thang();
void timnv();
void xoanv();
void optionsuanv();
void suanvTEN();
void suanvSDT();
void suanvCHUCVU();
void optiondoanhthu();
void tinhdoanhthutheongay();
void tinhdoanhthutheothang();
void tinhdoanhthutheonam();
void optionkho();
void themsp(sanpham* &sp);
void luusp(sanpham* &sp);
void capnhatsl();
void xoasp();
void timsp();
void xuatdskho();
// Hàm để thiết lập màu cho chữ trên Windows
void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}


int main()
{
    system("cls");
	optionchung();

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
			optionhd();
			break;
			case 2:
            system("cls");
			optionkh();
			break;
			case 3:
            system("cls");
			optionnv();
			break;
			case 4:
            system("cls");
			optionkho();
            break;
            case 5:
            system("cls");
            optiondoanhthu();
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
//////////////////////////////////////////////////////// HOA DON /////////////////////////////////////////////////////////

void optionhd()
{
	nhanvien* nv;
	hoadon* dshd;
	dshd = NULL;
	khach* kh[100];
	int slsp;
	int n;
	int a[100];
	int b[100];
	char thu [200];
	int x=0;
	int mssua;
	while (x!=7)
	{
		cout << "-----------------------------------------QUAN LY HOA DON------------------------------------" << endl;
		cout << "1. Xem MENU" << endl;
		cout << "2. Them hoa don" << endl;
		cout << "3. Xem danh sach hoa don" << endl;
		cout << "4. Tim hoa don" << endl;
		cout << "5. Xoa hoa don" << endl;
		cout << "6. Sua hoa don" << endl;
		cout << "7. Thoat" << endl;

		cout << "Nhap lua chon : ";
		cin>>x;
		switch (x)
		{
			case 1:
				menu();
				break;
			case 2:
				nhaphd(dshd, slsp, a,b);
				break;
			case 3:
				cout<<"////////////////////////////////// DANH SACH HOA DON //////////////////////////////////"<<endl;
				optionxemhd();
				break;
			case 4:
				timhd();
				break;
			case 5:
				xoahd();
				break;
			case 6:
				optionsuahd(dshd,mssua,slsp);
				break;
			case 7:
				cout<<"Thoat chuc nang!!!"<<endl;
				break;
		}
	}
}

void menu()
{
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
hoadon* newhd(hoadon* &dshd, int& slsp, int a[], int b[], int mahd, char tenkh[], char sdtkh[], char dckh[], int sl, int tongtien, string thu)
{
    hoadon* p = new hoadon;
    p->mahd = mahd;
    // Copy thông tin sản phẩm vào danh sách trong hoá đơn
    strcpy(p->kh.ten, tenkh);
    strcpy(p->kh.sdt,sdtkh);
    strcpy(p->kh.diachi, dckh);
    p->tong = tongtien;
    strcpy(p->ngay, thu.c_str());
    p->sp.sl = sl;
    for (int i = 0; i < slsp; i++)
    {
        p->sp.masp = a[i];
        p->a[i]= p->sp.masp;
        p->sp.sl = b[i];
        p->b[i]= p->sp.sl;
    }

    
    p->next = NULL;

    return p;
}
void nhaphd(hoadon* &dshd, int& slsp, int a[], int b[])
{
    int x;
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

    hoadon* p = newhd(dshd, slsp, a, b, mahd, tenkh, sdtkh, dckh, sl, tongtien, thu);
    if (dshd == NULL)
    {
        dshd = p; // Cập nhật con trỏ dssv để trỏ tới nút đầu tiên
    }
    else
    {
        hoadon* q = dshd;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    luuhd(dshd, slsp, a, b);
}

void luuhd(hoadon*& dshd, int& slsp, int a[], int b[]) {
    ofstream file;
    file.open("dshd.txt", ios::app);

    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    hoadon* current = dshd;
    while (current != NULL)
	{
        bool kiemtra = false;
        ifstream kiemtrafile("dshd.txt");
        string kiemtrastr;
        while (getline(kiemtrafile, kiemtrastr)) {
            if (kiemtrastr == "Ma Hoa Don: " + to_string(current->mahd))
			{
                kiemtra = true;
                break;
            }
        }
        kiemtrafile.close();

        if (!kiemtra)
		{
            file<< "--------------------------------------------------------" << endl;
            file<< "Ma Hoa Don: " << current->mahd << endl;
            file<< "SDT Khach Hang: " << current->kh.sdt << endl;
            file<< "Ten Khach Hang: " << current->kh.ten << endl;
            file<< "Dia Chi Khach Hang: " << current->kh.diachi << endl;
            file<< setw(30) << left << "Ma san pham " << setw(30) << left << "So luong"<<endl;

            for (int i = 0; i < slsp; i++) {
                file << setw(30) << left << current -> a[i] << setw(30) << left << current->b[i]<< endl;
            }

            file << "Ngay: " << current->ngay << endl
                << "Tong Tien: " << current->tong << endl;
        }
        current = current->next;
    }
    file.close();
    luukh(dshd);
    cout << "Da luu hoa don vao file dshd.txt!" << endl;
}


void xemhdtg()
{
	ifstream doc;
	doc.open("dshd.txt");
	if(!doc)
	{
		cout<<"Khong the mo file"<<endl;
	}
	else
	{
		string line;
		while(getline(doc,line))
		{
			cout<<line<<endl;
		}
	}
	doc.close();
}

void xemhdthapcao() {
    int x = 0;
    int i = 0;
    int a[1000], b[1000];
    ifstream doc;
    doc.open("dshd.txt");
    bool found = false;
    if (!doc) {
        cout << "Khong the mo file" << endl;
    }
    else {
        string line;
        while (getline(doc, line)) {
            if (line.find("Ma Hoa Don: ") != string::npos) {
                x += 1;
                a[i] = stoi(line.substr(12));
            }
            if (line.find("Tong Tien: ") != string::npos) {
                b[i] = stoi(line.substr(11));
                i += 1;
            }
        }

        for (int j = 0; j < x; j++) {
            int temp = b[j];
            int temp1 = a[j];
            int k = j-1;
            while (k >= 0 && b[k] > temp) {
                b[k+1] = b[k];
                a[k+1] = a[k];
                k--;
            }
            b[k+1] = temp;
            a[k+1] = temp1;
        }

        doc.clear();
        doc.seekg(0, ios::beg);

        for (int i = 0; i <x+1; i++) {
            found = false;
            while (getline(doc, line)) {
                if (line == "Ma Hoa Don: " + to_string(a[i])) {
                    found = true;
                }
                if (line == "--------------------------------------------------------" && found) {
                    cout << "--------------------------------------------------------" << endl;
					found = false;
                    break;
                }
                if (found) {
                    cout << line << endl;
                }
            }
            doc.clear();
            doc.seekg(0, ios::beg);
        }
    }
    doc.close();
}

void xemhdcaothap() {
    int x = 0;
    int i = 0;
    int a[1000], b[1000];
    ifstream doc;
    doc.open("dshd.txt");
    bool found = false;
    if (!doc) {
        cout << "Khong the mo file" << endl;
    }
    else {
        string line;
        while (getline(doc, line)) {
            if (line.find("Ma Hoa Don: ") != string::npos) {
                x += 1;
                a[i] = stoi(line.substr(12));
            }
            if (line.find("Tong Tien: ") != string::npos) {
                b[i] = stoi(line.substr(11));
                i += 1;
            }
        }

        for (int j = 0; j < x; j++) {
            int temp = b[j];
            int temp1 = a[j];
            int k = j-1;
            while (k >= 0 && b[k] > temp) {
                b[k+1] = b[k];
                a[k+1] = a[k];
                k--;
            }
            b[k+1] = temp;
            a[k+1] = temp1;
        }

        doc.clear();
        doc.seekg(0, ios::beg);

        for (int i = x-1; i>=0; i--) {
            found = false;
            while (getline(doc, line)) {
                if (line == "Ma Hoa Don: " + to_string(a[i])) {
                    found = true;
                }
                if (line == "--------------------------------------------------------" && found) {
                    cout << "--------------------------------------------------------" << endl;
					found = false;
                    break;
                }
                if (found) {
                    cout << line << endl;
                }
            }
            doc.clear();
            doc.seekg(0, ios::beg);
        }
    }
    doc.close();
}

void timhd()
{
	int x= 0;
    int mstim;
    cout << "Nhap ma so cua hoa don muon tim: ";
    cin>>mstim;
    ifstream doc;
    doc.open("dshd.txt");
    bool tim = false;
    if (!doc)
    {
        cout << "Khong the mo file" << endl;
    }
    else
    {
        string str;
        while (getline(doc, str))
        {
            if (str.find("Ma Hoa Don: " + to_string(mstim)) != string::npos) {
                tim = true;
                x+=1;
            }
            if (str.find("--------------------------------------------------------") != string::npos && tim)
            {
				cout<<"----------------------------------------------------------------"<<endl;;
                tim = false;
            }
            if (tim)
            {
                cout << str << endl;
            }
        }
    }
    if (x<1)
    {
        cout << "Khong tim thay hoa don!!!!!" << endl;
    }
    doc.close();
}

void optionxemhd()
{
	int x=0;
	while (x!=4)
	{
		cout<<"1. Xem hoa don theo thoi gian luu"<<endl;
		cout<<"2. Xem danh sach hoa don theo gia tri hoa don tu thap den cao"<<endl;
		cout<<"3. Xem danh sach hoa don theo gia tri hoa don tu cao den thap"<<endl;
		cout<<"4. Thoat chuc nang"<<endl;
		cout<<"Chon mot chuc nang: ";
		cin>>x;
		switch(x)
		{
			case 1:
			xemhdtg();
			break;
			case 2:
			xemhdthapcao();
			break;
			case 3:
			xemhdcaothap();
			break;
			case 4:
			cout<<"Thoat chuc nang!!!"<<endl;
			break;
		}

	}
}

void xoahd()
{
    int maxoa;
    cout << "Nhap ma so cua hoa don muon xoa: ";
    cin >> maxoa;

    ifstream filein;
    filein.open("dshd.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool xoa = false;
    while (getline(filein, str))
	{
        if (str == "Ma Hoa Don: " + to_string(maxoa)) {
            xoa = true;
        }
        if (str == "--------------------------------------------------------" && xoa) {
            xoa = false;
        }
        if (!xoa) {
            fileout << str << endl;
        }
    }

    filein.close();
    fileout.close();

    remove("dshd.txt");
    rename("temp.txt", "dshd.txt");

    cout << "Da xoa hoa don khoi file dshd.txt!" << endl;
    luukhsaukhixoahd();
}


void optionsuahd(hoadon* &dshd,int&masua,int&slsp)
{
	int x;
	while(x!= 5)
	{
		cout << "-----------------------------------------QUAN LY HOA DON------------------------------------" << endl;
		cout << "1. Sua ten khach hang trong 1 hoa don" << endl;
		cout << "2. Sua sdt khach hang trong 1 hoa don" << endl;
		cout << "3. Sua dia chi cua khach hang trong  hoa don" << endl;
		cout << "4. Sua danh sach san pham khach hang mua" << endl;
		cout << "5. Thoat" << endl;

		cout << "Nhap lua chon : ";
		cin>>x;
		switch (x)
		{
			case 1:
			suahdTEN(masua);
			break;
			case 2:
			suahdSDT(masua);
			break;
			case 3:
			suahdDC(masua);
			break;
			case 4:
			suahdSP(masua);
			break;
			case 5:
			cout<<"Thoat chuc nang"<<endl;
			break;
			default :
			cout<<"Khong co lua chon "<<x<<"!";
			break;
		}
}

}


void suahdTEN(int&masua)
{
	char tensua[40];
	cout<<"Nhap ma cua hoa don can sua ten khach hang: ";
	cin>>masua;
	cout<<"Nhap lai ten dung cua khach hang: ";
	cin.ignore();
	cin.getline(tensua,40);
    ifstream filein;
    filein.open("dshd.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein, str)) {
        if (str == "Ma Hoa Don: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("Ten Khach Hang: ") != string::npos && timthay) {
            fileout << "Ten Khach Hang: " << tensua << endl;
        }
        else {
            fileout << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein.close();
    fileout.close();

    remove("dshd.txt");
    rename("temp.txt", "dshd.txt");

    cout << "Da sua ten khach hang thanh cong!" << endl;
}

void suahdSDT(int&masua)
{
	char sdtsua[40];
	cout<<"Nhap ma cua hoa don can sua sdt khach hang: ";
	cin>>masua;
	cout<<"Nhap lai sdt cua khach hang: ";
	cin.ignore();
	cin.getline(sdtsua,40);
    ifstream filein;
    filein.open("dshd.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein, str)) {
        if (str == "Ma Hoa Don: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("SDT Khach Hang: ") != string::npos && timthay)
		{
            fileout << "SDT Khach Hang: " << sdtsua << endl;
        }
        else {
            fileout << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein.close();
    fileout.close();

    remove("dshd.txt");
    rename("temp.txt", "dshd.txt");

    cout << "Da sua sdt khach hang thanh cong!" << endl;
}

void suahdDC(int&masua)
{
	char dcsua[200];
	cout<<"Nhap ma cua hoa don can sua dia chi khach hang: ";
	cin>>masua;
	cout<<"Nhap lai dia chi cua khach hang: ";
	cin.ignore();
	cin.getline(dcsua,40);
    ifstream filein;
    filein.open("dshd.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein, str)) {
        if (str == "Ma Hoa Don: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("Dia Chi Khach Hang: ") != string::npos && timthay)
		{
            fileout << "Dia Chi Khach Hang: " << dcsua << endl;
        }
        else {
            fileout << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein.close();
    fileout.close();

    remove("dshd.txt");
    rename("temp.txt", "dshd.txt");

    cout << "Da sua dia chi khach hang thanh cong!" << endl;
}

void suahdSP(int&masua)
{
	int masp;
	int tongtien =0;
	int slspsua;
	char lydo [200];
	int a[100];
	int b[100];
	int sl;
	int slkho;
	time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    string thu = ss.str();
	cout<<"Nhap ma cua hoa don can sua dia chi khach hang: ";
	cin>>masua;
	cout<<"Ly do sua: ";
	cin.ignore();
	cin.getline(lydo,200);
	cout<<"Nhap lai so sp khach hang muon dat: ";
	cin>>slspsua;
	for (int i = 0; i < slspsua; i++) {
        cout << "Nhap loai san pham thu " << i + 1 << ": ";
        cin >> masp;
        a[i] = masp;
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
                ghi << "So luong: " << slkho - sl << endl;

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
		switch (a[i])
		{
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
        }
	}
    ifstream filein;
    filein.open("dshd.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein, str))
    {
        if (str == "Ma Hoa Don: " + to_string(masua))
        {
            timthay = true;
    	}
        if (str.find("Ma san pham                   So luong") != string::npos && timthay)
		{
			fileout<<"Hoa don sau khi chinh sua: "<<endl;
            fileout << "Ma san pham                   So luong" << endl;
		    for (int i = 0; i < slspsua; i++)
		    {
		        fileout << setw(30) << left << a[i] << setw(30) << left << b[i] << endl;
		    }
		    fileout << "Ngay: " << ss.str() << endl;
		    fileout << "Tong Tien: " << tongtien << endl;
		    fileout << "Ly do sua: " << lydo << endl;
			fileout<<"Hoa don truoc khi chinh sua: "<<endl;
		}
		if (str.find("Tong Tien: ") != string::npos && timthay)
		{
	        fileout<<"Tong cua hoa don cu bi xoa!!!"<<endl;
	    }
	    else
		{
			fileout<<str<<endl;
		}
	    if (str == "--------------------------------------------------------" && timthay)
		{
		    timthay = false;
        }
	}
    filein.close();
    fileout.close();

    remove("dshd.txt");
    rename("temp.txt", "dshd.txt");

    cout << "Da sua dan sach san pham thanh cong!" << endl;
}
////////////////////////////////////////////////////////KHACH HANG////////////////////////////////////////////////////////////////////////
void optionkh ()
{
	int x=0;
	while (x!=7)
	{
		cout << "-----------------------------------------QUAN LY KHACH HANG------------------------------------" << endl;
		cout << "1. Xem danh sach khach hang " << endl;
		cout << "2. Tim khach hang"  << endl;
		cout << "3. Xem tat ca hoa don 1 khach hang bat ky da mua" << endl;
		cout << "4. Sua sdt cua khach hang" << endl;
		cout << "5. Sua ten cua khach hang" << endl;
		cout << "6. Sua dia chi cua khach hang" << endl;
		cout << "7. Thoat" << endl;

		cout << "Nhap lua chon : ";
		cin>>x;
		switch (x)
		{
			case 1:
				cout<<"////////////////////////////////// DANH SACH KHACH HANG //////////////////////////////////"<<endl;
				xemdskh();
				break;
			case 2:
				timkh();
				break;
			case 3:
				timhdcuakh();
				break;
			case 4:
				suakhSDT();
				break;
			case 5:
				suakhTEN();
				break;
			case 6:
				suakhDC();
				break;
			case 7:
				cout<<"THOAT CHUONG TRINH!!!!!!"<<endl;
				break;
			default:
				cout<<"Lua chon khong hop le!!";
				break;
		}
	}
}

void luukh(hoadon*& dshd)
{
    ofstream file;
    file.open("dskh.txt", ios::app);

    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    hoadon* current = dshd;
    while (current != NULL)
	{
        bool kiemtra = false;
        ifstream kiemtrafile("dskh.txt");
        string kiemtrastr;
        string sdt_str(current->kh.sdt);
        while (getline(kiemtrafile, kiemtrastr)) {
            if (kiemtrastr == "SDT Khach Hang: " + sdt_str)
			{
                kiemtra = true;
                break;
            }
        }
        kiemtrafile.close();

        if (!kiemtra)
		{
            file<< "--------------------------------------------------------" << endl;
            file<< "SDT Khach Hang: " << current->kh.sdt << endl;
            file<< "Ten Khach Hang: " << current->kh.ten << endl;
            file<< "Dia Chi Khach Hang: " << current->kh.diachi << endl;

        }
        current = current->next;
    }
    file.close();
}

void luukhsaukhixoahd() {
    ofstream filetemp;
    filetemp.open("temp.txt", ios::app);
    ifstream filehd;
    filehd.open("dshd.txt");
    ifstream filekh;
    filekh.open("dskh.txt");
    string dochd;
    string dockh;
    string sdt;
    bool timthay = false;
    while (getline(filekh, dockh))
	{
        if (dockh.find("SDT Khach Hang: ") != string::npos && !timthay)
		{
            string sdt(dockh);
            while (getline(filehd, dochd))
			{
                if (dochd.find("SDT Khach Hang: ") != string::npos && !timthay)
				{
					string doc(dochd);
                    if ( sdt == dochd)
                    {
                    	timthay = true;
					}
                }
            }
    	}
        if (dockh.find("--------------------------------------------------------") != string::npos && timthay)
		{ // chỉnh sửa chuỗi
	    	timthay = false;
        }
   		if (timthay)
		{
 	    	filetemp << dockh << endl;
    	}
	}
    filetemp.close();
    filehd.close();
    filekh.close();
    remove("dskh.txt");
    rename("temp.txt", "dskh.txt");
}

void xemdskh()
{
	ifstream doc;
	doc.open("dskh.txt");
	if(!doc)
	{
		cout<<"Khong the mo file"<<endl;
	}
	else
	{
		string line;
		while(getline(doc,line))
		{
			cout<<line<<endl;
		}
	}
	doc.close();
}

void timkh()
{
	int Tong = 0;
	int x= 0;
    char sdttim[50];
    cout << "Nhap sdt khach hang muon tim: ";
    cin.ignore();
    cin.getline(sdttim, 50);
    ifstream doc;
    doc.open("dskh.txt");
    bool tim = false;
    if (!doc)
    {
        cout << "Khong the mo file" << endl;
    }
    else
    {
        string str;
        while (getline(doc, str))
        {
            if (str.find("SDT Khach Hang: " + string(sdttim)) != string::npos) {
                tim = true;
                x+=1;
            }
            if (str.find("--------------------------------------------------------") != string::npos && tim)
            {
				cout<<"----------------------------------------------------------------"<<endl;;
                tim = false;
            }
            if (tim)
            {
                cout << str << endl;
            }
    	}
    }

    if (x<1)
    {
        cout << "Khong tim thay khach hang!!!!!" << endl;
    }
    doc.close();
}

void timhdcuakh()
{
	int Tong = 0;
	int x= 0;
    char sdttim[50];
    cout << "Nhap sdt khach hang muon xem hoa don: ";
    cin.ignore();
    cin.getline(sdttim, 50);
    ifstream doc;
    doc.open("dshd.txt");
    bool tim = false;
    if (!doc)
    {
        cout << "Khong the mo file" << endl;
    }
    else
    {
        string str;
        while (getline(doc, str))
        {
            if (str.find("SDT Khach Hang: " + string(sdttim)) != string::npos) {
                tim = true;
                x+=1;
            }
            if (str.find("--------------------------------------------------------") != string::npos && tim)
            {
				cout<<"----------------------------------------------------------------"<<endl;;
                tim = false;
            }
            if (tim)
            {
                cout << str << endl;
            }
    }
    cout<<"Da mua "<< x <<" hoa don ";
    }
    if(x < 10)
    {
    	cout<<" ===> Mua them "<< 10 -x <<" hoa don de tro thanh KHACH HANG BAC <==="<<endl;
	}
    else if (x>=10 && x<30)
    {
    	cout<< "===> KHACH HANG BAC <===="<<endl;
    	cout<<"Nhan voucher giam gia 3% cho 1 lan mua hang"<<endl;
	}
	else if (x >= 30 && x<50)
    {
    	cout<< "===> KHACH HANG VANG <===="<<endl;
    	cout<<"Nhan voucher giam gia 5% cho 1 lan mua hang"<<endl;
	}
	else if (x >= 50)
    {
    	cout<< "===> KHACH HANG KIM CUONG <===="<<endl;
    	cout<<"Nhan voucher giam gia 10% cho 1 lan mua hang"<<endl;
	}
    if (x<1)
    {
        cout << "Khong tim thay khach hang!!!!!" << endl;
    }
    doc.close();
}

void suakhSDT()
{
    char sdtcu[40];
    cout << "Nhap sdt cua khach hang muon sua: ";
    cin.ignore();
    cin.getline(sdtcu, 40);
    char sdtmoi[40];
    cout << "Nhap lai sdt dung cua khach hang: ";
    cin.getline(sdtmoi, 40);
    ifstream filein1;
    filein1.open("dshd.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("temphd.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "SDT Khach Hang: " + string(sdtcu)) {
            timthay = true;
        }
        if (str.find("SDT Khach Hang: ") != string::npos && timthay) {
            fileout1 << "SDT Khach Hang: " << sdtmoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dshd.txt");
    rename("temphd.txt", "dshd.txt");

    ifstream filein2;
    filein2.open("dskh.txt");

    if (!filein2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout2;
    fileout2.open("tempkh.txt");

    if (!fileout2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    while (getline(filein2, str)) {
        if (str == "SDT Khach Hang: " + string(sdtcu)) {
            fileout2 << "SDT Khach Hang: " << sdtmoi << endl;
        }
        else {
            fileout2 << str << endl;
        }
    }

    filein2.close();
    fileout2.close();

    remove("dskh.txt");
    rename("tempkh.txt", "dskh.txt");

    cout << "Da sua sdt khach hang thanh cong!" << endl;
}
void suakhTEN()
{
    char sdt[40];
    cout << "Nhap sdt cua khach hang muon sua ten: ";
    cin.ignore();
    cin.getline(sdt, 40);
    char tenmoi[40];
    cout << "Nhap lai ten dung cua khach hang: ";
    cin.getline(tenmoi, 40);
    ifstream filein1;
    filein1.open("dshd.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("temphd.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "SDT Khach Hang: " + string(sdt)) {
            timthay = true;
        }
        if (str.find("Ten Khach Hang: ") != string::npos && timthay) {
            fileout1 << "Ten Khach Hang: " << tenmoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dshd.txt");
    rename("temphd.txt", "dshd.txt");

    ifstream filein2;
    filein2.open("dskh.txt");

    if (!filein2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout2;
    fileout2.open("tempkh.txt");

    if (!fileout2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    timthay = false;  // gán lại biến timthay thành false
    while (getline(filein2, str)) {
        if (str == "SDT Khach Hang: " + string(sdt)) {
            timthay = true;
        }
        if (str.find("Ten Khach Hang: ") != string::npos && timthay) {
            fileout2 << "Ten Khach Hang: " << tenmoi << endl;
        }
        else {
            fileout2 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein2.close();
    fileout2.close();

    remove("dskh.txt");
    rename("tempkh.txt", "dskh.txt");

    cout << "Da sua ten khach hang thanh cong!" << endl;
}

void suakhDC()
{
    char sdt[40];
    cout << "Nhap sdt cua khach hang muon sua dia chi: ";
    cin.ignore();
    cin.getline(sdt, 40);
    char dcmoi[200];
    cout << "Nhap lai dia chi dung cua khach hang: ";
    cin.getline(dcmoi, 40);
    ifstream filein1;
    filein1.open("dshd.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("temphd.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "SDT Khach Hang: " + string(sdt)) {
            timthay = true;
        }
        if (str.find("Dia Chi Khach Hang: ") != string::npos && timthay) {
            fileout1 << "Dia Chi Khach Hang: " << dcmoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dshd.txt");
    rename("temphd.txt", "dshd.txt");

    ifstream filein2;
    filein2.open("dskh.txt");

    if (!filein2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout2;
    fileout2.open("tempkh.txt");

    if (!fileout2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    while (getline(filein2, str)) {
        if (str == "SDT Khach Hang: " + string(sdt)) {
            timthay = true;
        }
        if (str.find("Dia Chi Khach Hang: ") != string::npos && timthay) {
            fileout2 << "Dia Chi Khach Hang: " << dcmoi << endl;
        }
        else {
            fileout2 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein2.close();
    fileout2.close();

    remove("dskh.txt");
    rename("tempkh.txt", "dskh.txt");

    cout << "Da sua sdt khach hang thanh cong!" << endl;
}


/////////////////////////////////////////////////////NHAN VIEN////////////////////////////////////////////////////////////////////
int optionnv()
{
    while (true) {
        cout << "--------------------------------- QUAN LY NHAN VIEN --------------------------------------------\n";
        cout << "1. Them nhan vien\n";
        cout << "2. Luu nhan vien\n";
        cout << "3. Xem danh sach nhan vien\n";
        cout << "4. Cap nhat trang thai lam viec\n";
        cout << "5. Tim nhan vien\n";
        cout << "6. Xoa nhan vien\n";
        cout << "7. Cham cong va tinh luong\n";
        cout << "8. Xem bang luong\n";
        cout << "9. Xem luong cua 1 nhan vien bat ky\n";
        cout << "10.Xem luong cua 1 thang bat ky\n";
        cout << "11. Sua thong tin nhan vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        int choice;
        cin >> choice;

        if (choice == 0)
		{
            break;
		}
        switch (choice) {
            case 1:
                themnv() ;
                break;
            case 2:
                luunv();
                break;
            case 3:
                xemdsnv();
                break;
            case 4:
                capnhatlamviec();
                break;
            case 5:
                timnv();
                break;
            case 6:
                xoanv();
                break;
            case 7:
            	chamcongvatinhluong();
            	break;
            case 8:
            	xembangluong();
            	break;
            case 9:
            	xemluong1nv();
            	break;
            case 10:
            	xemluong1thang();
            	break;
            case 11:
            	optionsuanv();
            	break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    }

    return 0;
}

nhanvien* dsnv = NULL;

void themnv()
{
    int manv;
    char hotennv[40];
    char chucvu [40];
    char sdt[12];
    cout<<"Nhap ma cua nhan vien: ";
    cin>>manv;
    cout<<"Nhap ten nhan vien: ";
    cin.ignore();
    cin.getline(hotennv,40);
    cout<<"Chuc vu: ";
    cin.getline(chucvu,40);
    cout<<"So dien thoai: ";
    cin.getline(sdt,12);

    // Thêm nhân viên vào danh sách
    nhanvien* nvMoi = new nhanvien;
    nvMoi->manv = manv;
    strcpy(nvMoi->ten, hotennv);
    strcpy(nvMoi->chucvu, chucvu);
    strcpy(nvMoi->sdt, sdt);
    nvMoi->lamviec = true;
    nvMoi->next = dsnv;
    dsnv = nvMoi;

    cout << "Them nhan vien thanh cong.\n";
}

void luunv()
{
    ofstream file;
    file.open("dsnv.txt", ios::app);

    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    nhanvien* current = dsnv;
    while (current != NULL)
    {
        bool kiemtra = false;
        ifstream kiemtrafile("dsnv.txt");
        string kiemtrastr;
        string manv_str = to_string(current->manv);
        while (getline(kiemtrafile, kiemtrastr)) {
            if (kiemtrastr == "Ma so: " + manv_str)
            {
                kiemtra = true;
                break;
            }
        }
        kiemtrafile.close();

        if (!kiemtra)
        {
        	file<< "--------------------------------------------------------" << endl;
            file<< "Ma so: " << current->manv << endl;
            file<< "Ten: " << current->ten << endl;
            file<< "Chuc vu: " << current->chucvu << endl;
			file<< "So dien thoai: "<< current ->sdt<<endl;
            file<< "Trang thai lam viec: Dang lam viec"<<endl;
        }
        current = current->next;
    }
    file.close();
}
void xemdsnv()
{
	ifstream doc;
	doc.open("dsnv.txt");
	if(!doc)
	{
		cout<<"Khong the mo file"<<endl;
	}
	else
	{
		string line;
		while(getline(doc,line))
		{
			cout<<line<<endl;
		}
	}
	doc.close();
}
void capnhatlamviec()
{
	int x;
	int masua;
	cout<<"Nhap ma cua nhan vien muon sua trang thai lam viec ";
	cin>>masua;
	cout<<"1. Dang lam viec"<<endl;
	cout<<"2. Dang tam nghi"<<endl;
	cout<<"Nhap lai trang thai lam viec: "<<endl;
	cin>>x;

    ifstream filein;
    filein.open("dsnv.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein, str)) {
        if (str == "Ma so: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("Trang thai lam viec: ") != string::npos && timthay)
		{
			if(x==1)
			{
				fileout<<"Trang thai lam viec: Dang lam viec"<<endl;
			}
			if(x==2)
			{
				fileout<<"Trang thai lam viec: Dang tam nghi"<<endl;
			}
        }
        else {
            fileout << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein.close();
    fileout.close();

    remove("dsnv.txt");
    rename("temp.txt", "dsnv.txt");

    cout << "Da sua trang thai lam viec cua nhan vien thanh cong!" << endl;
}
void chamcongvatinhluong()
{
    int ngaylam;
    long long luong= 0;
    int thang;
    int nam;
    cout<<"Nhap cham cong cua thang : ";
    cin>>thang;
    while(thang > 12 or thang <0 )
    {
    	cout<<"Thang khong hop le!! Vui long nhap lai: ";
    	cin>>thang;
	}

    cout<<"Nam: ";
    cin>>nam;
    while(nam < 0)
    {
    	cout<<"Nam khong hop le!! Vui long nhap lai: ";
    	cin>>nam;
	}

    ofstream file;
    file.open("bangluong.txt", ios::app);
    ifstream file1;
    file1.open("dsnv.txt");

    if (!(file && file1)) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    file<<"BANG LUONG "<<thang<<"/"<<nam<<endl;
    string str;
    bool tim = false;
    while(getline(file1,str))
    {
        if (str.find("Ma so: ")!= string::npos && !tim)
		{
			tim = true;
            cout<<str<<endl;
            cout<<"Nhap so ngay lam viec: ";
            cin>>ngaylam;
            if(thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang ==10 or thang == 12 )
            {
            	while(ngaylam >31 or ngaylam < 0)
            	{
            		cout<<"Ngay khong hop le!! Vui long nhap lai: ";
            		cin>>ngaylam;
				}
			}
			else if (thang == 4 or thang == 6 or thang == 9 or thang == 11)
			{
				while(ngaylam >30 or ngaylam <0)
				{
					cout<<"Ngay khong hop le!! Vui long nhap lai: ";
					cin>>ngaylam;
				}
			}
			else
			{
				if(nam%400==0)
				{
					while(ngaylam > 29 or ngaylam <0)
					{
						cout<<"Ngay khong hop le!! Vui long nhap lai: ";
						cin>>ngaylam;
					}
				}
				else if (nam % 4 == 0 && nam%100!=0 )
				{
					while(ngaylam > 29 or ngaylam <0)
					{
						cout<<"Ngay khong hop le!! Vui long nhap lai: ";
						cin>>ngaylam;
					}
				}
				else
				{
					while(ngaylam > 28 or ngaylam <0)
					{
						cout<<"Ngay khong hop le!! Vui long nhap lai: ";
						cin>>ngaylam ;
					}
				}
			}
        }

        if(str.find("Chuc vu: thu ngan")!= string::npos && tim)
        {
            file<<"So ngay lam viec: "<<ngaylam<<endl;
            file<<"Luong: "<<ngaylam*100000<<endl;
            tim = false;
        }
        else if (str.find("Chuc vu: ban hang")!= string::npos)
        {
            file<<"So ngay lam viec: "<<ngaylam<<endl;
            file<<"Luong: "<<ngaylam*100000<<endl;
            tim = false;
        }
        else if (str.find("Chuc vu: tho lam banh")!= string::npos)
        {
            file<<"So ngay lam viec: "<<ngaylam<<endl;
            file<<"Luong: "<<ngaylam*200000<<endl;
            tim = false;
    	}
    	if(tim)
    	{
    		file<<str<<endl;
		}
    }
    file<<"------------------------------------------------------------------"<<endl;
    file.close();
    file1.close();
}
void timnv()
{
	int matim;
	int x= 0;
    cout << "Nhap ma cua nhan vien muon tim : ";
    cin>> matim;
    ifstream doc;
    doc.open("dsnv.txt");
    bool tim = false;
    if (!doc)
    {
        cout << "Khong the mo file" << endl;
    }
    else
    {
        string str;
        while (getline(doc, str))
        {
            if (str.find("Ma so: " + to_string(matim)) != string::npos) {
                tim = true;
                x+=1;
            }
            if (str.find("--------------------------------------------------------") != string::npos && tim)
            {
				cout<<"----------------------------------------------------------------"<<endl;;
                tim = false;
            }
            if (tim)
            {
                cout << str << endl;
            }
    	}
    }

    if (x<1)
    {
        cout << "Khong tim thay nhan vien!!!!!" << endl;
    }
    doc.close();
}
void xoanv()
{
    int maxoa;
    cout << "Nhap ma so cua nhan vien muon xoa: ";
    cin >> maxoa;

    ifstream filein;
    filein.open("dsnv.txt");

    if (!filein) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout;
    fileout.open("temp.txt");

    if (!fileout) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool xoa = false;
    while (getline(filein, str))
	{
        while (getline(filein, str))
	{
        if (str == "Ma so: " + to_string(maxoa)) {
            xoa = true;
        }
        if (str == "--------------------------------------------------------" && xoa) {
            xoa = false;
        }
        if (!xoa) {
            fileout << str << endl;
        }
		fileout.close();
}}

    remove("dsnv.txt");
    rename("temp.txt", "dsnv.txt");

    cout << "Da xoa nhan vien khoi file dsnv.txt!" << endl;
}
void xembangluong()
{
	ifstream doc;
	doc.open("bangluong.txt");
	if(!doc)
	{
		cout<<"Khong the mo file"<<endl;
	}
	else
	{
		string line;
		while(getline(doc,line))
		{
			cout<<line<<endl;
		}
	}
	doc.close();
}
void xemluong1nv()
{
	int matim;
	cout<<"Nhap ma so de xem luong hang thang cua 1 nhan vien bat ki: ";
	cin>>matim;
	ifstream file;
	file.open("bangluong.txt");
	string line;
	bool tim = true;
	while(getline(file,line))
	{
		if(line.find("BANG LUONG ")!= string :: npos)
		{
			tim = true;
		}
		if(line == "Ma so: " + to_string(matim))
		{
			tim = true;
		}
		if(line.find("Luong: ")!= string :: npos&& tim)
		{
			tim = false;
		}
		if(tim)
		{
			cout<<line<<endl;
		}

	}

}
void xemluong1thang()
{
	int thang;
	int nam;
	cout<<"Nhap thang muon xem bang luong: ";
	cin>>thang;
	cout<<"Nhap nam: ";
	cin>>nam;
	ifstream file;
	file.open("bangluong.txt");
	string line;
	bool tim = false;
	while(getline(file,line))
	{
		if(line == "BANG LUONG "+to_string(thang)+"/"+to_string(nam))
		{
			tim = true;
		}
		if(line.find("------------------------------------------------------------------")&&true)
		{
			tim = false;
		}
		if (tim)
		{
			cout<<line<<endl;
		}
	}
	file.close();
}
void optionsuanv()
{
	int x=0;
	while(x!=4)
	{
		cout<<"1. Sua ten cua nhan vien."<<endl;
		cout<<"2. Sua sdt cua nhan vien."<<endl;
		cout<<"3. Sua chuc vu cua nhan vien"<<endl;
		cout<<"4. Thoat chuc nang"<<endl;
		cout<<"Chon 1 lua chon: ";
		cin>>x;
		switch(x)
		{
			case 1:
				suanvTEN();
				break;
			case 2:
				suanvSDT();
				break;
			case 3:
				suanvCHUCVU();
				break;
			case 4:
				cout<<"Thoat chuc nang!!!!!"<<endl;
				break;
			default:
				cout<<"Lua chon khong hop le!!!!!"<<endl;
		}
	}
}
void suanvTEN()
{
    int masua;
    cout << "Nhap ma so cua nhan vien muon sua ten: ";
    cin>>masua;
    char tenmoi[40];
    cout << "Nhap lai ten dung cua nhan vien: ";
    cin.ignore();
    cin.getline(tenmoi, 40);
    ifstream filein1;
    filein1.open("dsnv.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("tempnv.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "Ma so: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("Ten: ") != string::npos && timthay) {
            fileout1 << "Ten: " << tenmoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dsnv.txt");
    rename("tempnv.txt", "dsnv.txt");

    ifstream filein2;
    filein2.open("bangluong.txt");

    if (!filein2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout2;
    fileout2.open("tempbangluong.txt");

    if (!fileout2) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    timthay = false;
    while (getline(filein2, str))
	{
        if (str == "Ma so: " + to_string(masua)&& !timthay)
		{
            timthay = true;
        }
        if (str.find("Ten: ") != string::npos && timthay) {
            fileout2 << "Ten: " << tenmoi << endl;
        }
        else
		{
            fileout2 << str << endl;
        }
        if (str.find("Ma so: ") != string::npos && timthay)
		{
            timthay = false;
        }
    }

    filein2.close();
    fileout2.close();

    remove("bangluong.txt");
    rename("tempbangluong.txt", "bangluong.txt");

    cout << "Da sua ten nhan vien thanh cong!" << endl;
}
void suanvSDT()
{
    int masua;
    cout << "Nhap ma so cua nhan vien muon sua sdt: ";
    cin>>masua;
    char sdtmoi[12];
    cout << "Nhap lai sdt dung cua nhan vien: ";
    cin.ignore();
    cin.getline(sdtmoi, 12);
    ifstream filein1;
    filein1.open("dsnv.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("tempnv.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "Ma so: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("So dien thoai: ") != string::npos && timthay) {
            fileout1 << "So dien thoai: " << sdtmoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dsnv.txt");
    rename("tempnv.txt", "dsnv.txt");


    cout << "Da sua sdt nhan vien thanh cong!" << endl;
}
void suanvCHUCVU()
{
    int masua;
    cout << "Nhap ma so cua nhan vien muon sua chuc vu: ";
    cin>>masua;
    char chucvumoi[50];
    cout << "Nhap lai chuc vu dung cua nhan vien: ";
    cin.ignore();
    cin.getline(chucvumoi, 50);
    ifstream filein1;
    filein1.open("dsnv.txt");

    if (!filein1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    ofstream fileout1;
    fileout1.open("tempnv.txt");

    if (!fileout1) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string str;
    bool timthay = false;
    while (getline(filein1, str)) {
        if (str == "Ma so: " + to_string(masua)) {
            timthay = true;
        }
        if (str.find("Chuc vu: ") != string::npos && timthay) {
            fileout1 << "Chuc vu: " << chucvumoi << endl;
        }
        else {
            fileout1 << str << endl;
        }
        if (str == "--------------------------------------------------------" && timthay) {
            timthay = false;
        }
    }

    filein1.close();
    fileout1.close();

    remove("dsnv.txt");
    rename("tempnv.txt", "dsnv.txt");


    cout << "Da sua chuc vu nhan vien thanh cong!" << endl;
}
/////////////////////////////////////////////DOANH THU////////////////////////////////////////////////////////
void optiondoanhthu()
{
	int x=0;
	while(x!=4)
	{
		cout<<"----------------------- QUAN LY DOANH THU ------------------------"<<endl;
		cout<<"1. Xem doanh thu theo ngay"<<endl;
		cout<<"2. Xem doanh thu theo thang"<<endl;
		cout<<"3. Xem doanh thu theo nam"<<endl;
		cout<<"4. Thoat chuc nang"<<endl;
		cout<<"Nhap lua chon: ";
		cin>>x;
		switch(x)
		{
			case 1:
			tinhdoanhthutheongay();
			break;
			case 2:
			tinhdoanhthutheothang();
			break;
			case 3:
			tinhdoanhthutheonam();
			break;
			case 4:
			cout<<"Thoat chuc nang"<<endl;
			break;
		}
	}

}
void tinhdoanhthutheongay()
{
    int tongtien_ngay = 0;
    int ngay, thang, nam;
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;

    string kiemtrastr;
    ifstream kiemtrafile("dshd.txt");
    bool tim = false;
    while (getline(kiemtrafile, kiemtrastr))
	{
		if(ngay>10 && thang<10)
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
	            int nam_hd = stoi(kiemtrastr.substr(6, 4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 1));
	            int ngay_hd = stoi(kiemtrastr.substr(13, 2));
	            if (ngay_hd == ngay && thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                while (getline(kiemtrafile, kiemtrastr))
					{
						if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
						{
	                    	if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        {
	                        	tongtien_ngay += stoi(kiemtrastr.substr(11));
	                        	break;
							}
	                    }
	                }
	                tim = false;
	            }
	    	}
        }
        else if(ngay<10 && thang>10)
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
	            int nam_hd = stoi(kiemtrastr.substr(6, 4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 2));
	            int ngay_hd = stoi(kiemtrastr.substr(14, 1));
	            if (ngay_hd == ngay && thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                while (getline(kiemtrafile, kiemtrastr))
					{

						if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
						{
	               	        if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        {
	                        	tongtien_ngay += stoi(kiemtrastr.substr(11));
	                        	break;
							}
	                    }
	                }
	                tim = false;
	            }
	    	}
        }
        else if(ngay<10 && thang<10)
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
	            int nam_hd = stoi(kiemtrastr.substr(6, 4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 1));
	            int ngay_hd = stoi(kiemtrastr.substr(13, 1));
	            if (ngay_hd == ngay && thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                 while (getline(kiemtrafile, kiemtrastr))
					{
						if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
						{
	                   		if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        {
	                        	tongtien_ngay += stoi(kiemtrastr.substr(11));
	                        	break;
							}
	                    }
	                }
	                tim = false;
	            }
	    	}
        }
        else
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
	            int nam_hd = stoi(kiemtrastr.substr(6, 4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 2));
	            int ngay_hd = stoi(kiemtrastr.substr(14, 2));
	            if (ngay_hd == ngay && thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                while (getline(kiemtrafile, kiemtrastr))
					{
							if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
							{
	                        	if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        	{
	                        		tongtien_ngay += stoi(kiemtrastr.substr(11));
								}
								break;
	                    	}

	                }
	                tim = false;
	            }
	    	}
        }
}

    kiemtrafile.close();

    if (tongtien_ngay > 0) {
        cout << "Tong tien cac hoa don trong ngay " << ngay << "/" << thang << "/" << nam << " la: " << tongtien_ngay << endl;
    } else {
        cout << "Khong co hoa don nao trong ngay " << ngay << "/" << thang << "/" << nam << endl;
    }

}
void tinhdoanhthutheothang()
{
    int tongtien_thang = 0;
    int thang, nam;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;

    string kiemtrastr;
    ifstream kiemtrafile("dshd.txt");
    bool tim = false;
    while (getline(kiemtrafile, kiemtrastr))
	{
		if(thang<10)
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
				int nam_hd = stoi(kiemtrastr.substr(6,4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 1));
	            if (thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                while (getline(kiemtrafile, kiemtrastr))
					{
						if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
						{
	                    	if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        {
	                        	tongtien_thang += stoi(kiemtrastr.substr(11));
	                        	break;
							}
	                    }
	                }
	                tim = false;
	            }
	    	}
        }
        else if(thang>10)
		{
	        if (kiemtrastr.find("Ngay: ") != string::npos)
			{
	            int nam_hd = stoi(kiemtrastr.substr(6, 4));
	            int thang_hd = stoi(kiemtrastr.substr(11, 2));
	            if (thang_hd == thang && nam_hd == nam)
				{
					tim = true;
	                while (getline(kiemtrafile, kiemtrastr))
					{

						if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
						{
	               	        if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                        {
	                        	tongtien_thang+= stoi(kiemtrastr.substr(11));
	                        	break;
							}
	                    }
	                }
	                tim = false;
	            }
	    	}
        }
	}

    kiemtrafile.close();

    if (tongtien_thang > 0) {
        cout << "Tong tien cac hoa don trong thang " << thang << "/" << nam << " la: " << tongtien_thang << endl;
    } else {
        cout << "Khong co hoa don nao trong thang " << thang << "/" << nam << endl;
    }

}
void tinhdoanhthutheonam()
{
    int tongtien_nam = 0;
    int nam;
    cout << "Nhap nam: ";
    cin >> nam;

    string kiemtrastr;
    ifstream kiemtrafile("dshd.txt");
    bool tim = false;
    while (getline(kiemtrafile, kiemtrastr))
	{
	    if (kiemtrastr.find("Ngay: ") != string::npos)
		{
	        int nam_hd = stoi(kiemtrastr.substr(6, 4));
	        if (nam_hd == nam)
			{
				tim = true;
	            while (getline(kiemtrafile, kiemtrastr))
				{
					if(kiemtrastr.find( "Tong cua hoa don cu bi xoa!!!") == string :: npos&& tim)
					{
	               	if (kiemtrastr.find("Tong Tien: ") != string::npos&& tim)
	                    {
	                        tongtien_nam += stoi(kiemtrastr.substr(11));
	                        break;
						}
	                }
	            }
	            tim = false;
	        }
	    }
    }

    kiemtrafile.close();

    if (tongtien_nam > 0) {
        cout << "Tong tien cac hoa don trong nam " << nam << " la: " << tongtien_nam << endl;
    } else {
        cout << "Khong co hoa don nao trong nam " <<nam << endl;
    }

}
//////////////////////////////////////////////////////// KHO /////////////////////////////////////////////////////////////
void optionkho()
{
	sanpham* sp = NULL;
    int luaChon= 0;

    do
    {
        cout << "-------------------------------- QUAN LY KHO -------------------------------"<<endl;
        cout << "1. Them san pham moi\n";
        cout << "2. Luu san pham moi nhap vao file\n";
        cout << "3. Cap nhat lai so luong moi cua 1 san pham \n";
        cout << "4. Xoa san pham theo ma so\n";
        cout << "5. Tim kiem san pham theo ma so\n";
        cout << "6. Xuat danh sach trong kho \n";
        cout << "7. Thoat chuong trinh\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon)
        {
            case 1:
            themsp(sp);
            break;

            case 2:
            luusp(sp);
            break;

            case 3:
            capnhatsl();
            break;

            case 4:
            xoasp();
            break;

            case 5:
            timsp();
            break;

            case 6:
            xuatdskho();
            break;

            case 7:
            cout<<"Thoat chuong trinh";
            break;

            default:
            break;
        }

        cout << endl;

    } while (luaChon != 7);

}

void themsp(sanpham* &sp)
{
	char tensp[100];
    int masp;
    int sl;
    cout<<"Nhap ma cua san pham: ";
    cin>>masp;
    switch (masp)
    {
    	case 11:
    	strcpy(tensp,"Phin sua da");
    	break;
        case 12:
        strcpy(tensp,"Phin den da");
    	break;
        case 13:
        strcpy(tensp,"Bac xiu");
        break;
        case 14:
        strcpy(tensp,"Phindi hanh nhan");
        break;
    	case 15:
    	strcpy(tensp,"Phindi kem sua");
        break;
        case 16:
        strcpy(tensp,"Phindi choco");
        break;
        case 21:
        strcpy(tensp,"Espresso");
        break;
        case 31:
        strcpy(tensp,"Cappuchino");
        break;
        case 32:
        strcpy(tensp,"Mocha");
        break;
        case 33:
        strcpy(tensp,"Que Pate");
        break;
        case 41:
        strcpy(tensp,"Que Ga Pho Mai");
        break;
        case 42:
        strcpy(tensp,"Tra Sen Vang");
        break;
        case 43:
        strcpy(tensp,"Tra thach dao");
        break;
        case 51:
    	strcpy(tensp,"Tra thanh dao");
        break;
        case 52:
        strcpy(tensp,"Tra thach vai");
        break;
        case 53:
        strcpy(tensp,"Tra xanh dau do");
        break;
        case 61:
    	strcpy(tensp,"Banh pho mai chanh day");
        break;
        case 62:
        strcpy(tensp,"Banh pho mai caphe");
        break;
        case 63:
        strcpy(tensp,"Tiramisu");
        break;
        case 64:
        strcpy(tensp,"Mousse dao");
        break;
        case 65:
        strcpy(tensp,"Mousse cacao");
        break;
        case 66:
        strcpy(tensp," Banh chuoi");
        break;

        default:
        cout << "Lua chon khong hop le!";
        return;
	}

    cout << "Nhap so luong: ";
    cin >> sl;

    sanpham* new_sp = new sanpham;
    new_sp->masp = masp;
    strcpy(new_sp->ten, tensp);
    new_sp->slkho = sl;
    new_sp->next = NULL;

    if (sp == NULL) {
        sp = new_sp;
    } else {
        sanpham* current = sp;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_sp;
    }
}

void luusp(sanpham* &sp) {
    ofstream file;
    file.open("kho.txt", ios::app);

    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    sanpham* current = sp;
    while (current != NULL) {
        bool kiemtra = false;
        ifstream kiemtrafile("kho.txt");
        string kiemtrastr;
        string masp_str = to_string(current->masp);
        while (getline(kiemtrafile, kiemtrastr)) {
            if (kiemtrastr == "Ma so: " + masp_str) {
                kiemtra = true;
                break;
            }
        }
        kiemtrafile.close();

        if (!kiemtra) {
            file << "--------------------------------------------------------" << endl;
            file << "Ma so: " << current->masp << endl;
            file << "Ten san pham: " << current->ten << endl;
            file << "So luong: " << current->slkho << endl;
            file << "--------------------------------------------------------" << endl;
        }
        if (current->next == NULL) break;
        current = current->next;
    }
    file.close();
}
void capnhatsl()
{
	int ms;
	int sl;
	cout<<"Nhap ma so cua san pham muon cap nhat lai so luong: ";
	cin>>ms;
	cout<<"Nhap lai so luong: ";
	cin>>sl;
	ifstream file;
	file.open("kho.txt");
	ofstream ghi;
	ghi.open("temp.txt",ios::app);
	string str;
	bool tim = false;
	while(getline(file,str))
	{
		if(str == "Ma so: "+ to_string(ms))
		{
			tim = true;
		}
		if (str.find("So luong: ")!=string::npos && tim)
		{
			ghi<<"So luong: "<<sl<<endl;
		}
		else
		{
			ghi<<str<<endl;
		}
		if(str == "--------------------------------------------------------" && tim)
		{
			tim = false;
		}
	}
	file.close();
	ghi.close();
	remove("kho.txt");
	rename("temp.txt","kho.txt");
}

void xoasp()
{
	int ms;
	cout<<"Nhap ma so cua san pham muon xoa khoi kho: ";
	cin>>ms;
	ifstream file;
	file.open("kho.txt");
	ofstream ghi;
	ghi.open("temp.txt",ios::app);
	string str;
	bool tim = false;
	while(getline(file,str))
	{
		if(str == "Ma so: "+ to_string(ms))
		{
			tim = true;
		}
		if(str == "--------------------------------------------------------" && tim)
		{
			tim = false;
		}
		if(!tim)
		{
			ghi<<str<<endl;
		}
	}
	file.close();
	ghi.close();
	remove("kho.txt");
	rename("temp.txt","kho.txt");
}
void timsp()
{
	int ms;
	cout<<"Nhap ma so cua san pham muon tim: ";
	cin>>ms;
	ifstream file;
	file.open("kho.txt");
	string str;
	bool tim = false;
	while(getline(file,str))
	{
		if(str == "Ma so: "+ to_string(ms))
		{
			tim = true;
		}
		if(str == "--------------------------------------------------------" && tim)
		{
			tim = false;
		}
		if(tim)
		{
			cout<<str<<endl;
		}
	}
	file.close();
}
void xuatdskho()
{
	ifstream file;
	file.open("kho.txt");
	if(!file)
	{
		cout<<"Khong the mo file!";
	}
	string str;
	while(getline(file,str))
	{
		cout<<str<<endl;
	}
	file.close();
}
