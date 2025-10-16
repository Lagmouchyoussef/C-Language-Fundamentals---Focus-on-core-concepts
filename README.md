# C Language Fundamentals - Focus on Core Concepts

![C](https://img.shields.io/badge/C-11-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)

Welcome to this repository, which contains a series of C programming exercises designed to strengthen understanding of the language's core concepts. The modules progress from basic array manipulation to a complete data management system, demonstrating key principles like memory management, pointers, and data structures.

## 🎯 Key Concepts Demonstrated

This project aims to provide clear, practical examples of the following fundamental C concepts:

- **Dynamic Memory Allocation:** Using `malloc` and `free` to manage memory at runtime.
- **Pointer Manipulation:** Understanding the difference between passing arguments by value and by address.
- **Custom Data Structures:** Implementing complex data types using `struct`.
- **CRUD Logic:** Developing a console application with Create, Read, Update, and Delete functionalities.
- **Array Algorithms:** Performing common operations like searching, finding the maximum, and calculating averages.

## 📁 Project Structure

```
.
├── README.md
├── src/
│   ├── exercice1.c    // Interactive array operations with dynamic allocation
│   ├── exercice2.c    // Demonstration of pass-by-value vs. pass-by-address
│   └── exercice3.c    // Student grade management system (CRUD)
└── bin/               // Compiled executables
```

## 🛠️ Prerequisites

To compile and run this code, you must have a C compiler such as `GCC` installed on your system.

## 🚀 Installation and Usage

1.  **Clone the repository**
    ```bash
    git clone https://github.com/Lagmouchyoussef/C-Language-Fundamentals---Focus-on-core-concepts.git
    cd C-Language-Fundamentals---Focus-on-core-concepts
    ```

2.  **Compile a module**
    For example, to compile the first exercise:
    ```bash
    gcc -o bin/exercice1 src/exercice1.c
    ```

3.  **Run the program**
    ```bash
    ./bin/exercice1
    ```

## 📚 Module Details

### Module 1: Interactive Array Operations

**File:** `src/exercice1.c`

This program dynamically allocates an integer array based on user input and then performs a series of essential operations on it.

**Key Features:**
- `afficher_tableau`: Displays the contents of the array.
- `moyenne`: Calculates and returns the average of the array's elements.
- `rechercher_valeur`: Searches for a value and returns its first index or `-1` if not found.
- `max_tableau`: Finds the maximum value in the array.
- `nb_occurrences`: Counts the number of times a specific value appears.
- Properly frees allocated memory with `free()`.

### Module 2: Parameter Passing Methods

**File:** `src/exercice2.c`

This module provides a clear and concise demonstration of the difference between passing arguments by value and by address (using pointers) in C.

**Concepts Illustrated:**
- `echange_val(float a, float b)`: Attempts to swap two floats. It fails because it operates on copies of the variables (pass-by-value).
- `echange_addr(float *a, float *b)`: Successfully swaps two floats by modifying the values at the given memory addresses (pass-by-address).

### Module 3: Student Grade Management System

**File:** `src/exercice3.c`

A comprehensive console application for managing student grades. This module showcases the use of structs, dynamic memory allocation, and robust error handling to build a functional CRUD system.

**Data Structures:**
- `Note`: Contains a module name, coefficient, and grade.
- `Etudiant`: Contains a student's name, age, and a dynamically allocated array of `Note`.

**Implemented Features (CRUD):**
- **Create**: `init_etudiant`, `ajouter_note` (with checks for capacity, duplicate modules, and valid grades).
- **Read**: `affiche_etud` to display all student information in a formatted way.
- **Update**: `modifier_note` to change an existing grade.
- **Delete**: `supprimer_note` to remove a grade from the list.
- **Analysis**: `calculer_moyenne` (weighted average) and `note_maximale`.

## 👨‍💻 Author

- **Youssef Lagmouch**

## 📜 License

This project is licensed under the `MIT License`. See the [LICENSE](LICENSE) file for more details.
