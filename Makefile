all: ordvetor.o
	gcc ordvetor.o main.c -o main.exe

ordvetor.o:
	gcc -c ordvetor.c

clean:
	del *.o main.exe || rm *.o main.exe

run:
	./main.exe