/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "./inicio_sesion/servicio_inicio_sesion.h"
#include "./jefe_departamento/servicios_jd.h"
#include "./estudiante_director/servicios_ed.h"
#include "./evaluador/servicios_e.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Colocar los clinetes de forma global??????*/
/*-------------------------------Variables globales------------------*/
char *host;

//----Inicio de Sesion.
CLIENT *clnt_is;
int *result1_is;
datos_login_is datos_usuario;

char **result2_is;
datos_cambio_contrsenia_is datos_cambio_contrasenia_is;
/*//utilizar para el cambio de contrasenia<----------------------se debe copiar de todos los demas clinetes tambien
result_2 = cabiar_contrasenia_is_1(&datos_cambio_contrasenia_is, clnt);
	if (result_2 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
}*/
//----Jefe de Departamento
CLIENT *clnt_jd;
char **result1_jd;
usuario_jd *datos_reg_user;
char **result2_jd;
anteproyecto_jd *registrar_anteproyecto_jd_1_arg;
char **result3_jd;
evaluadores_jd *asignar_evaluadores_jd_1_arg;
anteproyecto_completo_jd *result4_jd;
char *buscar_anteproyecto_jd_1_arg;
char **result5_jd;
datos_concepto_jd *modificar_concepto_anteproyecto_jd_1_arg;
//----Estudiante- Director
CLIENT *clnt_ed;
anteproyecto_ed *result1_ed;
char *buscar_anteproyecto_ed_1_arg;
nodo_anteproyecto_ed *result2_ed;
char *listar_anteproyectos_ed_1_arg;
//----Evaluadores
CLIENT *clnt_e;
char **result1_e;
datos_concepto_e ingresar_concepto_anteproyecto_e_1_arg;

//*Crear clientes*//
void crear_clientes()
{
	//Inicio de sesion
	clnt_is = clnt_create(host, inicio_sesion, inicio_sesion_version, "udp");
	if (clnt_is == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	//Jefe de Departameto
	clnt_jd = clnt_create(host, jefe_departamento, jefe_departamento_version, "udp");
	if (clnt_jd == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	//Estudiante-Director
	clnt_ed = clnt_create(host, estudiante_director, estudiante_director_version, "udp");
	if (clnt_ed == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	//Evaluadores
	clnt_e = clnt_create(host, evaluador, evaluador_version, "udp");
	if (clnt_e == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
}
void destruir_clientes()
{
	//Inicio de sesio
	clnt_destroy(clnt_is);
	//Jefe de  Departamento
	clnt_destroy(clnt_jd);
	//Estudiante Director
	clnt_destroy(clnt_ed);
	//Evaluador
	clnt_destroy(clnt_e);
}

/*--------------------------------Metodos genericos--------------------------------*/
/**
 * @brief Permite al usuario ingresar una opcion.
 * 
 * @return int valor de la opcion ingresada
 */
int ingresar_opcion()
{
	//validar que no sea una cadena--
	int opcion = 0;
	printf("ingrese la opcion:  ");
	scanf("%d", &opcion);
	return opcion;
}
/**
 * @brief limpia la consola.
 * 
 */
void limpiar()
{
	system("clear");
}
/**
 * @brief Pone en espera la consola hasta que se oprima una tecla
 * 
 */
void espera()
{
	printf("\nPresione enter para continua...\n");
	getchar();
	getchar();
}

/**
 * @brief Se encarga de solicitar el código y retornarlo
 * 
 * @return char* 
 */
void pedir_codigo()
{
	printf("Ingrese el código:");
}
/**
 * @brief Imprime en pantalla el user
 * 
 * @param user 
 */
void mostrar_usuario(char *user)
{
	printf(">>>>%s\n", user);
}
/*----------------------------Menu del Jefe de Departamento-------------------------*/
/**
 * @brief Muestra en menu destinado para el Jefe de Departamento
 * 
 * @param user 
 */
void menu_jd(char *user)
{
	limpiar();
	printf("************Jefe Departamento**************\n");
	mostrar_usuario(user);
	printf("   1. Registrar usuario.\n");
	printf("   2. Registrar anteproyecto.\n");
	printf("   3. Asignar evaluadores.\n");
	printf("   4. Buscar anteproyecto.\n");
	printf("   5. Listar anteproyectos.\n");
	printf("   6. Modificar concepto de anteproyecto.\n");
	printf("   7. Cerrar Sesion.\n");
}
/**
 * @brief Permite ingresar los datos de un usuario al jefede departamento
 * 
 * @param user 
 */
void pedir_datos_usuario(char *user)
{
	//hacer validaciones al ingresar datos
	datos_reg_user = (usuario_jd *)malloc(sizeof(usuario_jd));
	limpiar();
	mostrar_usuario(user);
	printf("Identificación: ");
	scanf("%10s", datos_reg_user->identificacion);
	printf("Nombre y apellido: ");
	scanf("%30s", datos_reg_user->nombre_apellido);
	printf("Nombre de usuario: ");
	scanf("%10s", datos_reg_user->nom_user);
	printf("Contraseña: ");
	scanf("%10s", datos_reg_user->contrasenia);

	// Validamos que elija una de las opciones correctas
	int tipo = 0;
	do
	{
		printf("Jefe Deepartamento(1),Estudiante-Direcator(2), Evaluador(3): ");
		//scanf("%d", &datos_reg_user->tipo_user);
		scanf("%d", &tipo);
		if (tipo != 1 && tipo != 2 && tipo != 3)
		{
			printf("\nError, debe elegir un valor correcto. [1, 2, 3]\n\n");
			printf("Elija una opcion de las siguientes.\n");
		}

	} while (tipo != 1 && tipo != 2 && tipo != 3);
	datos_reg_user->tipo_user = tipo;

	/* printf("id: %s \n", datos_reg_user->identificacion);
	printf("NombreApellido %s \n", datos_reg_user->nombre_apellido);
	printf("NombreUser %s \n", datos_reg_user->nom_user);
	printf("Pass %s \n", datos_reg_user->contrasenia);
	printf("Tipo %d \n", datos_reg_user->tipo_user); */
}

//Logica para registrarun usuario
void registrar_usuario(char *user)
{
	pedir_datos_usuario(user);
	result1_jd = registrar_usuario_jd_1(datos_reg_user, clnt_jd);
	if (result1_jd == (char **)NULL)
	{
		clnt_perror(clnt_jd, "call failed");
	}
	else
	{
		printf("%s\n", *result1_jd);
		espera();
	}
	free(datos_reg_user);
}

/**
 * @brief Permite ingresar los datos de un usuario al jefede departamento
 * 
 * @param user Nombre del usuaro que inicio sesión.
 */
void pedir_datos_anteproyecto(char *user)
{
	//hacer validaciones al ingresar datos
	registrar_anteproyecto_jd_1_arg = (anteproyecto_jd *)malloc(sizeof(anteproyecto_jd));
	limpiar();
	mostrar_usuario(user);

	// Generamos un código aleatorio
	srand(time(NULL));
	char c[3] = {'0', '0', '0'};
	for (int i = 0; i < sizeof(registrar_anteproyecto_jd_1_arg->codigo) / sizeof(*registrar_anteproyecto_jd_1_arg->codigo); i++)
	{
		c[i] = '0' + (rand() % 10);
	}
	strcat(registrar_anteproyecto_jd_1_arg->codigo, c);

	// Valores por defecto
	registrar_anteproyecto_jd_1_arg->concepto = 2;
	registrar_anteproyecto_jd_1_arg->estado = 1;
	registrar_anteproyecto_jd_1_arg->numero_revision = 0;

	printf("Modalidad: ");
	scanf("%12s", registrar_anteproyecto_jd_1_arg->modalidad);
	printf("Título: ");
	scanf("%40s", registrar_anteproyecto_jd_1_arg->titulo);
	printf("Estudiante 1: ");
	scanf("%30s", registrar_anteproyecto_jd_1_arg->nombre_estud1);
	printf("Estudiante 2: ");
	scanf("%30s", registrar_anteproyecto_jd_1_arg->nombre_estud2);
	printf("Director: ");
	scanf("%30s", registrar_anteproyecto_jd_1_arg->director);
	printf("Director: ");
	scanf("%30s", registrar_anteproyecto_jd_1_arg->co_director);
	printf("Fecha de registro: ");
	scanf("%10s", registrar_anteproyecto_jd_1_arg->fecha_registro);
	printf("Fecha de aprobacion: ");
	scanf("%12s", registrar_anteproyecto_jd_1_arg->fecha_aprobacion);

	/* int opcion = 0;
	do
	{
		printf("Concepto:  1=Aprobado  2=No aprobado");
		opcion = ingresar_opcion();
		if(opcion !1 && opcion != 2){
			printf("\nError, debe elegir un valor correcto. [1, 2]\n\n");
			printf("Elija una opcion de las siguientes.\n");
		}
	} while (opcion != 1 && opcion != 2); 
	registrar_anteproyecto_jd_1_arg->concepto = opcion;*/
	/* 
	do
	{
		opcion = 0;
		printf("Estado\n");
		printf("1=> Sin asignación\n2=> Evaluadores asignados\n3 => En revisión\n4=> Evaluado");
		opcion = ingresar_opcion();

		if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
		{
			printf("\nError, debe elegir un valor correcto. [1, 2]\n\n");
			printf("Elija una opcion de las siguientes.\n");
		}
		
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4); 
	
	registrar_anteproyecto_jd_1_arg->estado = opcion;*/
}
/**
 * @brief Pide al jp los datos del anteproyectos
 * 
 * @param user 
 */
void registrar_anteproyecto(char *user)
{
	pedir_datos_anteproyecto(user);
	result2_jd = registrar_anteproyecto_jd_1(registrar_anteproyecto_jd_1_arg, clnt_jd);
	if (result2_jd == (char **)NULL)
	{
		clnt_perror(clnt_jd, "call failed");
	}
}

void pedir_datos_evaluadores()
{
	limpiar();
	asignar_evaluadores_jd_1_arg = (evaluadores_jd *)malloc(sizeof(evaluadores_jd));
	printf("\t\tAsignacion de evaluadores\n\n");
	printf("Código del anteproyecto: ");
	scanf("%12s", asignar_evaluadores_jd_1_arg->codigo_anteproyecto);
	printf("Nombre del evaluador 1: ");
	scanf("%30s", asignar_evaluadores_jd_1_arg->nombre_evaluador1);
	printf("Concepto del evaluador 1: ");
	scanf("%20s", asignar_evaluadores_jd_1_arg->concepto_evaluador1);
	printf("Fecha de revision 1: ");
	scanf("%10s", asignar_evaluadores_jd_1_arg->fecha_revision1);

	printf("Nombre del evaluador 2: ");
	scanf("%30s", asignar_evaluadores_jd_1_arg->nombre_evaluador2);
	printf("Concepto del evaluador 2: ");
	scanf("%20s", asignar_evaluadores_jd_1_arg->concepto_evaluador2);
	printf("Fecha de revision 2: ");
	scanf("%10s", asignar_evaluadores_jd_1_arg->fecha_revision2);
}
void asignar_evaluadores(char *user)
{
	pedir_datos_evaluadores();
	result3_jd = asignar_evaluadores_jd_1(asignar_evaluadores_jd_1_arg, clnt_jd);
	if (result3_jd == (char **)NULL)
	{
		clnt_perror(clnt_jd, "call failed");
	}
	else
	{
		printf("Se han asignado los evaluadores!\n");
		espera();
	}
}

void imprimir_estado(int estado)
{
	switch (estado)
	{
	case 1:
		printf("Estado: Sin asignación\n");
		/* code */
		break;
	case 2:
		printf("Estado: Evaluadores asignados\n");
		/* code */
		break;
	case 3:
		printf("Estado: En revisión\n");
		/* code */
		break;
	case 4:
		printf("Estado: Evaluado\n");
		/* code */
		break;

	default:
		break;
	}
}

void imprimir_concepto(int concepto)
{
	switch (concepto)
	{
	case 1:
		printf("Concepto: Aprobado.\n");
		break;
	case 2:
		printf("Concepto: No aprobado.\n");
		break;

	default:
		break;
	}
}
/**
 * @brief Probar peticion
 * 
 */
void porbar_antcom()
{
	strcpy(result4_jd->codigo, "001");
	strcpy(result4_jd->modalidad, "Aprobado");
	strcpy(result4_jd->titulo, "titulo");
	strcpy(result4_jd->nombre_estud1, "e1");
	strcpy(result4_jd->nombre_estud2, "e2");
	strcpy(result4_jd->director, "dir");
	strcpy(result4_jd->co_director, "codir");
	strcpy(result4_jd->fecha_registro, "fr");
	strcpy(result4_jd->fecha_aprobacion, "fApro");
	result4_jd->concepto = 1;
	result4_jd->estado = 1;
	result4_jd->numero_revision = 1;
	strcpy(result4_jd->codigo_anteproyecto, "001");
	strcpy(result4_jd->nombre_evaluador1, "ev1");
	strcpy(result4_jd->concepto_evaluador1, "conev1");
	strcpy(result4_jd->fecha_revision1, "fechaR1");
	strcpy(result4_jd->nombre_evaluador2, "ev2");
	strcpy(result4_jd->concepto_evaluador2, "conev2");
	strcpy(result4_jd->fecha_revision2, "fechaR2");
}
void buscar_anteproyectos_jd(char *user)
{
	pedir_codigo();
	buscar_anteproyecto_jd_1_arg = (char *)malloc(10);
	scanf("%s", buscar_anteproyecto_jd_1_arg);

	result4_jd = buscar_anteproyecto_jd_1(&buscar_anteproyecto_jd_1_arg, clnt_jd);

	// porbar_antcom(); //TODO Eliminar antes de entrea

	if (result4_jd == (anteproyecto_completo_jd *)NULL)
	{
		clnt_perror(clnt_jd, "call failed");
		// printf("Error\n");
	}
	else if (*(result4_jd)->codigo == -1)
	{
		printf("No se encontro ningun anteproyecto con ese codigo!\n");
	}
	else
	{
		printf("\tDATOS DE ANTEPROYECTO\n\n");
		// Datos del anteproyecto
		printf("Codigo: %s\n", result4_jd->codigo);
		printf("Codigo Anteproyecto: %s\n", result4_jd->codigo_anteproyecto);
		printf("Titulo: %s\n", result4_jd->titulo);
		printf("Director: %s\n", result4_jd->director);
		printf("Co-Director: %s\n", result4_jd->co_director);

		// Mostrar Estado
		imprimir_estado(result4_jd->estado);
		printf("Fecha registro: %s\n", result4_jd->fecha_registro);
		printf("Estudiante 1: %s\n", result4_jd->nombre_estud1);
		printf("Estudiante 2: %s\n", result4_jd->nombre_estud2);
		imprimir_concepto(result4_jd->concepto);
		printf("Fecha Aprovacion: %s\n", result4_jd->fecha_aprobacion);
		printf("Modalidad: %s\n", result4_jd->modalidad);
		printf("Revision # %d\n", result4_jd->numero_revision);

		printf("Nom. Evaluador 1: %s\n", result4_jd->nombre_evaluador1);
		printf("Concepto Eval. 1: %s\n", result4_jd->concepto_evaluador1);
		printf("Nom. Evaluador 2: %s\n", result4_jd->nombre_evaluador2);
		printf("Concepto Eval. 2: %s\n", result4_jd->concepto_evaluador2);

		printf("Fecha Revision 1: %s\n", result4_jd->fecha_revision1);
		printf("Fecha Revision 2: %s\n", result4_jd->fecha_revision2);
	}
	espera();
}
void listar_anteproyectos(char *user)
{
	limpiar();
	//estudiante direactor
	result2_ed = listar_anteproyectos_ed_1((void *)&listar_anteproyectos_ed_1_arg, clnt_ed);
	if (result2_ed == (nodo_anteproyecto_ed *)NULL)
	{
		clnt_perror(clnt_ed, "call failed");
	}
	else
	{
		int i = 0;

		printf("\n Listado de Anteproyectos \n");
		while ((result2_ed) != NULL)
		{
			printf("\n\t\tAnteproyectos %i\n", i + 1);
			printf("Código: %s \n", result2_ed->codigo);
			printf("Titulo: %s \n", result2_ed->titulo);

			result2_ed = result2_ed->nodo_siguiente;
			i++;
		}
		if (i == 0)
		{
			printf("No existen anteproyectos registrados. \n");
		}
	}
	espera();
}

void datos_modificar_concepto()
{
	limpiar();
	printf("\t\tModificar concepto proyecto\n\n");
	printf("Codigo proytecto: ");
	scanf("%3s", modificar_concepto_anteproyecto_jd_1_arg->codigo_proyecto);
	printf("Codigo proytecto: ");
	scanf("%20s", modificar_concepto_anteproyecto_jd_1_arg->concepto);
}
void modificar_concepto_jd(char *user)
{
	modificar_concepto_anteproyecto_jd_1_arg = (datos_concepto_jd *)malloc(sizeof(datos_concepto_jd));
	datos_modificar_concepto();
	result5_jd = modificar_concepto_anteproyecto_jd_1(modificar_concepto_anteproyecto_jd_1_arg, clnt_jd);
	if (result5_jd == (char **)NULL)
	{
		clnt_perror(clnt_jd, "call failed");
	}
	else
	{
		printf("Se ha modificado el concepto!\n");
		espera();
	}
}
void cambiar_contrasenia(char *user)
{
	//inicio de sesion
}
void iniciar_menu_jd(char *user)
{
	int opcion = 0;
	do
	{
		menu_jd(user);
		opcion = ingresar_opcion();
		switch (opcion)
		{
		case 1:
			registrar_usuario(user);
			break;
		case 2:
			registrar_anteproyecto(user);
			break;
		case 3:
			asignar_evaluadores(user);
			break;
		case 4:
			buscar_anteproyectos_jd(user);
			break;
		case 5:
			listar_anteproyectos(user);
			break;
		case 6:
			modificar_concepto_jd(user);
			break;
		case 7:
			printf("regresando....\n");
			break;

		/* case 8:
			cambiar_contrasenia(user);
			break; */
		default:
			printf("Opcion no valida!\n");
			espera();
		}
	} while (opcion != 7);
}

/*----------------------------Estudiante -Director-------------------------*/
void menu_ed(char *user)
{
	limpiar();
	printf("************Estudiante-Director*************\n");
	mostrar_usuario(user);
	printf("   1. Buscar anteproyecto.\n");
	printf("   2. Listar anteproyectos.\n");
	printf("   3.cerrar Sesion.\n");
}

void buscar_anteproyecto(char *user)
{
	limpiar();
	buscar_anteproyecto_ed_1_arg = (char *)malloc(sizeof(char *));
	printf("\t\tBuscar anteproyecto\n\n");
	pedir_codigo();
	scanf("%s", buscar_anteproyecto_ed_1_arg);

	result1_ed = buscar_anteproyecto_ed_1(&buscar_anteproyecto_ed_1_arg, clnt_ed);
	if (result1_ed == (anteproyecto_ed *)NULL)
	{
		clnt_perror(clnt_ed, "call failed");
	}
}
void iniciar_menu_ed(char *user)
{
	int opcion = 0;
	do
	{
		menu_ed(user);
		opcion = ingresar_opcion();
		switch (opcion)
		{
		case 1:
			buscar_anteproyecto(user);
			break;
		case 2:
			//listar_anteproyectos(user);
			break;
		case 3:
			printf("regresando....\n");
			break;
		default:
			printf("Opcion no valida!\n");
		}
		espera();

	} while (opcion != 3);
}
/*----------------------------Evaluadores-------------------------*/
void menu_e(char *user)
{
	limpiar();
	printf("****************Evaluadores****************\n");
	mostrar_usuario(user);
	printf("   1. Buscar anteproyecto.\n");
	printf("   2. Listar anteproyectos.\n");
	printf("   3. Modificar concepto de anteproyecto.\n");
	printf("   4.cerrar Sesion.\n");
}
void modificar_concepto_e(char *user)
{
}
void iniciar_menu_e(char *user)
{
	int opcion = 0;
	do
	{
		menu_e(user);
		opcion = ingresar_opcion();
		switch (opcion)
		{
		case 1:
			//buscar_anteproyecto(user);
			break;
		case 2:
			//listar_anteproyectos(user);
			break;
		case 3:
			//modificar_concepto_e(user);
			break;
		case 4:
			printf("regresando....\n");
			break;
		default:
			printf("Opcion no valida!\n");
			espera();
		}
	} while (opcion != 4);
}
/*----------------------------Inicio de sesion-------------------------------------*/
//Muestra el menu de sesion.
void menu_sesion()
{
	limpiar();
	printf("********************MENU********************\n");
	printf("	1. Iniciar sesion.\n");
	printf("	2. Salir.\n");
}

//Pide loos datos necesarios para iniciar session.
void pedir_datos(datos_login_is *datos_usuario)
{
	limpiar();
	printf("************Inicio de sesion***********\n");
	printf("Nombre de usuario:	");
	scanf("%10s", datos_usuario->nom_user);
	printf("Contrseña:	");
	scanf("%10s", datos_usuario->contrasenia);
}

int iniciar_sesiones(int opcion, char *user)
{
	switch (opcion)
	{
	case 1:
		iniciar_menu_jd(user);
		break;
	case 2:
		iniciar_menu_ed(user);
		break;
	case 3:
		iniciar_menu_e(user);
		break;
	default:
		printf("Datos incorrectos..\n");
		return -1;
	}
	return 0;
}

//Pide los datos al usuario e inicia sesion.
void iniciar_sesion()
{
	int bandera = 0;

	do
	{
		pedir_datos(&datos_usuario);

		result1_is = iniciar_sesion_is_1(&datos_usuario, clnt_is);
		if (result1_is == (int *)NULL)
		{
			clnt_perror(clnt_is, "call failed");
			espera();
		}
		else if (iniciar_sesiones(*result1_is, datos_usuario.nom_user) == -1)
		{
			printf("Datos incorrectos..\n");

			printf("1-> volver a intentarlo\n");
			printf("2-> regresar\n");
			bandera = ingresar_opcion();
			//scanf("%d",&bandera);
		}
		/* else if (iniciar_sesiones(2, "dodaniel") == -1)
		{
			printf("Datos incorrectos..\n");

			printf("1-> volver a intentarlo\n");
			printf("2-> regresar\n");
			bandera = ingresar_opcion();
		} */
		else
		{
			printf("Inicio correcto\n");
		}

		strcpy(datos_usuario.nom_user, "");
		strcpy(datos_usuario.contrasenia, "");
	} while (bandera == 1);
}

/*----------------------------Inicio-----------------------------------------------*/
void prog_servicio()
{
	crear_clientes();
	int opcion = 0;
	do
	{
		menu_sesion();
		opcion = ingresar_opcion();
		printf("\n");
		switch (opcion)
		{
		case 1:
			iniciar_sesion();
			break;
		case 2:
			printf("La aplicacion termino exitosamente.");
			break;
		default:
			printf("Opcion no valida!");
			espera();
		}
	} while (opcion != 2);
	destruir_clientes();
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	prog_servicio();
	exit(0);
}
