all: bin main
bin:
	mkdir -p bin
main:bin/main.o 
	g++ -std=c++03 -pedantic -Wall -Wextra bin/main.o -o main
smoke:bin/smoke_compile.o
	g++ -std=c++03 -pedantic -Wall -Wextra bin/smoke_compile.o -o smoke_compile
bin/smoke_compile.o:src/smoke_compile.cpp include/my_array.h
	g++ -c -I include src/smoke_compile.cpp -o bin/smoke_compile.o
bin/main.o:src/main.cpp include/my_array.h
	g++ -c -I include src/main.cpp -o bin/main.o
clean:
	rm -rf bin main
