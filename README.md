# BST Search Optimization — 
 
**École Nationale Supérieure d'Informatique (ESI), Algiers**.

The project implements and compares several **Binary Search Tree (BST)** strategies for storing and searching random words, using a configurable **triplet of prefix characters (X, Y, Z)** to optimize search performance.

A
---

## Overview

This repository contains two versions of the same program:

| File       | Language | Description                                      |
|------------|----------|--------------------------------------------------|
| `tp.txt`   | **Z**    | Original source in ESI's pedagogical Z language  |
| `TPZ.C`    | **C**    | Equivalent C implementation (Z → C conversion)   |

**Z** is the algorithmic language developed at ESI (Prof. D.E. Zegour) for teaching data structures and algorithms. The C version follows the same logic and includes an interactive menu with additional performance benchmarks.

---

## Problem Statement

Given a file of random words and three prefix characters **X**, **Y**, and **Z**:

1. Build several BST variants from the word file.
2. Support efficient **word search** and **range search** (between two words).
3. Analyze tree properties: depth, traversals, per-level statistics.
4. Compare a **standard BST** against an **optimized triplet-based BST architecture**.

---

## BST Variants

| Tree   | Insertion strategy |
|--------|--------------------|
| **BST0** | Standard BST — baseline, no rotations |
| **BST1** | When a word starts with X, Y, or Z → rotate the node to the root (`Rotation_bst13`) |
| **BST2** | Same trigger as BST1, but rotation depth depends on insertion path length (`Rotation_bst2`) |
| **BST3** | When a word does **not** start with X, Y, or Z → rotate to root (`Rotation_bst13`) |

All trees store **strings** as keys and maintain **parent pointers** to support rotations.

---

## Search Strategy (Triplet Routing)

Instead of searching one large tree, the program routes queries to the most suitable tree:

- Words starting with **X, Y, or Z** → **BST1**
- Words whose first character is **greater than** X, Y, and Z → **BST2**
- All other words → **BST3**

Search uses **`Cas_triv`** (trivial-case pruning) to skip subtrees that cannot contain the target word, reducing the number of visited nodes.

---

## Features

### Core operations (Z & C)
- Random word file generation (`Generate_file`) — ~100–120 words, some prefixed with X/Y/Z
- BST construction from file (`Create_bst0`, `Create_bst1`, `Create_bst2`, `Create_bst3`)
- Insertion with duplicate rejection (`Recherche_TO_INSERT`, `Recherche_by_path`)
- Left/right rotations (`Rot_left`, `Rot_right`)
- **Inorder** and **Preorder** traversals
- Count words starting with X, Y, or Z (`Count_number_of_words`)
- Tree depth computation (`Depth_tree`)
- Per-level XYZ node count (`N_node_xyz_level`, `Values_of_level`)
- Single-word search (`Search_word`, `Search_in_bst`)
- Range search between two words (`Range_search`, `Range_display`, `Tri_vecteur`)

### Additional features (C version only)
- Interactive colored menu (`show_menu`)
- Full test suite per BST variant (`Display_tests`)
- **Module 2** — single-word search efficiency: BST0 vs. triplet architecture
- **Module 3** — range search efficiency comparison over multiple simulations

---

## Data Structures Used

- **Binary Search Tree** (`ARB DE CHAINE`) with parent pointers
- **Queue** (`FILE DE CHAINE`) — range search results
- **Stack** (`PILE DE CHAINE`) — level-by-level traversal
- **Vector** (`VECTEUR DE CHAINES`) — selection sort for range output
- **Structured file** (`FICHIER DE CHAINES`) — random access word storage


---

## How to Run (C version)

### Prerequisites
- A C compiler (GCC, MinGW, MSVC)
- Create the word file directory: `D:\FILEWORD\` (or adjust paths in the source)

### Compile
```bash
gcc TPZ.C -o tpz
