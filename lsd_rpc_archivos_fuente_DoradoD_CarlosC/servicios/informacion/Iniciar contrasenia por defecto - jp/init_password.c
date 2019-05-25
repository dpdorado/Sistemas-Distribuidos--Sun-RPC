#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Datos{
	char user[10];
	char password[10];
}Datos;

int main(int argc, char *argv[]){
	Datos datos;
	FILE *file;	

	strcpy(datos.user,"dpdaniel");//nombre de usuario por defecto
	strcpy(datos.password,"123456");//contraseña por defecto
	


	file=fopen("./../admin.dat","ab");
	if (file==NULL){
		exit(EXIT_FAILURE);
	}

	fwrite(&datos, sizeof(Datos), 1, file);
	fclose(file);
	exit(EXIT_SUCCESS);
	
}
