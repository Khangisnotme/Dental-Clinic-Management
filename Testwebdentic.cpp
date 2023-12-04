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

int main() {
    // Tạo các đối tượng thành viên
    Patient patient("patient1", "password1", "John Doe", "john.doe@example.com", "123456789", 1990, "1234567890", "123 Main St", "Engineer", "New York");
    Dentist dentist("dentist1", "password2", "Dr. Jane Smith", "jane.smith@example.com", "987654321", 1985, "Orthodontics", "Senior Dentist", "DDS", "ABC Dental Clinic");
    Admin admin("admin1", "password3", "Admin User", "admin@example.com", "555555555", 1975, "Level 1");

    // Tạo các đối tượng lịch hẹn
    AppointmentSlip appointment1("A001", "2023-01-01", "2023-01-10", "10:00", "001", "Regular check-up", "Scheduled", "D001", "P001", "Dentist");
    AppointmentSlip appointment2("A002", "2023-01-02", "2023-01-15", "14:30", "002", "Tooth extraction", "Scheduled", "D002", "P002", "Patient");

    // Lưu trữ các đối tượng thành viên và lịch hẹn trong vector
    std::vector<Member*> members = { &patient, &dentist, &admin };
    std::vector<AppointmentSlip> appointmentSlips = { appointment1, appointment2 };

    // In thông tin của tất cả thành viên
    std::cout << "Member information:\n";
    for (const auto& member : members) {
        std::cout << "Username: " << member->getUsername() << "\n";
        std::cout << "Full Name: " << member->getFullName() << "\n";
        std::cout << "Email: " << member->getEmail() << "\n";
        std::cout << "Phone Number: " << member->getPhoneNumber() << "\n";
        std::cout << "Year of Birth: " << member->getYearOfBirth() << "\n";

        // Thông tin bổ sung cho bệnh nhân
        if (dynamic_cast<Patient*>(member)) {
            Patient* patient = dynamic_cast<Patient*>(member);
            std::cout << "ID Card: " << patient->getIdCard() << "\n";
            std::cout << "Address: " << patient->getAddress() << "\n";
            std::cout << "Occupation: " << patient->getOccupation() << "\n";
            std::cout << "Place of Birth: " << patient->getPlaceOfBirth() << "\n";
        }

        // Thông tin bổ sung cho bác sĩ
        if (dynamic_cast<Dentist*>(member)) {
            Dentist* dentist = dynamic_cast<Dentist*>(member);
            std::cout << "Expertise: " << dentist->getExpertise() << "\n";
            std::cout << "Position: " << dentist->getPosition() << "\n";
            std::cout << "Degree: " << dentist->getDegree() << "\n";
            std::cout << "Main Working Place: " << dentist->getMainWorkingPlace() << "\n";
        }

        std::cout << "\n";
    }

    // In thông tin của tất cả lịch hẹn
    std::cout << "Appointment information:\n";
    for (const auto& appointment : appointmentSlips) {
        std::cout << "Code: " << appointment.getCode() << "\n";
        std::cout << "Created Date: " << appointment.getCreatedDate() << "\n";
        std::cout << "Appointment Date: " << appointment.getAppointmentDate() << "\n";
        std::cout << "Appointment Time: " << appointment.getAppointmentTime() << "\n";
        std::cout << "Appointment Number: " << appointment.getAppointmentNumber() << "\n";
        std::cout << "Appointment Content: " << appointment.getAppointmentContent() << "\n";
        std::cout << "Status: " << appointment.getStatus() << "\n";
        std::cout << "Dentist Code: " << appointment.getDentistCode() << "\n";
        std::cout << "Patient Code: " << appointment.getPatientCode() << "\n";
        std::cout << "Scheduled: " << appointment.getScheduled() << "\n";

        std::cout << "\n";
    }

    return 0;
}
