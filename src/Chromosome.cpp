  #include "dataStorage.hpp"
  #include<vector>
  using namespace std;

  Chromosome::Chromosome()
  {
  }

  Chromosome::Chromosome(int id,int ts)
  {
    cid=id;
    teamSize=ts;
    genes.reserve(teamSize);
    fitnessVal=-1;
  }

  int Chromosome::getCid()
  {
    return cid;
  }

  int Chromosome::getTeamSize()
  {
     return teamSize;
  }

  int Chromosome::getFitnessVal()
  {
      return fitnessVal;
  }

  void Chromosome::setCid(int cid1)
  {
      cid=cid1;
  }

  void Chromosome::setTeamSize(int teamSize1)
  {
      teamSize = teamSize1;
  }

  void Chromosome::setGenes(vector<Gene> genes1)
  {
      copy(genes1.begin(), genes1.end(), back_inserter(genes)); 
  }

  void Chromosome::setFitnessVal(int fitnessVal1)
  { 
     fitnessVal = fitnessVal1;
  }

  void Chromosome::setGeneAtIndex(int i,Gene X)
  {
      genes[i]=X;
  }

  Gene* Chromosome::getGeneWithID(int id)
  {   
      vector<Gene>::iterator i;
      for(i=genes.begin();i!=genes.end(); ++i)
      {
        if( (*i).getGid() == id )
         return &(*i);
      }
      return NULL;
  }

  Gene Chromosome::getGeneAtIndex(int index)
  {
    return genes[index];
  }    

  void fitnessFunction(){

  };
