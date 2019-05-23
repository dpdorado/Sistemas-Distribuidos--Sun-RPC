#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_is.h"
#include "./../servicio_inicio_sesion.h"



//verifica las credenciales de inicio de sesion
retorno_is* logeo(datos_login_is * datas, char* path_user, char *path_admin){

	static retorno_is *ret; 			
	usuario_is *user; 
	FILE *file;
	int var_con=-1;
	
	ret=(retorno_is*)malloc(sizeof(retorno_is));	
	strcpy(ret->messaje,"No se pudo iniciar sesion.");
	ret->tipo_user=-1;
	
	var_con=esta_en_users(datas,path_user);
	if (var_con!=-1){
		strcpy(ret->messaje,"Sesion iniciada.");
		ret->tipo_user=var_con;
		return ret;
	}
	
	var_con=esta_en_admin(datas,path_admin);
	if (var_con!=-1){
		strcpy(ret->messaje,"Sesion iniciada.");
		ret->tipo_user=var_con;
		return ret;
	}
	
	return ret;
}

//Verifica si el usuario esta en usuarios tipo de usuario,-1=datos incorrectos
int esta_en_users(datos_login_is * datas, char* path_user){
	usuario_is *user; 
	FILE *file;
	int result=-1;

	file=fopen(path_user,"rb");
	if (file==NULL){
		return result;
	}
	
	user=(usuario_is*)malloc(sizeof(usuario_is));
	strcpy(user->nom_user,"");
	strcpy(user->contrasenia,"");	
	
	fread(user, sizeof(usuario_is), 1, file);

	while(!feof(file)){
		if (strcmp(datas->nom_user,user->nom_user)==0  && strcmp(datas->contrasenia,user->contrasenia)==0){
			result=user->tipo_user;		
			fclose(file);
			return result;
		}
		fread(user, sizeof(usuario_is), 1, file);
	}
	fclose(file);
	return result;
}


//Verifica si el usuario esta en usuarios tipo de usuario,-1=datos incorrectos
int esta_en_users(datos_login_is * datas, char* path_admin){
	admin_is *admin; 
	FILE *file;
	int result=-1;

	file=fopen(path_admin,"rb");
	if (file==NULL){
		return result;
	}
	
	admin=(admin_is*)malloc(sizeof(admin_is));
	
	fread(admin, sizeof(usuario_is), 1, file);

	if (strcmp(datas->nom_user,user->nom_user)==0  && strcmp(datas->contrasenia,user->contrasenia)==0){
		result=1;//1 es admin	
		fclose(file);
		return result;
	}

	fclose(file);
	
	return result;
}

//Modifica la contraseña de el administrador
char* modify_password_admin(datos_cambio_contrsenia_is *datas, char* path_admin){
	static char* messaje;
	admin_is *admin; 
	FILE *file;

	massaje = (char*)malloc(sizeof(char)*50);
	strcpy(messaje,"No se cambio la contrasenia.");
	
	file=fopen(path_admin,"r+b");
	if (file==NULL){
		return messaje;
	}

	admin=(admin_is*)malloc(sizeof(admin_is));

	fread(admin, sizeof(admin_is), 1, file);
	
	if (strcmp(datas->nom_user,admin->user)==0  && strcmp(datas->contrasenia,admin->contrasenia)==0){
		int pos = ftell(file)-sizeof(admin_is);
		fseek(file,pos,SEEK_SET);
		strcpy(admin->contrasenia,datas->nueva_contrasenia);
		fwrite(admin, sizeof(admin_is), 1, file);
		strcpy(messaje,"Se modifico la contrasenia.");
		fclose(file);
		return messaje;
	}
	
	fclose(file);
	return messaje;
}


