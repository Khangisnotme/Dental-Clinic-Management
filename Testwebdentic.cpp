#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // For system("cls")
using namespace std;
// Forward declarations
class DentalClinic;
class Member;
class Patient;
class Dentist;
class Admin;
class Appointment;
DentalClinic* createDentalClinic();

// Base class for members
class Member {
public:
    Member(const string& username, const string& password,
           const string& fullName, const string& email,
           const string& phoneNumber, int birthYear)
        : username(username), password(password), fullName(fullName),
          email(email), phoneNumber(phoneNumber), birthYear(birthYear) {}
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    virtual ~Member() {}

protected:
    string username;
    string password;
    string fullName;
    string email;
    string phoneNumber;
    int birthYear;
};

// Patient class derived from Member
class Patient : public Member {
public:

    string getFullName() const;
    string getAddress() const;
    int getBirthYear() const;
    Patient(const string& username, const string& password,
            const string& fullName, const string& email,
            const string& phoneNumber, int birthYear,
            const string& idCard, const string& address,
            const string& occupation, const string& birthPlace)
        : Member(username, password, fullName, email, phoneNumber, birthYear),
          idCard(idCard), address(address), occupation(occupation),
          birthPlace(birthPlace) {}

private:
    std::string idCard;
    std::string address;
    std::string occupation;
    std::string birthPlace;
};

// Dentist class derived from Member
class Dentist : public Member {
public:
    string getFullName() const {
        return fullName;
    }

    string getCode() const {
        return code;
    }

    Dentist(const string& username, const std::string& password,const std::string& code,
        const string& fullName, const std::string& email,
        const string& phoneNumber, int birthYear,
        const std::string& specialization, const std::string& position,
        const std::string& qualification, const std::string& workplace, const std::string& clinicCode)
    : Member(username, password, fullName, email, phoneNumber, birthYear),
      specialization(specialization), position(position), code(code), fullName(fullName),
      qualification(qualification), workplace(workplace) {}

private:
    string code;
    string fullName;
    string specialization;
    string position;
    string qualification;
    string workplace;
};

// Admin class derived from Member
class Admin : public Member {
public:
    Admin() : Member("", "", "", "", "", 0), adminLevel("") {}
    Admin(const std::string& username, const std::string& password,
          const std::string& fullName, const std::string& email,
          const std::string& phoneNumber, int birthYear,
          const std::string& adminLevel)
        : Member(username, password, fullName, email, phoneNumber, birthYear),
          adminLevel(adminLevel) {}

private:
    std::string adminLevel;
};


// Appointment class
class Appointment {
public:




    string getPatientCode() const {
        return patientCode;
    }
    string getCode() const {
        return code;
    }

    string getDateTime() const {
        return dateTime;
    }
    string getDentistCode() const {
        return dentistCode;
    }
    string getStatus() const {
        return status;
    }
    // Các hàm thành viên public để truy cập và thiết lập giá trị
    void setCode(const std::string& newCode) {
        code = newCode;
    }

    void setDateTime(const std::string& newDateTime) {
        dateTime = newDateTime;
    }

    void setAppointmentNumber(int newAppointmentNumber) {
        appointmentNumber = newAppointmentNumber;
    }



    int getAppointmentNumber() const {
        return appointmentNumber;
    }

     Appointment(const string& code, const string& dateCreated,
                const string& dateTime, int appointmentNumber,
                const string& content = "", const string& status = "",
                const string& dentistCode = "", const string& patientCode = "",
                const string& schedule = "", const string& displayStatus = "")
        : code(code), dateCreated(dateCreated), dateTime(dateTime),
          appointmentNumber(appointmentNumber), content(content), status(status),
          dentistCode(dentistCode), patientCode(patientCode),
          schedule(schedule), displayStatus(displayStatus) {}

private:
    string code;
    string dateCreated;
    string dateTime;
    int appointmentNumber;
    string content;
    string status;
    string dentistCode;
    string patientCode;
    string schedule;
    string displayStatus;
};

class DentalClinic {
public:
    // Thông tin và chức năng của phòng khám nha khoa
    vector<Patient> patients; // Danh sách bệnh nhân
    // Danh sách nha sĩ
    vector<Appointment> appointments; // Danh sách lịch hẹn

    // Các thành viên và chức năng khác của phòng khám nha khoa
    string getDentistName(const string& dentistCode) const {
        for (const auto& dentist : dentists) {
            if (dentist.getCode() == dentistCode) {
                return dentist.getFullName();
            }
        }
        return "Unknown Dentist";  // Modify this as needed
    }
    // Hàm khởi tạo
    DentalClinic() {
        // Khởi tạo các thành viên và dữ liệu khác cần thiết
    }

    // Hàm thêm bệnh nhân vào danh sách
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    // Hàm kiểm tra danh sách bệnh nhân có trống hay không
    bool isEmpty() const {
        return patients.empty();
    }

private:
     vector<Dentist> dentists;// Các hàm và chức năng khác có thể được thêm vào tùy thuộc vào yêu cầu
};

//Ham dặt lịch hẹn
void datLichHen(DentalClinic* dentalClinic) {
    string code, dateTime;
    int appointmentNumber;

    // Get input for appointment details
    cout << "Nhap ma lich hen: ";
    cin >> code;
    cout << "Nhap thoi gian lich hen (vd: 2023-12-31 14:30): ";
    cin.ignore();
    getline(cin, dateTime);
    cout << "Nhap so thu tu lich hen: ";
    cin >> appointmentNumber;
    cout << endl;
    cout << "Da them lich hen thanh cong." << endl;
    string appointmentNumberStr = to_string(appointmentNumber);

    // Chuyển đổi kiểu std::string sang int
    int convertedAppointmentNumber = stoi(appointmentNumberStr);
    // Tạo đối tượng Appointment với giá trị chuyển đổi
    Appointment newAppointment(code, "", dateTime, convertedAppointmentNumber, "", "", "", "", "");

    // Set values using member functions
    newAppointment.setCode(code);
    newAppointment.setDateTime(dateTime);
    newAppointment.setAppointmentNumber(appointmentNumber);

    // Add the appointment to the clinic's list
    dentalClinic->appointments.push_back(newAppointment);

}




// Định nghĩa hàm createDentalClinic
DentalClinic* createDentalClinic() {
    return new DentalClinic();
}
void inDanhSachBenhNhanVaLichHen(const DentalClinic* dentalClinic) {
    if (dentalClinic->isEmpty()) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }

    cout << "Danh sach benh nhan va lich hen:" << endl;

    for (const auto& patient : dentalClinic->patients) {
        cout << "\033[1;31mThong tin benh nhan\033[0m" << endl;
        cout << "ID: " << patient.getUsername() << endl;
        cout << "Ho va ten: " << patient.getFullName() << endl;
        cout << "Nam sinh: " << patient.getBirthYear() << endl;
        cout << "Dia chi: " << patient.getAddress() << endl;

        cout << "\033[1;34mDanh sach lich hen\033[0m" << endl;
        bool hasAppointments = false;

        for (const auto& appointment : dentalClinic->appointments) {
            if (appointment.getPatientCode() == patient.getUsername()) {
                hasAppointments = true;
                cout << "Ma lich hen: " << appointment.getCode() << endl;
                cout << "Thoi gian: " << appointment.getDateTime() << endl;
                cout << "Nha si: " << getDentistName(dentalClinic, appointment.getDentistCode()) << endl;
                cout << "Trang thai: " << appointment.getStatus() << endl;
                cout << "---------------------------" << endl;
            }
        }

        if (!hasAppointments) {
            cout << "Khong co lich hen." << endl;
        }

        cout << endl;
    }
}






//HÀM IN THÔNG BÁO
void inThongBao() {
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                HE THONG QUAN LY PHONG KHAM NHA KHOA BTK" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    cout << "He thong co nhung tac vu sau:" << endl;
    cout << "a) Dat lich hen cho khach hang" << endl;
    cout << "b) In lich hen" << endl;
    cout << "c) Tim kiem ho so benh nhan theo ho ten " << endl;
    cout << "d) Xoa mot ho so benh an co ma so chi dinh" << endl;
    cout << "e) Sap xep danh sach theo thu tu tang dan" << endl;
    cout << "f) Sap xep danh sach theo ten tang dan " << endl;
    cout << "g) Sua lich hen" << endl;
    cout << "h) In hoa don ma benh nhan phai tra" << endl;
    cout << "i) Mo danh sach tu file" << endl;
    cout << "k) Thoat" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

//Chức năng quản lý các tính năng của phòng khám nha khoa
void manageDentalClinic(DentalClinic* dentalClinic) {
    char choice;
    do {
        system("cls");
        inThongBao();

        cout << "Chon tac vu ma ban mong muon: ";
        cin >> choice;

        switch (choice) {
        case 'a': {
            // Chức năng đặt lịch hẹn
            char subChoice;
            do {
                system("cls");
                cout << "Nhan c de tiep tuc" << endl;
                cout << "Nhan m de quay lai cac tac vu chinh.";
                cin >> subChoice;
                if (subChoice == 'c' || subChoice == 'C') {
                    // Gọi hàm datLichHen(dentalClinic) ở đây
                    datLichHen(dentalClinic);
                    cout << "Ban da dat lich hen thanh cong!";

                }
            } while (subChoice == 'c' || subChoice == 'C');
            if (subChoice == 'm' || subChoice == 'M') {
                system("cls");
            }
            break;
        }

       case 'b': {
        // Chức năng in danh sách bệnh nhân và lịch hẹn
        system("cls");
        inDanhSachBenhNhanVaLichHen(dentalClinic);
        cout << "Chuc nang in danh sach benh nhan va lich hen da trien khai xong." << endl;
        break;
}


        case 'c': {
            // Chức năng tìm kiếm bệnh nhân theo họ tên
            system("cls");
            if (dentalClinic->isEmpty()) {
                cout << "Danh sach benh nhan rong." << endl;
            }
            else {
                // Gọi hàm timKiemBenhNhanTheoHoTen(dentalClinic) ở đây
                // timKiemBenhNhanTheoHoTen(dentalClinic);
                cout << "Chuc nang tim kiem benh nhan theo ho ten chua duoc trien khai." << endl;
            }
            break;
        }

        // Thêm các case khác cho các chức năng khác
        }

    } while (choice != 'k');
}


bool authenticateAdmin(const std::string& username, const std::string& password, Admin& loggedInAdmin, const std::vector<Admin>& admins);
// Sample usage
int main() {
     // Creating sample data
    DentalClinic dentalClinic;

    dentalClinic.addDentist(Dentist("D001", "Dr. Xuan Bach"));
    dentalClinic.addDentist(Dentist("D002", "Dr. Thanh Truong"));


    // Khởi tạo danh sách admin
    vector<Admin> admins = {
        Admin("admin1", "pass789", "Admin User", "admin@email.com", "555555555", 1975, "Super Admin"),
        // Thêm các admin khác nếu cần
    };

    // Đăng nhập admin
    Admin loggedInAdmin;
    string username, password;
    cout << "Nhap tai khoan & mat khau de co the dang nhap vao he thong." << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (authenticateAdmin(username, password, loggedInAdmin, admins)) {
        // Nếu đăng nhập thành công, hiển thị menu cho admin
        inThongBao();
        manageDentalClinic(createDentalClinic());
    }else {
        cout << "Xac thuc khong thanh cong. Thoat khoi chuong trinh..." << std::endl;
    }
    return 0;
}
bool authenticateAdmin(const string& username, const string& password, Admin& loggedInAdmin, const vector<Admin>& admins) {
    for (const Admin& admin : admins) {
        if (admin.getUsername() == username && admin.getPassword() == password) {
            loggedInAdmin = admin;
            return true;
        }
    }
    return false;
}
