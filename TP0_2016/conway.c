#include "OrgaTp0.h"

int nroValido(char* str) {
    int nro = atoi(str);
    if (nro > 0 && nro < 30) {
        return 1;
    }
    return 0;
}

int argumentosValidosSinOutput(int nroArgumentos, char** argumentos) {
    if (nroArgumentos == 5 && nroValido(argumentos[1]) && nroValido(argumentos[2]) && nroValido(argumentos[3])) {
        return 1;
    }
    return 0;
}

int argumentosValidosConOutput(int nroArgumentos, char** argumentos) {
    if (nroArgumentos == 7 && nroValido(argumentos[1]) && nroValido(argumentos[2]) && nroValido(argumentos[3]) && (strcmp(argumentos[5], "-o") == 0)) {
        return 1;
    }
    return 0;
}

int main( int argc, char *argv[] )  {
    if ((argc == 2)
        && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))) {
        printf("%s", help);
    } else if ((argc == 2)
        && ((strcmp(argv[1], "-V") == 0)
            || (strcmp(argv[1], "--version") == 0))) {
                printf("%s", version);
    } else if (argumentosValidosSinOutput(argc, argv) || argumentosValidosConOutput(argc, argv)) {
        
        char* filename = argv[4];
        char* outputPrefix;
        
        if (argumentosValidosSinOutput(argc, argv)) {
            outputPrefix = filename;
        } else {
            outputPrefix = argv[6];
        }
        
        int iteraciones = atoi(argv[1]);
        int filas = atoi(argv[2]);
        int columnas = atoi(argv[3]);
                   
        printf("Filas: %d\n", filas);
        printf("Columnas: %d\n", columnas);
                   
        unsigned char* celdas = inicializarCeldas(filas,columnas);
        
        leerDesdeArchivo(celdas, filename, columnas);
        
        for (int i = 0; i < iteraciones; i++) {
            
            char* aux = malloc(sizeof(char));
            *aux = i+'0';
            
            salidaPm(aux, argv[0], filas, columnas, celdas, outputPrefix);
            
            printMatriz(i, filas, columnas, celdas);
            
            conwayStep(celdas, filas, columnas);
            
            free(aux);
        }
        
        free(celdas);
                   
    } else {
        fprintf(stderr, "Argumentos invalidos.\n");
    }
    return EXIT_SUCCESS;    
}
