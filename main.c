//
// Created by agustin on 7/18/23.
//
#include "main.h"

int main(int argc, char* argv[]) {

    if(argc == 1){
        mycat(NULL);
    }else{
        status =mycat(argv[1]);
    }

    if(status == -1){
        printf("Hubo un problema durante la ejecucion del programa\n");
        return -1;
    }

    return 0;
}

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

    if(fileName = NULL){
        fclose(file);
    }

    return 0;
}
