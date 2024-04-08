#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ParkingLot {
public:
    int VehicleIn;
    int VehicleOut;
};

class Vehicle {
private:
    string VehicleId;
    string VehicleModel;
    string VehicleColor;
    bool Membership;
    bool Parked;
    string SlotNo;
public:
    string VehicleType;
    void addVehicle();
    void displayVehicle(string); //VehicleID
};

class Slot {
private:
    int SlotNo;
    bool Vacancy;
    int RemainingTime;
    string vehicleID;
public:
    float fareCalculator(); //Kept for debugging purposes
    void parkVehicle(string); //VehicleID
};

class Customer {
private: 
    string Name;
    int Age;
    char Gender;
    long int PhoneNumber;
    int WalletAmount;
    int VehiclesRegistered;
    bool MemberShip;
    char MembershipType;
    string Passwd;
    vector<Vehicle> vehicles;
public:
    // The two strings are for username and password
    void addUser();
    void displayUser(string, string);
    void registerVehicle(string, string);
    void addAmountToWallet(string, string);
    void showVehilce(string, string);
};

void Customer::addUser() {
    string op, Passwd, temp2;
    cout << "Enter name(without spaces): ";
    cin >> Name;
    cout << "Create new password(without spaces): ";
    cin >> Passwd;
    cout << "Confirm password: ";
    cin >> temp2;
    if (Passwd.compare(temp2)==0) {
        this->Passwd = Passwd;
        cout << "Password created successfully.!!" << endl;
    } else {
        cout << "Passwords do not match. Please try again." << endl;
        return;
    }
    cout << "Enter age: ";
    cin >> Age;
    cout << "Enter Gender (M or F): ";
    cin >> Gender;
    cout << "Enter Phone number: ";
    cin >> PhoneNumber;
    cout << "Add amount to wallet: ";
    cin >> WalletAmount;
    cout << "Need Membership? (y or n) ";
    cin >> op;
    if (op=="y") {
        cout << "Enter Membership type: (Weekly(w) or Monthly(m) or Yearly(y)): ";
        cin >> MembershipType;
        MemberShip = true;
    } else {
        MemberShip = false;
    }    
    
}

void Customer::displayUser(string userName, string passwd) {
    if (userName == Name && passwd == Passwd) {
        cout << "User Details:" << endl;
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Wallet Amount: " << WalletAmount << endl;
        cout << "Membership: " << (MemberShip ? "Yes" : "No") << endl;
        if (MemberShip) {
            cout << "Membership Type: " << MembershipType << endl;
        }
    } else {
        cout << "Invalid credentials!" << endl;
    }
}

void Customer::registerVehicle(string vehicleId, string slotNo) {
    Vehicle v;
    // Set vehicle details
    // Add the vehicle to the vector of vehicles for the customer
    vehicles.push_back(v);
    VehiclesRegistered++;
}

void Customer::addAmountToWallet(string userName, string passwd) {
    string tempPasswd;
    int amount;
    cout << "Enter your password to proceed: ";
    cin >> tempPasswd;
    if (tempPasswd == Passwd) {
        cout << "Enter amount to add to wallet: ";
        cin >> amount;
        WalletAmount += amount;
        cout << "Amount added successfully. Current wallet balance: " << WalletAmount << endl;
    } else {
        cout << "Incorrect password! Cannot proceed." << endl;
    }
}

void Customer::showVehilce(string userName, string passwd) {
    // Implement
}

void Slot::parkVehicle(string vehicleID) {
    // Implement
}

float Slot::fareCalculator() {
    // Implement
}

int main() {
    vector<Customer> customers;
    int choice;
    do {
        cout << "1) Add User" << endl;
        cout << "2) Register Vehicle" << endl;
        cout << "3) Deposit amount to wallet" << endl;
        cout << "4) Calculate fare" << endl;
        cout << "5) Show user details" << endl;
        cout << "6) Show vehicle details" << endl;
        cout << "7) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {
                Customer c;
                c.addUser();
                customers.push_back(c);
                break;
            }
            case 2: {
                string userName, passwd, vehicleId, slotNo;
                cout << "Enter your username and password to proceed: ";
                cin >> userName >> passwd;
                // Search for the customer in the vector by username and password
                // Call registerVehicle() for the found customer
                break;
            }
            case 3: {
                string userName, passwd;
                cout << "Enter your username and password to proceed: ";
                cin >> userName >> passwd;
                // Search for the customer in the vector by username and password
                // Call addAmountToWallet() for the found customer
                break;
            }
            case 4: {
                // Implement fare calculation
                break;
            }
            case 5: {
                string userName, passwd;
                cout << "Enter your username and password to proceed: ";
                cin >> userName >> passwd;
                // Search for the customer in the vector by username and password
                // Call displayUser() for the found customer
                break;
            }
            case 6: {
                string userName, passwd;
                cout << "Enter your username and password to proceed: ";
                cin >> userName >> passwd;
                // Search for the customer in the vector by username and password
                // Call showVehicle() for the found customer
                break;
            }
            case 7:
                cout << "Thank you, come again later :)" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
