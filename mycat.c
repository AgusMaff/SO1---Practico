//
// Created by agustin on 7/31/23.
//

#include "mycat.h"

int mycat(char* fileName){
    FILE* file;
    int c;

    if(fileName == NULL){
        file = stdin;
    }else{
        file = fopen(fileName, "r");
        if(file == NULL){
            fprintf(stderr,"Un error se produjo cuando se intento abrir el archivo indicado. %d: %s", errno, strerror(errno));
            return -1;
        }
    }

    while((c = fgetc(file)) != EOF){
        putc(c, stdout);
    }

    if(fileName == NULL){
        fclose(file);
    }

    return 0;
}
