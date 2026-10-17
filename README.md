# CCE-UNIT-3
# Emergency Alert Management System Using a Linked List

## 1. Project Overview

Emergency Alert Management System is a C++ Data Structures mini-project that manages emergency alerts using a Singly Linked List.
The system allows users to add, search, display, and resolve emergency alerts dynamically. Each alert contains a unique ID, emergency
type, location, and priority level.

## 2. Problem Statement

Managing multiple emergency alerts manually can make it difficult to track incidents and identify which alerts require attention. This
project provides a linked-list-based system to organize emergency information, search for specific alerts, and remove alerts once they
are resolved.

## 3. Objectives

- Manage emergency alerts using a linked list.
- Add new emergency alerts dynamically.
- Store alert IDs, emergency types, locations, and priority levels.
- Search for alerts using their unique IDs.
- Display all active emergency alerts.
- Resolve and remove completed alerts.
- Demonstrate the practical application of linked-list operations.

## 4. Technologies Used

- Programming Language: C++
- Data Structure: Singly Linked List
- Memory Management: Dynamic Memory Allocation
- Interface: Console-based application
- Compiler: Dev-C++

## 5. Features

1. Add a new emergency alert.
2. Assign a unique ID to each alert.
3. Specify the emergency type and location.
4. Set the priority as High, Medium, or Low.
5. Display all active alerts.
6. Search for an alert using its ID.
7. Resolve and remove an alert.
8. Handle empty lists and invalid menu choices.

## 6. Linked List Operations

- **Insertion:** Adds a new emergency alert to the linked list.
- **Traversal:** Displays all stored emergency alerts.
- **Searching:** Finds an alert using its unique ID.
- **Deletion:** Removes an alert when it has been resolved.
- **Dynamic Memory Allocation:** Creates nodes as new alerts are added and releases memory when alerts are removed.

## 7. How to Run

1. Download or clone this repository.
2. Open `main.cpp` in Dev-C++ or another C++ compiler.
3. Compile and run the program.

Example compilation command:

`g++ main.cpp -o emergency_alert`

Run on Windows:

`emergency_alert.exe`

## 8. Sample Input

- Alert ID: 101
- Emergency Type: Fire
- Location: College
- Priority: 1 (High)

## 9. Sample Output

When the user selects Add Alert:

`Emergency alert added successfully!`

When the user selects Display Alerts:

```text
--- Emergency Alerts ---

Alert ID: 101
Emergency: Fire
Location: College
Priority: HIGH
```

When the user selects Resolve Alert:

`Alert resolved successfully!`

## 10. Limitations

- The project is a console-based software simulation.
- Alert details are stored temporarily in memory.
- All alerts are lost when the program closes.
- Alerts must be entered manually by the user.
- The system does not send real emergency notifications.
- Priority levels are assigned manually and do not automatically dispatch emergency services.

## 11. Future Scope

- Integrate SMS and email notifications.
- Add a graphical user interface.
- Store alert information in a database.
- Implement automatic alert prioritization.
- Add user authentication and access control.
- Integrate GPS location tracking.
- Develop a web-based or mobile emergency alert application.

## 12. Conclusion

The Emergency Alert Management System demonstrates the practical application of a singly linked list in C++. It provides basic operations for adding, searching, displaying, and resolving emergency alerts. The project helps develop an understanding of pointers, dynamic memory allocation, node traversal, insertion, and deletion. It can serve as a foundation for a more advanced emergency management application.
