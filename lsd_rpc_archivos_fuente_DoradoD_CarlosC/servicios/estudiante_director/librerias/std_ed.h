#include "./../servicios_ed.h"

#ifndef STDSERV_H
#define STDSERV_H

#ifdef __cplusplus
extern "C"{
#endif 

//Bucar anteproyecto en anteproyectos
anteproyecto_ed * search_draft(char* code, char* path_draft);

//Declara un anteproyectos sin información
anteproyecto_ed * draft_null();

//Listar anteproyectos
prox_nodo_anteproyecto_ed * list_draft(char* path_draft);

//Cabeza de la lista sin infoemación
nodo_anteproyecto_ed * node_draft_null();

#ifdef __cplusplus
}
#endif

#endif
