Here's a detailed `README.md` file you can use for GitHub for your **Beverages Cooperation Limited** management system written in C.

---

````markdown
# 🍾 Beverages Cooperation Limited - Management System

This is a simple **console-based C project** that manages a beverage distribution company’s shop registration, brand inventory, billing, and restocking. It uses basic file operations to store and retrieve data from binary and text files.

---

## 📌 Features

This project allows:

1. **Shop Registration**  
   - Shops can register with gazette number, shop name, owner name, account details, phone number, and password.
   - Details are saved in `registration.dat`.

2. **Add New Brands**  
   - Admin can add new beverage brands with brand name, MRP, and stock count (cases).
   - Brand details are saved in `stock.dat`.

3. **Display Available Stock**  
   - Shows all current beverage brands with brand ID, name, MRP, and available stock.

4. **Billing System**  
   - Authenticated shops can generate bills by selecting brand IDs and the number of cases.
   - Adjusts available stock automatically.
   - Generates a `.txt` bill file with purchase details, shop info, and total bill.

5. **Refill Stock**  
   - Restock any brand by entering brand ID and number of cases.

---

## 🗃️ File Structure

| File Name         | Description                                  |
|------------------|----------------------------------------------|
| `main.c`         | The main source code file                    |
| `registration.dat`| Binary file storing registered shop data     |
| `stock.dat`       | Binary file storing beverage stock data      |
| `*.txt`           | Generated billing files based on date+shop   |

---

## 📂 Data Structures

### Shop Structure (`struct regis`)
```c
struct regis {
    int gn;            // Gazette Number
    char name[50];     // Owner Name
    char ac[50];       // Bank Account
    char phoneno[50];  // Phone Number
    char sname[50];    // Shop Name
    char pw[50];       // Password
};
````

### Brand Structure (`struct brand`)

```c
struct brand {
    int bid;        // Brand ID
    char bname[50]; // Brand Name
    long mrp;       // Price per Case
    int num;        // Available Cases
};
```

---

## 💡 How It Works

1. Upon running the program, the user is prompted to choose an action.
2. Based on input:

   * Shops can register or login.
   * Admin can add brands or refill stock.
   * Logged-in users can generate bills, which deducts stock and saves billing data in a `.txt` file.

---

## 🚀 Getting Started

### Requirements

* C Compiler (e.g., GCC)
* Windows Command Prompt (for `system("cls")` and `system("color F0")`)

> For Linux, replace `cls` with `clear` and remove color commands or use ANSI escape codes.

### Compile and Run

```bash
gcc main.c -o beverages
./beverages
```

---

## 📎 Notes

* All data is stored **locally** using binary and text files.
* No GUI — purely command-line interface.
* Case-sensitive authentication using Gazette Number and Password.
* Use proper input formatting for strings (no special characters or newline issues).

---

## 🧠 Concepts Used

* File Handling in C (`fopen`, `fread`, `fwrite`, `fseek`)
* Structs
* Arrays and Strings
* Basic Authentication
* Console I/O and formatting

---

## 🛠️ Improvements (Future Enhancements)

* Replace binary file format with SQLite or CSV.
* Add GUI using a C-based library (GTK or ncurses).
* Support for admin login for secure brand addition.
* Export billing history for all shops.
* Error logging and better input validation.

---

## 📃 Sample Bill Output

```txt
shop name:    CityMart         gazitte number: 1234        date=2025-07-04
Owner name:   Rakesh Gupta     Phone number:   9876543210

SL.NO   BRAND NAME         AMOUNT        CASES
============================================
1       Coke Zero          1200          3
2       Pepsi Max          1000          2

TOTAL BILL=2200.00
```

---

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🙏 Acknowledgements

* Developed as a C-based file handling mini project for academic purposes.

```
