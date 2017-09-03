all: bin main
bin:
	mkdir -p bin
main: bin/main.o
	g++ -Wall -Werror bin/main.o -o main
bin/main.o: include/my_vector.h
	g++ -Wall -Werror -c -I include src/main.cpp -o bin/main.o
clean:
	rm -rf bin main

