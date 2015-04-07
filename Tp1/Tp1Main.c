/*
 * Tp1Main.c
 *
 *  Created on: 06/04/2015
 *      Author: nikko
 */

#include "Tp1.h"

int main(int argc, char* argv[]){
	if (!checkArguments(argc,argv))
		return 0;
	return manejoArchivos(argc,argv);
}

