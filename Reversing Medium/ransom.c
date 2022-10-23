#include <stdio.h>
#include <string.h>

int encrypt(char* contents) {

    FILE* new_file;

    int LEN = strlen(contents);

    new_file = fopen("passwords_encrypted.txt", "w");

    if (new_file == NULL) {
        return 1;
    }

    unsigned char KEY[] = {0x52, 0x40, 0x4e, 0x24, 0x4f, 0x4d};
    int cnt = 6;

    for (int i = 0; i < LEN; i++) {
        if (cnt >= 5) {
            cnt = 0;
        } else {
            cnt += 1;
        }

        contents[i] = (char)((contents[i]) ^ KEY[cnt]);
        fputc(contents[i], new_file);

    }

    fclose(new_file);

    return 0;

}

int main() {

    FILE* file;
    char chr = {0};
    char contents[200] = {0};

    file = fopen("passwords.txt", "r");

    if (file == NULL) {
        return 1;
    }

    do {
        chr = fgetc(file);
        strncat(contents, &chr, 1);
    } while (chr != EOF);

    int success = encrypt(contents);

    return success;

}