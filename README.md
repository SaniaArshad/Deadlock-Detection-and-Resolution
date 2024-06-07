# Deadlock Detection and Resolution (C)

## Overview
This program is designed to detect and resolve deadlocks in a system with multiple processes and files. Deadlock occurs when two or more processes are unable to proceed because each is waiting for the other to release resources. The program reads input data from a file, processes it, detects deadlocks, and resolves them to ensure the system can continue execution without being stuck.

## Features
- **Input File**: The program expects input data to be provided in a specific format in a file named `task5p2.txt` which are proccesses to test the efficency and working of the algorithm.
- **Deadlock Detection**: It identifies potential deadlocks by analyzing the relationships between processes and files.
- **Deadlock Resolution**: Once deadlock is detected, the program takes necessary actions to resolve it, allowing the system to continue execution.
- **Execution Time Calculation**: It calculates the minimum execution time required to resolve deadlocks and continue execution.

4. **View Output**: The program will output information about the number of processes, unique files, and any deadlocks detected. It will also provide details on deadlock resolution and execution time.

## Tasks for Testing
Different tasks files can be used to test the program with various scenarios of processes and file interactions. Each task file contains data representing different processes and their interactions with files. The program analyzes this data to detect and resolve deadlocks accordingly.

## Notes
- Ensure that the input file path is correctly specified in the program code (`/home/user/CLionProjects/i202425_R_OSProject/task5p2.txt`).
- Review the code comments for better understanding of the implementation details and logic.
