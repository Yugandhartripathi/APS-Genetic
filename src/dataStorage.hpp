#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
void printFromHeader();
void printSec();
void printFromHeader(){
    std::cout<<"Hello from header file\n";
}
*/

class Gene;
class Chromosome;
class Population;

class Gene
{
    int gid;
    string name;
    vector<int> experience; // For a fixed skill mapped to index values
    int aptitude;
    int emotionalQuotient;
    int willingnessFactor; // Rating from 1-10
  public:
    int getGid();
    string getName();
    int getAptitude();
    int getEQ();
    int getWF();
    void setGid(int gid);
    void setName(string name);
    void setAptitude(int aptitude);
    void setEQ(int EQ);
    void setWF(int WF);
};

class Chromosome
{
  private:
    int cid;
    int teamSize;
    vector<Gene> genes;
    int fitnessVal;
  public:
    int getCid();
    int getTeamSize();
    int getFitnessVal();
    void setCid(int cid);
    void setTeamSize(int teamSize);
    void setGenes(vector<Gene> genes);
    void setFitnessVal(int fitnessVal);
    void setGeneAtIndex(int i,Gene X);
    Gene getGeneWithID(int id);
    Gene getGeneAtIndex(int index);
    void fitnessFunction();
};

class Population
{
  private:
    int id;
    vector<Chromosome> chromosomes;
  public:
    Chromosome fittestMember();
    void addNewChromosome(Chromosome X);
    void removeChromosomeWithCID(int cid);
    void crossOver();
    void mutation();
};
