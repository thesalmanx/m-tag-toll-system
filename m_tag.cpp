#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// Struct for new vehicle registration
struct VehicleInfo {
    string name;
    long long cnic;
    long long vaccinationNum;
    long long numberPlate;
    long long phoneNum;
};

void registerVehicle();
void rechargeBalance();
void calculateFare();

const string folder = "data/";

int main() {
    int choice;

    while (true) {
        cout << "\n------------WELCOME TO M-TAG SYSTEM--------------\n";
        cout << "1- New Vehicle Registration\n";
        cout << "2- Recharge Your M-TAG\n";
        cout << "3- Travel (Enter Toll Plaza Information)\n";
        cout << "4- Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerVehicle();
                break;
            case 2:
                rechargeBalance();
                break;
            case 3:
                calculateFare();
                break;
            case 4:
                cout << "\n-----------THANK YOU FOR USING OUR SYSTEM--------------\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Function for vehicle registration
void registerVehicle() {
    VehicleInfo vehicle;
    ofstream idFile(folder + "user_id.txt", ios::app);
    ofstream recordFile(folder + "user_record.txt", ios::app);
    ofstream balanceFile(folder + "balance.txt", ios::app);

    if (!idFile || !recordFile || !balanceFile) {
        cerr << "Error accessing files. Ensure the folder exists.\n";
        return;
    }

    cout << "\nEnter Your Full Name: ";
    cin.ignore();
    getline(cin, vehicle.name);

    cout << "Enter Your CNIC Number: ";
    cin >> vehicle.cnic;

    cout << "Enter Your COVID-19 Certificate Number: ";
    cin >> vehicle.vaccinationNum;

    cout << "Enter Your Vehicle Number Plate: ";
    cin >> vehicle.numberPlate;

    cout << "Enter Your Phone Number: ";
    cin >> vehicle.phoneNum;

    // Save data to files
    idFile << vehicle.phoneNum << endl;
    balanceFile << 0 << endl;

    recordFile << "-----------------------------------------------------------\n";
    recordFile << "Name: " << vehicle.name << "\n";
    recordFile << "CNIC: " << vehicle.cnic << "\n";
    recordFile << "Vaccination Number: " << vehicle.vaccinationNum << "\n";
    recordFile << "Number Plate: " << vehicle.numberPlate << "\n";
    recordFile << "Phone Number: " << vehicle.phoneNum << "\n";
    recordFile << "-----------------------------------------------------------\n";

    cout << "\nYour M-TAG has been registered successfully.\n";
    cout << "Please recharge your M-TAG to start using the system.\n";

    idFile.close();
    recordFile.close();
    balanceFile.close();
}

// Function to recharge balance
void rechargeBalance() {
    long long phone;
    int rechargeAmount;
    bool userFound = false;

    cout << "\nEnter Your Phone Number: ";
    cin >> phone;

    ifstream idFile(folder + "user_id.txt");
    ifstream balanceFile(folder + "balance.txt");
    ofstream tempFile(folder + "temp.txt");

    if (!idFile || !balanceFile || !tempFile) {
        cerr << "Error accessing files. Ensure the folder exists.\n";
        return;
    }

    long long phoneID;
    int balance, updatedBalance;

    while (idFile >> phoneID && balanceFile >> balance) {
        if (phoneID == phone) {
            cout << "Enter the amount you want to recharge: ";
            cin >> rechargeAmount;

            updatedBalance = balance + rechargeAmount;
            cout << "Recharge successful! Your new balance is: " << updatedBalance << " RS\n";
            userFound = true;
        } else {
            updatedBalance = balance;
        }
        tempFile << updatedBalance << endl;
    }

    idFile.close();
    balanceFile.close();
    tempFile.close();

    if (!userFound) {
        cout << "\nPhone number not found. Please register first.\n";
        remove((folder + "temp.txt").c_str());
    } else {
        remove((folder + "balance.txt").c_str());
        rename((folder + "temp.txt").c_str(), (folder + "balance.txt").c_str());
    }
}

// Function to calculate fare and deduct it from balance
void calculateFare() {
    map<int, string> tollPlazas = {
        {1, "Islamabad"}, {2, "Fateh Jhang"}, {3, "Sangjani"}, {4, "Bharama"},
        {5, "Burhan"}, {6, "Hazara"}, {7, "Ghazi"}, {8, "Chach"},
        {9, "Swabi"}, {10, "Kernal Sher Khan"}, {11, "Wali Interchange"},
        {12, "Rashaki"}, {13, "Charsadda"}, {14, "Peshawar"}
    };

    map<int, int> tollFares = {
        {1, 0}, {2, 30}, {3, 50}, {4, 70}, {5, 100}, {6, 120}, {7, 150},
        {8, 180}, {9, 200}, {10, 220}, {11, 250}, {12, 270}, {13, 300}, {14, 350}
    };

    int from, to;
    long long phone;

    cout << "\nEnter Your Phone Number: ";
    cin >> phone;

    // Verify user and retrieve balance
    ifstream idFile(folder + "user_id.txt");
    ifstream balanceFile(folder + "balance.txt");
    ofstream tempFile(folder + "temp.txt");

    if (!idFile || !balanceFile || !tempFile) {
        cerr << "Error accessing files. Ensure the folder exists.\n";
        return;
    }

    long long phoneID;
    int balance, updatedBalance;
    bool userFound = false;

    while (idFile >> phoneID && balanceFile >> balance) {
        if (phoneID == phone) {
            userFound = true;

            cout << "\nSelect Starting Toll Plaza:\n";
            for (const auto& plaza : tollPlazas) {
                cout << plaza.first << ". " << plaza.second << endl;
            }
            cin >> from;

            cout << "\nSelect Destination Toll Plaza:\n";
            for (const auto& plaza : tollPlazas) {
                cout << plaza.first << ". " << plaza.second << endl;
            }
            cin >> to;

            if (from >= 1 && from <= 14 && to >= 1 && to <= 14) {
                int fare = abs(tollFares[to] - tollFares[from]);

                if (balance >= fare) {
                    updatedBalance = balance - fare;
                    cout << "\nCalculated Fare: " << fare << " RS\n";
                    cout << "Remaining Balance: " << updatedBalance << " RS\n";
                } else {
                    cout << "\nInsufficient Balance. Please recharge your M-TAG.\n";
                    updatedBalance = balance;
                }
            } else {
                cout << "Invalid toll plaza selection. Please try again.\n";
                updatedBalance = balance;
            }

            tempFile << updatedBalance << endl;
        } else {
            tempFile << balance << endl;
        }
    }

    idFile.close();
    balanceFile.close();
    tempFile.close();

    if (!userFound) {
        cout << "\nPhone number not found. Please register first.\n";
        remove((folder + "temp.txt").c_str());
    } else {
        remove((folder + "balance.txt").c_str());
        rename((folder + "temp.txt").c_str(), (folder + "balance.txt").c_str());
    }
}
