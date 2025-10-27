#include <stdio.h>

void wc(FILE *file) {
    unsigned int charcounter = 0, wordcounter = 0, strcounter = 0;
    char buff;
    while ((buff = fgetc(file)) != EOF) {
        charcounter++;
        if (buff == ' ' || buff == '\t' || buff == '\n' || buff == '\r' ||
            buff == '\v') {
            wordcounter++;
        }
        if (buff == '\n') {
            strcounter++;
        }
    }
    printf("%d\n%d\n%d\n", strcounter, wordcounter, charcounter);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Invalid file name\n");
            return 1;
        }
        wc(file);
        fclose(file);
    }
    if (argc == 1) {
        wc(stdin);
    }
}
