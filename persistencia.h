#ifndef __GUARDAR_H__
#define __GUARDAR_H__

#include "validar.h"

#define FILENAME "usuarios.txt"

/*
* Guarda "n" usuarios del arreglo "usuarios" en el archivo FILENAME, un usuario por línea,
* con el siguiente formato:
* <nombre><tab><apellido><tab><username><tab><password><tab><userid>
*/
void guardar(Usuario_t *usuarios, int n);

#endif /* __GUARDAR_H__ */