#include <stdio.h>
#include <stdlib.h>

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // Create or overwrite
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "This is the initial content.\n");
    printf("Data written to %s successfully.\n", filename);
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r"); // Read mode
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    printf("Contents of %s:\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}
void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); // Append mode
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "Appended line added.\n");
    printf("Data appended to %s successfully.\n", filename);
    fclose(fp);
}

int main() {
    const char *filename = "sample.txt";

    // Step 1: Write (create file and write)
    writeFile(filename);

    // Step 2: Read the file
    readFile(filename);

    // Step 3: Append data
    appendFile(filename);

    // Step 4: Read again
    readFile(filename);
    return 0;
}
