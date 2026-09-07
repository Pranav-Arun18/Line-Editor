# 📝 SIMPLE LINE EDITOR IN C

Team Members:
1.Pranav Arun.
2.Nischith R Prakash.
3.Preetham Gowda G

### 🚀 A Lightweight Command-Line Text Editor Built with C

**Insert • Delete • Search • Replace • Undo • Save • Load**


## 📖 ABOUT THE PROJECT

> **Simple Line Editor** is a command-line text editor developed using **C programming**.

The editor stores text **line by line** and allows users to create, view, modify, search, save, and load a small document directly from the terminal.

The project uses a **2D character array** as its main data structure, making the implementation simple, efficient, and easy to understand.

```text
        ┌──────────────────────────────┐
        │      📝 LINE EDITOR          │
        ├──────────────────────────────┤
        │                              │
        │  ✏️  Insert                  │
        │  🗑️  Delete                  │
        │  👀  Display                 │
        │  💾  Save                    │
        │  📂  Load                    │
        │  🔎  Search                  │
        │  🔄  Replace                 │
        │  ↩️  Undo                    │
        │  📊  Statistics              │
        │                              │
        └──────────────────────────────┘
```

---

# 🧠 DATA STRUCTURE

The document is stored using a two-dimensional character array:

```c
char lines[MAX_LINES][MAX_LENGTH];
```

Each row represents one line of the document.

The number of currently stored lines is maintained using:

```c
int lineCount;
```

For the Undo feature, another 2D array stores the previous document state:

```c
char oldLines[MAX_LINES][MAX_LENGTH];
```

### Example

```text
lines[0] → "Hello"
lines[1] → "World"
lines[2] → "C Programming"
```

This represents:

```text
1. Hello
2. World
3. C Programming
```

---

# 💡 WHY A 2D ARRAY?

A 2D character array was chosen because the editor is designed for a **small text document**.

### Advantages

```text
✓ Simple to understand
✓ Easy to implement
✓ Direct access to any line
✓ Easy string manipulation
✓ No complicated pointer operations
✓ Suitable for small documents
```

### Trade-offs

```text
⚠ Maximum number of lines is fixed
⚠ Maximum line length is fixed
⚠ Insertion requires shifting lines
⚠ Deletion requires shifting lines
```

For a small command-line editor, these limitations are acceptable.

---

# ✨ FEATURES

## 🛠️ Core Features

### 1. ✏️ Insert Line

Insert a new line at any valid position.

### 2. 🗑️ Delete Line

Delete a selected line from the document.

### 3. 👀 Display Document

Display all currently stored lines with line numbers.

---

## 🚀 Additional Features

| Feature            | Description                                 |
| ------------------ | ------------------------------------------- |
| 💾 Save File       | Save the document to a `.txt` file          |
| 📂 Load File       | Load a previously saved text file           |
| 🔎 Search          | Search for a word or phrase                 |
| 🔄 Find & Replace  | Replace matching text                       |
| ↩️ Undo            | Undo the most recent supported modification |
| 📊 Line Count      | Count the number of lines                   |
| 🔤 Word Count      | Count the number of words                   |
| 🔡 Character Count | Count the number of characters              |
| ❓ Help             | Display instructions for using the editor   |

---

# 🖥️ MENU

```text
╔══════════════════════════════════════════╗
║          📝 SIMPLE LINE EDITOR           ║
╠══════════════════════════════════════════╣
║                                          ║
║  1. ✏️  Insert Line                     ║
║  2. 🗑️  Delete Line                      ║
║  3. 👀  Display Document                ║
║  4. 💾  Save File                       ║
║  5. 📂  Load File                       ║
║  6. 🔎  Search                           ║
║  7. 🔄  Find and Replace                ║
║  8. ↩️  Undo                             ║
║  9. 📊  Line / Word Count              ║
║ 10. ❓  Help                             ║
║ 11. 🚪  Exit                             ║
║                                          ║
╚══════════════════════════════════════════╝
```

---

# 🎬 EXAMPLE

### Insert Line

```text
Enter choice: 1

Enter line number: 1
Enter text: Hello World

✓ Line inserted successfully.
```

### Display Document

```text
Enter choice: 3

──────────── DOCUMENT ────────────

1. Hello World

──────────────────────────────────
```

---

# 🔀 INSERT OPERATION

Suppose the document contains:

```text
1. Hello
2. World
3. C Programming
```

The user inserts a new line at position `2`.

```text
Enter line number: 2
Enter text: Simple Line Editor
```

The lines below the insertion point are shifted downward.

```text
BEFORE

1. Hello
2. World
3. C Programming

        ↓ INSERT

AFTER

1. Hello
2. Simple Line Editor
3. World
4. C Programming
```

### Complexity

```text
Insert → O(n)
```

---

# 🗑️ DELETE OPERATION

Before deletion:

```text
1. Hello
2. Simple Line Editor
3. World
```

Delete line `2`:

```text
Enter line number: 2

✓ Line deleted successfully.
```

After deletion:

```text
1. Hello
2. World
```

The lines below the deleted line are shifted upward.

### Complexity

```text
Delete → O(n)
```

---

# 🔎 SEARCH

The Search feature finds a word or phrase and displays the line numbers where it occurs.

Example:

```text
Enter word or phrase to search: C

✓ Found at line 2: C Programming
```

If the text does not exist:

```text
✗ Text not found in the document.
```

### Complexity

```text
Search → O(n) approximately
```

---

# 🔄 FIND AND REPLACE

The editor can search for text and replace matching text.

Example:

```text
Enter text to find: Hello
Enter replacement text: Hi
```

Before:

```text
1. Hello World
```

After:

```text
1. Hi World
```

This feature uses C string manipulation techniques to locate and replace text.

---

# ↩️ UNDO

The Undo feature stores the previous state of the document before a supported modification.

```text
Current Document
       │
       ▼
Save Previous State
       │
       ▼
Perform Modification
       │
       ▼
     UNDO
       │
       ▼
Restore Previous State
```

### Example

```text
Before:

1. Hello
2. World

        ↓ Insert

1. Hello
2. C Programming
3. World

        ↓ Undo

1. Hello
2. World
```

The editor supports undoing the **most recent supported modification**.

---

# 💾 SAVE FILE

The current document can be saved as a text file.

```text
Enter file name: notes.txt

✓ Document saved successfully.
```

The document is written line by line into the specified `.txt` file.

---

# 📂 LOAD FILE

A previously saved text file can be loaded into the editor.

```text
Enter file name: notes.txt

✓ Document loaded successfully.
```

Loading a file replaces the current document.

---

# 📊 DOCUMENT STATISTICS

The Count option displays the number of:

* Lines
* Words
* Characters

Example:

```text
╔══════════════════════════════════╗
║       DOCUMENT STATISTICS        ║
╠══════════════════════════════════╣
║ Lines      : 3                   ║
║ Words      : 8                   ║
║ Characters : 45                  ║
╚══════════════════════════════════╝
```

---

# 🛡️ ERROR HANDLING

The program handles common errors such as:

```text
✓ Invalid line numbers
✓ Invalid insertion position
✓ Deleting from an empty document
✓ Full document
✓ Empty search text
✓ File opening errors
✓ Invalid menu choices
✓ Text not found during search
✓ Replacement text that is too long
```

Example:

```text
Enter line number: 25

✗ Invalid line number.
Please enter a valid position.
```

---

# ⚡ COMPLEXITY ANALYSIS

Let `n` represent the number of lines in the document.

| Operation      |     Time Complexity |
| -------------- | ------------------: |
| Display        |                O(n) |
| Insert         |                O(n) |
| Delete         |                O(n) |
| Search         |  O(n) approximately |
| Find & Replace |  O(n) approximately |
| Save           |                O(n) |
| Load           |                O(n) |
| Count          | O(total characters) |
| Undo           |                O(n) |

Insertion and deletion take `O(n)` because lines may need to be shifted.

---

# 📁 PROJECT STRUCTURE

```text
simple-line-editor/
│
├── 📄 main.c
├── 📘 README.md
└── 📕 HELP.md
```

### `main.c`

Contains the complete implementation of the line editor.

### `README.md`

Contains project documentation and usage information.

### `HELP.md`

Contains detailed instructions for operating the editor.

---

# ⚙️ REQUIREMENTS

```text
C Compiler
GCC Recommended
Terminal / Command Prompt
```

---

# 🚀 HOW TO COMPILE

## Windows

Compile:

```bash
gcc main.c -o line_editor
```

Run:

```bash
.\line_editor.exe
```

---

## Linux / macOS

Compile:

```bash
gcc main.c -o line_editor
```

Run:

```bash
./line_editor
```

---

# 🧪 COMPLETE EXAMPLE

```text
=========================================
        📝 SIMPLE LINE EDITOR
=========================================

1. Insert Line
2. Delete Line
3. Display Document
4. Save File
5. Load File
6. Search
7. Find and Replace
8. Undo
9. Line / Word Count
10. Help
11. Exit

Enter choice: 1

Enter line number: 1
Enter text: Hello World

✓ Line inserted successfully.


Enter choice: 1

Enter line number: 2
Enter text: C Programming

✓ Line inserted successfully.


Enter choice: 3

------------ DOCUMENT ------------

1. Hello World
2. C Programming

----------------------------------


Enter choice: 6

Enter word or phrase to search: C

✓ Found at line 2: C Programming


Enter choice: 9

--------- DOCUMENT STATISTICS ---------

Lines      : 2
Words      : 4
Characters : 25

----------------------------------------


Enter choice: 11

Thank you for using Simple Line Editor!
```

---

# 📌 CONCLUSION

**Simple Line Editor** is a command-line text editing application implemented using fundamental C programming concepts.

The project combines:

```text
2D Arrays
    +
Strings
    +
Functions
    +
File Handling
    +
Searching
    +
Data Manipulation
    +
Undo Logic
        ↓
📝 SIMPLE LINE EDITOR
```

It provides a simple and practical way to understand how text can be stored and manipulated using arrays and string operations in C.

---
