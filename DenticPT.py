class Member:
    def __init__(self, username, password, fullName, email, phoneNumber, yearOfBirth):
        self.username = username
        self.password = password
        self.fullName = fullName
        self.email = email
        self.phoneNumber = phoneNumber
        self.yearOfBirth = yearOfBirth

class Patient(Member):
    def __init__(self, username, password, fullName, email, phoneNumber, yearOfBirth, idCard, address, occupation, placeOfBirth):
        super().__init__(username, password, fullName, email, phoneNumber, yearOfBirth)
        self.idCard = idCard
        self.address = address
        self.occupation = occupation
        self.placeOfBirth = placeOfBirth

class Dentist(Member):
    def __init__(self, username, password, fullName, email, phoneNumber, yearOfBirth, expertise, position, degree, mainWorkingPlace):
        super().__init__(username, password, fullName, email, phoneNumber, yearOfBirth)
        self.expertise = expertise
        self.position = position
        self.degree = degree
        self.mainWorkingPlace = mainWorkingPlace

class Admin(Member):
    def __init__(self, username, password, fullName, email, phoneNumber, yearOfBirth, adminLevel):
        super().__init__(username, password, fullName, email, phoneNumber, yearOfBirth)
        self.adminLevel = adminLevel

class AppointmentSlip:
    def __init__(self, code, createdDate, appointmentDate, appointmentTime, appointmentNumber, appointmentContent, status, dentistCode, patientCode, scheduled):
        self.code = code
        self.createdDate = createdDate
        self.appointmentDate = appointmentDate
        self.appointmentTime = appointmentTime
        self.appointmentNumber = appointmentNumber
        self.appointmentContent = appointmentContent
        self.status = status
        self.dentistCode = dentistCode
        self.patientCode = patientCode
        self.scheduled = scheduled

# Create member objects
patient = Patient("patient1", "password1", "John Doe", "john.doe@example.com", "123456789", 1990, "1234567890", "123 Main St", "Engineer", "New York")
dentist = Dentist("dentist1", "password2", "Dr. Jane Smith", "jane.smith@example.com", "987654321", 1985, "Orthodontics", "Senior Dentist", "DDS", "ABC Dental Clinic")
admin = Admin("admin1", "password3", "Admin User", "admin@example.com", "555555555", 1975, "Level 1")

# Create appointment objects
appointment1 = AppointmentSlip("A001", "2023-01-01", "2023-01-10", "10:00", "001", "Regular check-up", "Scheduled", "D001", "P001", "Dentist")
appointment2 = AppointmentSlip("A002", "2023-01-02", "2023-01-15", "14:30", "002", "Tooth extraction", "Scheduled", "D002", "P002", "Patient")

# Store member and appointment objects in lists
members = [patient, dentist, admin]
appointmentSlips = [appointment1, appointment2]

# Function to validate password strength
def validate_password(password):
    if len(password) < 6:
        return False
    if password[0].isupper() or not password.isalnum():
        return False
    return True

# User registration
def register():
    username = input("Enter username: ")
    password = input("Enter password: ")
    fullName = input("Enter full name: ")
    email = input("Enter email: ")
    phoneNumber = input("Enter phone number: ")
    yearOfBirth = int(input("Enter year of birth: "))

    # Validate password strength
    if not validate_password(password):
        print("Invalid password. Password should have at least 6 characters, start with a lowercase letter, and contain only alphanumeric characters.")
        return

    # Create patient object
    patient = Patient(username, password, fullName, email, phoneNumber, yearOfBirth, "", "", "", "")
    members.append(patient)
    print("Registration successful!")

# Print member information
print("Member information:")
for member in members:
    print("Username:", member.username)
    print("Full Name:", member.fullName)
    print("Email:", member.email)
    print("Phone Number:", member.phoneNumber)
    print("Year of Birth:", member.yearOfBirth)

    if isinstance(member, Patient):
        print("ID Card:", member.idCard)
        print("Address:", member.address)
        print("Occupation:", member.occupation)
        print("Place of Birth:", member.placeOfBirth)

    if isinstance(member, Dentist):
        print("Expertise:", member.expertise)
        print("Position:", member.position)
        print("Degree:", member.degree)
        print("Main Working Place:", member.mainWorkingPlace)

    print()

# Print appointment information
print("Appointment information:")
for appointment in appointmentSlips:
    print("Code:", appointment.code)
    print("Created Date:", appointment.createdDate)
    print("Appointment Date:", appointment.appointmentDate)
    print("Appointment Time:", appointment.appointmentTime)
    print("Appointment Number:", appointment.appointmentNumber)
    print("Appointment Content:", appointment.appointmentContent)
    print("Status:", appointment.status)
    print("Dentist Code:", appointment.dentistCode)
    print("Patient Code:", appointment.patientCode)
    print("Scheduled:", appointment.scheduled)

    print()
