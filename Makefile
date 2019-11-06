usuarios: main.o validar.o guardar.o
	gcc -o usuarios main.o validar.o guardar.o

main.o: main.c validar.h guardar.h 
	gcc -c main.c

validar.o: validar.c validar.h
	gcc -c validar.c

guardar.o: guardar.c guardar.h validar.h
	gcc -c guardar.c

.PHONY: clean
clean:
	rm *.o usuarios