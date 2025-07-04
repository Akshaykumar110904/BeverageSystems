# Beverages Cooperation Limited - Inventory & Billing Management System

## Overview
This is a console-based C application developed to manage daily operations of a beverage distribution company. It allows shop registration, stock management, order billing, and inventory refilling. The system uses **binary file storage** (`.dat`) and generates **text-based bills** for persistence and record-keeping.

---

## Features

- **Shop Registration**: Register new shops with full details (owner name, account, phone, shop name, etc.).
- **Brand Management**: Add new beverage brands with price and available stock.
- **Display Stock**: View current inventory with brand ID, name, MRP, and available cases.
- **Order & Billing**: Generate invoices after verifying shop credentials, update stock, and create bill files.
- **Refill Inventory**: Refill stock by entering the brand ID and number of cases.
- **File Handling**: Stores and retrieves data using binary files (`registration.dat`, `stock.dat`) and generates bills as `.txt` files.

---

## Prerequisites

1. **C Compiler** (e.g., GCC)
2. **Windows OS** (or modify `system("cls")` and `system("color F0")` for Linux)
3. Basic terminal or command-line knowledge

---

## Installation & Execution

1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   cd <repository-folder>


2. **Compile the Program**

   ```bash
   gcc BeverageSystem.c -o beverages
   ```

3. **Run the Program**

   ```bash
   ./beverages
   ```

> ✅ For Linux: Replace `system("cls")` with `system("clear")` and remove `system("color F0")` or use ANSI codes.

---

## Menu Options

1. **Register Shop**

   * Enter owner name, phone, account, shop name, and password
   * Stored in `registration.dat`

2. **Add Brands**

   * Add multiple beverage brands (name, MRP, stock)
   * Stored in `stock.dat`

3. **Display Stock**

   * View all current brands with ID, name, price, and stock

4. **Billing**

   * Authenticate shop using gazette number and password
   * Select brand IDs and number of cases
   * Stock updates automatically
   * Bill generated as `shopname+date.txt`

5. **Refill Stock**

   * Replenish stock for selected brand IDs

6. **Exit**

   * Close the application

---

## Data Structures

### Shop Registration

```c
struct regis {
    int gn;               // Gazette Number
    char name[50];        // Owner Name
    char ac[50];          // Bank Account
    char phoneno[50];     // Phone Number
    char sname[50];       // Shop Name
    char pw[50];          // Password
};
```

### Brand Inventory

```c
struct brand {
    int bid;              // Brand ID
    char bname[50];       // Brand Name
    long mrp;             // Price per Case
    int num;              // Available Cases
};
```

---

## File Formats

* **registration.dat**: Binary file storing shop details
* **stock.dat**: Binary file storing brand stock
* **<shopname><date>.txt**: Text file containing bill details for each order

---

## Sample Bill Output

```txt
shop name:   SparkMart       gazitte number: 1002       date=2025-07-04
Owner name:  Nikhil Reddy    Phone number:   9876543210

SL.NO   BRAND NAME     AMOUNT     CASES
==========================================
1       Coke Zero       2400       4
2       Sprite          1800       3

TOTAL BILL = 4200.00
```

---

## Limitations

* No GUI (command-line only)
* Passwords are stored as plain text
* No database backend (file-based only)
* No role-based access (admin/shop combined)

---

## Possible Enhancements

* 🔐 Admin login with access control
* 📊 Sales analytics and reports
* ☁️ Shift to SQLite or PostgreSQL for robust data handling
* 🌐 Web-based UI using Django/Flask
* 🧾 Export complete sales history and logs

---

## Acknowledgments

* Developed using standard C file-handling concepts
* Designed for academic and learning purposes
