#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_e.h"
#include "./../servicios_e.h"
 

//Modifica el concepto de un anteproyecto
char * modify_concept_eval(datos_concepto_e *datas,char* path_eval){
	static char* messaje;
	evaluadores_e *eval;
	FILE *file;

	messaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"Concepto no modificado.");
	
	file=fopen(path_eval,"r+b");
	if (file==NULL){
		return messaje;
	}

	eval=(evaluadores_e*)malloc(sizeof(evaluadores_e));

	fread(eval, sizeof(evaluadores_e), 1, file);

	while(!feof(file)){
		if (strncmp(datas->codigo_proyecto,eval->codigo_anteproyecto,3)==0){
			int pos = ftell(file)-sizeof(evaluadores_e);
			fseek(file,pos,SEEK_SET);
			if (datas->eval_numero==1){
				strcpy(eval->concepto_evaluador1,datas->concepto);
				strcpy(eval->fecha_revision1,datas->fecha);
			}else {
				strcpy(eval->concepto_evaluador2,datas->concepto);
				strcpy(eval->fecha_revision2,datas->fecha);
			}
			
			fwrite(eval, sizeof(evaluadores_e), 1, file);
			strcpy(messaje,"Se modifico elconcepto.");
			fclose(file);
			free(eval);
			return messaje;
		}
		fread(eval, sizeof(evaluadores_e), 1, file);
	}
	fclose(file);
	free(eval);
	return messaje;
	
}




