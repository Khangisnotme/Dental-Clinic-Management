#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
// Forward declarations
class Member;
class Patient;
class Dentist;
class Admin;
class Appointment;

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
    Dentist(const std::string& username, const std::string& password,
            const std::string& fullName, const std::string& email,
            const std::string& phoneNumber, int birthYear,
            const std::string& specialization, const std::string& position,
            const std::string& qualification, const std::string& workplace)
        : Member(username, password, fullName, email, phoneNumber, birthYear),
          specialization(specialization), position(position),
          qualification(qualification), workplace(workplace) {}

private:
    std::string specialization;
    std::string position;
    std::string qualification;
    std::string workplace;
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
    Appointment(const std::string& code, const std::string& dateCreated,
                const std::string& dateTime, int appointmentNumber,
                const std::string& content, const std::string& status,
                const std::string& dentistCode, const std::string& patientCode,
                const std::string& schedule, const std::string& displayStatus)
        : code(code), dateCreated(dateCreated), dateTime(dateTime),
          appointmentNumber(appointmentNumber), content(content), status(status),
          dentistCode(dentistCode), patientCode(patientCode),
          schedule(schedule), displayStatus(displayStatus) {}

private:
    std::string code;
    std::string dateCreated;
    std::string dateTime;
    int appointmentNumber;
    std::string content;
    std::string status;
    std::string dentistCode;
    std::string patientCode;
    std::string schedule;
    std::string displayStatus;
};

//HÀM IN THÔNG BÁO
void inThongBao() {
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                HE THONG QUAN LY PHONG KHAM NHA KHOA KHANG PS" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    cout << "Menu:" << endl;
    cout << "a) Dat lich hen cho khach hang" << endl;
    cout << "b) In lich hen" << endl;
    cout << "c) Tim kiem mot khach hang theo ho ten " << endl;
    cout << "d) Them mot khach hang sau mot khach hang co ma so chi dinh" << endl;
    cout << "e) Xoa mot khach hang co ma so chi dinh" << endl;
    cout << "f) Sap xep danh sach theo thu tu tang dan" << endl;
    cout << "g) Sap xep danh sach theo ten tang dan " << endl;
    cout << "h) Sua lich hen" << endl;
    cout << "i) In hoa don" << endl;
    cout << "j) Mo danh sach tu file" << endl;
    cout << "k) Thoat" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}
bool authenticateAdmin(const std::string& username, const std::string& password, Admin& loggedInAdmin, const std::vector<Admin>& admins);
// Sample usage
int main() {
    // Khởi tạo danh sách admin
    std::vector<Admin> admins = {
        Admin("admin1", "pass789", "Admin User", "admin@email.com", "555555555", 1975, "Super Admin"),
        // Thêm các admin khác nếu cần
    };

    // Đăng nhập admin
    Admin loggedInAdmin;
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (authenticateAdmin(username, password, loggedInAdmin, admins)) {
        // Nếu đăng nhập thành công, hiển thị menu cho admin
        inThongBao();

        char choice;
        do {
            std::cout << "Enter your choice (a-j): ";
            std::cin >> choice;

            switch (choice) {
                case 'a':
                    // Xử lý đặt lịch hẹn
                    break;
                case 'b':
                    // Xử lý in lịch hẹn
                    break;
                // ... (Thêm các case xử lý cho các chức năng khác)
                case 'k':
                    std::cout << "Exiting program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }

        } while (choice != 'j');
    } else {
        std::cout << "Authentication failed. Exiting program..." << std::endl;
    }

    return 0;
}
bool authenticateAdmin(const std::string& username, const std::string& password, Admin& loggedInAdmin, const std::vector<Admin>& admins) {
    for (const Admin& admin : admins) {
        if (admin.getUsername() == username && admin.getPassword() == password) {
            loggedInAdmin = admin;
            return true;
        }
    }
    return false;
}
