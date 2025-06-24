# Console-Based-Task-Manager-in-C++-Code-Alpha-Internship-Project
A simple and interactive console-based Task Manager application written in C++ as part of the Code Alpha internship program. This project demonstrates core C++ programming concepts including classes, file handling, and user-driven menus to manage tasks efficiently from the command line.
 Console-Based Task Manager in C++

### 👨‍💻 Internship Project – Code Alpha

This is a simple console-based Task Manager application developed using **C++** as a part of my internship with **Code Alpha**. It allows users to add, view, and manage tasks through a terminal interface. All tasks are stored in a local file and are loaded automatically when the program starts.

## 🚀 Features
- ➕ Add new tasks with an optional category  
- 📋 View all pending or completed tasks  
- ✔️ Mark tasks as completed  
- 💾 Save tasks to `tasks.txt`  
- 🔄 Load tasks automatically on startup  

## 🛠️ Technologies Used
- C++ (Standard Template Library)  
- File Handling (fstream)  
- OOP Concepts (classes)  
- Console Input/Output  

## 📁 File Structure
📦 ConsoleTaskManager  
┣ 📄 ConsoleTaskManager.cpp → Main source code  
┗ 📄 tasks.txt → Auto-generated file for saving tasks  

📝 Sample Interaction
==== To-Do List Application ====

Add Task

Mark Task as Completed

View Pending Tasks

View Completed Tasks

Save and Exit
Enter your choice: 1
Enter task description: Complete report
Enter task category (optional): Internship
Task added successfully!

📌 Data Format (tasks.txt)
Each line is stored as:
<description>|<category>|<completed_status>
Example:
Complete report|Internship|0
Submit code|Coding|1
