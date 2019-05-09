#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Gene;
class Chromosome;
class Population;

void printSec();
void createCSV();
void read_record();
void update_record();
void delete_record();
Gene readRecordAtIndexAndReturnGene(int index);
void train(Population p, int gen,bool rS[]);
void newTrain(Population p, int gen,bool rS[]);


class Gene
{
private:
  int gid;
  string name;
  //vector<int> experience;       // For a fixed skill mapped to index values
  int e1;
  int e2;
  int e3;
  int e4;
  int e5;
  int e6;
  int e7;
  //vector<bool> areasOfInterest; //For a fixed domain mapped to index value
  int aptitude;
  int emotionalQuotient;
  int socialQuotient;

public:
  Gene();
  //Gene(Gene &G);
  int getGid();
  string getName();
  int getAptitude();
  int getEQ();
  int getSQ();
  int getExperienceBySkill(int skillNo);
  //bool checkAreaOfInterest(int domainNo);
  void setGid(int gid);
  void setName(string name);
  void setAptitude(int aptitude);
  void setEQ(int EQ);
  void setSQ(int SQ);
  void setExperienceBySkill(int skillNo, int val);
  //void setAreaOfInterest(int domainNo, bool val);
};

class Chromosome
{
private:
  int cid;
  int teamSize;
  vector<Gene> genes;
  int fitnessVal;

public:
  Chromosome();
  Chromosome(int id, int ts);
  int getCid();
  int getTeamSize();
  int getFitnessVal();
  void setCid(int cid);
  void setTeamSize(int teamSize);
  void setGenes(vector<Gene> genes);
  void setFitnessVal(int fitnessVal);
  void setGeneAtIndex(int i, Gene X);
  Gene getGeneAtIndex(int index);
  void fitnessFunction(bool requiredSkills[7]);
};

class Population
{
private:
  int pid;
  int populationSize;
  int sizeOfEachTeam;
  int numOfEmployees;
  vector<Chromosome> chromosomes;

public:
  Population();
  Population(int id, int ps, int ts);
  int getID();
  void setID(int pid);
  int getPopulationSize();
  void setPopulationSize(int ps);
  int getTeamSize();
  void setTeamSize(int ts);
  void populate();
  Chromosome fittestMember();
  void addNewChromosome(Chromosome X);
  void removeChromosomeWithCID(int cid);
  Population crossOver();
  void mutation();
  Chromosome getChromosomeAtIndex(int ind);
};
