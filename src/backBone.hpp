#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Gene;
class Chromosome;
class Population;

extern vector<Gene> Genealogy;

void createCSV();
void readRecordsAndSaveGene();
void train(Population p, int gen, int rS[]);
void newTrain(Population p, int gen, int rS[]);

class Gene
{
private:
  int gid;
  string name;
  vector<int> experience;      // For a fixed skill mapped to index values
  vector<int> areasOfInterest; //For a fixed domain mapped to index value
  int aptitude;
  int emotionalQuotient;
  int socialQuotient;

public:
  Gene();
  int getGid();
  void setGid(int gid);
  string getName();
  void setName(string name);
  int getAptitude();
  void setAptitude(int aptitude);
  int getEQ();
  void setEQ(int EQ);
  int getSQ();
  void setSQ(int SQ);
  vector<int> getExperience();
  vector<int> getInterest();
  void setExperience(const vector<int> &a);
  void setInterest(const vector<int> &a);
  int getExperienceBySkill(int skillNo);
  int checkAreaOfInterest(int domainNo);
  void setExperienceBySkill(int skillNo, int val);
  void setAreaOfInterestByDomain(int domainNo, int val);
};

class Chromosome
{
private:
  int cid;
  int teamSize;
  vector<int> genes;
  int fitnessVal;

public:
  Chromosome();
  Chromosome(int id, int ts);
  int getCid();
  void setCid(int cid);
  int getTeamSize();
  void setTeamSize(int teamSize);
  int getFitnessVal();
  void setFitnessVal(int fitnessVal);
  vector<int> getGenes();
  void setGenes(const vector<int>& g);
  void setGeneAtIndex(int i,int geneID);
  int getGeneAtIndex(int index);
  void fitnessFunction(const vector<int>& requiredSkills);
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
