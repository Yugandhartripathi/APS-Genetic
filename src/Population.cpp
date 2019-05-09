#include "dataStorage.hpp"
#include <vector>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

Population::Population()
{
}

Population::Population(int id, int ps, int ts)
{
  pid = id;
  populationSize = ps;
  sizeOfEachTeam = ts;
}

int Population::getID()
{
  return pid;
}

void Population::setID(int id)
{
  pid = id;
}

int Population::getPopulationSize()
{
  return populationSize;
}

void Population::setPopulationSize(int ps)
{
  populationSize = ps;
}

int Population::getTeamSize()
{
  return sizeOfEachTeam;
}

void Population::setTeamSize(int ts)
{
  sizeOfEachTeam = ts;
}

Chromosome Population::fittestMember()
{
  Chromosome fittest;
  vector<Chromosome>::iterator i;
  i = chromosomes.begin();
  fittest = (*i);
  for (; i != chromosomes.end(); ++i)
  {
    if ((*i).getFitnessVal() >= fittest.getFitnessVal())
    {
      fittest = (*i);
    }
  }
  return fittest;
}

void Population::addNewChromosome(Chromosome X)
{
  chromosomes.push_back(X);
}

void Population::removeChromosomeWithCID(int cid)
{
  Chromosome toBeDeleted;
  vector<Chromosome>::iterator i;
  vector<Chromosome>::iterator pos;
  pos = chromosomes.end();
  for (i = chromosomes.begin(); i != chromosomes.end(); ++i)
  {
    if ((*i).getCid() == cid)
    {
      toBeDeleted = (*i);
      pos = i;
      break;
    }
  }
  if (pos != chromosomes.end())
    chromosomes.erase(pos);
}

void Population::populate()
{
  for (int i = 0; i < populationSize; i++)
  {
    Chromosome newOrder(i, sizeOfEachTeam);
    for (int j = 0; j < sizeOfEachTeam; j++)
    {
      Gene randomGene;
      int r=(rand()%60)+1;
      randomGene=readRecordAtIndexAndReturnGene(r);
      newOrder.setGeneAtIndex(j, randomGene);
    }
    chromosomes.push_back(newOrder);
  }
}

void Population::mutation()
{
  for (int i = 0; i < populationSize; i++)
  {
    int loopR = rand() % 100;
    if (loopR < 50)
    {
      for (int j = 0; j < loopR; j++)
      {
        int r1 = rand() % populationSize;
        int r2 = rand() % sizeOfEachTeam;
        int r3 = rand() % sizeOfEachTeam;
        chromosomes[i].setGeneAtIndex(r2, chromosomes[r1].getGeneAtIndex(r3));
      }
    }
  }
}

//OX1 or order 1 crossover because it's the fastest and fulfills our need for uniqueness within chromosome
Population Population::crossOver()
{
  Population newPopulation(pid + 1, populationSize, sizeOfEachTeam);
  for (int i = 0; i < populationSize; i++)
  {
    vector<Gene> crossedGenes(sizeOfEachTeam);
    int r1 = rand() % sizeOfEachTeam;
    int r2 = rand() % sizeOfEachTeam;
    if (r1 > r2)
    {
      //make a swap function in helperFunctions file for this
      int temp = r2;
      r2 = r1;
      r1 = temp;
    }
    for (int j = r1; j < r2; j++)
    {
      crossedGenes[j] = chromosomes[i].getGeneAtIndex(j);
    }
    int r = rand() % populationSize;
    int curr = r2;
    for (int j = r2; j < (sizeOfEachTeam + r2); j++)
    {
      bool found = false;
      int index = j % sizeOfEachTeam;
      for (int k = r1; k < r2; k++)
      {
        if (chromosomes[r].getGeneAtIndex(index).getGid() == crossedGenes[k].getGid())
        {
          found = true;
        }
      }
      if (!found)
      {
        crossedGenes[curr] = chromosomes[r].getGeneAtIndex(index);
        curr++;
        curr %= sizeOfEachTeam;
      }
    }
    Chromosome X(i, sizeOfEachTeam);
    X.setGenes(crossedGenes);
    newPopulation.addNewChromosome(X);
  }
  return newPopulation;
}

Chromosome Population::getChromosomeAtIndex(int ind)
{
  return chromosomes[ind];
}