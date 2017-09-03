all: bin pose_db

bin:
	mkdir -p bin
pose_db:  bin/main.o bin/clist.o
	gcc bin/main.o bin/clist.o -o pose_db
bin/main.o: src/main.c include/clist.h
	gcc -c src/main.c -o bin/main.o
bin/clist.o: src/clist.c include/clist.h
	gcc -c src/clist.c -o bin/clist.o
clean:
	rm -rf bin pose_db