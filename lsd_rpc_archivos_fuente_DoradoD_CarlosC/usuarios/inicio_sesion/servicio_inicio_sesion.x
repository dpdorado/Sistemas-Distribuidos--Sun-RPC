/*Interfaz necesaria para el inicio de sesion.*/

/*Definición de constantes.*/
const MAXPER_is = 10;

/*Datos necesarios para que el usuario ingrese a los servicios de la app.*/
struct datos_login_is{
	char nom_user[MAXPER_is];
	char contrasenia[MAXPER_is];
};
/*Datos necesarios para hacer un cambio de contrasenia.*/
struct datos_cambio_contrsenia_is{
	char nom_user[MAXPER_is];
	char contrasenia[MAXPER_is];
	char nueva_contrasenia[MAXPER_is];
};

/*Definición de las operaciones necesarias.*/
program inicio_sesion{
	version inicio_sesion_version{
		int iniciar_sesion_is(datos_login_is objDatos)=1;
		string cabiar_contrasenia_is(datos_cambio_contrsenia_is objDatos)=2;
	}=1;
}=0x20000005;
