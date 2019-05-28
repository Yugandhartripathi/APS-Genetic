CC := g++

all: executable

executable: main.o Gene.o Chromosome.o Population.o readWriteCSV.o GA.o
	$(CC) main.o Gene.o Chromosome.o Population.o readWriteCSV.o GA.o -o bin/executable
	
main.o: src/main.cpp
	$(CC) -c src/main.cpp

Gene.o: src/Gene.cpp
	$(CC) -c src/Gene.cpp

Chromosome.o: src/Chromosome.cpp
	$(CC) -c src/Chromosome.cpp

Population.o: src/Population.cpp
	$(CC) -c src/Population.cpp

readWriteCSV.o: src/readWriteCSV.cpp
	$(CC) -c src/readWriteCSV.cpp

GA.o: src/GeneticAlgorithmTraining.cpp
	$(CC)  
clean:
	rm -rf *o bin/executable
