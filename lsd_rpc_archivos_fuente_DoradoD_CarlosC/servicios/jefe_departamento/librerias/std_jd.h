#include "./../servicios_jd.h"

#ifndef STDSERV_H
#define STDSERV_H

#ifdef __cplusplus
extern "C"{
#endif 

//Registra un usuario.
char* register_user(usuario_jd *user, char* path);

//Verifica si existe un usuario
int registered_user(char* id,char* n_user,char *path);

//Registra un anteproyecto.
char* register_draft(anteproyecto_jd *draft, char* path);

//Verifica si existe un anteproyecto
int registered_draft(char* code,char *path);

//Registra los evaluadores de un anteproyectos
char* register_evaluators(evaluadores_jd *eval, char* path);

//Verifica si existe un anteproyecto
int registered_draft_eval(char* code,char *path);

//Buscar un anteproyecto
anteproyecto_completo_jd * search_draft(char* code, char* path_draft,char* path_eval);

//Bucar anteproyecto en anteproyectos
anteproyecto_jd * search_draft_dr(char* code, char* path_draft);

//Declara un anteproyectos sin información
anteproyecto_jd * draft_null();

//Buscar anteproyecto en evaluadores
evaluadores_jd * search_draft_ev(char* code, char* path_eval);

//Define evaluadores sin información
evaluadores_jd * eval_null();

//Modifica el concepto de un anteproyecto
char * modify_concept_draft(char* code, int concept, char* path_draft);


#ifdef __cplusplus
}
#endif

#endif
