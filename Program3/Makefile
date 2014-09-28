#Makefile for p3.cc
#Sheyn Denizov
#CSE 109
#Fall 2013

p3: p3.o String.o check.o
	g++ -o p3 p3.o String.o check.o

p3.o: p3.cc String.h check.h
	g++ -c -Wall -Werror p3.cc

String.o: String.h String.cc check.h
	g++ -c -Wall -Werror String.cc

check.o: check.cc check.h
	g++ -c -Wall -Werror check.cc

clean:
	rm -f *~ *.o p3