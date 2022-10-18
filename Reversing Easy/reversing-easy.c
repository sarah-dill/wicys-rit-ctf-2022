#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Incorrect number of arguments: should be 2\n");
        printf("Goodbye");
        return 1;
    } 

    int LENGTH = strlen(argv[1]);

    if (LENGTH != 4) {
        printf("Incorrect number of characters in second argument: should be 4\n");
        printf("Goodbye");
        return 2;
    }

    char flag[4];

    strcpy(flag, argv[1]);

    if (flag[0] != 'f') {
        printf("Incorrect first character: should be f\n");
        printf("Goodbye");
        return 3;
    } else if (flag[1] != 'l') {
        printf("Incorrect second character: should be l\n");
        printf("Goodbye");
        return 4;
    } else if (flag[2] != 'a') {
        printf("Incorrect third character: should be a\n");
        printf("Goodbye");
        return 5;
    } else if (flag[3] != 'g') {
        printf("Incorrect last character: should be g\n");
        printf("Goodbye");
        return 6;
    } else {
        unsigned char string[] = {0x6f, 0x65, 0x68, 0x6e, 0x13, 0x09, 0x7b, 0x7a, 0x52, 0x6c, 0x71, 0x79, 0x65, 0x66, 0x60, 0x7d, 0x76, 0x7f, 0x6c, 0x7b, 0x6b, 0x66, 0x7a, 0x6c, 0x76, 0x6c, 0x7b, 0x7b, 0x66, 0x7b, 0x76, 0x64, 0x6c, 0x7a, 0x7a, 0x68, 0x6e, 0x6c, 0x7a, 0x54};
        char answer[80];
        char actual_answer[80];
        int KEY = 0x129;

        int SIZE = strlen(string);
        
        for (int i = 0; i < SIZE-1; i++) {
            answer[i] = string[i] ^ KEY;
            printf("%c", answer[i]);
        }

    }

    return 0;
}