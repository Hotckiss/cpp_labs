all: bin ms_cli
bin:
	mkdir -p bin
ms_cli: bin/main.o bin/mergesort.o bin/util.o
	gcc bin/main.o bin/mergesort.o bin/util.o -o ms_cli
bin/main.o: src/main.c include/util.h include/mergesort.h
	gcc -c src/main.c -o bin/main.o 
bin/mergesort.o: src/mergesort.c
	gcc -c src/mergesort.c -o bin/mergesort.o
bin/util.o: src/util.c
	gcc -c src/util.c -o bin/util.o
clean:
	rm -rf bin ms_cli