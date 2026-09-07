#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Used for undo */
char oldLines[MAX_LINES][MAX_LENGTH];
int oldLineCount = 0;
int canUndo = 0;

/* Save current document before changing it */
void saveForUndo()
{
    int i;

    oldLineCount = lineCount;

    for (i = 0; i < lineCount; i++)
    {
        strcpy(oldLines[i], lines[i]);
    }

    canUndo = 1;
}


/* Display all lines */
void displayLines()
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n--- DOCUMENT ---\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("----------------\n");
}


/* Insert a line */
void insertLine()
{
    int position;
    int i;
    char text[MAX_LENGTH];

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    saveForUndo();

    /* Shift lines to the right */
    for (i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}


/* Delete a line */
void deleteLine()
{
    int position;
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    saveForUndo();

    /* Shift lines to the left */
    for (i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}


/* Save document to a file */
void saveFile()
{
    char filename[100];
    FILE *file;
    int i;

    printf("Enter file name: ");
    scanf("%99s", filename);
    getchar();

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}


/* Load document from a file */
void loadFile()
{
    char filename[100];
    FILE *file;
    char text[MAX_LENGTH];

    printf("Enter file name: ");
    scanf("%99s", filename);
    getchar();

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    saveForUndo();

    lineCount = 0;

    while (fgets(text, MAX_LENGTH, file) != NULL)
    {
        if (lineCount >= MAX_LINES)
        {
            printf("Maximum line limit reached.\n");
            break;
        }

        text[strcspn(text, "\n")] = '\0';

        strcpy(lines[lineCount], text);

        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}


/* Search for a word or phrase */
void searchText()
{
    char search[MAX_LENGTH];
    int i;
    int found = 0;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter word or phrase to search: ");
    fgets(search, MAX_LENGTH, stdin);

    search[strcspn(search, "\n")] = '\0';

    if (strlen(search) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found at line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}

/* Find and replace text */
void findReplace()
{
    char find[MAX_LENGTH];
    char replace[MAX_LENGTH];
    char newLine[MAX_LENGTH];

    int i;
    int changed = 0;

    printf("Enter text to find: ");
    fgets(find, MAX_LENGTH, stdin);
    find[strcspn(find, "\n")] = '\0';

    if (strlen(find) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    printf("Enter replacement text: ");
    fgets(replace, MAX_LENGTH, stdin);
    replace[strcspn(replace, "\n")] = '\0';

    for (i = 0; i < lineCount; i++)
    {
        char *location;

        location = strstr(lines[i], find);

        if (location != NULL)
        {
            int before;
            int after;

            before = location - lines[i];
            after = strlen(location + strlen(find));

            if (before + strlen(replace) + after >= MAX_LENGTH)
            {
                printf("Replacement is too long for line %d.\n", i + 1);
                continue;
            }

            if (changed == 0)
            {
                saveForUndo();
                changed = 1;
            }

            strncpy(newLine, lines[i], before);
            newLine[before] = '\0';

            strcat(newLine, replace);
            strcat(newLine, location + strlen(find));

            strcpy(lines[i], newLine);
        }
    }

    if (changed)
    {
        printf("Find and replace completed.\n");
    }
    else
    {
        printf("Text not found.\n");
    }
}

/* Count lines, words and characters */
void countStatistics()
{
    int i;
    int j;

    int words = 0;
    int characters = 0;

    for (i = 0; i < lineCount; i++)
    {
        int insideWord = 0;

        characters += strlen(lines[i]);

        for (j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] != ' ' &&
                lines[i][j] != '\t')
            {
                if (insideWord == 0)
                {
                    words++;
                    insideWord = 1;
                }
            }
            else
            {
                insideWord = 0;
            }
        }
    }

    printf("\n--- DOCUMENT STATISTICS ---\n");
    printf("Lines      : %d\n", lineCount);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", characters);
    printf("---------------------------\n");
}


/* Undo the last modification */
void undo()
{
    int i;

    if (canUndo == 0)
    {
        printf("Nothing to undo.\n");
        return;
    }

    for (i = 0; i < oldLineCount; i++)
    {
        strcpy(lines[i], oldLines[i]);
    }

    lineCount = oldLineCount;

    canUndo = 0;

    printf("Last action undone.\n");
}


/* Display help */
void help()
{
    printf("\n========== HELP ==========\n");

    printf("1. Insert Line\n");
    printf("   Add a new line at a given position.\n");

    printf("2. Delete Line\n");
    printf("   Remove a line from the document.\n");

    printf("3. Display Document\n");
    printf("   Show all lines with line numbers.\n");

    printf("4. Save File\n");
    printf("   Save the document to a text file.\n");

    printf("5. Load File\n");
    printf("   Load a text file into the editor.\n");

    printf("6. Search\n");
    printf("   Find a word or phrase in the document.\n");

    printf("7. Find and Replace\n");
    printf("   Replace a word or phrase in selected lines.\n");

    printf("8. Undo\n");
    printf("   Undo the most recent modification.\n");

    printf("9. Line/Word Count\n");
    printf("   Show document statistics.\n");

    printf("10. Help\n");
    printf("    Show this help menu.\n");

    printf("11. Exit\n");
    printf("    Close the editor.\n");

    printf("==========================\n");
}


/* Main program */
int main()
{
    int choice;

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");

    while (1)
    {
        printf("\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Save File\n");
        printf("5. Load File\n");
        printf("6. Search\n");
        printf("7. Find and Replace\n");
        printf("8. Undo\n");
        printf("9. Line/Word Count\n");
        printf("10. Help\n");
        printf("11. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayLines();
                break;

            case 4:
                saveFile();
                break;

            case 5:
                loadFile();
                break;

            case 6:
                searchText();
                break;

            case 7:
                findReplace();
                break;

            case 8:
                undo();
                break;

            case 9:
                countStatistics();
                break;

            case 10:
                help();
                break;

            case 11:
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}