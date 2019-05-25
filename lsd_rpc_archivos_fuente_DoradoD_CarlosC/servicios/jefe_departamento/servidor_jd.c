/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "servicios_jd.h"
#include "./librerias/std_jd.h"

char **
registrar_usuario_jd_1_svc(usuario_jd *argp, struct svc_req *rqstp)
{
	static char * result;
	
	result=(char*)malloc(sizeof(char)*50);
	
	strcpy(result,register_user(argp, "./../informacion/usuarios.dat"));

	return &result;
}

char **
registrar_anteproyecto_jd_1_svc(anteproyecto_jd *argp, struct svc_req *rqstp)
{
	static char * result;

	result=(char*)malloc(sizeof(char)*50);
	
	strcpy(result,register_draft(argp, "./../informacion/anteproyectos.dat"));

	return &result;
}

char **
asignar_evaluadores_jd_1_svc(evaluadores_jd *argp, struct svc_req *rqstp)
{
	static char * result;

	result=(char*)malloc(sizeof(char)*50);
	
	strcpy(result,register_evaluators(argp, "./../informacion/anteproyectos.dat", "./../informacion/evaluadores.dat"));

	return &result;
}

anteproyecto_completo_jd *
buscar_anteproyecto_jd_1_svc(char **argp, struct svc_req *rqstp)
{
	static anteproyecto_completo_jd  *result;

	result=(anteproyecto_completo_jd*)malloc(sizeof(anteproyecto_completo_jd));
	
	result = search_draft(*argp, "./../informacion/anteproyectos.dat","./../informacion/evaluadores.dat");

	return result;
}

char **
modificar_concepto_anteproyecto_jd_1_svc(datos_concepto_jd *argp, struct svc_req *rqstp)
{
	static char * result;
	int concept=0;
	
	if (strcmp("APROBADO", argp->concepto)==0){
		concept=1;
	}else if(strcmp("NO_APROBADO", argp->concepto)==0){
		concept=2;
	}	
	
	result=(char*)malloc(sizeof(char)*50);
	
	strcpy(result,modify_concept_draft(argp->codigo_proyecto,concept, "./../informacion/anteproyectos.dat"));

	return &result;
}
