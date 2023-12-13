#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // Add the necessary header for file input/output operations
#include <regex>

using namespace std;


// Base class for all members
class Dichvu{
    public:
        string tendichvu;
        int gia = 0;
};
class Member {
protected:
    string username;
    string password;
    string fullName;
    string email;
    string phoneNumber;
    int yearOfBirth;

public:
    Member(const string& username, const string& password, const string& fullName, const string& email, const string& phoneNumber, int yearOfBirth)
        : username(username), password(password), fullName(fullName), email(email), phoneNumber(phoneNumber), yearOfBirth(yearOfBirth) {}
    virtual ~Member() {}
    // Getters for member information
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getFullName() const { return fullName; }
    string getEmail() const { return email; }
    string getPhoneNumber() const { return phoneNumber; }
    int getYearOfBirth() const { return yearOfBirth; }
};

// Derived class for patients
class Patient : public Member {
private:
    string idCard;
    string address;
    string occupation;
    string placeOfBirth;

public:
    Patient(const string& username, const string& password, const string& fullName, const string& email, const string& phoneNumber, int yearOfBirth,
        const string& idCard, const string& address, const string& occupation, const string& placeOfBirth)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), idCard(idCard), address(address), occupation(occupation), placeOfBirth(placeOfBirth) {}

    // Getters for patient information
    string getIdCard() const { return idCard; }
    string getAddress() const { return address; }
    string getOccupation() const { return occupation; }
    string getPlaceOfBirth() const { return placeOfBirth; }
};

// Derived class for dentists
class Dentist : public Member {
private:
    string expertise;
    string position;
    string degree;
    string mainWorkingPlace;

public:
    Dentist(const string& username, const string& password, const string& fullName, const string& email, const string& phoneNumber, int yearOfBirth,
        const string& expertise, const string& position, const string& degree, const string& mainWorkingPlace)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), expertise(expertise), position(position), degree(degree), mainWorkingPlace(mainWorkingPlace) {}

    // Getters for dentist information
    string getExpertise() const { return expertise; }
    string getPosition() const { return position; }
    string getDegree() const { return degree; }
    string getMainWorkingPlace() const { return mainWorkingPlace; }
};

// Derived class for admins
class Admin : public Member {
private:
    string adminLevel;

public:
    Admin(const string& username, const string& password, const string& fullName, const string& email, const string& phoneNumber, int yearOfBirth,
        const string& adminLevel)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), adminLevel(adminLevel) {}

    // Getter for admin level
    string getAdminLevel() const { return adminLevel; }
};

// Class for appointment slip
class AppointmentSlip {
private:
    string code;
    string createdDate;
    string appointmentDate;
    string appointmentTime;
    string appointmentNumber;
    string appointmentContent;
    string status;
    string dentistCode;
    string patientCode;
    string scheduled;

public:
    AppointmentSlip(const string& code, const string& createdDate, const string& appointmentDate, const string& appointmentTime,
        const string& appointmentNumber, const string& appointmentContent, const string& status, const string& dentistCode,
        const string& patientCode, const string& scheduled)
        : code(code), createdDate(createdDate), appointmentDate(appointmentDate), appointmentTime(appointmentTime), appointmentNumber(appointmentNumber),
        appointmentContent(appointmentContent), status(status), dentistCode(dentistCode), patientCode(patientCode), scheduled(scheduled) {}

    // Getters for appointment slip information
    string getCode() const { return code; }
    string getCreatedDate() const { return createdDate; }
    string getAppointmentDate() const { return appointmentDate; }
    string getAppointmentTime() const { return appointmentTime; }
    string getAppointmentNumber() const { return appointmentNumber; }
    string getAppointmentContent() const { return appointmentContent; }
    string getStatus() const { return status; }
    string getDentistCode() const { return dentistCode; }
    string getPatientCode() const { return patientCode; }
    string getScheduled() const { return scheduled; }
};

class Account {
private:
    std::vector<Member*> members;

public:
    void signUp(Member* member) {
        members.push_back(member);
    }

    Member* login(const std::string& username, const std::string& password) {
        for (Member* member : members) {
            if (member->getUsername() == username && member->getPassword() == password) {
                return member;
            }
        }
        return nullptr;
    }



    bool validatePassword(const std::string& password) {
        std::regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{6,}$");
        return std::regex_match(password, pattern);
}
    Member* createAccount(std::vector<Member*>& members) {
    std::string username, password, fullName, email, phoneNumber;
    int yearOfBirth;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter year of birth: ";
    std::cin >> yearOfBirth;

    // Validate password
    if (!validatePassword(password)) {
        std::cout << "Invalid password! Password must not start with a special character and must have at least 6 characters." << std::endl;
        return nullptr;
    }

    // Create a new patient account
    Patient* patient = new Patient(username, password, fullName, email, phoneNumber, yearOfBirth, "", "", "", "");
    members.push_back(patient);

    // Save the new account to a file

    saveAccount(username, password);  // Utilize the existing saveAccount function


    cout << "Tai khoan duoc tao thanh cong!" << endl;

    // Return the new account
    return patient;
}
    void saveAccount(const string& username, const string& password) {
    ofstream file("khoacc.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
    }
}

    void loadAccounts(vector<Member*>& members) {
    ifstream inputFile("khoacc.txt");

    if (inputFile.is_open()) {
        string line;
        while (std::getline(inputFile, line)) {
            // Trích xuất thông tin từng dòng
            // Tạo đối tượng Member tương ứng và thêm vào vector members
        }

        inputFile.close();
    }
    else {
        cout << "Khong the mo file tai khoan" << endl;
    }
}

};





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

void datLichHen() {
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

    ofstream file("lich_hen.txt", ios::app); // Mở file để ghi dữ liệu, sử dụng ios::app để ghi tiếp vào cuối file

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
        cout << "Ban chua co lich hen voi phong kham!" << endl;
    }
}


int main() {
    std::vector<Member*> members;
    std::vector<AppointmentSlip> appointmentSlips;
    Dichvu dichvu[5] = {
        {"Trong rang su voi 1 rang",9000000},
        {"Trong rang vang voi 1 rang",10000000},
        {"Cao voi rang hai ham",400000},
        {"Tieu phau",3500000},
        {"Tay trang rang 2 ham",2000000},
    };

    Account account;

    // Load accounts from file
    account.loadAccounts(members);

    // Create some initial members and appointment slips
    Admin admin("admin1", "password1", "Admin User", "admin@example.com", "555555555", 1975, "Level 1");
    members.push_back(&admin);

    Patient patient("patient1", "password2", "John Doe", "john.doe@example.com", "123456789", 1990, "1234567890", "123 Main St", "Engineer", "New York");
    members.push_back(&patient);

    Dentist dentist("dentist1", "password3", "Dr. Jane Smith", "jane.smith@example.com", "987654321", 1985, "Orthodontics", "Senior Dentist", "DDS", "ABC Dental Clinic");
    members.push_back(&dentist);

    AppointmentSlip appointment1("A001", "2023-01-01", "2023-01-10", "10:00", "001", "Regular check-up", "Scheduled", "D001", "P001", "Dentist");
    AppointmentSlip appointment2("A002", "2023-01-02", "2023-01-15", "14:30", "002", "Tooth extraction", "Scheduled", "D002", "P002", "Patient");
    appointmentSlips.push_back(appointment1);
    appointmentSlips.push_back(appointment2);

    // User interface
    std::cout << "Welcome to the Dental Clinic Management System!" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. Patient" << std::endl;
    std::cout << "3. Dentist" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    Member* loggedInMember = nullptr;

    switch (choice) {
        case 0:
            // Exit the program
            return 0;
        case 1: {
            string username, password;
            cout << "Enter admin username: ";
            cin >> username;
            cout << "Enter admin password: ";
            cin >> password;

            // Check if the entered username and password match the admin account
            if (username == admin.getUsername() && password == admin.getPassword()) {
                loggedInMember = &admin;
                std::cout << "Logged in as admin: " << loggedInMember->getUsername() << std::endl;
                // Add code for the admin user interface
            } else {
                std::cout << "Invalid admin username or password!" << std::endl;
            }
            break;
        }
        case 2: {
            bool loggedIn = false;
            while (true) {

                std::cout << "\nPress 'q' to go back\n";
                std::cout << "Press 'l' to login as a patient\n";
                std::cout << "Press 't' to create a new patient account\n";
                char option;
                std::cin >> option;

                if (option == 'q') {
                    break; // Quay lại màn hình chính
                } else if (option == 'l') {

                    std::string username, password;
                    std::cout << "Nhap ten tai khoan: ";
                    std::cin >> username;
                    std::cout << "Nhap mat khau: ";
                    std::cin >> password;

                    // Kiểm tra xem tên người dùng và mật khẩu có khớp với tài khoản bệnh nhân hay không
                    loggedInMember = Account.login(username, password, members);
                    if (loggedInMember != nullptr && dynamic_cast<Patient*>(loggedInMember) != nullptr) {

                        loggedIn = true;
                        std::cout << "Logged in as patient: " << loggedInMember->getUsername() << std::endl;
                        // Thêm mã cho giao diện người dùng bệnh nhân
                        while (loggedIn) {
                            // Mã cho giao diện người dùng bệnh nhân
                            cout << "\nPress 'x' to view appointments\n";
                            cout << "Press 's' to schedule an appointment\n";
                            cout << "\nNhan 'q' de quay lai\n";

                            char patientOption;
                            cin >> patientOption;

                            if (patientOption == 'x') {
                                // Xem lịch hẹn
                                account.xemLichHen();
                            } else if (patientOption == 's') {
                                // Đặt lịch hẹn
                                account.datLichHen();
                            }
                            cout << "\nNhan 'q' de thoat\n";
                            char logoutOption;
                            cin >> logoutOption;
                            if (logoutOption == 'q') {
                                loggedIn = false;
                                break;
                            }
                        }
                        break; // Quay lại màn hình chính sau khi đăng xuất
                    } else {
                        std::cout << "Invalid patient username or password!" << std::endl;
                    }
                } else if (option == 't') {
                    Account account2;  // Tạo một đối tượng Account
                    Member* newPatient = account2.createAccount(members);  // Sử dụng phương thức createAccount để tạo tài khoản bệnh nhân mới
                } else {
                    std::cout << "Invalid option!" << std::endl;
                }
            }
            break;
        }

        case 3: {
            std::string username, password;
            std::cout << "Enter dentist username: ";
            std::cin >> username;
            std::cout << "Enter dentist password: ";
            std::cin >> password;

            // Check if the entered username and password match a dentist account
            loggedInMember = account.login(username, password, members);
            if (loggedInMember != nullptr && dynamic_cast<Dentist*>(loggedInMember) != nullptr) {
                std::cout << "Logged in as dentist: " << loggedInMember->getUsername() << std::endl;
                // Add code for the dentist user interface
            } else {
                std::cout << "Invalid dentist username or password!" << std::endl;
            }
            break;
        }

        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
