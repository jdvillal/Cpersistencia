#ifndef __VALIDAR_H__
#define __VALIDAR_H__

#define MAXSTR 50
#define MINPASS 10

typedef struct Usuario{
 char nombre[MAXSTR];
 char apellido[MAXSTR];
 char username[MAXSTR];
 char password[MAXSTR];
 int userid;
}Usuario_t;

//Enumeración de códigos de error en función validar
enum ERROR_CODE {OK = 0, E_MAXSTR, E_MINPASS, E_ALPHA, E_DIGIT};

/*
* Revisa los datos en "user" y hace lo siguiente:
* - Mayúscula primera letra en campos nombre y apellido
* - Genera campo username en minúsculas usando primera letra del nombre y todo el apellido.
* - Valida contraseña en campo password
*
* Retorna 0 si no hubó error o el siguiente código de error (enum ERROR_CODE):
* - E_MAXSTR si campo password tiene más que MAXSTR caracteres
* - E_MINPASS si campo password tiene menos que MINPASS caracteres
* - E_ALPHA si campo password no contiene letras
* - E_DIGIT si campo password no contiene dígitos
*/
int validar(Usuario_t *user);

#endif /* __VALIDAR_H__ */