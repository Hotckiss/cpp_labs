all: bin empl_db
bin:
	mkdir -p bin
empl_db: bin/empl_db.o bin/employees.o
	g++ -Wall -Werror bin/empl_db.o bin/employees.o -o empl_db
bin/empl_db.o: src/empl_db.cpp include/employees.h
	g++ -Wall -Werror -c -I include src/empl_db.cpp -o bin/empl_db.o
bin/employees.o: src/employees.cpp include/employees.h
	g++ -Wall -Werror -c -I include src/employees.cpp -o bin/employees.o
clean:
	rm -rf bin empl_db

