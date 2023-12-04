#include <iostream>
#include <string>
#include <vector>

// Base class for all members
class Member {
protected:
    std::string username;
    std::string password;
    std::string fullName;
    std::string email;
    std::string phoneNumber;
    int yearOfBirth;

public:
    Member(const std::string& username, const std::string& password, const std::string& fullName, const std::string& email, const std::string& phoneNumber, int yearOfBirth)
        : username(username), password(password), fullName(fullName), email(email), phoneNumber(phoneNumber), yearOfBirth(yearOfBirth) {}
    virtual ~Member() {}
    // Getters for member information
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getEmail() const { return email; }
    std::string getPhoneNumber() const { return phoneNumber; }
    int getYearOfBirth() const { return yearOfBirth; }
};

// Derived class for patients
class Patient : public Member {
private:
    std::string idCard;
    std::string address;
    std::string occupation;
    std::string placeOfBirth;

public:
    Patient(const std::string& username, const std::string& password, const std::string& fullName, const std::string& email, const std::string& phoneNumber, int yearOfBirth,
        const std::string& idCard, const std::string& address, const std::string& occupation, const std::string& placeOfBirth)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), idCard(idCard), address(address), occupation(occupation), placeOfBirth(placeOfBirth) {}

    // Getters for patient information
    std::string getIdCard() const { return idCard; }
    std::string getAddress() const { return address; }
    std::string getOccupation() const { return occupation; }
    std::string getPlaceOfBirth() const { return placeOfBirth; }
};

// Derived class for dentists
class Dentist : public Member {
private:
    std::string expertise;
    std::string position;
    std::string degree;
    std::string mainWorkingPlace;

public:
    Dentist(const std::string& username, const std::string& password, const std::string& fullName, const std::string& email, const std::string& phoneNumber, int yearOfBirth,
        const std::string& expertise, const std::string& position, const std::string& degree, const std::string& mainWorkingPlace)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), expertise(expertise), position(position), degree(degree), mainWorkingPlace(mainWorkingPlace) {}

    // Getters for dentist information
    std::string getExpertise() const { return expertise; }
    std::string getPosition() const { return position; }
    std::string getDegree() const { return degree; }
    std::string getMainWorkingPlace() const { return mainWorkingPlace; }
};

// Derived class for admins
class Admin : public Member {
private:
    std::string adminLevel;

public:
    Admin(const std::string& username, const std::string& password, const std::string& fullName, const std::string& email, const std::string& phoneNumber, int yearOfBirth,
        const std::string& adminLevel)
        : Member(username, password, fullName, email, phoneNumber, yearOfBirth), adminLevel(adminLevel) {}

    // Getter for admin level
    std::string getAdminLevel() const { return adminLevel; }
};

// Class for appointment slip
class AppointmentSlip {
private:
    std::string code;
    std::string createdDate;
    std::string appointmentDate;
    std::string appointmentTime;
    std::string appointmentNumber;
    std::string appointmentContent;
    std::string status;
    std::string dentistCode;
    std::string patientCode;
    std::string scheduled;

public:
    AppointmentSlip(const std::string& code, const std::string& createdDate, const std::string& appointmentDate, const std::string& appointmentTime,
        const std::string& appointmentNumber, const std::string& appointmentContent, const std::string& status, const std::string& dentistCode,
        const std::string& patientCode, const std::string& scheduled)
        : code(code), createdDate(createdDate), appointmentDate(appointmentDate), appointmentTime(appointmentTime), appointmentNumber(appointmentNumber),
        appointmentContent(appointmentContent), status(status), dentistCode(dentistCode), patientCode(patientCode), scheduled(scheduled) {}

    // Getters for appointment slip information
    std::string getCode() const { return code; }
    std::string getCreatedDate() const { return createdDate; }
    std::string getAppointmentDate() const { return appointmentDate; }
    std::string getAppointmentTime() const { return appointmentTime; }
    std::string getAppointmentNumber() const { return appointmentNumber; }
    std::string getAppointmentContent() const { return appointmentContent; }
    std::string getStatus() const { return status; }
    std::string getDentistCode() const { return dentistCode; }
    std::string getPatientCode() const { return patientCode; }
    std::string getScheduled() const { return scheduled; }
};

// Function to validate password
bool validatePassword(const std::string& password) {
    // Password must not start with a special character and must have at least 6 characters
    if (password.length() < 6 || !isalpha(password[0])) {
        return false;
    }
    return true;
}

// Function to create a new account
void createAccount(std::vector<Member*>& members) {
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
        return;
    }

    // Create a new patient account
    Patient* patient = new Patient(username, password, fullName, email, phoneNumber, yearOfBirth, "", "", "", "");
    members.push_back(patient);

    std::cout << "Account created successfully!" << std::endl;
}

// Function to log in
Member* login(const std::vector<Member*>& members) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Find the member with the given username and password
    for (const auto& member : members) {
        if (member->getUsername() == username && member->getPassword() == password) {
            return member;
        }
    }

    std::cout << "Invalid username or password!" << std::endl;
    return nullptr;
}

int main() {
    std::vector<Member*> members;
    std::vector<AppointmentSlip> appointmentSlips;

    // Create some initial members and appointment slips
    Patient patient("patient1", "password1", "John Doe", "john.doe@example.com", "123456789", 1990, "1234567890", "123 Main St", "Engineer", "New York");
    Dentist dentist("dentist1", "password2", "Dr. Jane Smith", "jane.smith@example.com", "987654321", 1985, "Orthodontics", "Senior Dentist", "DDS", "ABC Dental Clinic");
    Admin admin("admin1", "password3", "Admin User", "admin@example.com", "555555555", 1975, "Level 1");

    members.push_back(&patient);
    members.push_back(&dentist);
    members.push_back(&admin);

    AppointmentSlip appointment1("A001", "2023-01-01", "2023-01-10", "10:00", "001", "Regular check-up", "Scheduled", "D001", "P001", "Dentist");
    AppointmentSlip appointment2("A002", "2023-01-02", "2023-01-15", "14:30", "002", "Tooth extraction", "Scheduled", "D002", "P002", "Patient");

    appointmentSlips.push_back(appointment1);
    appointmentSlips.push_back(appointment2);

    // User interface
    std::cout << "Welcome to the Dental Clinic Management System!" << std::endl;
    std::cout << "1. Log in" << std::endl;
    std::cout << "2. Create a new account" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    Member* loggedInMember = nullptr;

    switch (choice) {
    case 1:
        loggedInMember = login(members);
        if (loggedInMember != nullptr) {
            // Logged in successfully
            std::cout << "Logged in as: " << loggedInMember->getUsername() << std::endl;
            // Add code for the user interface after logging in
        }
        break;
    case 2:
        createAccount(members);
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}

