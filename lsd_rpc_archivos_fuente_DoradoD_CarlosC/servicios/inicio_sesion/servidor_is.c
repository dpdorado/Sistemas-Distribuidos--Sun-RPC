/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "servicio_inicio_sesion.h"
#include "./librerias/std_is.h"
#include <stdio.h>
#include <stdlib.h>

int *
iniciar_sesion_is_1_svc(datos_login_is *argp, struct svc_req *rqstp)
{
	static int  result;	
	retorno_is *ret;

	ret=(retorno_is*)malloc(sizeof(retorno_is));

	ret=logeo(argp, "./informacion/usuarios.dat", "./informacion/admin.dat");
	
	result=ret->tipo_user;
		
	free(ret);
	return &result;
}

char **
cabiar_contrasenia_is_1_svc(datos_cambio_contrsenia_is *argp, struct svc_req *rqstp)
{
	static char * result;
	
	result=(char*)malloc(sizeof(char)*50);
	strcpy(result,modify_password_admin(argp, "./informacion/admin.dat"));

	return &result;
}
