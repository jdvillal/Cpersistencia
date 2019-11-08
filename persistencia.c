#include "persistencia.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define MAXSTR 50

void guardar(Usuario_t *usuarios, int n) {
    FILE *fp;
    fp = fopen(FILENAME, "a"); //Abre un archivo y escribe al final, lo crea si no existe
    for (int i = 0; i < n; i++)
        //<nombre><tab><apellido><tab><username><tab><password><tab><userid>
        fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", usuarios[i].nombre, usuarios[i].apellido, usuarios[i].username, usuarios[i].password, usuarios[i].userid);
    fclose(fp);
}

int leer(Usuario_t *usuarios) {
    FILE *fp;
    char linea[250];
    fp = fopen(FILENAME, "r");
    char lineaAnterior[250];
    if (fp == NULL) {
        printf("Por el momento no hay usuarios registrados\n");
    } else {
        int ciclo = 1;
        while (!feof(fp)) {
            fgets(linea, 250, fp);
            if (strcmp(linea, lineaAnterior) == 0) {
                break;
            } else {
                if (ciclo == 1) {
                    printf("El archivo usuarios.txt existe. \n\n");
		    printf("Mostrando datos de los usuarios registrados con el siguiente formato: \n");
		    printf("[Nombre y apellido\tusername\tpassword\tuserid]. \n\n");
                }
                printf("%s",linea);
                for (int i = 0; i < 250; i++) {
                    lineaAnterior[i] = linea[i];
                }
            }
            ciclo = ciclo + 1;

        }
        fclose(fp);
    }

}

















