#include "Tp0.h"

int main(int argc, char* argv[]){
	if (!checkArguments(argc,argv))
		return 0;
	return manejoArchivos(argc,argv);
}

