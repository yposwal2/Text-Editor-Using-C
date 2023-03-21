#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 10000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    char c;
    int option;

    printf("Welcome to Text Editor\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Save file\n");
        printf("4. Exit\nHey User! Enter your response below\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter file content (press Ctrl+D to save): \n");
                fflush(stdin);
                fgets(content, MAX_FILE_CONTENT_LENGTH, stdin);

                FILE *fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Failed to create file.\n");
                    exit(1);
                }

                fprintf(fp, "%s", content);
                fclose(fp);
                printf("File created successfully.\n");
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("File not found.\n");
                    exit(1);
                }

                printf("File content:\n");
                while ((c = getc(fp)) != EOF) {
                    putchar(c);
                }
                fclose(fp);
                break;
            case 3:
                printf("Enter filename: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Failed to save file.\n");
                    exit(1);
                }

                printf("Enter file content (press Ctrl+D to save): \n");
                fflush(stdin);
                fgets(content, MAX_FILE_CONTENT_LENGTH, stdin);
                fprintf(fp, "%s", content);
                fclose(fp);
                printf("File saved successfully.\n");
                break;
            case 4:
                printf("Exiting Text Editor...\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}
