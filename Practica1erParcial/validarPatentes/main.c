#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void convertir( char cad[] );

void convertir( char cad[] )
	{
	int i;
	char cad2[20];

	for( i=0; i<strlen(cad); i++ ){
        cad[i] = toupper( cad[i] );
	}



	printf( "\n\nHola %s", cad );
	}

int main()
	{
	char cad[40];

	system( "cls" );
	printf( "\nEscribe tu Nombre (de preferencia en minusculas): " );
	gets( cad );
	fflush( stdout );

	convertir( cad );
	//printf( "\n\nHola %s", cad );
	//getchar();
	return 0;
	}


