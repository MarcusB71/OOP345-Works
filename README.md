# OOP345-Works
This repository contains the code for workshops I have done throughout the semester with the purpose of learning advanced C++ and OOP principles in order to create the Assembly Line Simulation project which can be found in the [MS3](./MS3) directory.

# MS3 - Assembly Line Simulation
## Project Overview
This project is a C++ Object-Oriented real-world assembly line simulation. The simulation is capable of generating a custom number of stations as a set of workstations, each having a specific stock of items. A line manager is responsible for moving queues of customer orders down the line, filling orders at each station. The simulation manages inventory at each station and will result in a complete or incomplete order if inventory permits. 

## Skills Developed
### C++ Programming
- **OOP Principles:** Employed the use of OOP core concepts such as encapsulation, inheritance, polymorphism, and abstraction.
- **Reading-in Files:** Exposure to reading and writing files.
- **Memory Management:** Application of memory allocation and management.
### System Design
- **Modular Architecture:** Separation of code into header and cpp files to create maintainable and readable code, as seen in modules `Utilities`, `Station`, `WorkStation`, `CustomerOrder`, and `LineManager`.
- **Process Flow Management:** Complex order processing across stations.
### Data Structures and Algorithms
- **Efficient Data Handling:** Use of queues in `Workstation` for optimal data management.
- **Algorithms:** Application of algorithms in station management and for order processing.
### Real-world App Development
- **Business Logic Implementation:** Tranformation of business logic into code.
- **Code Documentation:** Focus on writing properly documented and readable code.

## Features
### `Utilities` and `Station` Classes
- **Utilities Module:** Supports parsing of files for configuration.
- **Station Module:** Manages information for each station on the assembly line and handles items for customers orders.
### `CustomerOrder` Module
- Manages a single customer order on the assembly line, checking if a station can fill the order as it moves from station to station.
### `Workstation` and `LineManager` Modules
- **Workstation Module:** Represents an active station on the assembly line and manages order processing.
- **LineManager Module:** Reponsible for configuring the assembly line, then moving orders along it, and determining if orders are complete or incomplete. 

# How to compile and Run the Project

To compile and run the Assembly Line Simulation, follow these steps:
1. Clone the repository to your local machine
2. Ensure you have a C++ compiler such as GCC or Clang.
3. Compile the source files. For example using GCC:
 ```
 g++ -Wall -std=c++17 -o AssemblyLine *.cpp
 ```
4. Run the compiled Application:
 ```
 ./AssemblyLine Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt
 ```
# Contribution
Contributions are welcome. Please fork the repository and submit a pull request for review.
