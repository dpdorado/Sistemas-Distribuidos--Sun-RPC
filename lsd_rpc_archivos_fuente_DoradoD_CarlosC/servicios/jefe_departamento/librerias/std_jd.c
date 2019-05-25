#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_jd.h"
#include "./../servicios_jd.h"

//Registra un usuario.
char* register_user(usuario_jd *user, char* path){
	static char *messaje;
	FILE *file;
	int aux=0;

	messaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"No se pudo registrar al usuario.");

	aux=registered_user(user->identificacion, user->nom_user,path);	
	if (aux==0){
		file=fopen(path,"ab");
		if (file==NULL){
			return messaje;
		}
		fwrite(user, sizeof(usuario_jd), 1, file);
		strcpy(messaje,"Usuario registrado.");
		fclose(file);
	}else if(aux==1){
		strcpy(messaje,"La identificacion del usuario ya esta registrada.");
	}else if(aux==2){
		strcpy(messaje,"El nombre de usuario ya esxiste.");
	}
	return messaje;
}

//Verifica si existe un usuario
int registered_user(char* id,char* n_user,char *path){
	FILE *file;
	usuario_jd *user;
	int result=3;

	file=fopen(path,"rb");
	if (file==NULL){
		return result;
	}
	
	user=(usuario_jd*)malloc(sizeof(usuario_jd));

	fread(user, sizeof(usuario_jd), 1, file);

	while(!feof(file)){
		if (strcmp(id,user->identificacion)==0){
			result=1;	   
			break;
		}else if (strcmp(n_user,user->nom_user)==0){
			result=2;	   
			break;
		}
		fread(user, sizeof(usuario_jd), 1, file);
	}

	if (result != 1 && result!=2){
		result=0;
	}

	fclose(file);
	return result;
}

//Registra un anteproyecto.
char* register_draft(anteproyecto_jd *draft, char* path){
	static char *messaje;
	FILE *file;
	int aux=0;

	messaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"No se pudo registrar el anteproyecto.");

	aux=registered_draft(draft->codigo,path);	
	if (aux==0){
		file=fopen(path,"ab");
		if (file==NULL){
			return messaje;
		}
		fwrite(draft, sizeof(anteproyecto_jd), 1, file);
		strcpy(messaje,"Anteproyecto registrado.");
		fclose(file);
	}else if(aux==1){
		strcpy(messaje,"El codigo del anteproyecto ya esta registrado.");
	}
	return messaje;
}

//Verifica si existe un anteproyecto
int registered_draft(char* code,char *path){
	FILE *file;
	anteproyecto_jd *draft;
	int result=2;

	file=fopen(path,"rb");
	if (file==NULL){
		return result;
	}

	draft=(anteproyecto_jd*)malloc(sizeof(anteproyecto_jd));

	fread(draft, sizeof(anteproyecto_jd), 1, file);

	while(!feof(file)){
		if (strcmp(code,draft->codigo)==0){
			result=1;	   
			break;
		}
		fread(draft, sizeof(usuario_jd), 1, file);
	}

	if (result != 1){
		result=0;
	}

	fclose(file);
	return result;
}

//Registra los evaluadores de un anteproyectos
char* register_evaluators(evaluadores_jd *eval, char* path_draft,char* path_eval){
	static char *messaje;
	FILE *file;
	int aux=0;

	messaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"No se registraron los evaluadores.");
	
	if(registered_draft(eval->codigo_anteproyecto,path_draft)==0){
		strcpy(messaje,"No existe el anteproyecto.");
		return messaje;
	} 

	aux=registered_draft_eval(eval->codigo_anteproyecto,path_eval);	
	if (aux==0){
		file=fopen(path_eval,"ab");
		if (file==NULL){
			return messaje;
		}
		fwrite(eval, sizeof(evaluadores_jd), 1, file);
		strcpy(messaje,"Evaluadores registrados.");
		fclose(file);
	}else if(aux==1){
		strcpy(messaje,"El anteproyecto ya tiene evaluadores.");
	}
	return messaje;
}

//Verifica si existe un anteproyecto
int registered_draft_eval(char* code,char *path){
	FILE *file;
	evaluadores_jd *eval;
	int result=2;

	file=fopen(path,"rb");
	if (file==NULL){
		return result;
	}
	
	eval=(evaluadores_jd*)malloc(sizeof(evaluadores_jd));

	fread(eval, sizeof(evaluadores_jd), 1, file);

	while(!feof(file)){
		if (strcmp(code,eval->codigo_anteproyecto)==0){
			result=1;	   
			break;
		}
		fread(eval, sizeof(evaluadores_jd), 1, file);
	}

	if (result != 1){
		result=0;
	}

	fclose(file);
	return result;
}

//Buscar un anteproyecto
anteproyecto_completo_jd * search_draft(char* code, char* path_draft,char* path_eval){
	static anteproyecto_completo_jd * draft_complete;
	static anteproyecto_jd * draft; 
	static evaluadores_jd * eval;	
	
	draft_complete=(anteproyecto_completo_jd*)malloc(sizeof(anteproyecto_completo_jd));
	
	draft=(anteproyecto_jd*)malloc(sizeof(anteproyecto_jd));
	draft=search_draft_dr(code,path_draft);
	
	eval=(evaluadores_jd*)malloc(sizeof(evaluadores_jd));
	eval=search_draft_ev(code,path_eval);
	
	strcpy(draft_complete->modalidad,draft->modalidad);
	strcpy(draft_complete->titulo,draft->titulo);
	strcpy(draft_complete->codigo,draft->codigo);
	strcpy(draft_complete->nombre_estud1,draft->nombre_estud1);
	strcpy(draft_complete->nombre_estud2,draft->nombre_estud2);
	strcpy(draft_complete->director,draft->director);
	strcpy(draft_complete->co_director,draft->co_director);
	strcpy(draft_complete->fecha_registro,draft->fecha_registro);
	strcpy(draft_complete->fecha_aprobacion,draft->fecha_aprobacion);
	draft_complete->concepto=draft->concepto;
	draft_complete->estado=draft->estado;
	draft_complete->numero_revision=draft->numero_revision;	
	strcpy(draft_complete->codigo_anteproyecto,eval->codigo_anteproyecto);//No es necesario
	strcpy(draft_complete->nombre_evaluador1,eval->nombre_evaluador1);
	strcpy(draft_complete->concepto_evaluador1,eval->concepto_evaluador1);
	strcpy(draft_complete->fecha_revision1,eval->fecha_revision1);
	strcpy(draft_complete->nombre_evaluador2,eval->nombre_evaluador2);
	strcpy(draft_complete->concepto_evaluador2,eval->concepto_evaluador2);
	strcpy(draft_complete->fecha_revision2,eval->fecha_revision2);

	return draft_complete;
}

//Bucar anteproyecto en anteproyectos
anteproyecto_jd * search_draft_dr(char* code, char* path_draft){
	static anteproyecto_jd *draft; 	
	FILE *file;
	
	file=fopen(path_draft,"rb");
	if (file==NULL){
		return draft_null();
	}
	
	draft=(anteproyecto_jd*)malloc(sizeof(anteproyecto_jd));
	
	fread(draft, sizeof(anteproyecto_jd), 1, file);

	while(!feof(file)){
		if (strcmp(code,draft->codigo)==0){
			fclose(file);
			return draft;
		}
		fread(draft, sizeof(anteproyecto_jd), 1, file);
	}
	
	fclose(file);
	return draft_null();
}
//Declara un anteproyectos sin información
anteproyecto_jd * draft_null(){
	static anteproyecto_jd * draft;
	
	draft=(anteproyecto_jd*)malloc(sizeof(anteproyecto_jd));

	strcpy(draft->modalidad,"");
	strcpy(draft->titulo,"");
	strcpy(draft->codigo,"");
	strcpy(draft->nombre_estud1,"");
	strcpy(draft->nombre_estud2,"");
	strcpy(draft->director,"");
	strcpy(draft->co_director,"");
	strcpy(draft->fecha_registro,"");
	strcpy(draft->fecha_aprobacion,"");
	draft->concepto=2;
	draft->estado=0;
	draft->numero_revision=1;

	return draft;

} 
//Buscar anteproyecto en evaluadores
evaluadores_jd * search_draft_ev(char* code, char* path_eval){
	static evaluadores_jd *eval; 	
	FILE *file;
	
	file=fopen(path_eval,"rb");
	if (file==NULL){
		return eval_null();
	}
	
	eval=(evaluadores_jd*)malloc(sizeof(evaluadores_jd));
	
	fread(eval, sizeof(evaluadores_jd), 1, file);

	while(!feof(file)){
		if (strcmp(code,eval->codigo_anteproyecto)==0){
			fclose(file);
			return eval;
		}
		fread(eval, sizeof(anteproyecto_jd), 1, file);
	}
	
	fclose(file);
	return eval_null();
}

//Define evaluadores sin información
evaluadores_jd * eval_null(){
	static evaluadores_jd * eval;
	
	eval=(evaluadores_jd*)malloc(sizeof(evaluadores_jd));

	strcpy(eval->codigo_anteproyecto,"");
	strcpy(eval->nombre_evaluador1,"");
	strcpy(eval->concepto_evaluador1,"");
	strcpy(eval->fecha_revision1,"");
	strcpy(eval->nombre_evaluador2,"");
	strcpy(eval->concepto_evaluador2,"");
	strcpy(eval->fecha_revision2,"");

	return eval;

} 

//Modifica el concepto de un anteproyecto
char * modify_concept_draft(char* code, int concept, char* path_draft){
	static char* messaje;
	anteproyecto_jd *draft;
	FILE *file;

	messaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"Concepto no modificado.");
	
	file=fopen(path_draft,"r+b");
	if (file==NULL){
		return messaje;
	}

	draft=(anteproyecto_jd*)malloc(sizeof(anteproyecto_jd));

	fread(draft, sizeof(anteproyecto_jd), 1, file);

	while(!feof(file)){
		if (strcmp(code,draft->codigo)==0){
			int pos = ftell(file)-sizeof(anteproyecto_jd);
			fseek(file,pos,SEEK_SET);
			draft->concepto=concept;
			fwrite(draft, sizeof(anteproyecto_jd), 1, file);
			strcpy(messaje,"Se modifico elconcepto.");
			fclose(file);
			return messaje;
		}
		fread(draft, sizeof(anteproyecto_jd), 1, file);
	}
	fclose(file);
	return messaje;
	
}




