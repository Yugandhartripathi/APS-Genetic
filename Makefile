CC := g++

all: executable

executable: main.o helperFunctions.o
	$(CC) main.o helperFunctions.o -o bin/executable
	
main.o: src/main.cpp
	$(CC) -c src/main.cpp

helperFunctions.o: src/helperFunctions.cpp
	$(CC) -c src/helperFunctions.cpp

clean:
	rm -rf *o bin/executable
