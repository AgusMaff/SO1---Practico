//
// Created by agustin on 7/31/23.
//

#include "mycat.h"

int mycat(char* fileName){
    char cadena[CANT_MAX];
    ssize_t bytes;
    if(fileName == NULL){
        bytes = read(0, cadena, CANT_MAX);

        if(bytes == -1){
            fprintf(stderr,"Un error se produjo cuando se intento leer el archivo indicado. %d: %s", errno, strerror(errno));
            return -1;
        }
        while(bytes != 0){
            printf("El texto leido es:\n");
            fprintf(stdout,"%s", cadena);
            memset(cadena, 0, sizeof(cadena));
            printf("\n");
            bytes = read(0, cadena, CANT_MAX);
            if(bytes == -1){
                fprintf(stderr,"Un error se produjo cuando se intento leer el archivo indicado. %d: %s", errno, strerror(errno));
                return -1;
            }
        }
    }else{
        int file = open(fileName, O_RDONLY);

        if(file == -1){
            fprintf(stderr,"Un error se produjo cuando se intento abrir el archivo indicado. %d: %s", errno, strerror(errno));
            return -1;
        }

        bytes = read(file, cadena, CANT_MAX);
        if(bytes == -1){
            fprintf(stderr,"Un error se produjo cuando se intento leer el archivo indicado. %d: %s", errno, strerror(errno));
            return -1;
        }

        while(bytes != 0){
            write(1, cadena, CANT_MAX);
            memset(cadena, 0, sizeof(cadena));
            bytes = read(file, cadena, CANT_MAX);
            if(bytes == -1){
                fprintf(stderr,"Un error se produjo cuando se intento leer el archivo indicado. %d: %s", errno, strerror(errno));
                return -1;
            }
        }
        printf("\n");
        close(file);
        return 0;
        /*
        FILE* file;
        file = fopen(fileName, "r");

        if(file == NULL){
            fprintf(stderr,"Un error se produjo cuando se intento abrir el archivo indicado. %d: %s", errno, strerror(errno));
            return -1;
        }

        if (file == NULL) {
            perror("Error al abrir el archivo");
            return 1;
        }

        while (fgets(cadena, CANT_MAX, file) != NULL) {
            fputs(cadena, stdout);
        }
        */

        /*
        int c;
        while((c = fgetc(file)) != EOF){
            putc(c, stdout);
        }
        */

        /*
        if(fileName == NULL){
            fclose(file);
        }
        */
    }
}
