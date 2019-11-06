#include "validar.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int validar(Usuario_t *user)
{
	int i;
	bool hasDigit = false;
	bool hasLetter = false;

	user->username[0] = tolower(user->nombre[0]);

	for(i=0; i < strlen(user->apellido); i++){
		/* En caso de ingresar nombres muy largos */
		if(i == (MAXSTR - 2)) break;
		user->username[i+1] = tolower(user->apellido[i]);
	}
	user->username[i+1] = 0; //Finaliza la cadena de caracteres
	
	user->nombre[0] = toupper(user->nombre[0]);
	user->apellido[0] = toupper(user->apellido[0]);


	int l = strlen(user->password);
	if(l < MINPASS)
		return E_MINPASS;

	/* Chequea si contraseña es más larga que arreglo */
	if(l > (MAXSTR - 1))
		return E_MAXSTR;

	for(i=0; i < l; i++) {
		if(isdigit(user->password[i]))
			hasDigit = true;

		if(isalpha(user->password[i]))
			hasLetter = true;
	}

	if(!hasLetter)
		return E_ALPHA;

	if(!hasDigit)
		return E_DIGIT;

	return OK;
}