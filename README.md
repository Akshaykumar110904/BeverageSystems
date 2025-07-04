````markdown
🍾 Beverages Cooperation Limited - Management System

A **C language** project for managing beverage company operations including **shop registration**, **brand stock**, **billing**, and **refilling**. This CLI-based application uses binary files for data storage and handles core inventory operations efficiently.

---

## 📌 Features

- ✅ **Shop Registration** (with authentication)
- ✅ **Add New Brands** to inventory
- ✅ **Display Available Stock**
- ✅ **Generate Billing** (with file output)
- ✅ **Refill Existing Stock**

---

## 🛠️ Technologies Used

- **Language**: C
- **File I/O**: Binary (`.dat`) and Text (`.txt`)
- **Platform**: Windows Console (uses `system("cls")` and `system("color F0")`)

---

## 🗂️ Project Structure

| File                | Description                            |
|---------------------|----------------------------------------|
| `main.c`            | Main source code file                  |
| `registration.dat`  | Binary file storing shop details       |
| `stock.dat`         | Binary file storing brand inventory    |
| `*.txt`             | Bill files generated for each shop     |

---

## 🧱 Data Structures

### `struct regis` – Shop Registration
```c
struct regis {
    int gn;             // Gazette Number
    char name[50];      // Owner Name
    char ac[50];        // Bank Account
    char phoneno[50];   // Phone Number
    char sname[50];     // Shop Name
    char pw[50];        // Password
};
````

### `struct brand` – Brand Inventory

```c
struct brand {
    int bid;            // Brand ID
    char bname[50];     // Brand Name
    long mrp;           // Price per Case
    int num;            // Available Cases
};
```

---

## 🖥️ How to Run

### ⚙️ Requirements

* C Compiler (GCC or Turbo C)
* Windows OS or Command Prompt support

### 🧪 Compile & Execute

```bash
gcc main.c -o beverages
./beverages
```

> For Linux: Replace `system("cls")` with `system("clear")` or remove it.

---

## 💡 Functional Breakdown

### 1. Register Your Shop

* Enter details like name, account number, shop name, and password.
* Data is saved in `registration.dat`.

### 2. Add Brand

* Add new beverage brands to `stock.dat`.
* Each brand has ID, name, MRP, and quantity.

### 3. Display Stock

* View the list of all beverage brands and available cases.

### 4. Do Billing

* Login using gazette number & password.
* Choose brands and quantity to purchase.
* Generates a `.txt` bill file and updates stock automatically.

### 5. Refill Stock

* Replenish stock for existing brands.

---

## 🧾 Sample Bill Output

```text
shop name:     CoolDrinksHub        gazitte number: 1234        date=2025-07-04
Owner name:    Ajay Kumar           Phone number:   9876543210

SL.NO   BRAND NAME         AMOUNT        CASES
============================================
1       Sprite              2400          4
2       Fanta               1800          3

TOTAL BILL = 4200.00
```

---

## 🚀 Future Improvements

* 🔐 Admin login and roles
* 📈 Analytics dashboard (sales, stock trends)
* 🧾 Save billing history to central database
* 🌐 Web-based or GUI version
* ☁️ Migrate from file I/O to SQLite/JSON

---

## 📃 License

This project is released under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

* Developed for academic and practice purposes.
* Inspired by real-world retail and distribution systems.

---

## 🤝 Contributing

Contributions and suggestions are welcome. Please open issues or submit pull requests!

````

---

### ✅ Next Steps:
- Save this as `README.md` in your GitHub repository root.
- You may also upload screenshots (e.g., of the terminal, sample output) and reference them using:
  ```markdown
  ![Sample Output](screenshots/sample-output.png)
````

Would you like a sample `.gitignore`, `Makefile`, or screenshot template too?
