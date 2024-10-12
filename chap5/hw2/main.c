#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LENGTH 256

int main() {
    FILE *file;
    char *lines[MAX_LINES];
    int count = 0;

    file = fopen("test.txt", "r");
    
    while (count < MAX_LINES && !feof(file)) {
        lines[count] = (char *)malloc(MAX_LENGTH);
        if (fgets(lines[count], MAX_LENGTH, file) != NULL) {
            count++;
        }
    }

    fclose(file);

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return EXIT_SUCCESS;
}

