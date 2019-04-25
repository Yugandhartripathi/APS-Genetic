#include<dataStorage.hpp>
#include<vector>
using namespace std;

    Chromosome Population::fittestMember()
    { 
      Chromosome fittest;
      vector<Chromosome>::iterator i;
      i=chromosomes.begin();
      fittest = (*i);
      for(;i!=chromosomes.end(); ++i)
      {
        if( (*i).getFitnessVal() >= fittest.getFitnessVal() )
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
    void removeChromosomeWithCID(int cid);
    { Chromosome toBeDeleted;
      vector<Chromosome>::iterator i,;
      for(i=chromosomes.begin();i!=chromosomes.end(); ++i)
      {
        if( (*i).getCid() == cid )
         { toBeDeleted = (*i);
           break;
         }
      }
      vector<Chromosome>::iterator position = find(chromosomes.begin(),chromosomes.end(),toBeDeleted);
      if (position != chromosomes.end())
        chromosomes.erase(position);
    }
