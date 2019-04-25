#include "dataStorage.hpp"
#include <vector>
using namespace std;



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
