/*Interfaz para los servicios de los evaluadores*/

/*Definición de constantes.*/
const MAXCODA_e = 3;
const MAXCONC_e = 20;
const MAXFEC_e=10;

/*Datos necesarios para ingresar y editar concepto de un proyecto */
struct datos_concepto_e
{
	char codigo_proyecto[MAXCODA_e];
	char concepto[MAXCONC_e];
	char fecha[MAXFEC_e];
	int eval_numero;
};

program evaluador{
	version evaluador_version{
		string ingresar_concepto_anteproyecto_e(datos_concepto_e objDatosConcepto)=3;
	}=1;
}=0x20000004;
