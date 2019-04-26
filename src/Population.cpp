#include "dataStorage.hpp"
#include <vector>
using namespace std;

Population::Population()
{
}

Population::Population(int id,int ps)
{
  pid=id;
  populationSize=ps;
}

int Population::getID(){
  return pid;
}

void Population::setID(int id)
{
  pid=id;
}

int Population::getPopulationSize()
{
  return populationSize;
}

void Population::setPopulationSize(int ps)
{
  populationSize=ps;
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
  pos=chromosomes.end();
  for (i = chromosomes.begin(); i != chromosomes.end(); ++i)
  {
    if ((*i).getCid() == cid)
    {
      toBeDeleted = (*i);
      pos=i;
      break;
    }
  }
  if (pos != chromosomes.end())
    chromosomes.erase(pos);
}

void Population::populate()
{
  for(int i=0;i<populationSize;i++)
  {
    Chromosome newOrder(i,sizeOfEachTeam);
    for(int j=0;j<sizeOfEachTeam;j++)
    {
      Gene randomGene;
      newOrder.setGeneAtIndex(j,randomGene);
    }
    chromosomes.push_back(newOrder);
  }
}