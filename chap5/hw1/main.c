#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void Read(int fd, char savedText[MAX_LINES][MAX_LENGTH]) {
    char buf;
    int line = 0, col = 0;

    while (line < MAX_LINES && read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            savedText[line][col] = '\0';
            line++;
            col = 0;
        } else {
            if (col < MAX_LENGTH - 1) {
                savedText[line][col++] = buf;
            }
        }
    }
}

void PrintLines(char savedText[MAX_LINES][MAX_LENGTH], char* input) {
    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < MAX_LINES; i++) {
            if (strlen(savedText[i]) > 0) {
                printf("%s\n", savedText[i]);
            }
        }
    } else {
        char* token = strtok(input, ",");
        while (token != NULL) {
            int start, end;
            if (sscanf(token, "%d-%d", &start, &end) == 2) {
                for (int i = start - 1; i <= end - 1 && i < MAX_LINES; i++) {
                    if (strlen(savedText[i]) > 0) {
                        printf("%s\n", savedText[i]);
                    }
                }
            } else if (sscanf(token, "%d", &start) == 1) {
                if (start >= 1 && start <= MAX_LINES) {
                    printf("%s\n", savedText[start - 1]);
                }
            }
            token = strtok(NULL, ",");
        }
    }
}

int main() {
    char savedText[MAX_LINES][MAX_LENGTH] = {{0}}; 
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    Read(fd, savedText);
    close(fd);


    int totalLines = 0;
    for (int i = 0; i < MAX_LINES; i++) {
        if (strlen(savedText[i]) > 0) {
            totalLines++;
        }
    }


    printf("Total Lines: %d\n", totalLines);
    printf("You can choose 1 ~ %d\n", totalLines);
    printf("Please enter the line to select: ");

    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    PrintLines(savedText, input);

    return 0;
}

