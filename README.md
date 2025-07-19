# 💡 Data Structures Lab – Polynomial Operations in C

This repository contains a set of C programs developed as part of the **Data Structures Laboratory** curriculum. The primary focus is on implementing **Polynomial Addition** using different representations such as arrays and structures.

---

## 📌 Overview

Polynomials are fundamental in computer science and mathematics, and this lab explores various ways to represent and manipulate them in C. Each program demonstrates a different approach to adding two polynomials:

- Using **1D arrays** for fixed degree polynomials
- Using **2D arrays** for term-by-term representation
- Using **structures** for modular and readable code

---

## 📂 File Descriptions

| File Name           | Description                                                                 |
|---------------------|-----------------------------------------------------------------------------|
| `polynomial.c`      | Adds two polynomials using **1D arrays**; suitable for polynomials of same degree. |
| `polynomial_sum.c`  | Uses **2D arrays** to store `[coefficient, exponent]` pairs for polynomial terms. |
| `structpoly.c`      | Implements polynomial addition using **structures** and clean modular functions.  |

---

## ⚙️ How to Compile and Run

Make sure you have a C compiler installed (`gcc` or similar). Use the following commands:

```bash
# For 1D array method
gcc polynomial.c -o polynomial
./polynomial

# For 2D array method
gcc polynomial_sum.c -o polynomial_sum
./polynomial_sum

# For structure-based method
gcc structpoly.c -o structpoly
./structpoly
