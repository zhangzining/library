main: main.o func.o
	gcc main.c func.c -o main
main.o: main.c main.h
	gcc main.c -c
func.o: func.c main.h
	gcc func.c -c
	
