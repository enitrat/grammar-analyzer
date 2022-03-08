all: analyse


analyse: lexer.o symbole.o state.o automate.o main.o
	g++ -o analyse lexer.o symbole.o state.o automate.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -o lexer.o -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -o symbole.o -c symbole.cpp

state.o: state.cpp state.h
	g++ -o state.o -c State.cpp

automate.o: automate.cpp automate.h
	g++ -o automate.o -c Automate.cpp

main.o: main.cpp symbole.h lexer.h state.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf analyse

