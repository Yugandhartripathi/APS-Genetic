#include "backBone.hpp"

Chromosome::Chromosome()
{
  cid=0;
  teamSize=4;
  genes.resize(teamSize);
  fitnessVal=-1;
}

Chromosome::Chromosome(int id, int ts)
{
  cid = id;
  teamSize = ts;
  genes.resize(teamSize);
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

vector<int> Chromosome::getGenes()
{
  return genes;
}

void Chromosome::setGenes(const vector<int>& g)
{
  genes=g;
}

void Chromosome::setFitnessVal(int fitnessVal1)
{
  fitnessVal = fitnessVal1;
}

void Chromosome::setGeneAtIndex(int i, int gid)
{
  genes.at(i)=gid;
}

int Chromosome::getGeneAtIndex(int index)
{
  return genes.at(index);
}

void Chromosome::fitnessFunction(const vector<int>& requiredSkill)
{
  int avgSQ = 0, avgEQ = 0, avgAptitude = 0, avgMatchingSkill = 0, avgNonMatchingSkill = 0;
  int match = 0, nonMatch = 0;
  for (int i = 0; i < teamSize; i++)
  {
    avgSQ += Genealogy.at(genes.at(i)).getSQ();
    avgEQ += Genealogy.at(genes.at(i)).getEQ();
    avgAptitude += Genealogy.at(genes.at(i)).getAptitude();
    for (int j = 0; j < 7; j++)
    {
      if (requiredSkill[j] == 1)
      {
        avgMatchingSkill += Genealogy.at(genes.at(i)).getExperienceBySkill(j);
        match++;
      }
      else
      {
        avgNonMatchingSkill += Genealogy.at(genes.at(i)).getExperienceBySkill(j);
        nonMatch++;
      }
    }
  }
  cout<<2*avgSQ/teamSize<<" "<<avgEQ/teamSize<<" "<<avgAptitude/teamSize<<" "<<(avgMatchingSkill*15)<<" "<<(avgNonMatchingSkill*3)<<endl;
  fitnessVal = 2 * (avgSQ / teamSize) + (avgEQ / teamSize) + (avgAptitude / teamSize) + avgMatchingSkill * 15 + avgNonMatchingSkill * 3;
}
