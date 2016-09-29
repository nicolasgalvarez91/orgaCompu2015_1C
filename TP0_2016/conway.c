#include "OrgaTp0.h"

int main( int argc, char *argv[] )  {
    if ((argc == 2)
        && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))) {
        printf("%s", help);
    } else if ((argc == 2)
        && ((strcmp(argv[1], "-V") == 0)
            || (strcmp(argv[1], "--version") == 0))) {
                printf("%s", version);
    } else if (argc == 5) {
        int iteraciones = atoi(argv[1]);
        int filas = atoi(argv[2]);
        int columnas = atoi(argv[3]);
                   
        printf("Filas: %d\n", filas);
        printf("Columnas: %d\n", columnas);
                   
        unsigned char** celdas = inicializarCeldas(filas,columnas);
                   
        leerDesdeArchivo(celdas, argv[4]);
        
        for (int i = 0; i < iteraciones; i++) {
            
            //salidaPm(aux, argv[0], filas, columnas, celdas);
            
            printMatriz(i, filas, columnas, celdas);
            
            conwayStep(celdas, filas, columnas);
            
        }
        
        for (int i = 0; i < filas; i++) {
            free(celdas[i]);
        }
        free(celdas);
                   
    } else {
        fprintf(stderr, "Numero de argumentos invalido.\n");
    }
    return EXIT_SUCCESS;    
}
