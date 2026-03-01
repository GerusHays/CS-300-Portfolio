# CS-300: Data Structures and Algorithms Portfolio Artifact

## Overview
This repository contains my runtime analysis and implementation of a course advising system that loads, stores, searches, and prints Computer Science course information. The purpose of this project was to evaluate different data structures and implement a solution that efficiently supports course lookup and alphabetical listing.

This artifact demonstrates my ability to analyze algorithm performance, select appropriate data structures, and implement maintainable, efficient software.

---

## Problem Being Solved
The goal of this project was to build a course advising system that could:

- Load course data from a file
- Store course information and prerequisites
- Quickly search for a specific course
- Print all courses in alphanumeric order

The challenge was selecting a data structure that balances fast lookup performance with efficient sorting and overall runtime efficiency.

To solve this, I analyzed three data structures:

- Vector
- Hash Table
- Binary Search Tree

Each structure was evaluated based on runtime performance for loading data, searching for courses, and printing sorted output.

---

## My Approach and Importance of Data Structures
I approached this project by first analyzing the runtime complexity of each data structure and understanding how they perform under different operations.

Data structures are critical because they directly impact program performance and scalability. For example:

- A vector is simple but inefficient for searching large datasets.
- A binary search tree improves search time and maintains sorted order.
- A hash table provides the fastest lookup performance on average.

Based on runtime analysis, the hash table was the best overall choice because it provides **constant-time average lookup**, which is the most common operation in an advising system.

---

## Roadblocks and How I Overcame Them
One of the biggest challenges was understanding how each data structure impacts runtime and when one structure is better than another. It is easy to assume one structure is always better, but this project showed that the best choice depends on system requirements.

Another challenge was implementing the data structure correctly while keeping the program organized and readable. I overcame this by breaking the problem into smaller steps:

- First loading and parsing the data
- Then storing the data properly
- Then implementing search functionality
- Finally implementing sorted output

Testing each step individually helped ensure the program worked correctly.

---

## How This Project Expanded My Software Design Approach
This project helped me better understand how important it is to choose the right data structure early in the design process. The choice of data structure directly affects:

- Performance
- Scalability
- Maintainability
- Program complexity

It also reinforced the importance of analyzing algorithm complexity rather than just focusing on making the program work.

I now think more about efficiency and scalability when designing systems.

---

## How This Project Improved My Programming Practices
This project improved how I write software in several ways:

- I now structure programs more logically and modularly
- I focus more on readability and maintainability
- I consider runtime performance during design, not after implementation
- I use structured problem-solving to break complex problems into smaller pieces

Understanding runtime complexity and data structure tradeoffs will help me design more efficient systems in the future.

---

## Data Structure Runtime Comparison

| Data Structure | Load Data | Search | Print Sorted |
|---------------|-----------|--------|--------------|
| Vector | O(n) | O(n) | O(n log n) |
| Hash Table | O(n) avg | O(1) avg | O(n log n) |
| Binary Search Tree | O(n log n) avg | O(log n) avg | O(n) |

The hash table was selected because it provides the fastest average search performance, which is the most critical operation for this system.

---

## Skills Demonstrated

- Data structure analysis
- Algorithm runtime analysis (Big-O)
- Hash table implementation
- Binary search tree concepts
- File parsing and data management
- Writing maintainable and structured C++ code
- Software design decision-making based on performance

---

## Portfolio Purpose
This artifact demonstrates my ability to evaluate data structures, analyze algorithm performance, and implement efficient software solutions. These skills are fundamental to software engineering, systems engineering, and performance-focused application development.
