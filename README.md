# Data Structures 

This repository contains various data structures implementations and examples in C++. It's a resource to help you understand and practice data structures, including linked lists, stacks, queues, binary trees, and graphs. Each data structure is presented with code examples .

## Table of Contents

- [Linked List](#linked-list)
- [Double Linked List](#double-linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Binary Tree](#binary-tree)
- [Graph](#graph)

---

### Linked List

This section includes implementations of a basic singly linked list data structure along with examples of how to use it. Key functions to include:
- `Node` struct/class: To represent the elements of the list.
- `LinkedList` class: Contains functions like `insert`, `delete`, `search`,`revers`,  and `display`.

---

### Double Linked List

Here, you'll find an implementation of a doubly linked list, a more advanced version of the linked list with bidirectional traversal. Functions to add:
- `Node` struct/class: Similar to the linked list but with two pointers (next and previous).
- `DoubleLinkedList` class: Functions for insertion, deletion, traversal in both directions, etc.

---

### Stack

We provide two implementations of a stack data structure(LIFO), one using arrays and the other using a linked list. Examples include balancing parentheses, infix to postfix conversion, and expression evaluation using postfix and prefix notations.

**Stack (Array Implementation):**
- `Stack` class with functions like `push`, `pop`, `peek`, `isEmpty`, and `isFull`,`display`.

**Stack (Linked List Implementation):**
- `Node` struct/class for the stack elements.
- `Stack` class with functions like `push`, `pop`, `peek`, `isEmpty`,`display`.

---

### Queue

This section covers three types of queues: a simple queue using an array, a circular queue using an array, and a queue using a linked list. Queues are essential for managing data in a first-in, first-out (FIFO) order.Functions to add:

- **Queue (Array Implementation):**
  - `Queue` class with functions for `enqueue`, `dequeue`, `isEmpty`, and `isFull`,`peek`,`display``clear`.

- **Circular Queue (Array Implementation):**
  - Similar to the regular queue but with modifications to handle circularity.

- **Queue (Linked List Implementation):**
  - `Node` struct/class for queue elements.
  - `Queue` class with functions for `enqueue`, `dequeue`, `peek`, `display`.

---

### Binary Tree

In this part, you'll find an implementation of a binary tree. We also include examples of binary search trees and AVL trees (height-balanced binary search trees). Functions to include:
- `Node` struct/class to represent the tree nodes.
- `BinaryTree` class with functions for insertion, traversal (inorder, preorder, postorder),level order, githight and searching.

**Binary Search Tree (BST):**
- Inherits or uses `BinaryTree` class but enforces the BST property with insert, delete, and search ,fin min find max,functions.

**AVL Tree (Height-Balanced Tree):**
- Inherits or uses the BST class, but includes balancing functions (rotation) and maintains the AVL property.

---

### Graph

This section focuses on graph representation in memory and includes implementations of two common graph traversal algorithms:

**Graph Representation:**
- Classes to represent a graph using adjacency lists or adjacency matrices.

**Breadth-First Search (BFS):**
- Function that takes a graph and a starting node, and returns the BFS traversal order.

**Depth-First Search (DFS):**
- Recursive function to perform DFS on a graph starting from a given node along a branch before backtracking..

---

## Getting Started

Each data structure is organized into its respective folder within the repository. You can explore the code, understand the implementation, and see examples of how to use them.

## Contributing

If you'd like to contribute to this repository by adding more data structures, improving existing code, or providing additional examples, please feel free to create a pull request.

