#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int line_count;
    int line_numbering = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        line_numbering = 1;
    }

    for (int i = line_numbering ? 2 : 1; i < argc; i++) {
        fp = fopen(argv[i], "r");

        line_count = 0;
        int line_started = 0;

        c = getc(fp);
        while (c != EOF) {
            if (c == '\n') {
                line_count++;
                putc(c, stdout);
                line_started = 0;
            } else {
                if (line_numbering && !line_started) {
                    printf("%d ", line_count + 1);
                    line_started = 1;
                }
                putc(c, stdout);
            }
            c = getc(fp);
        }

        fclose(fp);
    }

    return 0;
}

