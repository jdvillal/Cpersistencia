usuarios.txt: main.o validar.o persistencia.o
	gcc -o usuarios.txt main.o validar.o persistencia.o

main.o: main.c validar.h persistencia.h 
	gcc -c main.c

validar.o: validar.c validar.h
	gcc -c validar.c

guardar.o: persistencia.c persistencia.h validar.h
	gcc -c persistencia.c

.PHONY: clean
clean:
	rm *.o usuarios.txt
