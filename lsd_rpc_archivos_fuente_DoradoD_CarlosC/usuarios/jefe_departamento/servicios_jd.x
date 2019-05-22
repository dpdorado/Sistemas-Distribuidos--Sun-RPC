/*Interfaz para los sevicios del jefe de departamento.*/

/*Definición de constantes.*/
const MAXCODA_jd= 3;
const MAXDAG_jd = 10;
const MAXMOD_jd = 12;
const MAXCONC_jd = 20;
const MAXNOM_jd = 30;
const MAXCON_jd = 30;
const MAXTIT_jd = 40;

/*Datos de un usuario.*/
struct usuario_jd{
	char identificacion[MAXDAG_jd];
	char nombre_apellido[MAXNOM_jd];
	char nom_user[MAXDAG_jd];
	char contrasenia[MAXDAG_jd];
	int tipo_user;
};
/*Datos de un anteproyecto*/
struct anteproyecto_jd{
	char modalidad[MAXMOD_jd];
	char titulo[MAXTIT_jd];
	char codigo[MAXCODA_jd];
	char nombre_estud1[MAXNOM_jd];
	char nombre_estud2[MAXNOM_jd];
	char director[MAXNOM_jd];
	char co_director[MAXNOM_jd];
	char fecha_registro[MAXDAG_jd];
	char fecha_aprobacion[MAXDAG_jd];
	int concepto;
	int estado;
	int numero_revision;
};
/*Datos de evaludaores de un proyecto*/
struct evaluadores_jd{
	char codigo_anteproyecto[MAXMOD_jd];
	char nombre_evaluador1[MAXNOM_jd];
	char concepto_evaluador1[MAXCONC_jd];
	char fecha_revision1[MAXDAG_jd];
	char nombre_evaluador2[MAXNOM_jd];
	char concepto_evaluador2[MAXCON_jd];
	char fecha_revision2[MAXDAG_jd];
};

/*Datos necesarios para buscar un anteproyectos*/
struct anteproyecto_completo_jd{
	char modalidad[MAXMOD_jd];
	char titulo[MAXTIT_jd];
	char codigo[MAXCODA_jd];
	char nombre_estud1[MAXNOM_jd];
	char nombre_estud2[MAXNOM_jd];
	char director[MAXNOM_jd];
	char co_director[MAXNOM_jd];
	char fecha_registro[MAXDAG_jd];
	char fecha_aprobacion[MAXDAG_jd];
	int concepto;
	int estado;
	int numero_revision;
	char codigo_anteproyecto[MAXMOD_jd];
	char nombre_evaluador1[MAXNOM_jd];
	char concepto_evaluador1[MAXCONC_jd];
	char fecha_revision1[MAXDAG_jd];
	char nombre_evaluador2[MAXNOM_jd];
	char concepto_evaluador2[MAXCON_jd];
	char fecha_revision2[MAXDAG_jd];
};

/*Datos necesarios para ingresar y editar concepto de un proyecto */
struct datos_concepto_jd{
	char codigo_proyecto[MAXCODA_jd];
	char concepto[MAXCONC_jd];
};

/*Definición de las operaciones necesarias.*/
program jefe_departamento{
	version jefe_departamento_version{
		string registrar_usuario_jd(usuario_jd objUsuario)=1;
		string registrar_anteproyecto_jd(anteproyecto_jd objAnteproyecto)=2;
		string asignar_evaluadores_jd(evaluadores_jd objEvaluadores)=3;
		anteproyecto_completo_jd buscar_anteproyecto_jd(string codigo)=4;
		string modificar_concepto_anteproyecto_jd(datos_concepto_jd objDatosConcepto)=5;
	}=1;
}=0x20000002;
