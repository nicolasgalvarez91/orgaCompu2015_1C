#include "Tp1.h"

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
int checkArguments(int cantidadArgumentos, char* argumentos[],int* cantidad){
	int retorno=1;
	if ((cantidadArgumentos == 2) && ((strcmp(argumentos[1], "-h") == 0) || (strcmp(argumentos[1], "--help") == 0))) {
		printHelp();
		retorno=0;
	} else if ((cantidadArgumentos == 2) && ((strcmp(argumentos[1], "-V") == 0) || (strcmp(argumentos[1], "--version") == 0))) {
		printf("Version 1.0\n");
		retorno=0;
	}

	*cantidad=cantidadArgumentos;
	if (*cantidad >= 2)
		*cantidad-=1;

	return retorno;
}

int procesarArchivo(FILE* fd,char* argumentos[],int numeroArchivo){

	int j,estado=0;
	char letra;
	long int bufTam = BUF_TAM;

	if (fd == NULL) {
		fprintf(stderr, "Imposible abrir %s\n", argumentos[numeroArchivo + 1]);
		return 1;
	}
	char** lines;
	int k = 0;
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
	procesarSalidaArchivo(lines,k);
	return 0;
}

void procesarSalidaArchivo(char** lines, int k){
	int a;
	for( a = k-1; a >= 0 ; a--){
		printf("%s \n", lines[a]);
		free(lines[a]);
	}
	if (k!=0)
		free(lines);

}

int manejoArchivos(int cantidadParametros,char* argumentos[]){
	FILE* fd;
	int i;
	// Si no hay argumentos considero stdin como el único archivo
	if (cantidadParametros == 1)
		fd = stdin;

	// Recorro los archivos para abrir y procesarlos
	for (i = 0; i < cantidadParametros; i++) {
		if (cantidadParametros !=1)
			fd = fopen(argumentos[i + 1], "r");

		int resultadoProcesamiento=procesarArchivo(fd,argumentos,i);

		if (resultadoProcesamiento!=0)
			return resultadoProcesamiento;
	}
	return 0;
}



