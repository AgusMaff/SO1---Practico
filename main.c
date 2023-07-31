//
// Created by agustin on 7/18/23.
//
#include "mycat.h"

int main(int argc, char* argv[]) {
    int status;

    if(argc == 1){
        mycat(NULL);
    }else{
        status = mycat(argv[1]);
    }

    if(status == -1){
        printf("Hubo un problema durante la ejecucion del programa\n");
        return -1;
    }

    return 0;
}

