all: bin main
board_test: bin board_test1
bin:
	mkdir -p bin
main:bin/main.o bin/Board.o bin/BoardView.o bin/NcursesBoardView.o
	g++ -Wall -Werror bin/main.o bin/Board.o bin/BoardView.o bin/NcursesBoardView.o -lncurses -o main
board_test1:bin/test_main.o bin/BoardTest.o bin/Test.o bin/Board.o
	g++ -Wall -Werror bin/test_main.o bin/BoardTest.o bin/Test.o bin/Board.o -o board_test
bin/test_main.o:test/test_main.cpp include/BoardTest.h include/Test.h
	g++ -Wall -Werror -c -I include test/test_main.cpp -o bin/test_main.o
bin/Test.o:test/Test.cpp include/Test.h
	g++ -Wall -Werror -c -I include test/Test.cpp -o bin/Test.o
bin/BoardTest.o:test/BoardTest.cpp include/BoardTest.h include/Test.h include/Board.h
	g++ -Wall -Werror -c -I include test/BoardTest.cpp -o bin/BoardTest.o
bin/main.o:src/main.cpp include/BoardView.h
	g++ -Wall -Werror -c -I include src/main.cpp -o bin/main.o
bin/Board.o:src/Board.cpp include/Board.h
	g++ -Wall -Werror -c -I include src/Board.cpp -o bin/Board.o
bin/NcursesBoardView.o:src/NcursesBoardView.cpp include/NcursesBoardView.h include/Board.h
	g++ -Wall -Werror -c -I include src/NcursesBoardView.cpp -o bin/NcursesBoardView.o
bin/BoardView.o:src/BoardView.cpp include/BoardView.h include/Board.h
	g++ -Wall -Werror -c -I include src/BoardView.cpp -o bin/BoardView.o
clean:
	rm -rf bin main board_test
