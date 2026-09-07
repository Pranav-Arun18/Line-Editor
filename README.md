# Line-Editor
A command-line line editor written in C that allows users to insert, delete, display, save, load, search, and count lines in a text document using a dynamic array of strings.

Simple Line Editor in C

Team Members

Member 1: Pranav Arun

Member 2: Nischith R Prakash

Member 3: Preetham Gowda G

About the Project

This project is a simple command-line line editor developed using C.

The editor stores text line by line and allows the user to create, view and modify a small document through a terminal-based menu.

Data Structure Used

The program uses a 2D character array to store the document.

char lines[MAX_LINES][MAX_LENGTH]; 

The program also uses:

int lineCount; 

to keep track of the number of lines currently stored.

For the Undo feature, another 2D character array is used to store the previous state of the document.

char oldLines[MAX_LINES][MAX_LENGTH]; 

Why did we choose a 2D array?

We chose a 2D character array because the problem is designed for a small text document and this approach is simple and easy to manage in C.

Advantages:

Simple to understand

Easy to implement

Direct access to any line

No complicated pointer operations

Suitable for a small document

Trade-off

The number of lines and the maximum length of each line are fixed.

Insertion and deletion in the middle also require shifting lines, so these operations take O(n) time.

For a small document, this is acceptable.

Features Implemented

Core Features

Insert a line

Delete a line

Display the document

Bonus Features

Save document to a .txt file

Load document from a .txt file

Search for a word or phrase

Find and replace text

Undo the most recent modification

Line count

Word count

Character count

Menu

The program provides the following options:

1. Insert Line 2. Delete Line 3. Display Document 4. Save File 5. Load File 6. Search 7. Find and Replace 8. Undo 9. Line/Word Count 10. Help 11. Exit 

How to Compile

The project can be compiled using GCC.

gcc main.c -o line_editor 

How to Run

Windows

.\line_editor.exe 

Linux/macOS

./line_editor 

Example

================================= SIMPLE LINE EDITOR ================================= 1. Insert Line 2. Delete Line 3. Display Document 4. Save File 5. Load File 6. Search 7. Find and Replace 8. Undo 9. Line/Word Count 10. Help 11. Exit Enter choice: 1 Enter line number: 1 Enter text: Hello World Line inserted successfully. 

Displaying the document:

Enter choice: 3 --- DOCUMENT --- 1. Hello World ---------------- 

Insert Example

Suppose the document contains:

1. Hello 2. World 3. C Programming 

If the user inserts a new line at position 2:

Enter line number: 2 Enter text: Simple Line Editor 

The document becomes:

1. Hello 2. Simple Line Editor 3. World 4. C Programming 

The lines below the insertion point are shifted down.

Delete Example

Before deletion:

1. Hello 2. Simple Line Editor 3. World 

If line 2 is deleted:

1. Hello 2. World 

The lines below the deleted line are shifted up.

Search

The search feature finds a word or phrase in the document and displays the line numbers containing it.

Example:

Enter word or phrase to search: C Found at line 2: C Programming 

Find and Replace

The find and replace feature searches the document for text and allows the user to replace matching text.

Example:

Enter text to find: Hello Enter replacement text: Hi 

The matching text is replaced in the selected line.

Undo

The Undo feature stores the previous document state before a modification.

It can undo the most recent supported modification.

Example:

> Insert a new line Line inserted successfully. > Undo Last action undone. 

The document returns to its previous state.

Save and Load

Save

The current document can be saved into a text file.

Example:

Enter file name: notes.txt Document saved successfully. 

Load

A previously saved text file can be loaded into the editor.

Example:

Enter file name: notes.txt Document loaded successfully. 

Loading a file replaces the current document.

Document Statistics

The Count option displays:

Number of lines

Number of words

Number of characters

Example:

--- DOCUMENT STATISTICS --- Lines : 3 Words : 8 Characters : 45 --------------------------- 

Error Handling

The program handles common errors such as:

Invalid line numbers

Inserting outside the valid range

Deleting from an empty document

Full document

Empty search text

File opening errors

Invalid menu choices

Searching for text that does not exist

Replacement text that is too long

Complexity

OperationComplexityDisplayO(n)InsertO(n)DeleteO(n)SearchO(n) approximatelyFind & ReplaceO(n) approximatelySaveO(n)LoadO(n)CountO(total characters)UndoO(n)

Here, n represents the number of lines in the document.

Project Structure

simple-line-editor/ │ ├── main.c ├── README.md └── HELP.md 

Requirements

C compiler

GCC recommended

Terminal/Command Prompt

Course

Portfolio Building — Studio Course
3rd Semester Coding Competition

Conclusion

The project demonstrates the implementation of a basic line-oriented text editor using fundamental C programming concepts such as arrays, strings, functions, file handling and basic data manipulation.
