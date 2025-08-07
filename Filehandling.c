#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char data[100];

    // 1. Create and Write to a file
    fp = fopen("myfile.txt", "w");
    if (fp == NULL) {
        printf("Error in creating file.\n");
        return 1;
    }
    printf("Enter data to write in the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written successfully.\n");

    // 2. Append data to the file
    fp = fopen("myfile.txt", "a");
    if (fp == NULL) {
        printf("Error in opening file for appending.\n");
        return 1;
    }
    printf("Enter data to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully.\n");

    // 3. Read and display file content
    fp = fopen("myfile.txt", "r");
    if (fp == NULL) {
        printf("Error in reading file.\n");
        return 1;
    }
    printf("\nContents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
