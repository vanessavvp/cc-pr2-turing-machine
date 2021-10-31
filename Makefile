OBJECTS = Main.o Symbol.o State.o Alphabet.o Transition.o Tape.o TuringMachine.o
CFLAGS = -g -c -O3 -std=c++17 -I../include
SRC = src/Main.cc src/Symbol.cc src/Transition.cc src/State.cc src/Alphabet.cc src/Tape.cc src/TuringMachine.cc
exe: $(OBJECTS)
	g++ $(SRC) -o exe
	mv *.o ./obj
	
Main.o:
	g++ $(CFLAGS) ./src/Main.cc

Symbol.o:
	g++ $(CFLAGS) ./src/Symbol.cc

State.o:
	g++ $(CFLAGS) ./src/State.cc

Alphabet.o:
	g++ $(CFLAGS) ./src/Alphabet.cc

Transition.o:
	g++ $(CFLAGS) ./src/Transition.cc

Tape.o:
	g++ $(CFLAGS) ./src/Tape.cc

TuringMachine.o:
	g++ $(CFLAGS) ./src/TuringMachine.cc

.PHONY: 

default:
	make exe

clean:
	rm -rf ./obj/*.o && rm ./exe

run:
	make -s && ./exe