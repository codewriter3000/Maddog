#include <stdio.h>
#include <stdlib.h>
#include "include/tokenizer.h"

int main(int argc, char *argv[]) {
    if(argc == 2){
        FILE *fp;
        long fsize;
        char *buffer;
        if((fp = fopen(argv[1], "r")) == NULL){
            printf("You gave me a file that doesn't exist. I'm going back to sleep: %s", argv[1]);
            exit(1);
        } else {
            printf("File opening successful\n");
            fseek(fp, 0, SEEK_END);
            fsize = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            buffer = malloc(fsize + 1);
            fread(buffer, fsize, 1, fp);
            buffer[fsize] = 0;
            fclose(fp);
            tokenize(buffer);
            printf("jimmy buffer: %s\n", buffer);
        }
    } else {
        printf("Expected 2 arguments, received %d", argc);
        exit(1);
    }
    return 0;
}