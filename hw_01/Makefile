all: bin main
bin:
	mkdir -p bin
main: bin/main.o bin/bmp.o
	gcc -std=c99 -Wall -Werror bin/main.o bin/bmp.o -o main
bin/main.o: src/main.c include/bmp.h
	gcc -std=c99 -Wall -Werror -c -I include src/main.c -o bin/main.o
bin/bmp.o: src/bmp.c include/bmp.h
	gcc -std=c99 -Wall -Werror -c -I include src/bmp.c -o bin/bmp.o
clean:
	rm -rf bin main
