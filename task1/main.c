#include <stdio.h>
void wc(FILE *file);
void wcin(void);
int main(int argc, char *argv[]) {
    if (argc > 1){
    FILE *file = fopen(argv[1], "r");
    wc(file);
    }
    if (argc == 1){
    wcin();
    }
}

void wc(FILE *file){
unsigned int charcounter = 0, wordcounter = 0, strcounter = 0;
int buff;
while ((buff = fgetc(file)) != EOF){
    charcounter++;
    if ((char)buff == ' ' || (char)buff == '\t' || (char)buff == '\n' || (char)buff == '\r' || (char)buff == '\v') {
        wordcounter++;
    }
    if ((char)buff == '\n') {
        strcounter++;
    }
    }
printf("%d\n%d\n%d\n", strcounter, wordcounter, charcounter);
fclose(file);
}

void wcin(void){
unsigned int charcounter = 0, wordcounter = 0, strcounter = 0;
char c = 0;
while ((c = getchar()) != EOF) {
    charcounter++;
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v') {
        wordcounter++;
    }
    if (c == '\n'){
        strcounter++;
    }
}
printf("%d\n%d\n%d\n", strcounter, wordcounter, charcounter);
}
