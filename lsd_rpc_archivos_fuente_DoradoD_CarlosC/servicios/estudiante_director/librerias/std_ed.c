#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_ed.h"
#include "./../servicios_ed.h"


//Bucar anteproyecto en anteproyectos
anteproyecto_ed * search_draft(char* code, char* path_draft){
	anteproyecto_ed *draft; 	
	FILE *file;

	printf("buscando codigo\n");
	
	file=fopen(path_draft,"rb");
	if (file==NULL){
		return draft_null();
	}
	
	draft=(anteproyecto_ed*)malloc(sizeof(anteproyecto_ed));
	
	fread(draft, sizeof(anteproyecto_ed), 1, file);
	

	while(!feof(file)){
		printf("Codigo: %s\n",draft->codigo);
		if (strcmp(code,draft->codigo)==0){
			fclose(file);
			return draft;
		}
		fread(draft, sizeof(anteproyecto_ed), 1, file);
	}
	
	fclose(file);
	return draft_null();
}
//Declara un anteproyectos sin información
anteproyecto_ed * draft_null(){
	anteproyecto_ed * draft;
	
	draft=(anteproyecto_ed*)malloc(sizeof(anteproyecto_ed));

	strcpy(draft->modalidad,"");
	strcpy(draft->titulo,"");
	strcpy(draft->codigo,"-1");
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

//Listar anteproyectos
prox_nodo_anteproyecto_ed * list_draft(char* path_draft){
	anteproyecto_ed *draft; 	
	FILE *file;
	static prox_nodo_anteproyecto_ed retorno=NULL;	
	prox_nodo_anteproyecto_ed cabeza = NULL,sig_anteproyecto;
	prox_nodo_anteproyecto_ed nuevo_anteproyecto;
	
	file=fopen(path_draft,"rb");
	if (file==NULL){
		return NULL;
	}
	
	draft=(anteproyecto_ed*)malloc(sizeof(anteproyecto_ed));
	
	fread(draft, sizeof(anteproyecto_ed), 1, file);

	while(!feof(file)){
		nuevo_anteproyecto=(prox_nodo_anteproyecto_ed)malloc(sizeof(nodo_anteproyecto_ed));
		strcpy(nuevo_anteproyecto->titulo,draft->titulo);
		strcpy(nuevo_anteproyecto->codigo,draft->codigo);
		if (cabeza==NULL)
		{
			cabeza = nuevo_anteproyecto;
			sig_anteproyecto = cabeza;
		}
		else
		{
			sig_anteproyecto->nodo_siguiente = nuevo_anteproyecto;
			sig_anteproyecto=nuevo_anteproyecto;
		}
		sig_anteproyecto->nodo_siguiente=NULL;
		fread(draft, sizeof(anteproyecto_ed), 1, file);
	}
	
	fclose(file);
	retorno=cabeza;
	return &retorno;
}
//Cabeza de la lista sin infoemación
nodo_anteproyecto_ed * node_draft_null(){
	nodo_anteproyecto_ed * draft;
	
	draft=(prox_nodo_anteproyecto_ed)malloc(sizeof(nodo_anteproyecto_ed));

	strcpy(draft->titulo,"");
	strcpy(draft->codigo,"-1");
	draft->nodo_siguiente=NULL;

	return draft;

} 
