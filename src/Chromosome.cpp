#include "dataStorage.hpp"

Chromosome::Chromosome()
{
}

Chromosome::Chromosome(int id, int ts)
{
  cid = id;
  teamSize = ts;
  genes.reserve(teamSize);
  fitnessVal = -1;
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
  cid = cid1;
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

void Chromosome::setGeneAtIndex(int i, Gene X)
{ 
  genes[i] = X;
  cout<<i<<" \n";
}

Gene Chromosome::getGeneAtIndex(int index)
{
  return genes[index];
}

void Chromosome::fitnessFunction(bool requiredSkill[7])
{
  int avgSQ = 0, avgEQ = 0, avgAptitude = 0, avgMatchingSkill = 0, avgNonMatchingSkill = 0;
  int match = 0, nonMatch = 0;
  //cout<<genes[0].getSQ()<<endl;
  for(int i=0;i<teamSize;i++) 
  { 
    avgSQ += genes[i].getSQ();
    avgEQ += genes[i].getEQ();
    avgAptitude += genes[i].getAptitude();
    for (int j = 1; j <= 7; j++)
    {
      if (requiredSkill[j-1] == true)
      {
        avgMatchingSkill += genes[i].getExperienceBySkill(j);
        match++;
      }
      else
      {
        avgNonMatchingSkill += genes[i].getExperienceBySkill(j);
        nonMatch++;
      }
    }
  }
  cout<<2*avgSQ/teamSize<<" "<<avgEQ/teamSize<<" "<<avgAptitude/teamSize<<" "<<(avgMatchingSkill*15)<<" "<<(avgNonMatchingSkill*3)<<endl;
  fitnessVal = 2*(avgSQ / teamSize) + (avgEQ / teamSize) + (avgAptitude / teamSize)+avgMatchingSkill*15+avgNonMatchingSkill*3;
  cout<<fitnessVal<<endl;
}
