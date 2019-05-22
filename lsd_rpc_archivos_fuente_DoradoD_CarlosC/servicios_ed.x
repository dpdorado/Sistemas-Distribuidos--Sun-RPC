/*Interfaz para los servicions de los estudiantes-directores*/

/*Definición de constantes.*/
const MAXCODA_ed = 3;
const MAXDAG_ed = 10;
const MAXMOD_ed = 12;
const MAXNOM_ed = 30;
const MAXTIT_ed = 40;


/*Apuntador necesario para listar anteproyectos*/
typedef struct nodo_anteproyecto_ed *prox_nodo_anteproyecto_ed;

/*Datos de un anteproyecto*/
struct anteproyecto_ed{
	char modalidad[MAXMOD_ed];
	char titulo[MAXTIT_ed];
	char codigo[MAXCODA_ed];
	char nombre_estud1[MAXNOM_ed];
	char nombre_estud2[MAXNOM_ed];
	char director[MAXNOM_ed];
	char co_director[MAXNOM_ed];
	char fecha_registro[MAXDAG_ed];
	char fecha_aprobacion[MAXDAG_ed];
	int concepto;
	int estado;
	int numero_revision;
};

/*Datos necesarios para listar anteproyectos*/
struct nodo_anteproyecto_ed{
	char titulo[MAXTIT_ed];
	char codigo[MAXCODA_ed];
	prox_nodo_anteproyecto_ed nodo_siguiente;
};

program estudiante_director{
	version estudiante_director_version{
		anteproyecto_ed buscar_anteproyecto_ed(string codigo)=1;
		nodo_anteproyecto_ed listar_anteproyectos_ed(void)=2;
	}=1;
}=0x20000003;
