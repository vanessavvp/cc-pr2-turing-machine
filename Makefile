OBJECTS = Main.o
CFLAGS = -c -O3 -std=c++17 -I../include
SRC = src/Main.cc
exe: $(OBJECTS)
	g++ $(SRC) -o exe
	mv *.o ./obj
	
Main.o:
	g++ $(CFLAGS) ./src/Main.cc

.PHONY: 

default:
	make exe

clean:
	rm -rf ./obj/*.o

run:
	make -s && ./exe