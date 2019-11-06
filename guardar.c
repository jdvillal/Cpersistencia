#include "guardar.h"
#include "stdio.h"

void guardar(Usuario_t *usuarios, int n)
{
	FILE *fp;
	fp = fopen (FILENAME,"w"); //Abre un archivo para escritura, lo crea si no existe, lo sobreescribe si existe
	for(int i=0; i < n; i++)
		//<nombre><tab><apellido><tab><username><tab><password><tab><userid>
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", usuarios[i].nombre, usuarios[i].apellido, usuarios[i].username, usuarios[i].password, usuarios[i].userid);

	fclose (fp);
}