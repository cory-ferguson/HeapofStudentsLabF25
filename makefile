game: address.o date.o student.o main.o
	g++ -g address.o date.o student.o main.o -o game

main.o: address.h date.h student.h main.cpp
	g++ -c -g main.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

date.o: date.h date.cpp
	g++ -c -g date.cpp

student.o: student.h student.cpp
	g++ -c -g student.cpp

clean:
	rm *.o
	rm game

run: game
	./game

debug: game
	gdb game

leak: game
	valgrind --leak-check=full ./game
