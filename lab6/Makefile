all: bin main
bin:
	mkdir -p bin
main: bin/main.o
	gcc bin/main.o -o main -lexpat
bin/main.o: src/main.c include/phonebook.h include/names.h
	gcc -c src/main.c -o bin/main.o
clean:
	rm -rf bin main
