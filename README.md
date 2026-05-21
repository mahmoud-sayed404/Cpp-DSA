#  Data Structures & Algorithms in C++

This repository contains my implementations of Data Structures and Algorithms (DSA) using C++. The goal of this repo is to practice and understand core concepts like searching, sorting, linked lists, stacks, and queues, and I will keep adding more topics later.

---

# Implemented Algorithms

## Searching Algorithms
- Linear Search  
- Binary Search (Iterative)  
- Binary Search (Recursive)  

##  Sorting Algorithms
- Selection Sort  
- Insertion Sort  
- Bubble Sort  
- Merge Sort  
- Quick Sort  

---

# Implemented Data Structures

## 🔗 Singly Linked List (SLL)
Implemented a full Singly Linked List with:
- Insert at beginning  
- Insert at end  
- Insert at middle (by position)  
- Delete from beginning  
- Delete from end  
- Delete by value  
- Search for element  
- Display list elements  
- Get size of the list  

---

## 📚 Stack (Array Implementation)
A dynamic stack implementation using arrays in C++.

### Features:
- Push / Pop / Peek operations  
- Dynamic resizing when full (auto-expand)  
- Check if empty or full  
- Display stack elements  
- Manual memory management using pointers  

### About:
The stack is implemented using a dynamic array. When the stack reaches its capacity, it automatically doubles its size to accommodate more elements.

---

##  Stack (Linked List Implementation)
A stack implementation using a singly linked list in C++.

### Features:
- Push (insert element at top)  
- Pop (remove top element)  
- Peek (view top element)  
- Check if stack is empty  
- Get size of the stack  
- Display stack elements  
- Automatic memory management using destructor  

### About:
The stack is implemented using a linked list, where each node contains data and a pointer to the next node.  
The top of the stack is always represented by the head of the linked list.  

This implementation avoids fixed size limitations and allows dynamic memory allocation.

---

##  Queue (Array Implementation)
A queue implementation using a circular array in C++.

### Features:
- Enqueue (insert element at rear)  
- Dequeue (remove element from front)  
- Front/Top element access  
- Check if queue is empty or full  
- Display queue elements  
- Circular queue implementation for efficient space usage  
- Manual memory management using pointers  

### About:
The queue is implemented using a circular array technique.  
This allows efficient enqueue and dequeue operations without shifting elements.  

The `Front` pointer tracks the first element, while `Rear` tracks the last inserted element.  
Modulo operation (`% Capacity`) is used to make the queue circular and reuse empty spaces efficiently.

---

# Technologies Used
- C++
- OOP (Object-Oriented Programming)
- Pointers & Dynamic Memory Allocation
