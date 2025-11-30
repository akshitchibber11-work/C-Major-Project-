# C-Major-Project-
Student Finance Management System

A simple and practical C-based console application that helps students manage their daily finances. This system allows users to securely sign up, log in, track income, record expenses, and calculate savings — with data stored permanently for future use.

📌 Features

User Signup and Login system

Add Income and automatically update balance

Add Expenses with balance check

Enter Savings Percentage to move money from balance to savings

Persistent data storage using files (no data loss on exit)

Delete Account option to remove a user permanently

Fully modular code split into multiple .c and .h files

Simple, menu-driven interface suitable for students

🗂️ Repository Structure
/
|-- src/          (All .c files)
|-- include/      (All .h files)
|-- docs/         (Project report and diagrams)
|-- assets/       (Screenshots - optional)
|-- data/         (Persistent storage files)
|-- README.md     (This file)
|-- sample_input.txt (optional test input)


Important: Folder names are case-sensitive and must match exactly:
src, include, docs

⚙️ Technologies Used
Component	Purpose
C Language	Core implementation
Structures	Storing user profile data
File Handling	Persistent user data storage
Modular Programming	Clean and maintainable design
Switch Case	User menu navigation
📁 Modules Overview
Module	Description
main.c	Controls the main menu and navigation
auth.c	Login and signup system
finance.c	Handles income, expenses and savings logic
delete.c	Deletes a user account
storage.c	Loads and saves user data to file
utils.c	Input helpers and validation
common.h	Defines the User structure and constants
🚀 How to Compile and Run
Step 1: Ensure GCC is installed
gcc --version

Step 2: Compile the project
gcc -Wall -Wextra -std=c99 -Iinclude src\*.c -o student_finance.exe

Step 3: Run the program
student_finance.exe

🧠 How the System Works

The user signs up or logs in

After login, the finance dashboard displays:

Username

Total Balance

Savings

Options available:

Add income

Add expense

Save a percentage of balance

The system updates values in realtime and stores them permanently in:

data/users.dat


User can delete their account if needed

💡 Example Console Output
----------------------
Student Finance System

1) Login
2) Sign up
3) Delete Account
0) Exit
----------------------
Choose:

📌 Future Enhancements

Encrypt stored passwords

Monthly financial reports

Graphical user interface (GUI)

Android/mobile version

Graphs for spending visualization

🎓 Educational Value

This project demonstrates:

Real-life use of C structures

File handling for persistent data

Modular programming best practices

Logical problem-solving

Practical financial management concepts

Ideal for B.Tech, Diploma, and practical examinations.

👨‍💻 Author

Developed by: Akshit Chibber
Department: Computer Science Engineering
Project Type: Major Project in C Programming

✔️ Project Status

COMPLETED — READY FOR EVALUATION

Thank you for checking out this project!
