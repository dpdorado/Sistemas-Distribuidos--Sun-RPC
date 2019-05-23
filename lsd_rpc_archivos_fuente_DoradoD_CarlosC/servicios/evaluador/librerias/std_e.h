#include "./../servicios_e.h"

#ifndef STDSERV_H
#define STDSERV_H

#ifdef __cplusplus
extern "C"{
#endif 

#define MAXDAG_e 10
#define MAXMOD_e 12
#define MAXCONC_e 20
#define MAXNOM_e 30
#define MAXCON_e 30

struct evaluadores_e {
	char codigo_anteproyecto[MAXMOD_e];
	char nombre_evaluador1[MAXNOM_e];
	char concepto_evaluador1[MAXCONC_e];
	char fecha_revision1[MAXDAG_e];
	char nombre_evaluador2[MAXNOM_e];
	char concepto_evaluador2[MAXCON_e];
	char fecha_revision2[MAXDAG_e];
};
typedef struct evaluadores_e evaluadores_e;

//Modifica el concepto de un anteproyecto
char * modify_concept_eval(datos_concepto_e *datas,char* path_eval);

#ifdef __cplusplus
}
#endif

#endif
