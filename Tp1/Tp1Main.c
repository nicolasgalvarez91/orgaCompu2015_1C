/*
 * Tp1Main.c
 *
 *  Created on: 06/04/2015
 *      Author: nikko
 */

#include "Tp1.h"

int main(int argc, char* argv[]){
	int manejoParametros = 1;
	if (!checkArguments(argc,argv,&manejoParametros))
		return 0;
	return manejoArchivos(manejoParametros,argv);
}

