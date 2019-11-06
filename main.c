#include "guardar.h"
#include "validar.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAXUSERS 20

/*
* Ingresa nombre, apellido y contraseña de usuarios desde consola.
* Valida la contraseña, genera un userid aleatorio para cada usuario
* y graba los usuarios, un usuario por línea, en un archivo de texto.
*/
int main()
{
	Usuario_t user;
	Usuario_t usuarios[MAXUSERS];

	char respuesta[MAXSTR];
	bool continuar = false;

	int i_usuarios = 0;
	time_t t;

	do{
		printf("Ingrese el nombre y apellido del usuario (ej. Jose Perez): ");
		scanf("%s %s", user.nombre, user.apellido);

		printf("Ingrese la contraseña (min. 10 caracteres con letras y números): ");
		scanf("%s", user.password);

		srand((unsigned) time(&t)); //Semilla del random por clock
  		user.userid = rand() % 1001; //Numero random entre 0-1000

		int error = validar(&user);

		while(error){
			switch(error){
				case E_MAXSTR:
					fprintf(stderr, "contraseña muy larga...\n");
					break;
				case E_MINPASS:
					fprintf(stderr, "Contraseña muy corta, necesita más de %d caracteres...\n", MINPASS);
					break;
				case E_ALPHA:
					fprintf(stderr, "Contraseña no contiene letras...\n");
					break;
				case E_DIGIT:
					fprintf(stderr, "Contraseña no contiene dígitos...\n");
					break;
				default:
					fprintf(stderr, "Error desconocido...\n");
			}

			printf("Ingrese su contraseña (min. 10 caracteres con letras y números): ");
			scanf("%s", user.password);

			error = validar(&user);
		}

		printf("Usuario %s %s con contraseña %s\n", user.nombre, user.apellido, user.password);
		printf("Nombre de usuario sugerido %s\n", user.username);

		usuarios[i_usuarios] = user;
		i_usuarios++;

		if(i_usuarios < MAXUSERS){
			printf("¿Desea ingresar otro usuario? (S/N)\n");
			scanf("%s", respuesta);
			if(tolower(respuesta[0]) == 's')
				continuar = true;
			else
				continuar = false;
		}else{
			fprintf(stderr, "Número máximo de usuarios alcanzado...\n");
			continuar = false;
		}

		printf("\n");
	}while(continuar);

	guardar(usuarios, i_usuarios);

	printf("Usuarios ingresados almacenados en %s\n", FILENAME);
	
}