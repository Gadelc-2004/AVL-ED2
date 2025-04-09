all: clean ./bin/main

./bin/main: ./obj/avlOb.o ./apps/main.cpp
	g++ -Wall -I./include ./obj/avlOb.o ./apps/main.cpp -o ./bin/main

./obj/avlOb.o: ./src/avl.cpp
	g++ -Wall -I./include -c ./src/avl.cpp -o ./obj/avlOb.o

debug: clean
	g++ -Wall -g -I./include ./src/avl.cpp ./apps/main.cpp -o ./src/debug/main-debug

clean:
	rm -f ./obj/*.o ./src/debug/* ./bin/*

run:
	./bin/main

run-gdb: debug
	gdb -x ./debug_script.gdb ./src/debug/main-debug

run-ddd: debug
	ddd -x ./debug_script.gdb ./src/debug/main-debug
