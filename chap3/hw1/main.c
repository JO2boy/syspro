#include <stdio.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 100

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    char temp[MAX_LENGTH];

    for (int i = 0; i < MAX_STRINGS; i++) {
        fgets(strings[i], MAX_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }

    for (int i = 0; i < MAX_STRINGS - 1; i++) {
        for (int j = i + 1; j < MAX_STRINGS; j++) {
            if (strlen(strings[i]) < strlen(strings[j])) {
                copy(strings[i], temp);  
                copy(strings[j], strings[i]);
                copy(temp, strings[j]);    
            }
        }
    }

    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
