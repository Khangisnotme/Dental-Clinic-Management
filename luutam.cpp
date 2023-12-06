#include <iostream>
#include <fstream>
#include <vector>

class Member {
public:
    std::string username;
    std::string password;

    Member(const std::string& username, const std::string& password)
        : username(username), password(password) {}
};

void loadAccounts(std::vector<Member*>& members) {
    std::ifstream file("accounts.txt");
    if (file.is_open()) {
        std::string username, password;
        while (file >> username >> password) {
            Member* member = new Member(username, password);
            members.push_back(member);
        }
        file.close();
    }
}

void saveAccount(const std::string& username, const std::string& password) {
    std::ofstream file("accounts.txt", std::ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
    }
}

bool login(const std::string& username, const std::string& password, const std::vector<Member*>& members) {
    for (const auto& member : members) {
        if (member->username == username && member->password == password) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<Member*> members;
    loadAccounts(members);

    int choice;
    std::string username, password;

    std::cout << "Welcome to the Dental Clinic Management System!\n";
    std::cout << "1. Log in\n";
    std::cout << "2. Create a new account\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (login(username, password, members)) {
            std::cout << "Login successful!\n";
            // Thực hiện các hoạt động sau khi đăng nhập thành công
        } else {
            std::cout << "Invalid username or password!\n";
        }
    } else if (choice == 2) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        saveAccount(username, password);
        std::cout << "Account created successfully!\n";
    }

    // Giải phóng bộ nhớ đã cấp phát cho các đối tượng Member
    for (const auto& member : members) {
        delete member;
    }

    return 0;
}
