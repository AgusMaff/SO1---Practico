//
// Created by agustin on 7/18/23.
//

#include "main.h"


int main(){
    //printf("Estoy aca\n");
    printf("*Ingrese 1 para ejecutar la funcion 'mycat'\n*Ingrese 2 para ejecutar la funcion 'mycp'\n*Ingrese 3 para ejecutar la funcion 'mysystem'\n*Ingrese 0 para finalizar la ejecucion del programa\n\n");
    while(1){
        fgets(input, sizeof(input), stdin);
        func_num = atoi(input);
        //printf("%d\n", func_num);
    }

    return 0;
}
