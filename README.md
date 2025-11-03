# 🏦 Banking System Using C++

A simple **Bank Management System** built using **Object-Oriented Programming (OOP)** concepts in **C++**.  
This project demonstrates **inheritance, polymorphism, abstraction**, and **file handling** to simulate real banking operations.

---

## 💡 Project Overview

The system allows users to:
- Create **Savings**, **Current**, or **Fixed Deposit (FD)** accounts.
- Deposit and withdraw money.
- Restrict withdrawals for Fixed Deposits.
- Automatically generate a unique account number.
- Save all account details to a text file (`acc.txt`).

---

## 🧱 OOP Concepts Used

| Concept | Description |
|----------|--------------|
| **Abstraction** | Implemented using pure virtual functions in the base class `Account`. |
| **Inheritance** | Classes `Savings`, `Current`, and `FixedDeposit` inherit from `Account`. |
| **Polymorphism** | Achieved through virtual functions for account creation and withdrawal. |
| **Encapsulation** | Account details like `accNo`, `balance`, etc. are protected members. |
| **File Handling** | Account details are saved in a text file (`acc.txt`). |

---

## 🧩 Class Structure

### 🏛️ Base Class: `Account`
- Contains common attributes (`accNo`, `name`, `balance`)
- Abstract functions:
  - `createAccount()`
  - `type()`
- Functions for deposit, withdrawal, and displaying account info.
- File writing through `saveToFile()`.

### 💰 Derived Classes

| Class | Description |
|--------|--------------|
| **Savings** | Allows normal deposit and withdrawal. |
| **Current** | Similar to Savings but categorized separately. |
| **FixedDeposit** | Calculates maturity amount based on interest and years; withdrawal disabled. |

---

## ⚙️ Features

✅ Create multiple types of accounts  
✅ Deposit money  
✅ Withdraw money (except for FD accounts)  
✅ View updated balance  
✅ Store data persistently in a text file  

---

## 💾 File: `acc.txt`

Each time an account is created, details are appended in the format:

