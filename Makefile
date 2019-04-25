CC := g++

all: executable

executable: main.o helperFunctions.o Gene.o Chromosome.o Population.o
	$(CC) main.o helperFunctions.o Gene.o Chromosome.o Population.o -o bin/executable
	
main.o: src/main.cpp
	$(CC) -c src/main.cpp

helperFunctions.o: src/helperFunctions.cpp
	$(CC) -c src/helperFunctions.cpp

Gene.o: src/Gene.cpp
	$(CC) -c src/Gene.cpp

Chromosome.o: src/Chromosome.cpp
	$(CC) -c src/Chromosome.cpp

Population.o: src/Population.cpp
	$(CC) -c src/Population.cpp

clean:
	rm -rf *o bin/executable
