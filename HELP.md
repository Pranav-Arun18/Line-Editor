# 📝 SIMPLE LINE EDITOR

> **A tiny editor. A simple terminal. Your document.**

Welcome to **Simple Line Editor**, a lightweight command-line text editor built in C.

No GUI. No mouse. Just commands and text.

---

## 🚀 QUICK START

Run the program and you'll see:

```text
╔════════════════════════════════════╗
║        SIMPLE LINE EDITOR          ║
╠════════════════════════════════════╣
║  1. Insert Line                    ║
║  2. Delete Line                    ║
║  3. Display Document               ║
║  4. Save File                      ║
║  5. Load File                      ║
║  6. Search                         ║
║  7. Find and Replace               ║
║  8. Undo                           ║
║  9. Line/Word Count                ║
║ 10. Help                           ║
║ 11. Exit                           ║
╚════════════════════════════════════╝
```

**Choose a number → perform an action → continue editing.**

---

# ✍️ 1. INSERT LINE

Want to add something to your document?

Choose:

```text
1
```

Then enter the line number and text.

### Example

```text
Enter choice: 1
Enter line number: 1
Enter text: Welcome to C Programming

Line inserted successfully.
```

Your document:

```text
1. Welcome to C Programming
```

### Insert in the middle

Before:

```text
1. Hello
2. World
3. C Programming
```

Insert at line `2`:

```text
2. This is a new line
```

Result:

```text
1. Hello
2. This is a new line
3. World
4. C Programming
```

💡 **Behind the scenes:** existing lines are shifted one position down.

---

# 🗑️ 2. DELETE LINE

Made a mistake?

Choose:

```text
2
```

Enter the line number you want to remove.

### Example

```text
Enter choice: 2
Enter line number to delete: 2

Line deleted successfully.
```

Before:

```text
1. Hello
2. This is a mistake
3. World
```

After:

```text
1. Hello
2. World
```

💡 **Behind the scenes:** the lines below the deleted line move one position up.

---

# 👀 3. DISPLAY DOCUMENT

See what's currently inside your document.

Choose:

```text
3
```

Example:

```text
--- DOCUMENT ---
1. Hello
2. C Programming
3. Line Editor
----------------
```

If there is nothing to display:

```text
Document is empty.
```

---

# 💾 4. SAVE FILE

Don't lose your work!

Choose:

```text
4
```

Enter a filename:

```text
Enter file name: notes.txt
```

The editor stores the current document in that text file.

Example:

```text
Document saved successfully.
```

---

# 📂 5. LOAD FILE

Already have a text file?

Bring it into the editor.

Choose:

```text
5
```

Then:

```text
Enter file name: notes.txt
```

The file contents become the current document.

```text
Document loaded successfully.
```

⚠️ **Note:** Loading a file replaces the document currently in memory.

---

# 🔎 6. SEARCH

Looking for something?

Choose:

```text
6
```

Enter a word or phrase.

### Example

```text
Enter word or phrase to search: programming
```

The editor checks every line.

Output:

```text
Found at line 2: C Programming
```

If nothing matches:

```text
Text not found.
```

---

# 🔄 7. FIND & REPLACE

Found something you want to change?

Choose:

```text
7
```

Enter the text you want to find:

```text
Enter text to find: Hello
```

Then enter the replacement:

```text
Enter replacement text: Hi
```

If a matching line is found:

```text
Line 1: Hello World
Replace this line? (y/n):
```

Enter:

```text
y
```

Result:

```text
Hi World
```

Enter:

```text
n
```

to leave that line unchanged.

---

# ↩️ 8. UNDO

Oops.

Made a change you don't want?

Choose:

```text
8
```

The editor restores the previous document state.

Example:

```text
Last action undone.
```

### Important

This editor supports **one level of Undo**.

That means it can undo the most recent modification.

---

# 📊 9. DOCUMENT STATISTICS

Curious about your document?

Choose:

```text
9
```

You'll see:

```text
--- DOCUMENT STATISTICS ---
Lines      : 5
Words      : 18
Characters : 96
---------------------------
```

The editor counts:

* 📄 Lines
* 🔤 Words
* 🔢 Characters

---

# ❓ 10. HELP

Lost?

That's what this command is for.

Choose:

```text
10
```

The editor displays the available operations.

---

# 🚪 11. EXIT

Finished editing?

Choose:

```text
11
```

You'll see:

```text
Exiting editor...
```

And the program closes.

---

# 🧪 TRY THIS MINI DEMO

Want to test everything quickly?

Start by inserting three lines:

```text
1 → Hello World
2 → C Programming
3 → Simple Line Editor
```

Then display:

```text
1. Hello World
2. C Programming
3. Simple Line Editor
```

Search:

```text
Search: C
```

Result:

```text
Found at line 2: C Programming
```

Check statistics:

```text
Lines      : 3
Words      : 6
Characters : ...
```

Save:

```text
notes.txt
```

Delete line 2:

```text
1. Hello World
2. Simple Line Editor
```

Then:

```text
Undo
```

And the deleted line comes back.

---

# ⚠️ COMMON ERRORS

### Invalid line number

```text
Invalid line number.
```

Make sure the line number exists.

### Empty document

Some operations cannot be performed when there are no lines.

```text
Document is empty.
```

### File cannot be opened

```text
Could not open file.
```

Check that the filename is correct.

### Empty search

```text
Search text cannot be empty.
```

Enter a word or phrase to search.

---

# 🧠 HOW THE EDITOR STORES YOUR TEXT

The document is stored using a simple **2D character array**:

```text
lines

┌──────────────────────────┐
│ Hello World              │ ← Line 1
├──────────────────────────┤
│ C Programming            │ ← Line 2
├──────────────────────────┤
│ Simple Line Editor       │ ← Line 3
├──────────────────────────┤
│                          │
├──────────────────────────┤
│           ...            │
└──────────────────────────┘
```

Each row represents one line.

The editor currently supports:

```text
100 lines
199 characters per line
```

---

# ⚡ COMMAND CHEAT SHEET

| Option | Action         |
| -----: | -------------- |
|    `1` | Insert         |
|    `2` | Delete         |
|    `3` | Display        |
|    `4` | Save           |
|    `5` | Load           |
|    `6` | Search         |
|    `7` | Find & Replace |
|    `8` | Undo           |
|    `9` | Statistics     |
|   `10` | Help           |
|   `11` | Exit           |

---

# 🏁 THE IDEA

The goal was simple:

> **Make a useful text editor using only fundamental C programming concepts.**

The project demonstrates:

```text
Arrays
   ↓
Strings
   ↓
Functions
   ↓
File Handling
   ↓
Searching
   ↓
Text Manipulation
   ↓
Undo
```

**Simple code. Simple commands. One small editor.**
