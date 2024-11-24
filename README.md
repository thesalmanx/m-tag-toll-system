# 🚗 M-TAG Toll Management System

Welcome to the **M-TAG Toll Management System**, a modern and efficient solution for toll plaza management. This program offers a user-friendly interface to handle vehicle registrations, balance management, and toll fare calculations. With robust features and clear output, this project is ideal for automating toll operations seamlessly.

---

## ✨ Features

- **🚘 New Vehicle Registration**: Securely register vehicles with essential details like name, CNIC, phone number, and license plate.
- **💳 Balance Recharge**: Recharge your M-TAG account and track your updated balance.
- **🛣️ Toll Fare Calculation**: Automatically calculate toll fares based on start and end plazas and deduct the amount from the user's balance.
- **📁 Organized File Management**: All data is stored in a dedicated `data` folder for better organization and easy access.

---

## 🛠️ Prerequisites

Ensure the following tools are installed:
- **C++ Compiler** (e.g., `g++`)
- **Terminal/Command Line**

---

## 🚀 How to Run the Program

Follow these steps to compile and run the project:

### Step 1: Clone the Repository
```bash
git clone https://github.com/thesalmanx/m-tag-toll-system.git
cd m-tag-toll-system
```

### Step 2: Compile the Code
Use g++ to compile the program:
```bash
g++ -std=c++11 m_tag.cpp -o mtag
```

### Step 3: Create the Output data Folder
Ensure the data folder exists. You can create it manually or let the program handle it automatically:

```bash
mkdir data
```

### Step 4: Run the Program
```bash
./mtag
```

###📖 Usage Instructions
When you run the program, you'll see the following menu:

```bash
------------WELCOME TO M-TAG SYSTEM--------------
1- New Vehicle Registration
2- Recharge Your M-TAG
3- Travel (Enter Toll Plaza Information)
4- Exit Program
Enter your choice:
```

#### 1️⃣ New Vehicle Registration
Enter the required details (name, CNIC, car number plate, phone number).
Recharge the initial M-TAG balance.
Registration details will be saved in the output_files folder.
#### 2️⃣ Recharge Your M-TAG
Enter your phone number to identify the account.
Add the desired recharge amount.
The updated balance will be displayed and saved.
#### 3️⃣ Travel (Enter Toll Plaza Information)
Select your starting and ending toll plazas from the menu.
The program calculates the toll fare and deducts it from your balance.
Displays the updated balance.
#### 4️⃣ Exit Program
Close the program safely.

### 📁 File Structure
```bash
.
├── mtag.cpp               # Main C++ source code
├── output_files/          # Directory for output files
│   ├── user_id.txt        # Stores user IDs
│   ├── balance.txt        # Stores user balances
│   ├── user_record.txt    # Detailed user registration records
├── README.md              # Documentation (this file)
```



### 📊 Example Output:
```
------------WELCOME TO M-TAG SYSTEM--------------
1- New Vehicle Registration
2- Recharge Your M-TAG
3- Travel (Enter Toll Plaza Information)
4- Exit Program
Enter your choice:  
```

New Vehicle Registration
```
Enter Your Full Name: Muhammad Salman
Enter Your CNIC Number: 3120592251569
Enter Your COVID-19 Certificate Number: 13422438
Enter Your Vehicle Number Plate: 1221
Enter Your Phone Number: 03061622389

Your M-TAG has been registered successfully.
Please recharge your M-TAG to start using the system.
```

Recharge Balance
```
Enter Your Phone Number: 03061622389
Enter the amount you want to recharge: 350
Recharge successful! Your new balance is: 350 RS
```

Travel Between Plazas
```
Enter Your Phone Number: 03061622389

Select Starting Toll Plaza:
1. Islamabad
2. Fateh Jhang
3. Sangjani
4. Bharama
5. Burhan
6. Hazara
7. Ghazi
8. Chach
9. Swabi
10. Kernal Sher Khan
11. Wali Interchange
12. Rashaki
13. Charsadda
14. Peshawar
1

Select Destination Toll Plaza:
1. Islamabad
2. Fateh Jhang
3. Sangjani
4. Bharama
5. Burhan
6. Hazara
7. Ghazi
8. Chach
9. Swabi
10. Kernal Sher Khan
11. Wali Interchange
12. Rashaki
13. Charsadda
14. Peshawar
4

Calculated Fare: 70 RS
Remaining Balance: 280 RS
```

#### 💡 Why Choose This Project?
- Real-World Application: Perfect for toll plaza automation with practical features.
- Easy to Use: Clean interface with detailed prompts.
- Organized Data: Stores all records in dedicated files for easy retrieval.
- Well-Documented: Clear instructions and comments for scalability and further development.

### ✨ Thank you for using M-TAG Toll Management System! Let's automate toll operations together! 🚦









