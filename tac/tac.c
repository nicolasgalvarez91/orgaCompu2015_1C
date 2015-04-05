
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define BUF_TAM 100

void printHelp() {
	char *help =
			"Usage:"
			"\ttp0 -h \n"
			"\ttp0 -V \n"
			"\ttp0 [file...] \n"
			"Options: \n"
			" -V, --version \n\t Print version and quit. \n"
			" -h, --help \n\t Print this information and quit.\n"
			" Examples: \n"
			"  tp0 foo.txt bar.txt \n"
			"  tp0 gz.txt \n";

	printf("%s", help);
}

int main(int argc, char* argv[]){

	// Imprimo la ayuda o la versión
	if ((argc == 2) && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))) {
		printHelp();
		return 0;
	} else if ((argc == 2) && ((strcmp(argv[1], "-V") == 0) || (strcmp(argv[1], "--version") == 0))) {
		printf("Version 1.0\n");
		return 0;
	}

	int tam = 1;
	if (argc >= 2)
		tam = argc - 1;

	FILE* fd;
	// Si no hay argumentos considero stdin como el único archivo
	if (argc == 1){
		fd = stdin;
		tam = 1;
	}
	int i, j;

	int estado = 0;
	char letra;

	long int bufTam = BUF_TAM;

	// Recorro los archivos para abrir y procesarlos
	for (i = 0; i < tam; i++) {
		if (argc !=1)
			fd = fopen(argv[i + 1], "r");
		char** lines;
		int k = 0;
		if (fd == NULL) {
			fprintf(stderr, "Imposible abrir %s\n", argv[i + 1]);
			return 1;
		}
		estado = fread(&letra, 1, 1, fd); //Lee desde archivo 1 elemento de 1 byte y lo guarda en letra.
		while (estado > 0) {
			char* line;
			j = 0;
			line = (char*) malloc(bufTam);

			while ((estado > 0) && (letra != '\n')){	//mientras haya caracteres para leer y no haya llegado a fin de linea.

				if(j > bufTam) {						//realloc si es necesario
					bufTam += BUF_TAM;
					line = realloc(line, bufTam);
				}
				line[j] = letra;
				j++;
				estado = fread(&letra, 1, 1, fd);
			}
			if(letra == '\n'){
				if (k==0)
					lines = (char**) malloc(sizeof(char*));
				else
					lines = realloc (lines,sizeof(char*));
				line[j]='\0';
				lines[k] = line;
				k++;
			}
			estado = fread(&letra, 1, 1, fd);
		}
		fclose(fd);
		int a;
		for( a = k-1; a >= 0 ; a--){
			printf("%s \n", lines[a]);
			free(lines[a]);
		}
		if (k!=0)
			free(lines);

	}

	return 0;

}
