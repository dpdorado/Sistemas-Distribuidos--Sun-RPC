#include "./../servicio_inicio_sesion.h"

#ifndef STDSERV_H
#define STDSERV_H
#define MAXDAG_is 10
#define MAXNOM_is 30

#ifdef __cplusplus
extern "C"{
#endif 

struct usuario_is {
	char identificacion[MAXDAG_is];
	char nombre_apellido[MAXNOM_is];
	char nom_user[MAXDAG_is];
	char contrasenia[MAXDAG_is];
	int tipo_user;
};
typedef struct usuario_is usuario_is;

struct retorno_is{
	char messaje[50];
	int tipo_user;
};

typedef struct retorno_is retorno_is;

struct admin_is{
	char user[10];
	char contrasenia[10];
};
typedef struct admin_is admin_is;

//verifica las credenciales de inicio de sesion
retorno_is* logeo(datos_login_is * datas, char* path_user, char *path_admin);

//Verifica si el usuario esta en usuarios tipo de usuario,-1=datos incorrectos
int esta_en_users(datos_login_is * datas, char* path_user);

//Verifica si el usuario esta en usuarios tipo de usuario,-1=datos incorrectos
int esta_en_users(datos_login_is * datas, char* path_admin);

//Modifica la contraseña de el administrador
char* modify_password_admin(datos_cambio_contrsenia_is *datas, char* path_admin);
#ifdef __cplusplus
}
#endif

#endif
